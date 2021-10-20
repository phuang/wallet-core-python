// This is a GENERATED FILE, changes made here WILL BE LOST.

#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWRippleXAddress.h>

struct PyRippleXAddressObject {
  PyObject_HEAD;
  TWRippleXAddress* value;
};

// Returns true if the object is a PyRippleXAddress.
bool PyRippleXAddress_Check(PyObject* object);

// Create PyRippleXAddress from an TWRippleXAddress.
PyObject* PyRippleXAddress_FromTWRippleXAddress(TWRippleXAddress* value);

// Get enum TWRippleXAddress value from a PyRippleXAddress object.
TWRippleXAddress* PyRippleXAddress_GetTWRippleXAddress(PyObject* object);

// Initialize for PyRippleXAddress. It is called by python module init function.
bool PyInit_RippleXAddress(PyObject* module);