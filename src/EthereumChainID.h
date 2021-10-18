#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWEthereumChainID.h>

struct PyEthereumChainIDObject {
    PyObject_HEAD
    const TWEthereumChainID value;
};

PyObject* PyEthereumChainID_FromTWEthereumChainID(TWEthereumChainID value);
bool PyInit_EthereumChainID(PyObject *module);