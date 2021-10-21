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
import base64

def main():
  print('''
  Wallet Core Demo, python

  *** DISCLAIMER ***
  THIS IS A SAMPLE APPLICATION WITH DEMONSTRATION PURPOSES ONLY.
  DO NOT USE WITH REAL SECRETS, REAL ADDRESSESS, OR REAL TRANSACTIONS.  USE IT AT YOUR OWN RISK.
  *** DISCLAIMER ***
''')

  # Create a new multi-coin HD wallet, with new recovery phrase (mnemonic)
  print('Creating a new HD wallet ... ')
  wallet = core.HDWallet.Create(128, '')
  print('Done.')
  print('Secret mnemonic for new wallet:')
  print(wallet.Mnemonic)

  # Alternative: Import wallet with existing recovery phrase (mnemonic)
  print('Importing an HD wallet from earlier ... ')
  secretMnemonic = 'ripple scissors kick mammal hire column oak again sun offer wealth tomorrow wagon turn fatal'
  wallet = core.HDWallet.CreateWithMnemonic(secretMnemonic, '')
  print('Done.')
  print('Secret mnemonic for new wallet:')
  print(wallet.Mnemonic)

  # coin type: we use Ethereum
  coinType = core.CoinType.Ethereum
  print('Working with coin: {} {}'.format(
    core.CoinTypeConfiguration.GetName(coinType),
    core.CoinTypeConfiguration.GetSymbol(coinType)))

  # Derive default address.
  print('Obtaining default address ... ')
  address = wallet.GetAddressForCoin(coinType)
  print('Default address: "{}"'.format(address))


  # Alternative: Derive address using default derivation path.
  # Done in 2 steps: derive private key, then address from private key.
  # Note that private key is passed around between the two calls by the wallet -- be always cautious when handling secrets, avoid the risk of leaking secrets.
  print('Default derivation path:  ' + coinType.DerivationPath())
  secretPrivateKeyDefault = wallet.GetKeyForCoin(coinType)
  addressDefault = coinType.DeriveAddress(secretPrivateKeyDefault)
  print('Address from default key: ' + addressDefault)

  # Alternative: Derive address using custom derivation path.
  # Done in 2 steps: derive private key, then address.
  customDerivationPath = "m/44'/60'/1'/0/0"
  secretPrivateKeyCustom = wallet.GetKey(coinType, customDerivationPath)
  addressCustom = coinType.DeriveAddress(secretPrivateKeyCustom)
  print('custom address for derivation path {}: "{}"'.format(customDerivationPath, addressCustom))

  # Steps for sending:
  # 1. put together a send message (contains sender and receiver address, amount, gas price, etc.)
  # 2. sign this message
  # 3. broadcast this message to the P2P network -- not done in this sample
  # Note that Signer input and output are represented as protobuf binary messages, for which support is missing in C++.
  # Therefore some direct serialization/parsing is done in helper methods.
  print('SEND funds:')
  dummyReceiverAddress = '0xC37054b3b48C3317082E7ba872d7753D13da4986'
  secretPrivKey = secretPrivateKeyDefault.Data

  print('preparing transaction (using AnySigner) ... ')
  chainIdB64 = 'AQ=='        # base64(parse_hex("01"))
  gasPriceB64 = '1pOkAA=='   # base64(parse_hex("d693a4")) decimal 3600000000
  gasLimitB64 = 'Ugg='       # base64(parse_hex("5208")) decimal 21000
  amountB64 = 'A0i8paFgAA==' # base64(parse_hex("0348bca5a160"))  924400000000000
  transaction = '''
{{
   "chainId": "{}",
   "gasPrice":"{}",
   "gasLimit":"{}",
   "toAddress":"{}",
   "transaction":{{
     "transfer":{{
       "amount":"{}"
     }}
   }}
}}'''.format(chainIdB64, gasPriceB64, gasLimitB64, dummyReceiverAddress, amountB64)

  print('transaction: ' + transaction)

  print('signing transaction ... ')

  json = transaction
  signedTransaction = core.AnySigner.SignJSON(json, secretPrivKey, coinType)

  print('done')
  print('Signed transaction data (to be broadcast to network):  (len {}) "{}"'.format(
    len(signedTransaction), signedTransaction))
  # see e.g. https://github.com/flightwallet/decode-eth-tx for checking binary output content

if __name__ == '__main__':
  main()
