#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWCoinType.h>

struct PyCoinTypeObject {
    PyObject_HEAD
    const TWCoinType value;
};

PyObject* PyCoinType_FromTWCoinType(TWCoinType value);
bool PyInit_CoinType(PyObject *module);