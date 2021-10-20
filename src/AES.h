// This is a GENERATED FILE, changes made here WILL BE LOST.

#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWAES.h>

struct PyAESObject {
  PyObject_HEAD;
  TWAES* value;
};

// Returns true if the object is a PyAES.
bool PyAES_Check(PyObject* object);

// Create PyAES from an TWAES.
PyObject* PyAES_FromTWAES(TWAES* value);

// Get enum TWAES value from a PyAES object.
TWAES* PyAES_GetTWAES(PyObject* object);

// Initialize for PyAES. It is called by python module init function.
bool PyInit_AES(PyObject* module);