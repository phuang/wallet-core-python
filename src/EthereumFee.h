// This is a GENERATED FILE, changes made here WILL BE LOST.

#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWEthereumFee.h>

struct PyEthereumFeeObject {
  PyObject_HEAD;
  TWEthereumFee* value;
};

// Returns true if the object is a PyEthereumFee.
bool PyEthereumFee_Check(PyObject* object);

// Create PyEthereumFee from an TWEthereumFee.
PyObject* PyEthereumFee_FromTWEthereumFee(TWEthereumFee* value);

// Initialize for PyEthereumFee. It is called by python module init function.
bool PyInit_EthereumFee(PyObject* module);