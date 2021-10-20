// This is a GENERATED FILE, changes made here WILL BE LOST.

#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWHRP.h>

struct PyHRPObject {
  PyObject_HEAD;
  const TWHRP value;
};

// Returns true if the object is a PyHRP.
bool PyHRP_Check(PyObject* object);

// Create PyHRP from an enum TWHRP value.
// Note: it returns the same PyHRP instance for the same enum TWHRP value.
// the caller should release the reference after using.
PyObject* PyHRP_FromTWHRP(TWHRP value);

// Initialize for PyHRP. It is called by python module init function.
bool PyInit_HRP(PyObject* module);