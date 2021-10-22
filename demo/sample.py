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
  wallet = core.HDWallet.create(128, '')
  print('Done.')
  print('Secret mnemonic for new wallet:')
  print(wallet.mnemonic)

  # Alternative: Import wallet with existing recovery phrase (mnemonic)
  print('Importing an HD wallet from earlier ... ')
  secret_mnemonic = 'ripple scissors kick mammal hire column oak again sun offer wealth tomorrow wagon turn fatal'
  wallet = core.HDWallet.create_with_mnemonic(secret_mnemonic, '')
  print('Done.')
  print('Secret mnemonic for new wallet:')
  print(wallet.mnemonic)

  # coin type: we use Ethereum
  coin_type = core.CoinType.Ethereum
  print('Working with coin: {} {}'.format(
    core.CoinTypeConfiguration.get_name(coin_type),
    core.CoinTypeConfiguration.get_symbol(coin_type)))

  # Derive default address.
  print('Obtaining default address ... ')
  address = wallet.get_address_for_coin(coin_type)
  print('Default address: "{}"'.format(address))


  # Alternative: Derive address using default derivation path.
  # Done in 2 steps: derive private key, then address from private key.
  # Note that private key is passed around between the two calls by the wallet -- be always cautious when handling secrets, avoid the risk of leaking secrets.
  print('Default derivation path:  ' + coin_type.derivation_path())
  secret_private_key_default = wallet.get_key_for_coin(coin_type)
  address_default = coin_type.derive_address(secret_private_key_default)
  print('Address from default key: ' + address_default)

  # Alternative: Derive address using custom derivation path.
  # Done in 2 steps: derive private key, then address.
  custom_derivation_path = "m/44'/60'/1'/0/0"
  secret_private_key_custom = wallet.get_key(coin_type, custom_derivation_path)
  address_custom = coin_type.derive_address(secret_private_key_custom)
  print('custom address for derivation path {}: "{}"'.format(custom_derivation_path, address_custom))

  # Steps for sending:
  # 1. put together a send message (contains sender and receiver address, amount, gas price, etc.)
  # 2. sign this message
  # 3. broadcast this message to the P2P network -- not done in this sample
  # Note that Signer input and output are represented as protobuf binary messages, for which support is missing in C++.
  # Therefore some direct serialization/parsing is done in helper methods.
  print('SEND funds:')
  dummy_receiver_address = '0xC37054b3b48C3317082E7ba872d7753D13da4986'
  secret_priv_key = secret_private_key_default.data

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
}}'''.format(chainIdB64, gasPriceB64, gasLimitB64, dummy_receiver_address, amountB64)

  print('transaction: ' + transaction)

  print('signing transaction ... ')

  json = transaction
  signed_transaction = core.AnySigner.sign_json(json, secret_priv_key, coin_type)

  print('done')
  print('Signed transaction data (to be broadcast to network):  (len {}) "{}"'.format(
    len(signed_transaction), signed_transaction))
  # see e.g. https://github.com/flightwallet/decode-eth-tx for checking binary output content

if __name__ == '__main__':
  main()
