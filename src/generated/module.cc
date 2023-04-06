// Copyright 2021 Peng Huang <shawn.p.huang@gmail.com>
// This file is part of Wallet-core-python.
//
// Wallet-core-python is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Wallet-core-python is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Wallet-core-python.  If not, see <https://www.gnu.org/licenses/>.
//
// NOTE: this is a GENERATED FILE, changes made here WILL BE LOST.

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include "AnySigner.h"
#include "generated/AES.h"
#include "generated/AESPaddingMode.h"
#include "generated/Account.h"
#include "generated/AnyAddress.h"
#include "generated/Base32.h"
#include "generated/Base58.h"
#include "generated/Base64.h"
#include "generated/BitcoinAddress.h"
#include "generated/BitcoinMessageSigner.h"
#include "generated/BitcoinScript.h"
#include "generated/BitcoinSigHashType.h"
#include "generated/Blockchain.h"
#include "generated/Cardano.h"
#include "generated/CoinType.h"
#include "generated/CoinTypeConfiguration.h"
#include "generated/Curve.h"
#include "generated/DataVector.h"
#include "generated/DerivationPath.h"
#include "generated/DerivationPathIndex.h"
#include "generated/Ethereum.h"
#include "generated/EthereumAbi.h"
#include "generated/EthereumAbiFunction.h"
#include "generated/EthereumAbiValue.h"
#include "generated/EthereumMessageSigner.h"
#include "generated/FIOAccount.h"
#include "generated/FilecoinAddressConverter.h"
#include "generated/FilecoinAddressType.h"
#include "generated/GroestlcoinAddress.h"
#include "generated/HDVersion.h"
#include "generated/HDWallet.h"
#include "generated/Hash.h"
#include "generated/Mnemonic.h"
#include "generated/NEARAccount.h"
#include "generated/NervosAddress.h"
#include "generated/PBKDF2.h"
#include "generated/PrivateKey.h"
#include "generated/PrivateKeyType.h"
#include "generated/PublicKey.h"
#include "generated/PublicKeyType.h"
#include "generated/Purpose.h"
#include "generated/RippleXAddress.h"
#include "generated/SS58AddressType.h"
#include "generated/SegwitAddress.h"
#include "generated/SolanaAddress.h"
#include "generated/StarkExMessageSigner.h"
#include "generated/StarkWare.h"
#include "generated/StellarMemoType.h"
#include "generated/StellarPassphrase.h"
#include "generated/StellarVersionByte.h"
#include "generated/StoredKey.h"
#include "generated/StoredKeyEncryption.h"
#include "generated/StoredKeyEncryptionLevel.h"
#include "generated/THORChainSwap.h"
#include "generated/TezosMessageSigner.h"
#include "generated/TransactionCompiler.h"
#include "generated/TronMessageSigner.h"

typedef bool (*InitProc)(PyObject* module);
const InitProc init_functions[] = {
    // clang-format off
    PyInit_AES,
    PyInit_AESPaddingMode,
    PyInit_Account,
    PyInit_AnyAddress,
    PyInit_AnySigner,
    PyInit_Base32,
    PyInit_Base58,
    PyInit_Base64,
    PyInit_BitcoinAddress,
    PyInit_BitcoinMessageSigner,
    PyInit_BitcoinScript,
    PyInit_BitcoinSigHashType,
    PyInit_Blockchain,
    PyInit_Cardano,
    PyInit_CoinType,
    PyInit_CoinTypeConfiguration,
    PyInit_Curve,
    PyInit_DataVector,
    PyInit_DerivationPath,
    PyInit_DerivationPathIndex,
    PyInit_Ethereum,
    PyInit_EthereumAbi,
    PyInit_EthereumAbiFunction,
    PyInit_EthereumAbiValue,
    PyInit_EthereumMessageSigner,
    PyInit_FIOAccount,
    PyInit_FilecoinAddressConverter,
    PyInit_FilecoinAddressType,
    PyInit_GroestlcoinAddress,
    PyInit_HDVersion,
    PyInit_HDWallet,
    PyInit_Hash,
    PyInit_Mnemonic,
    PyInit_NEARAccount,
    PyInit_NervosAddress,
    PyInit_PBKDF2,
    PyInit_PrivateKey,
    PyInit_PrivateKeyType,
    PyInit_PublicKey,
    PyInit_PublicKeyType,
    PyInit_Purpose,
    PyInit_RippleXAddress,
    PyInit_SS58AddressType,
    PyInit_SegwitAddress,
    PyInit_SolanaAddress,
    PyInit_StarkExMessageSigner,
    PyInit_StarkWare,
    PyInit_StellarMemoType,
    PyInit_StellarPassphrase,
    PyInit_StellarVersionByte,
    PyInit_StoredKey,
    PyInit_StoredKeyEncryption,
    PyInit_StoredKeyEncryptionLevel,
    PyInit_THORChainSwap,
    PyInit_TezosMessageSigner,
    PyInit_TransactionCompiler,
    PyInit_TronMessageSigner,
    // clang-format on
};

PyMODINIT_FUNC PyInit_walletcore(void) {
  static struct PyModuleDef enum_module_def = {
      PyModuleDef_HEAD_INIT, "walletcore", /* m_name */
      nullptr,                             /* m_doc */
      -1,                                  /* m_size */
      nullptr                              /* m_methods */
  };

  PyObject* module = PyModule_Create(&enum_module_def);
  if (module == nullptr) {
    return nullptr;
  }

  for (const auto func : init_functions) {
    if (!func(module)) {
      Py_DECREF(module);
      return nullptr;
    }
  }

  return module;
}