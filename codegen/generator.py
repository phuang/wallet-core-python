#!/usr/bin/env python3

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

    def generate(self):
        names = []
        for enum in self._parser._enums:
            self.generate_enum(enum)
            names.append(enum._name[2:])
        names.sort()

        includes = '\n'.join(['#include "{}.h"'.format(f) for f in names])
        functions = '\n'.join(['  PyInit_{},'.format(f) for f in names])

        values = { 'functions' : functions, 'includes' : includes }
        with open(os.path.join(OUTPUT_DIR, 'module.cc'), 'w') as out:
            template = self.template('module.cc')
            out.write(template.substitute(values))

        self.format()

    def format(self):
        # format generated c/c++ source code
        os.system('/usr/bin/clang-format -style=Chromium -i \
            {0}/*.cc {0}/*.h'.format(OUTPUT_DIR))

    def process_properties(self, name, props):
        template = T('''
// getter function for ${prop_name}
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
            elif prop._type._type == 'enum':
                prop_type = prop._type._name[2:]
                used_types.add(prop_type)
                return_ = 'Py{0}_FromTW{0}'.format(prop_type)
            else:
                continue

            values = {
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

        getsetdefs = [ '{{ "{1}", (getter)Py{0}{1} }},'.format(name, p) for p in getsetdefs ] + [ '{}' ]
        return includes, functions, getsetdefs

    def process_arguments(self, args):
        prepare_args = []
        prepare_args.append(T('''
  if (nargs != ${nargs}) {
    PyErr_Format(PyExc_TypeError, "Expect ${nargs} instead of %d.", nargs);
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
            print(arg._name)
            print(arg._type._name)
            if arg._type._name == 'TWString':
                assert arg._type._is_ptr
                arg_type  = 'Unicode'
                get_ctype = 'PyUnicode_GetTWString'
                call_args.append('arg{}.get()'.format(i))
                used_types.add('String')
            else:
                continue
            values = {
                'arg_type' : arg_type,
                'i' : i,
                'get_ctype' : get_ctype,
            }
            prepare_args.append(template.substitute(values))
        prepare_args = '\n'.join(prepare_args)
        call_args = ', '.join(call_args)
        return prepare_args, call_args, used_types

    def process_methods(self, name, methods):
        template = T('''
// method function for ${method_name}
static PyObject* Py${name}${method_name}(Py${name}Object *self,
                                         PyObject *const *args,
                                         Py_ssize_t nargs) {
  ${prepare_args}
  ${return_type} result = TW${name}${method_name}(${call_args});
  return ${return}(result);
}\n''')
        used_types = set()
        methoddefs = []
        functions = []
        for method in methods:
            method_name = method._name[len(name) + 2:]
            if method._type._name in ('uint8_t', 'uint16_t', 'uint32_t'):
                return_type = method._type._name
                return_ = 'PyLong_FromLong'
            elif method._type._name == 'bool':
                return_type = method._type._name
                return_ = 'PyBool_FromLong'
            elif method._type._type == 'enum':
                return_type = method._type._name
                used_types.add(return_type[2:])
                return_ = 'Py{}_FromTW{}'.format(return_type[2:])
            else:
                continue
            prepare_args, call_args, types = self.process_arguments(method._args[1:])
            call_args = 'self->value, '  + call_args if call_args else 'self->value'
            used_types |= types
            values = {
                'name' : name,
                'method_name' : method_name,
                'prepare_args' : prepare_args,
                'call_args' : call_args,
                'return_type' : return_type,
                'return' : return_,
            }
            function = template.substitute(values)
            functions.append(function)
            methoddefs.append(method_name)

        includes = list(used_types)
        includes.sort()
        includes = [ '#include "{}.h"'.format(n) for n in includes]

        methoddefs = [ '{{ "{1}", (PyCFunction)Py{0}{1}, METH_FASTCALL }},'.format(name, m) for m in methoddefs ] + [ '{}' ]
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
        method_includes, method_functions, methoddefs = self.process_methods(name, enum._methods)

        includes = prop_includes + method_includes
        includes = '\n'.join(includes)
        functions = prop_functions + method_functions
        functions = '\n'.join(functions)

        getsetdefs = '\n  '.join(getsetdefs)
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


if __name__ == '__main__':
    Generator().generate()
