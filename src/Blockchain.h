#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWBlockchain.h>

struct PyBlockchainObject {
    PyObject_HEAD
    const TWBlockchain value;
};

PyObject* PyBlockchain_FromTWBlockchain(TWBlockchain value);
bool PyInit_Blockchain(PyObject *module);