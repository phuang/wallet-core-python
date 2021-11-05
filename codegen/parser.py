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

import glob
import os
import re

from os.path import basename
from os.path import dirname

DIR = dirname(__file__)
WALLET_CORE_INCLUDE = os.path.join(DIR, '..', 'wallet-core', 'include')


class Type:
    def __init__(self, text):
        self._text = text
        words = [w.strip() for w in text.split('*')]
        self._is_ptr = len(words) == 2
        self._is_nonnull = False
        if self._is_ptr:
            self._is_nonnull = words[1].strip() == '_Nonnull'

        words = words[0].split()
        self._name = words.pop()
        if self._name == 'int':
            self._name = 'int32_t'

        self._type = ''
        self._is_const = False
        self._is_static = False

        for word in words:
            if word == 'const':
                self._is_const = True
            elif word == 'enum':
                self._type = "enum"
            elif word == 'struct':
                self._type = "struct"
            elif word == 'static':
                self._is_static = True

    def __str__(self):
        words = []
        if self._is_static:
            words.append('static')
        if self._is_const:
            words.append('const')
        if self._type != '':
            words.append(self._type)
        words.append(self._name)
        if self._is_ptr:
            return ' '.join(words) + '*'
        else:
            return ' '.join(words)


class Argument:
    def __init__(self, text):
        type, name = text.rsplit(' ', 1)
        self._name = name
        self._type = Type(type)

    def __str__(self):
        return '{} {}'.format(str(self._type), self._name)


class Function:
    def __init__(self, text):
        result = re.findall(r'(.*) (\w+)\((.*)\);', text)
        if not result:
            raise Exception('failed to parse property: "{}"'.format(text))
        return_type, name, args = result[0]

        self._type = Type(return_type)
        self._name = name
        args = args.strip()
        if args != '' and args != 'void':
            args = [arg.strip() for arg in args.split(',')]
            self._args = [Argument(arg) for arg in args]
        else:
            self._args = []

    def __str__(self):
        args = map(str, self._args)
        return '{} {}({})'.format(str(self._type), self._name, ', '.join(args))


class Entity:
    def __init__(self, file, includes):
        self._file = file
        self._includes = includes
        self._methods = []
        self._properties = []
        self._static_methods = []
        self._static_properties = []

    def __str__(self):
        lines = []
        for method in self._methods:
            lines.append('TW_EXPORT_METHOD')
            lines.append(str(method))

        for property in self._properties:
            lines.append('TW_EXPORT_PROPERTY')
            lines.append(str(property))

        for method in self._static_methods:
            lines.append('TW_EXPORT_STATIC_METHOD')
            lines.append(str(method))

        for property in self._static_properties:
            lines.append('TW_EXPORT_STATIC_PROPERTY')
            lines.append(str(property))

        return '\n'.join(lines)

    def parse(self):
        assert not self._methods
        assert not self._properties
        # pare rest properties and methods
        for line in self._file:
            line = line.strip()
            if line == 'TW_EXPORT_PROPERTY':
                self.handle_function(self._properties)
            elif line == 'TW_EXPORT_METHOD':
                self.handle_function(self._methods)
            elif line == 'TW_EXPORT_STATIC_PROPERTY':
                self.handle_function(self._static_properties)
            elif line == 'TW_EXPORT_STATIC_METHOD':
                self.handle_function(self._static_methods)

    def handle_function(self, functions):
        line = self._file.readline().strip()
        if line == 'TW_METHOD_DISCARDABLE_RESULT':
            line = ''
        while not line.endswith(';'):
            line += ' '
            line += self._file.readline().strip()
        functions.append(Function(line))


class Enum(Entity):
    def __init__(self, file, line, includes):
        Entity.__init__(self, file, includes)
        self._name = None
        if line == 'TW_EXPORT_ENUM(uint32_t)' or line == 'TW_EXPORT_ENUM()':
            self._type = 'enum'
            self._enum_type = 'unit32_t'
        elif line == 'TW_EXPORT_ENUM(uint16_t)':
            self._type = 'enum'
            self._enum_type = 'unit16_t'
        elif line == 'TW_EXPORT_ENUM(uint8_t)':
            self._type = 'enum'
            self._enum_type = 'unit8_t'
        else:
            raise Exception('Parase enum failed ' + line)

        # parse enum TWName {
        line = self._file.readline()
        self._name = re.findall(r'^enum (\w+) {', line)[0]

        print('Found enum ' + self._name)

        # parse constants in the enum
        self._constants = []
        for line in self._file:
            line = line.strip()
            if line == '};':
                break

            # Examples:
            # TWCoinTypeCelo = 52752,
            # TWCurveED25519Extended        /* "ed25519-cardano-seed" */,
            # TWCurveNone
            result = re.findall(r'^(\w+)\s*.*,?', line)
            if result:
                self._constants.append(result[0])
                continue

        if not self._constants:
            raise Exception('No constants in {}'.format(self._name))
        # parse rest of the file
        Entity.parse(self)

    def __str__(self):
        lines = []
        lines.append('TW_EXPORT_ENUM({})'.format(self._enum_type))
        lines.append('enum {} {'.format(self._name))
        for name, value in self._constants:
            lines.append('{} = {}'.format(name, value))
        lines.append('}')
        lines.append(Entity.__str__(self))
        return '\n'.join(lines)


class Class(Entity):
    def __init__(self, file, line, includes):
        Entity.__init__(self, file, includes)
        self._name = None
        if line == 'TW_EXPORT_STRUCT':
            self._type = 'struct'
        elif line == 'TW_EXPORT_CLASS':
            self._type = 'class'
        else:
            raise Exception('Parase class failed ' + line)

        # parse struct TWName; or struct TWName {
        line = self._file.readline()
        self._name = re.findall(r'^struct (\w+)', line)[0]
        print('Found {} {}'.format(self._type, self._name))

        # parse rest of the file
        Entity.parse(self)

    def __str__(self):
        lines = []
        lines.append('TW_EXPORT_{} '.format(self._type.upper()))
        lines.append('struct {};'.format(self._name))
        lines.append(Entity.__str__(self))
        return '\n'.join(lines)


class Parser:
    def __init__(self):
        self._enums = []
        self._structs = []
        self._classes = []
        for filename in glob.glob(os.path.join(WALLET_CORE_INCLUDE, 'TrustWalletCore', '*.h')):
            if not filename.endswith('Proto.h'):
                self.parse_file(filename)

    def parse_file(self, filename):
        with open(filename) as file:
            self.parse(file)

    def parse(self, file):
        includes = []
        for line in file:
            line = line.strip()
            m = re.findall(r'^#include \"TW(\w+).h\"', line)
            if m:
                includes.append(m[0])
                continue

            if line == 'TW_EXPORT_CLASS':
                self._classes.append(Class(file, line, includes))
            elif line == 'TW_EXPORT_STRUCT':
                self._structs.append(Class(file, line, includes))
            elif line.startswith('TW_EXPORT_ENUM'):
                self._enums.append(Enum(file, line, includes))
            elif line == 'TW_EXPORT_FUNC':
                raise Exception('Not implemented ' + line)
            else:
                continue
            break


if __name__ == "__main__":
    parser = Parser()
