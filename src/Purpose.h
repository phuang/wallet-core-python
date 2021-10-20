// This is a GENERATED FILE, changes made here WILL BE LOST.

#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWPurpose.h>

struct PyPurposeObject {
  PyObject_HEAD;
  const TWPurpose value;
};

// Returns true if the object is a PyPurpose.
bool PyPurpose_Check(PyObject* object);

// Create PyPurpose from an enum TWPurpose value.
// Note: it returns the same PyPurpose instance for the same enum TWPurpose
// value. the caller should release the reference after using.
PyObject* PyPurpose_FromTWPurpose(TWPurpose value);

// Initialize for PyPurpose. It is called by python module init function.
bool PyInit_Purpose(PyObject* module);