// This is a GENERATED FILE, changes made here WILL BE LOST.

#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TW${name}.h>

struct Py${name}Object {
  PyObject_HEAD
  const TW${name} value;
};

// Returns true if the object is a Py${name}.
bool Py${name}_Check(PyObject* object);

// Create Py${name} from an enum TW${name} value.
// Note: it returns the same Py${name} instance for the same enum TW${name} value.
// the caller should release the reference after using.
PyObject* Py${name}_FromTW${name}(TW${name} value);

bool PyInit_${name}(PyObject *module);