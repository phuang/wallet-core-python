// This is a GENERATED FILE, changes made here WILL BE LOST.

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include "AES.h"
#include "AESPaddingMode.h"
#include "Account.h"
#include "AnyAddress.h"
#include "Base58.h"
#include "BitcoinAddress.h"
#include "BitcoinScript.h"
#include "BitcoinSigHashType.h"
#include "Blockchain.h"
#include "CoinType.h"
#include "CoinTypeConfiguration.h"
#include "Curve.h"
#include "EthereumAbi.h"
#include "EthereumAbiFunction.h"
#include "EthereumAbiValue.h"
#include "EthereumChainID.h"
#include "EthereumFee.h"
#include "FIOAccount.h"
#include "GroestlcoinAddress.h"
#include "HDVersion.h"
#include "HDWallet.h"
#include "HRP.h"
#include "Hash.h"
#include "Mnemonic.h"
#include "NEARAccount.h"
#include "PrivateKey.h"
#include "PublicKey.h"
#include "PublicKeyType.h"
#include "Purpose.h"
#include "RippleXAddress.h"
#include "SS58AddressType.h"
#include "SegwitAddress.h"
#include "SolanaAddress.h"
#include "StellarMemoType.h"
#include "StellarPassphrase.h"
#include "StellarVersionByte.h"
#include "StoredKey.h"

typedef bool (*InitProc)(PyObject* module);
const InitProc init_functions[] = {
    PyInit_AES,
    PyInit_AESPaddingMode,
    PyInit_Account,
    PyInit_AnyAddress,
    PyInit_Base58,
    PyInit_BitcoinAddress,
    PyInit_BitcoinScript,
    PyInit_BitcoinSigHashType,
    PyInit_Blockchain,
    PyInit_CoinType,
    PyInit_CoinTypeConfiguration,
    PyInit_Curve,
    PyInit_EthereumAbi,
    PyInit_EthereumAbiFunction,
    PyInit_EthereumAbiValue,
    PyInit_EthereumChainID,
    PyInit_EthereumFee,
    PyInit_FIOAccount,
    PyInit_GroestlcoinAddress,
    PyInit_HDVersion,
    PyInit_HDWallet,
    PyInit_HRP,
    PyInit_Hash,
    PyInit_Mnemonic,
    PyInit_NEARAccount,
    PyInit_PrivateKey,
    PyInit_PublicKey,
    PyInit_PublicKeyType,
    PyInit_Purpose,
    PyInit_RippleXAddress,
    PyInit_SS58AddressType,
    PyInit_SegwitAddress,
    PyInit_SolanaAddress,
    PyInit_StellarMemoType,
    PyInit_StellarPassphrase,
    PyInit_StellarVersionByte,
    PyInit_StoredKey,
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