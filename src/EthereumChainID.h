// This is a GENERATED FILE, changes made here WILL BE LOST.

#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWEthereumChainID.h>

struct PyEthereumChainIDObject {
  PyObject_HEAD const TWEthereumChainID value;
};

// Returns true if the object is a PyEthereumChainID.
bool PyEthereumChainID_Check(PyObject* object);

// Create PyEthereumChainID from an enum TWEthereumChainID value.
// Note: it returns the same PyEthereumChainID instance for the same enum
// TWEthereumChainID value. the caller should release the reference after using.
PyObject* PyEthereumChainID_FromTWEthereumChainID(TWEthereumChainID value);

// Initialize for PyEthereumChainID. It is called by python module init
// function.
bool PyInit_EthereumChainID(PyObject* module);