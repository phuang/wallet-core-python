// This is a GENERATED FILE, changes made here WILL BE LOST.

#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWPublicKeyType.h>

struct PyPublicKeyTypeObject {
  PyObject_HEAD;
  const TWPublicKeyType value;
};

// Returns true if the object is a PyPublicKeyType.
bool PyPublicKeyType_Check(PyObject* object);

// Create PyPublicKeyType from an enum TWPublicKeyType value.
// Note: it returns the same PyPublicKeyType instance for the same enum
// TWPublicKeyType value. the caller should release the reference after using.
PyObject* PyPublicKeyType_FromTWPublicKeyType(TWPublicKeyType value);

// Initialize for PyPublicKeyType. It is called by python module init function.
bool PyInit_PublicKeyType(PyObject* module);