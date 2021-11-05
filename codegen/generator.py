#!/usr/bin/env python3
# Copyright 2021 Peng Huang <shawn.p.huang@gmail.com>
# This file is part of Wallet-core-python.
#
# Wallet-core-python is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# Wallet-core-python is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with Wallet-core-python.  If not, see <https://www.gnu.org/licenses/>.

import os
import os.path
import shutil

from filecmp import dircmp
from jinja2 import Environment, FileSystemLoader
from os.path import dirname
from parser import Parser
from string import Template as T
from tempfile import mkdtemp

DIR = os.path.abspath(os.path.dirname(__file__))
OUTPUT_DIR = os.path.join(DIR, '..', 'src', 'generated')
TEMPLATES_DIR = os.path.join(DIR, 'templates')


class Generator:
    def __init__(self):
        self._parser = Parser()
        self._tmp_dir = mkdtemp()
        self._loader = Environment(
            loader=FileSystemLoader(TEMPLATES_DIR), autoescape=False)

    def py_name(self, name):
        py_name = [name[0].lower()]
        last_is_upper = True
        for c in name[1:]:
            if not c.isupper():
                last_is_upper = False
                py_name.append(c)
            else:
                if not last_is_upper:
                    py_name.append('_')
                    last_is_upper = True
                py_name.append(c.lower())
        return ''.join(py_name)

    def get_template(self, name):
        return self._loader.get_template(name)

    def clang_format(self, path):
        # format generated c/c++ source code
        os.system('/usr/bin/clang-format -style=Chromium -i \
            {0}/*.cc {0}/*.h'.format(path))

    def get_includes(self, used_types):
        non_generated = {'AnySigner', 'Bool', 'Data', 'Number',  'String'}
        includes = [name if name in non_generated else 'generated/' + name
                    for name in used_types]
        includes.sort()
        includes = ['#include "{}.h"'.format(n) for n in includes]
        return includes

    def process_properties(self, name, props):
        template = T('''
// getter function for ${prop_name}
static const char Py${name}${prop_name}_doc[] =
    "${c_property}";
static PyObject* Py${name}${prop_name}(Py${name}Object *self, void *) {
  ${return_type} prop = TW${name}${prop_name}(self->value);
  return ${return}(prop);
}\n''')
        template_with_unique = T('''
// getter function for ${prop_name}
static const char Py${name}${prop_name}_doc[] =
    "${c_property}";
static PyObject* Py${name}${prop_name}(Py${name}Object *self, void *) {
  ${return_type} prop(TW${name}${prop_name}(self->value));
  return ${return}(prop);
}\n''')
        used_types = set()
        getsetdefs = []
        functions = []
        for prop in props:
            prop_name = prop._name[len(name) + 2:]
            if prop._type._name in ('uint8_t', 'uint16_t', 'uint32_t', 'size_t'):
                return_type = prop._type._name
                return_ = 'PyLong_FromLong'
            elif prop._type._name == 'bool':
                return_type = prop._type._name
                return_ = 'PyBool_FromLong'
            elif prop._type._type == 'enum':
                return_type = prop._type._name
                prop_type = prop._type._name[2:]
                used_types.add(prop_type)
                return_ = 'Py{0}_FromTW{0}'.format(prop_type)
            elif prop._type._type == 'struct':
                return_type = prop._type._name + '*'
                prop_type = prop._type._name[2:]
                used_types.add(prop_type)
                return_ = 'Py{0}_FromTW{0}'.format(prop_type)
            elif prop._type._name == 'TWString':
                return_type = 'TWStringPtr'
                prop_type = prop._type._name[2:]
                used_types.add('String')
                return_ = 'PyUnicode_FromTWString'
            elif prop._type._name == 'TWData':
                return_type = 'TWDataPtr'
                prop_type = prop._type._name[2:]
                used_types.add('Data')
                return_ = 'PyBytes_FromTWData'
            else:
                raise Exception(
                    'Not support property type: ' + str(prop._type))

            values = {
                'c_property': str(prop),
                'name': name,
                'prop_name': prop_name,
                'return_type': return_type,
                'return': return_,
            }
            if return_type in {'TWStringPtr', 'TWDataPtr'}:
                t = template_with_unique
            else:
                t = template
            function = t.substitute(values)
            functions.append(function)
            getsetdefs.append(prop_name)

        includes = self.get_includes(used_types)
        getsetdefs_format = '{{ "{2}", (getter)Py{0}{1}, nullptr, Py{0}{1}_doc }}'
        getsetdefs = [
            getsetdefs_format.format(name, p, self.py_name(p))
            for p in getsetdefs]
        return includes, functions, getsetdefs

    def process_arguments(self, args):
        prepare_args = []
        prepare_args.append(T('''
  if (nargs != ${nargs}) {
    PyErr_Format(PyExc_TypeError, "Expect ${nargs} args, but %d args are passed in.", nargs);
    return nullptr;
  }
''').substitute(nargs=len(args)))

        template = T('''
  if (!Py${arg_type}_Check(args[${i}])) {
    PyErr_SetString(PyExc_TypeError, "The arg ${i} is not in type ${arg_type}");
    return nullptr;
  }
  auto arg${i} = ${get_ctype}(args[${i}]);
''')
        template_for_number = T('''
  auto checked_arg${i} = PyLongArg_ToNumber<${arg_ctype}>(args[${i}], ${i}, "${arg_ctype}");
  if (!checked_arg${i})
      return nullptr;
  const auto& arg${i} = checked_arg${i}.value();
''')
        call_args = []
        int_types = {
            'int8_t', 'uint8_t', 'int16_t', 'uint16_t', 'int',
            'int32_t', 'uint32_t', 'size_t', 'int64_t', 'uint64_t'
        }
        used_types = set()
        for i, arg in enumerate(args):
            is_number = False
            if arg._type._name == 'bool':
                arg_type = 'Bool'
                arg_ctype = 'bool'
                get_ctype = 'PyBool_IsTrue'
                call_args.append('arg{}'.format(i))
                used_types.add('Bool')
            elif arg._type._name in int_types:
                arg_type = 'Long'
                arg_ctype = arg._type._name
                get_ctype = 'PyLong_AsLongLong'
                call_args.append('arg{}'.format(i))
                used_types.add('Number')
                is_number = True
            elif arg._type._name == 'TWString':
                assert arg._type._is_ptr
                arg_type = 'Unicode'
                arg_ctype = 'TWStringPtr'
                get_ctype = 'PyUnicode_GetTWString'
                call_args.append('arg{}.get()'.format(i))
                used_types.add('String')
            elif arg._type._name == 'TWData':
                assert arg._type._is_ptr
                arg_type = 'Bytes'
                arg_ctype = 'TWDataPtr'
                get_ctype = 'PyBytes_GetTWData'
                call_args.append('arg{}.get()'.format(i))
                used_types.add('Data')
            elif arg._type._type == 'enum':
                assert not arg._type._is_ptr
                arg_type = arg._type._name[2:]
                arg_ctype = arg._type._name
                get_ctype = 'Py{0}_GetTW{0}'.format(arg_type)
                call_args.append('arg{}'.format(i))
                used_types.add(arg_type)
            elif arg._type._type == 'struct':
                assert arg._type._is_ptr
                arg_type = arg._type._name[2:]
                arg_ctype = arg._type._name + '*'
                get_ctype = 'Py{0}_GetTW{0}'.format(arg_type)
                call_args.append('arg{}'.format(i))
                used_types.add(arg_type)
            else:
                raise Exception('Not support argument type:' + str(arg._type))
            values = {
                'arg_type': arg_type,
                'arg_ctype': arg_ctype,
                'i': i,
                'get_ctype': get_ctype,
            }
            t = template_for_number if is_number else template
            prepare_args.append(t.substitute(values))

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
        unique_template = T('''
// ${static}method function for ${method_name}
static const char Py${name}${method_name}_doc[] =
    "${c_function}";
static PyObject* Py${name}${method_name}(Py${name}Object *self,
                                         PyObject *const *args,
                                         Py_ssize_t nargs) {
  ${prepare_args}
  ${return_type} result(TW${name}${method_name}(${call_args}));
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
        int_types = {
            'int8_t', 'int16_t', 'int32_t', 'int64_t',
            'uint8_t', 'uint16_t', 'uint32_t', 'uint64_t',
        }
        for method in methods:
            method_name = method._name[len(name) + 2:]
            if method_name == 'Delete':
                assert not is_static
                continue
            if method._type._name in int_types:
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
                return_ = 'PyBytes_FromTWData'
            elif method._type._name == 'TWString':
                return_type = 'TWStringPtr'
                used_types.add('String')
                return_ = 'PyUnicode_FromTWString'
            elif method._type._name == 'void':
                return_type = 'void'
                return_ = ''
            else:
                raise Exception(
                    'Not support method return type:' + str(method._type))
            if not is_static:
                prepare_args, call_args, types = self.process_arguments(
                    method._args[1:])
                call_args = 'self->value, ' + call_args if call_args else 'self->value'
            else:
                prepare_args, call_args, types = self.process_arguments(
                    method._args)
            used_types |= types
            values = {
                'static': 'static ' if is_static else '',
                'c_function': str(method),
                'name': name,
                'method_name': method_name,
                'prepare_args': prepare_args,
                'call_args': call_args,
                'return_type': return_type,
                'return': return_,
            }
            if return_type == 'void':
                t = void_template
            elif return_type in {'TWStringPtr', 'TWDataPtr'}:
                t = unique_template
            else:
                t = template
            function = t.substitute(values)
            functions.append(function)
            methoddefs.append(method_name)

        used_types.discard(name)
        includes = self.get_includes(used_types)

        flags = 'METH_FASTCALL | METH_STATIC' if is_static else 'METH_FASTCALL'
        methoddef_fomat = '{{ "{0}", (PyCFunction)Py{1}{2}, {3}, Py{1}{2}_doc }}'
        methoddefs = [
            methoddef_fomat.format(self.py_name(m), name, m, flags)
            for m in methoddefs]
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
            constants.append(shortname)

        prop_includes, prop_functions, getsetdefs = self.process_properties(
            name, enum._properties)
        method_includes, method_functions, methoddefs = self.process_methods(
            name, enum._methods, False)
        static_method_includes, static_method_functions, static_methoddefs = self.process_methods(
            name, enum._static_methods, True)

        includes = prop_includes + method_includes + static_method_includes
        includes.sort()

        functions = prop_functions + method_functions + static_method_functions
        methoddefs = methoddefs + static_methoddefs

        values = {
            'name': name,
            'includes': includes,
            'constants': constants,
            'getsetdefs': getsetdefs,
            'methoddefs': methoddefs,
            'functions': functions,
            'properties': enum._properties,
        }

        with open(os.path.join(self._tmp_dir, name) + '.cc', 'w') as out:
            template = self.get_template('enum.cc')
            output = template.render(values)
            out.write(output)

        with open(os.path.join(self._tmp_dir, name) + '.h', 'w') as out:
            template = self.get_template('enum.h')
            output = template.render(values)
            out.write(output)

    def generate_class(self, class_):
        name = class_._name
        assert name.startswith('TW')
        name = name[2:]
        used_types = set()

        prop_includes, prop_functions, getsetdefs = self.process_properties(
            name, class_._properties)
        method_includes, method_functions, methoddefs = self.process_methods(
            name, class_._methods, False)
        static_method_includes, static_method_functions, static_methoddefs = self.process_methods(
            name, class_._static_methods, True)

        includes = prop_includes + method_includes + static_method_includes
        includes.sort()
        functions = prop_functions + method_functions + static_method_functions
        methoddefs = methoddefs + static_methoddefs

        values = {
            'name': name,
            'includes': includes,
            'getsetdefs': getsetdefs,
            'methoddefs': methoddefs,
            'functions': functions
        }

        with open(os.path.join(self._tmp_dir, name) + '.cc', 'w') as out:
            template = self.get_template('class.cc')
            out.write(template.render(values))

        with open(os.path.join(self._tmp_dir, name) + '.h', 'w') as out:
            template = self.get_template('class.h')
            out.write(template.render(values))

    def generate_struct(self, struct):
        name = struct._name
        assert name.startswith('TW')
        name = name[2:]
        used_types = set()

        prop_includes, prop_functions, getsetdefs = self.process_properties(
            name, struct._properties)
        method_includes, method_functions, methoddefs = self.process_methods(
            name, struct._methods, False)
        static_method_includes, static_method_functions, static_methoddefs = self.process_methods(
            name, struct._static_methods, True)

        includes = prop_includes + method_includes + static_method_includes
        includes.sort()
        functions = prop_functions + method_functions + static_method_functions
        methoddefs = methoddefs + static_methoddefs

        values = {
            'name': name,
            'includes': includes,
            'getsetdefs': getsetdefs,
            'methoddefs': methoddefs,
            'functions': functions
        }

        with open(os.path.join(self._tmp_dir, name) + '.cc', 'w') as out:
            template = self.get_template('struct.cc')
            out.write(template.render(values))

        with open(os.path.join(self._tmp_dir, name) + '.h', 'w') as out:
            template = self.get_template('struct.h')
            out.write(template.render(values))

    def generate(self):
        used_types = set()
        for enum in self._parser._enums:
            self.generate_enum(enum)
            used_types.add(enum._name[2:])

        for class_ in self._parser._classes:
            self.generate_class(class_)
            used_types.add(class_._name[2:])

        for struct in self._parser._structs:
            self.generate_struct(struct)
            used_types.add(struct._name[2:])

        used_types.add('AnySigner')
        includes = self.get_includes(used_types)

        names = list(used_types)
        names.sort()
        functions = ['PyInit_' + f for f in names]

        values = {'functions': functions, 'includes': includes}
        with open(os.path.join(self._tmp_dir, 'module.cc'), 'w') as out:
            template = self.get_template('module.cc')
            out.write(template.render(values))

        self.clang_format(self._tmp_dir)
        result = dircmp(self._tmp_dir, OUTPUT_DIR)
        for file in result.left_only:
            print('new file: ' + file)
            shutil.copy(os.path.join(self._tmp_dir, file), OUTPUT_DIR)
        for file in result.diff_files:
            print('diff file: ' + file)
            shutil.copy(os.path.join(self._tmp_dir, file), OUTPUT_DIR)
        shutil.rmtree(self._tmp_dir)


if __name__ == '__main__':
    Generator().generate()
