// This is a GENERATED FILE, changes made here WILL BE LOST.

#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWEthereumChainID.h>

extern PyTypeObject PyEthereumChainIDType;

struct PyEthereumChainIDObject {
    PyObject_HEAD
    const TWEthereumChainID value;
};

PyObject* PyEthereumChainID_FromTWEthereumChainID(TWEthereumChainID value);

bool PyInit_EthereumChainID(PyObject *module);