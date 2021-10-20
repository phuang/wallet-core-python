// This is a GENERATED FILE, changes made here WILL BE LOST.

#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TW${name}.h>

struct Py${name}Object {
  PyObject_HEAD;
  TW${name}* value;
};

// Returns true if the object is a Py${name}.
bool Py${name}_Check(PyObject* object);

// Create Py${name} from an TW${name}.
PyObject* Py${name}_FromTW${name}(TW${name}* value);

// Initialize for Py${name}. It is called by python module init function.
bool PyInit_${name}(PyObject *module);