// This is a GENERATED FILE, changes made here WILL BE LOST.

#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWHDWallet.h>

struct PyHDWalletObject {
  PyObject_HEAD;
  TWHDWallet* value;
};

// Returns true if the object is a PyHDWallet.
bool PyHDWallet_Check(PyObject* object);

// Create PyHDWallet from an TWHDWallet.
PyObject* PyHDWallet_FromTWHDWallet(TWHDWallet* value);

// Get enum TWHDWallet value from a PyHDWallet object.
TWHDWallet* PyHDWallet_GetTWHDWallet(PyObject* object);

// Initialize for PyHDWallet. It is called by python module init function.
bool PyInit_HDWallet(PyObject* module);