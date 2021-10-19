// This is a GENERATED FILE, changes made here WILL BE LOST.

#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TW${name}.h>

extern PyTypeObject Py${name}Type;

struct Py${name}Object {
    PyObject_HEAD
    const TW${name} value;
};

bool Py${name}_Check(PyObject* object);

PyObject* Py${name}_FromTW${name}(TW${name} value);

bool PyInit_${name}(PyObject *module);