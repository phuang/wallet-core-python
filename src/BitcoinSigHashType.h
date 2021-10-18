#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWBitcoinSigHashType.h>

struct PyBitcoinSigHashTypeObject {
    PyObject_HEAD
    const TWBitcoinSigHashType value;
};

PyObject* PyBitcoinSigHashType_FromTWBitcoinSigHashType(TWBitcoinSigHashType value);
bool PyInit_BitcoinSigHashType(PyObject *module);