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

typedef bool (*InitProc)(PyObject* module);
const InitProc init_functions[]= {
    AESPaddingMode_enum_init,
    BitcoinSigHashType_enum_init,
    Blockchain_enum_init,
    CoinType_enum_init,
    Curve_enum_init,
    EthereumChainID_enum_init,
    HDVersion_enum_init,
    HRP_enum_init,
    PublicKeyType_enum_init,
    Purpose_enum_init,
    SS58AddressType_enum_init,
    StellarMemoType_enum_init,
    StellarPassphrase_enum_init,
    StellarVersionByte_enum_init,
};

PyMODINIT_FUNC
PyInit_walletcore(void) {
    static struct PyModuleDef enum_module_def = {
        PyModuleDef_HEAD_INIT,
        "walletcore",   /* name of module */
        nullptr,        /* module documentation, may be NULL */
        -1,             /* size of per-interpreter state of the module,
                           or -1 if the module keeps state in global variables. */
        nullptr
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