// This is a GENERATED FILE, changes made here WILL BE LOST.

#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWHash.h>

struct PyHashObject {
  PyObject_HEAD;
  TWHash* value;
};

// Returns true if the object is a PyHash.
bool PyHash_Check(PyObject* object);

// Create PyHash from an TWHash.
PyObject* PyHash_FromTWHash(TWHash* value);

// Get enum TWHash value from a PyHash object.
TWHash* PyHash_GetTWHash(PyObject* object);

// Initialize for PyHash. It is called by python module init function.
bool PyInit_Hash(PyObject* module);