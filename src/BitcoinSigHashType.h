// This is a GENERATED FILE, changes made here WILL BE LOST.

#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWBitcoinSigHashType.h>

extern PyTypeObject PyBitcoinSigHashTypeType;

struct PyBitcoinSigHashTypeObject {
    PyObject_HEAD
    const TWBitcoinSigHashType value;
};

PyObject* PyBitcoinSigHashType_FromTWBitcoinSigHashType(TWBitcoinSigHashType value);

bool PyInit_BitcoinSigHashType(PyObject *module);