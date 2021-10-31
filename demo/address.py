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

import walletcore as core

def main():
    mnemonic = input('mnemonic:')
    passphrase = input('passphrase:')
    wallet = core.HDWallet.create_with_mnemonic(mnemonic, passphrase)
    if not wallet:
        print('Invalid mnemonic')
        return
    address = wallet.get_address_for_coin(core.CoinType.Bitcoin)
    print('BTC address="{}"'.format(address))
    address = wallet.get_address_for_coin(core.CoinType.Ethereum)
    print('ETH address="{}"'.format(address))

if __name__ == '__main__':
    main()