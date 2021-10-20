// This is a GENERATED FILE, changes made here WILL BE LOST.

#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWEthereumAbiValue.h>

struct PyEthereumAbiValueObject {
  PyObject_HEAD;
  TWEthereumAbiValue* value;
};

// Returns true if the object is a PyEthereumAbiValue.
bool PyEthereumAbiValue_Check(PyObject* object);

// Create PyEthereumAbiValue from an TWEthereumAbiValue.
PyObject* PyEthereumAbiValue_FromTWEthereumAbiValue(TWEthereumAbiValue* value);

// Get enum TWEthereumAbiValue value from a PyEthereumAbiValue object.
TWEthereumAbiValue* PyEthereumAbiValue_GetTWEthereumAbiValue(PyObject* object);

// Initialize for PyEthereumAbiValue. It is called by python module init
// function.
bool PyInit_EthereumAbiValue(PyObject* module);