// This is a GENERATED FILE, changes made here WILL BE LOST.

#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWBase58.h>

struct PyBase58Object {
  PyObject_HEAD;
  TWBase58* value;
};

// Returns true if the object is a PyBase58.
bool PyBase58_Check(PyObject* object);

// Create PyBase58 from an TWBase58.
PyObject* PyBase58_FromTWBase58(TWBase58* value);

// Get enum TWBase58 value from a PyBase58 object.
TWBase58* PyBase58_GetTWBase58(PyObject* object);

// Initialize for PyBase58. It is called by python module init function.
bool PyInit_Base58(PyObject* module);