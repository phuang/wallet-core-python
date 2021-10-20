// This is a GENERATED FILE, changes made here WILL BE LOST.

#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWPrivateKey.h>

struct PyPrivateKeyObject {
  PyObject_HEAD;
  TWPrivateKey* value;
};

// Returns true if the object is a PyPrivateKey.
bool PyPrivateKey_Check(PyObject* object);

// Create PyPrivateKey from an TWPrivateKey.
PyObject* PyPrivateKey_FromTWPrivateKey(TWPrivateKey* value);

// Get enum TWPrivateKey value from a PyPrivateKey object.
TWPrivateKey* PyPrivateKey_GetTWPrivateKey(PyObject* object);

// Initialize for PyPrivateKey. It is called by python module init function.
bool PyInit_PrivateKey(PyObject* module);