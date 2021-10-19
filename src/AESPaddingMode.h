// This is a GENERATED FILE, changes made here WILL BE LOST.

#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWAESPaddingMode.h>

struct PyAESPaddingModeObject {
  PyObject_HEAD const TWAESPaddingMode value;
};

// Returns true if the object is a PyAESPaddingMode.
bool PyAESPaddingMode_Check(PyObject* object);

// Create PyAESPaddingMode from an enum TWAESPaddingMode value.
// Note: it returns the same PyAESPaddingMode instance for the same enum
// TWAESPaddingMode value. the caller should release the reference after using.
PyObject* PyAESPaddingMode_FromTWAESPaddingMode(TWAESPaddingMode value);

// Initialize for PyAESPaddingMode. It is called by python module init function.
bool PyInit_AESPaddingMode(PyObject* module);