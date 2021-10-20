// This is a GENERATED FILE, changes made here WILL BE LOST.

#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWEthereumAbi.h>

struct PyEthereumAbiObject {
  PyObject_HEAD;
  TWEthereumAbi* value;
};

// Returns true if the object is a PyEthereumAbi.
bool PyEthereumAbi_Check(PyObject* object);

// Create PyEthereumAbi from an TWEthereumAbi.
PyObject* PyEthereumAbi_FromTWEthereumAbi(TWEthereumAbi* value);

// Initialize for PyEthereumAbi. It is called by python module init function.
bool PyInit_EthereumAbi(PyObject* module);