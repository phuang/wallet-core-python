// This is a GENERATED FILE, changes made here WILL BE LOST.

#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWHDVersion.h>

struct PyHDVersionObject {
  PyObject_HEAD const TWHDVersion value;
};

// Returns true if the object is a PyHDVersion.
bool PyHDVersion_Check(PyObject *object);

// Create PyHDVersion from an enum TWHDVersion value.
// Note: it returns the same PyHDVersion instance for the same enum TWHDVersion
// value. the caller should release the reference after using.
PyObject *PyHDVersion_FromTWHDVersion(TWHDVersion value);

bool PyInit_HDVersion(PyObject *module);