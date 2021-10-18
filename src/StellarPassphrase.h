#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWStellarPassphrase.h>

struct PyStellarPassphraseObject {
    PyObject_HEAD
    const TWStellarPassphrase value;
};

PyObject* PyStellarPassphrase_FromTWStellarPassphrase(TWStellarPassphrase value);
bool PyInit_StellarPassphrase(PyObject *module);