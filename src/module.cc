// This is a GENERATED FILE, changes made here WILL BE LOST.

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include "AESPaddingMode.h"
#include "BitcoinSigHashType.h"
#include "Blockchain.h"
#include "CoinType.h"
#include "Curve.h"
#include "EthereumChainID.h"
#include "HDVersion.h"
#include "HRP.h"
#include "PublicKeyType.h"
#include "Purpose.h"
#include "SS58AddressType.h"
#include "StellarMemoType.h"
#include "StellarPassphrase.h"
#include "StellarVersionByte.h"

typedef bool (*InitProc)(PyObject *module);
const InitProc init_functions[] = {
    PyInit_AESPaddingMode,
    PyInit_BitcoinSigHashType,
    PyInit_Blockchain,
    PyInit_CoinType,
    PyInit_Curve,
    PyInit_EthereumChainID,
    PyInit_HDVersion,
    PyInit_HRP,
    PyInit_PublicKeyType,
    PyInit_Purpose,
    PyInit_SS58AddressType,
    PyInit_StellarMemoType,
    PyInit_StellarPassphrase,
    PyInit_StellarVersionByte,
};

PyMODINIT_FUNC PyInit_walletcore(void) {
  static struct PyModuleDef enum_module_def = {
      PyModuleDef_HEAD_INIT, "walletcore", /* m_name */
      nullptr,                             /* m_doc */
      -1,                                  /* m_size */
      nullptr                              /* m_methods */
  };

  PyObject *module = PyModule_Create(&enum_module_def);
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