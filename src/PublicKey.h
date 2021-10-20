// This is a GENERATED FILE, changes made here WILL BE LOST.

#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWPublicKey.h>

struct PyPublicKeyObject {
  PyObject_HEAD;
  TWPublicKey* value;
};

// Returns true if the object is a PyPublicKey.
bool PyPublicKey_Check(PyObject* object);

// Create PyPublicKey from an TWPublicKey.
PyObject* PyPublicKey_FromTWPublicKey(TWPublicKey* value);

// Get enum TWPublicKey value from a PyPublicKey object.
TWPublicKey* PyPublicKey_GetTWPublicKey(PyObject* object);

// Initialize for PyPublicKey. It is called by python module init function.
bool PyInit_PublicKey(PyObject* module);