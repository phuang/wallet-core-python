// This is a GENERATED FILE, changes made here WILL BE LOST.

#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWStoredKey.h>

struct PyStoredKeyObject {
  PyObject_HEAD;
  TWStoredKey* value;
};

// Returns true if the object is a PyStoredKey.
bool PyStoredKey_Check(PyObject* object);

// Create PyStoredKey from an TWStoredKey.
PyObject* PyStoredKey_FromTWStoredKey(TWStoredKey* value);

// Initialize for PyStoredKey. It is called by python module init function.
bool PyInit_StoredKey(PyObject* module);