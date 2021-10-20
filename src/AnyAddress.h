// This is a GENERATED FILE, changes made here WILL BE LOST.

#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWAnyAddress.h>

struct PyAnyAddressObject {
  PyObject_HEAD;
  TWAnyAddress* value;
};

// Returns true if the object is a PyAnyAddress.
bool PyAnyAddress_Check(PyObject* object);

// Create PyAnyAddress from an TWAnyAddress.
PyObject* PyAnyAddress_FromTWAnyAddress(TWAnyAddress* value);

// Initialize for PyAnyAddress. It is called by python module init function.
bool PyInit_AnyAddress(PyObject* module);