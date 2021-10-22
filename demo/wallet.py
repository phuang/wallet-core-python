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

def create_wallet():
  print('=== creat wallet')
  wallet = core.HDWallet.create(128, 'aabbcc')
  mnemonic = wallet.mnemonic
  entropy = wallet.entropy
  print('mnemonic="{}"'.format(mnemonic))
  print('Entropy="{}" size={}'.format(entropy, len(entropy)))

  address = wallet.get_address_for_coin(core.CoinType.Bitcoin)
  print('BTC address="{}"'.format(address))

  address = wallet.get_address_for_coin(core.CoinType.Ethereum)
  print('ETH address="{}"'.format(address))

def mnemonic_demo():
  print('=== mnemonic demo')
  suggestion = core.Mnemonic.suggest('be')
  print('Mnemonic suggestion for "be": {}'.format(suggestion))


if __name__ == '__main__':
  create_wallet()
  mnemonic_demo()
