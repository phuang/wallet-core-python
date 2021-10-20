// This is a GENERATED FILE, changes made here WILL BE LOST.

#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWSegwitAddress.h>

struct PySegwitAddressObject {
  PyObject_HEAD;
  TWSegwitAddress* value;
};

// Returns true if the object is a PySegwitAddress.
bool PySegwitAddress_Check(PyObject* object);

// Create PySegwitAddress from an TWSegwitAddress.
PyObject* PySegwitAddress_FromTWSegwitAddress(TWSegwitAddress* value);

// Initialize for PySegwitAddress. It is called by python module init function.
bool PyInit_SegwitAddress(PyObject* module);