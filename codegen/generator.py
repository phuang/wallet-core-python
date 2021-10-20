#!/usr/bin/env python3

import os

from os.path import basename
from os.path import dirname
from parser import Parser
from string import Template

DIR = dirname(__file__)
OUTPUT_DIR = os.path.join(DIR, '..', 'src')

class Generator:
    def __init__(self):
        self._parser = Parser()

    def template(self, filename):
        filepath = os.path.join(DIR, 'templates', filename)
        return Template(open(filepath).read())

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
        template = Template('''
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

        for arg in args:
            pass

    def process_methods(self, name, methods):
        template = Template('''
// method function for ${method_name}
static PyObject* Py${name}${method_name}(Py${name}Object *self,
                                         PyObject *const *args,
                                         Py_ssize_t nargs) {
  ${prepare_args};
  auto${return_ptr} result = TW${name}${method_name}(self->value${args});
  return ${return}(result);
}\n''')
        used_types = set()
        methoddefs = []
        functions = []
        for method in methods:
            method_name = method._name[len(name) + 2:]
            if method._type._name in ('uint8_t', 'uint16_t', 'uint32_t'):
                return_ = 'PyLong_FromLong'
            elif method._type._name == 'bool':
                return_ = 'PyBool_FromLong'
            elif method._type._type == 'enum':
                method_type = method._type._name[2:]
                used_types.add(method_type)
                return_ = 'Py{0}_FromTW{0}'.format(method_type)
            else:
                continue
            values = {
                'name' : name,
                'method_name' : method_name,
                'prepare_args' : '',
                'args' : '',
                'return_ptr' : '',
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
