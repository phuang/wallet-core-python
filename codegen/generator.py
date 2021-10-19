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
        functions = '\n'.join(['    PyInit_{},'.format(f) for f in names])

        values = { 'functions' : functions, 'includes' : includes }
        with open(os.path.join(OUTPUT_DIR, 'module.cc'), 'w') as out:
            template = self.template('module.cc')
            out.write(template.substitute(values))

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

        properties = []
        functions = []
        for prop in enum._properties:
            prop_name = prop._name[len(name) + 2:]
            values = { 'name' : name, 'prop_name' : prop_name }
            if prop._type._name in ('uint8_t', 'uint16_t', 'uint32_t'):
                function = '''
static PyObject* Py{name}{prop_name}(Py{name}Object *self, void *) {{
  return PyLong_FromLong((long)TW{name}{prop_name}(self->value));
}}\n'''.format_map(values)
            elif prop._type._name == 'bool':
                function = '''
static PyObject* Py{name}{prop_name}(Py{name}Object *self, void *) {{
  PyObject* result = TW{name}{prop_name}(self->value) ? Py_True : Py_False;
  Py_XINCREF(result);
  return result;
}}\n'''.format_map(values)
            elif prop._type._type == 'enum':
                prop_type = prop._type._name[2:]
                used_types.add(prop_type)
                values['prop_type'] = prop._type._name[2:]
                function = '''
static PyObject* Py{name}{prop_name}(Py{name}Object *self, void *) {{
  return Py{prop_type}_FromTW{prop_type}(TW{name}{prop_name}(self->value));
}}\n'''.format_map(values)
            else:
                continue
            properties.append(prop_name)
            functions.append(function)

        includes = list(used_types)
        includes.sort()
        includes = '\n'.join([ '#include "{}.h"'.format(n) for n in includes])

        properties = '\n  '.join([ '{{ "{1}", (getter)Py{0}{1} }},'.format(name, p) for p in properties ])

        values = {
            'name' : name,
            'includes' : includes,
            'constants' : constants,
            'properties' : properties,
            'methods' : '',
            'functions' : '\n'.join(functions)
        }

        with open(os.path.join(OUTPUT_DIR, name) + '.cc', 'w') as out:
            template = self.template('enum.cc')
            out.write(template.substitute(values))

        with open(os.path.join(OUTPUT_DIR, name) + '.h', 'w') as out:
            template = self.template('enum.h')
            out.write(template.substitute(values))


if __name__ == '__main__':
    Generator().generate()