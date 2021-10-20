#!/usr/bin/env python3
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

import walletcore as core

wallet_a = core.HDWallet.Create(128, 'aabbcc')
mnemonic = wallet_a.Mnemonic
address = wallet_a.GetAddressForCoin(core.CoinType.Bitcoin)
print('mnemonic="{}"'.format(mnemonic))
print('BTC address="{}"'.format(address))

wallet_b = core.HDWallet.CreateWithMnemonic(mnemonic, '')
print(wallet_b)
address = wallet_a.GetAddressForCoin(core.CoinType.Bitcoin)
print('BTC address="{}"'.format(address))

print('Mnemonic suggest for "be":{}'.format(core.Mnemonic.Suggest('be')))