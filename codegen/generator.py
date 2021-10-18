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
        functions = []
        for enum in self._parser._enums:
            self.generate_enum(enum)
            functions.append(enum._name[2:])
        
        declares = ['bool {}_init(PyObject* module);'.format(f) for f in functions]
        declares = '\n'.join(declares)

        functions = ['    {}_init,'.format(f) for f in functions]
        functions = '\n'.join(functions)

        values = { 'functions' : functions, 'declares' : declares }
        with open(os.path.join(OUTPUT_DIR, 'module.cc'), 'w') as out:
            template = self.template('module.cc')
            out.write(template.substitute(values))

    def generate_enum(self, enum):
        name = enum._name
        assert name.startswith('TW')
        name = name[2:]

        constants = []
        for fullname, v in enum._constants:
            assert fullname.startswith('TW' + name)
            shortname = fullname[2 + len(name):]
            constants.append('    PyDict_SetItemString(dict, "{}", PyLong_FromLong({}));'.format(shortname, fullname))
        constants = '\n'.join(constants)

        values = { 'name' : name, 'constants' : constants }
        
        with open(os.path.join(OUTPUT_DIR, name) + '.cc', 'w') as out:
            template = self.template('enum.cc')            
            out.write(template.substitute(values))


if __name__ == '__main__':
    Generator().generate()