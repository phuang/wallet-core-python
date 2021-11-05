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

compile_args = ['-std=c++17']

module = Extension('walletcore',
                   include_dirs=[WALLET_CORE_INCLUDE, 'src'],
                   library_dirs=[WALLET_CORE_BUILD, TREZOR_CRYPTO],
                   libraries=['TrustWalletCore', 'protobuf', 'TrezorCrypto'],
                   extra_compile_args=compile_args,
                   extra_link_args=link_args,
                   sources=glob('src/*.cc') + glob('src/generated/*.cc'))

setup(name='walletcore',
      version='0.1.0',
      description='Trust wallet core',
      author='Peng Huang',
      author_email='shawn.p.huang@gmail.com',
      url='https://github.com/phuang/wallet-core-python',
      download_url='',
      keywords=['cryptocurrency', 'wallet'],
      ext_modules=[module],
      classifiers=[
          'Development Status :: 3 - Alpha',
          'Intended Audience :: Developers',
          'Operating System :: POSIX :: Linux',
          'Topic :: Software Development :: Libraries :: Python Modules',
          'License :: OSI Approved :: GPL3',
          'Programming Language :: C++',
          '',
      ])
