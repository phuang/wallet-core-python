// This is a GENERATED FILE, changes made here WILL BE LOST.

#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWEthereumAbiFunction.h>

struct PyEthereumAbiFunctionObject {
  PyObject_HEAD;
  TWEthereumAbiFunction* value;
};

// Returns true if the object is a PyEthereumAbiFunction.
bool PyEthereumAbiFunction_Check(PyObject* object);

// Create PyEthereumAbiFunction from an TWEthereumAbiFunction.
PyObject* PyEthereumAbiFunction_FromTWEthereumAbiFunction(
    TWEthereumAbiFunction* value);

// Get enum TWEthereumAbiFunction value from a PyEthereumAbiFunction object.
TWEthereumAbiFunction* PyEthereumAbiFunction_GetTWEthereumAbiFunction(
    PyObject* object);

// Initialize for PyEthereumAbiFunction. It is called by python module init
// function.
bool PyInit_EthereumAbiFunction(PyObject* module);