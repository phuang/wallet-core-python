#!/usr/bin/env python3
# Copyright 2021 Peng Huang <shawn.p.huang@gmail.com>
# This file is part of wallet-core-python.
#
# Foobar is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# Foobar is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with Foobar.  If not, see <https://www.gnu.org/licenses/>.

import os

from os.path import basename
from os.path import dirname
from parser import Parser
from string import Template as T

DIR = dirname(__file__)
OUTPUT_DIR = os.path.join(DIR, '..', 'src')

class Generator:
    def __init__(self):
        self._parser = Parser()

    def template(self, filename):
        filepath = os.path.join(DIR, 'templates', filename)
        return T(open(filepath).read())

    def format(self):
        # format generated c/c++ source code
        os.system('/usr/bin/clang-format -style=Chromium -i \
            {0}/*.cc {0}/*.h'.format(OUTPUT_DIR))

    def process_properties(self, name, props):
        template = T('''
// getter function for ${prop_name}
static const char Py${name}${prop_name}_doc[] =
    "${c_property}";
static PyObject* Py${name}${prop_name}(Py${name}Object *self, void *) {
  return ${return}(TW${name}${prop_name}(self->value));
}\n''')
        used_types = set()
        getsetdefs = []
        functions = []
        for prop in props:
            prop_name = prop._name[len(name) + 2:]
            if prop._type._name in ('uint8_t', 'uint16_t', 'uint32_t'):
                return_ = 'PyLong_FromLong'
            elif prop._type._name == 'bool':
                return_ = 'PyBool_FromLong'
            elif prop._type._type in ('struct', 'enum'):
                prop_type = prop._type._name[2:]
                used_types.add(prop_type)
                return_ = 'Py{0}_FromTW{0}'.format(prop_type)
            elif prop._type._name == 'TWString':
                prop_type = prop._type._name[2:]
                used_types.add('String')
                return_ = 'PyUnicode_FromTWString'
            elif prop._type._name == 'TWData':
                prop_type = prop._type._name[2:]
                used_types.add('Data')
                return_ = 'PyByteArray_FromTWData'
            else:
                continue

            values = {
                'c_property' : str(prop),
                'name' : name,
                'prop_name' : prop_name,
                'return' : return_,
            }
            function = template.substitute(values)
            functions.append(function)
            getsetdefs.append(prop_name)

        includes = list(used_types)
        includes.sort()
        includes = [ '#include "{}.h"'.format(n) for n in includes]

        getsetdefs = [ '{{ "{1}", (getter)Py{0}{1}, nullptr, Py{0}{1}_doc }},'.format(name, p) for p in getsetdefs ] + [ '{}' ]
        return includes, functions, getsetdefs

    def process_arguments(self, args):
        prepare_args = []
        prepare_args.append(T('''
  if (nargs != ${nargs}) {
    PyErr_Format(PyExc_TypeError, "Expect ${nargs} args, but %d args are passed in.", nargs);
    return nullptr;
  }
''').substitute(nargs = len(args)))

        template = T('''
  if (!Py${arg_type}_Check(args[${i}])) {
    PyErr_SetString(PyExc_TypeError, "The arg ${i} is not in type ${arg_type}");
    return nullptr;
  }
  auto arg${i} = ${get_ctype}(args[${i}]);
''')
        call_args = []
        used_types = set()
        for i, arg in enumerate(args):
            if arg._type._name == 'bool':
                arg_type  = 'Bool'
                get_ctype = 'PyBool_IsTrue'
                call_args.append('arg{}'.format(i))
                used_types.add('Bool')
            elif arg._type._name in ('int8_t', 'uint8_t', 'int16_t', 'uint16_t', 'int', 'int32_t', 'uint32_t', 'size_t'):
                # Check overflow
                arg_type  = 'Long'
                get_ctype = 'PyLong_AsLong'
                call_args.append('arg{}'.format(i))
            elif arg._type._name in ('int64_t', 'uint64_t'):
                # Check overflow
                arg_type  = 'Long'
                get_ctype = 'PyLong_AsLongLong'
                call_args.append('arg{}'.format(i))
            elif arg._type._name == 'TWString':
                assert arg._type._is_ptr
                arg_type  = 'Unicode'
                get_ctype = 'PyUnicode_GetTWString'
                call_args.append('arg{}.get()'.format(i))
                used_types.add('String')
            elif arg._type._name == 'TWData':
                assert arg._type._is_ptr
                arg_type  = 'ByteArray'
                get_ctype = 'PyByteArray_GetTWData'
                call_args.append('arg{}.get()'.format(i))
                used_types.add('Data')
            elif arg._type._type == 'enum':
                assert not arg._type._is_ptr
                arg_type  = arg._type._name[2:]
                get_ctype = 'Py{0}_GetTW{0}'.format(arg_type)
                call_args.append('arg{}'.format(i))
                used_types.add(arg_type)
            elif arg._type._type == 'struct':
                assert arg._type._is_ptr
                arg_type  = arg._type._name[2:]
                get_ctype = 'Py{0}_GetTW{0}'.format(arg_type)
                call_args.append('arg{}'.format(i))
                used_types.add(arg_type)
            else:
                raise Exception('Not support argument type:' + str(arg._type))
            values = {
                'arg_type' : arg_type,
                'i' : i,
                'get_ctype' : get_ctype,
            }
            prepare_args.append(template.substitute(values))

        prepare_args = '\n'.join(prepare_args)
        call_args = ', '.join(call_args)
        return prepare_args, call_args, used_types

    def process_methods(self, name, methods, is_static):
        template = T('''
// ${static}method function for ${method_name}
static const char Py${name}${method_name}_doc[] =
    "${c_function}";
static PyObject* Py${name}${method_name}(Py${name}Object *self,
                                         PyObject *const *args,
                                         Py_ssize_t nargs) {
  ${prepare_args}
  ${return_type} result = TW${name}${method_name}(${call_args});
  return ${return}(result);
}\n''')
        void_template = T('''
// ${static}method function for ${method_name}
static const char Py${name}${method_name}_doc[] =
    "${c_function}";
static PyObject* Py${name}${method_name}(Py${name}Object *self,
                                         PyObject *const *args,
                                         Py_ssize_t nargs) {
  ${prepare_args}
  TW${name}${method_name}(${call_args});
  return nullptr;
}\n''')
        used_types = set()
        methoddefs = []
        functions = []
        for method in methods:
            method_name = method._name[len(name) + 2:]
            if method._type._name in ('uint8_t', 'uint16_t', 'uint32_t', 'int'):
                return_type = method._type._name
                return_ = 'PyLong_FromLong'
            elif method._type._name in ('uint64_t'):
                return_type = method._type._name
                return_ = 'PyLong_FromLongLong'
            elif method._type._name == 'bool':
                return_type = method._type._name
                return_ = 'PyBool_FromLong'
            elif method._type._type == 'enum':
                return_type = method._type._name
                used_types.add(return_type[2:])
                return_ = 'Py{0}_FromTW{0}'.format(return_type[2:])
            elif method._type._type == 'struct':
                assert method._type._is_ptr
                return_type = method._type._name
                used_types.add(return_type[2:])
                return_ = 'Py{0}_FromTW{0}'.format(return_type[2:])
                return_type += '*'
            elif method._type._name == 'TWData':
                return_type = 'TWDataPtr'
                used_types.add('Data')
                return_ = 'PyByteArray_FromTWData'
            elif method._type._name == 'TWString':
                return_type = 'TWStringPtr'
                used_types.add('String')
                return_ = 'PyUnicode_FromTWString'
            elif method._type._name == 'void':
                return_type = 'void'
                return_ = ''
            else:
                raise Exception('Not support method return type:' + str(method._type))
            if not is_static:
                prepare_args, call_args, types = self.process_arguments(method._args[1:])
                call_args = 'self->value, '  + call_args if call_args else 'self->value'
            else:
                prepare_args, call_args, types = self.process_arguments(method._args)
            used_types |= types
            values = {
                'static' : 'static ' if is_static else '',
                'c_function' : str(method),
                'name' : name,
                'method_name' : method_name,
                'prepare_args' : prepare_args,
                'call_args' : call_args,
                'return_type' : return_type,
                'return' : return_,
            }
            function = template.substitute(values) if return_type != 'void' else void_template.substitute(values)
            functions.append(function)
            methoddefs.append(method_name)

        used_types.discard(name)
        includes = list(used_types)
        includes.sort()
        includes = [ '#include "{}.h"'.format(n) for n in includes]

        flags = 'METH_FASTCALL | METH_STATIC' if is_static else 'METH_FASTCALL'
        methoddefs = [ '{{ "{1}", (PyCFunction)Py{0}{1}, {2}, Py{0}{1}_doc }},'.format(name, m, flags) for m in methoddefs ]
        return includes, functions, methoddefs

    def generate_enum(self, enum):
        name = enum._name
        assert name.startswith('TW')
        name = name[2:]
        used_types = set()

        constants = []
        for fullname in enum._constants:
            assert fullname.startswith('TW' + name)
            shortname = fullname[2 + len(name):]
            constants.append('    I({}) \\'.format(shortname))
        constants = '\n'.join(constants)

        prop_includes, prop_functions, getsetdefs = self.process_properties(name, enum._properties)
        method_includes, method_functions, methoddefs = self.process_methods(name, enum._methods, False)
        static_method_includes, static_method_functions, static_methoddefs = self.process_methods(name, enum._static_methods, True)

        includes = prop_includes + method_includes + static_method_includes
        includes = '\n'.join(includes)
        functions = prop_functions + method_functions + static_method_functions
        functions = '\n'.join(functions)
        getsetdefs = '\n  '.join(getsetdefs)
        methoddefs = methoddefs + static_methoddefs + [ '{}' ]
        methoddefs = '\n  '.join(methoddefs)

        values = {
            'name' : name,
            'includes' : includes,
            'constants' : constants,
            'getsetdefs' : getsetdefs,
            'methoddefs' : methoddefs,
            'functions' : functions
        }

        with open(os.path.join(OUTPUT_DIR, name) + '.cc', 'w') as out:
            template = self.template('enum.cc')
            out.write(template.substitute(values))

        with open(os.path.join(OUTPUT_DIR, name) + '.h', 'w') as out:
            template = self.template('enum.h')
            out.write(template.substitute(values))

    def generate_class(self, class_):
        name = class_._name
        assert name.startswith('TW')
        name = name[2:]
        used_types = set()

        prop_includes, prop_functions, getsetdefs = self.process_properties(name, class_._properties)
        method_includes, method_functions, methoddefs = self.process_methods(name, class_._methods, False)
        static_method_includes, static_method_functions, static_methoddefs = self.process_methods(name, class_._static_methods, True)

        includes = prop_includes + method_includes + static_method_includes
        includes = '\n'.join(includes)
        functions = prop_functions + method_functions + static_method_functions
        functions = '\n'.join(functions)
        getsetdefs = '\n  '.join(getsetdefs)
        methoddefs = methoddefs + static_methoddefs + [ '{}' ]
        methoddefs = '\n  '.join(methoddefs)

        values = {
            'name' : name,
            'includes' : includes,
            'getsetdefs' : getsetdefs,
            'methoddefs' : methoddefs,
            'functions' : functions
        }

        with open(os.path.join(OUTPUT_DIR, name) + '.cc', 'w') as out:
            template = self.template('class.cc')
            out.write(template.substitute(values))

        with open(os.path.join(OUTPUT_DIR, name) + '.h', 'w') as out:
            template = self.template('class.h')
            out.write(template.substitute(values))

    def generate_struct(self, struct):
        name = struct._name
        assert name.startswith('TW')
        name = name[2:]
        used_types = set()

        prop_includes, prop_functions, getsetdefs = self.process_properties(name, struct._properties)
        method_includes, method_functions, methoddefs = self.process_methods(name, struct._methods, False)
        static_method_includes, static_method_functions, static_methoddefs = self.process_methods(name, struct._static_methods, True)

        includes = prop_includes + method_includes + static_method_includes
        includes = '\n'.join(includes)
        functions = prop_functions + method_functions + static_method_functions
        functions = '\n'.join(functions)
        getsetdefs = '\n  '.join(getsetdefs)
        methoddefs = methoddefs + static_methoddefs + [ '{}' ]
        methoddefs = '\n  '.join(methoddefs)

        values = {
            'name' : name,
            'includes' : includes,
            'getsetdefs' : getsetdefs,
            'methoddefs' : methoddefs,
            'functions' : functions
        }

        with open(os.path.join(OUTPUT_DIR, name) + '.cc', 'w') as out:
            template = self.template('struct.cc')
            out.write(template.substitute(values))

        with open(os.path.join(OUTPUT_DIR, name) + '.h', 'w') as out:
            template = self.template('struct.h')
            out.write(template.substitute(values))

    def generate(self):
        names = []
        for enum in self._parser._enums:
            self.generate_enum(enum)
            names.append(enum._name[2:])

        for class_ in self._parser._classes:
            self.generate_class(class_)
            names.append(class_._name[2:])

        for struct in self._parser._structs:
            self.generate_struct(struct)
            names.append(struct._name[2:])

        names.sort()
        includes = '\n'.join(['#include "{}.h"'.format(f) for f in names])
        functions = '\n'.join(['  PyInit_{},'.format(f) for f in names])

        values = { 'functions' : functions, 'includes' : includes }
        with open(os.path.join(OUTPUT_DIR, 'module.cc'), 'w') as out:
            template = self.template('module.cc')
            out.write(template.substitute(values))

        self.format()


if __name__ == '__main__':
    Generator().generate()
