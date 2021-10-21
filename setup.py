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
from glob import glob
from distutils.core import setup, Extension

# Use clang since wallet-core headers don't compile with gcc
if 'CC' not in os.environ:
    os.environ['CC'] = 'clang'
if 'CXX' not in os.environ:
    os.environ['CXX'] = 'clang++'

WALLET_CORE_ROOT = 'wallet-core'
WALLET_CORE_INCLUDE = os.path.join(WALLET_CORE_ROOT, 'include')
WALLET_CORE_BUILD = os.path.join(WALLET_CORE_ROOT, 'build')
TREZOR_CRYPTO = os.path.join(WALLET_CORE_BUILD, 'trezor-crypto')

link_args = []
# Add --coverage link arg otherwise linking fails with undefined symbols
for line in open(os.path.join(WALLET_CORE_BUILD, 'CMakeCache.txt')):
    line = line.strip()
    if line == 'CODE_COVERAGE:BOOL=ON':
        link_args.append('--coverage')
        break

compile_args = []

module = Extension('walletcore',
                    include_dirs = [ WALLET_CORE_INCLUDE ],
                    library_dirs = [ WALLET_CORE_BUILD, TREZOR_CRYPTO ],
                    libraries = [ 'TrustWalletCore', 'protobuf' , 'TrezorCrypto'],
                    extra_compile_args = compile_args,
                    extra_link_args = link_args,
                    sources = glob('src/*.cc'))

setup(name = 'walletcore',
      version = '1.0',
      description = 'Trust wallet core',
      author = 'Peng Huang',
      author_email = 'shawn.p.huang@gmail.com',
      ext_modules = [module])
