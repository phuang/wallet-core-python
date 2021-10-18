import os
from glob import glob
from distutils.core import setup, Extension

# Use clang since wallet-core headers don't compile with gcc
os.environ['CC'] = 'clang'
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

module = Extension('walletcore',
                    include_dirs = [ WALLET_CORE_INCLUDE ],
                    library_dirs = [ WALLET_CORE_BUILD, TREZOR_CRYPTO ],
                    libraries = [ 'TrezorCrypto', 'TrustWalletCore', 'protobuf' ],
                    extra_link_args = link_args,
                    sources = glob('src/*.cc'))

setup (name = 'walletcore',
       version = '1.0',
       description = 'Trust wallet core',
       ext_modules = [module])
