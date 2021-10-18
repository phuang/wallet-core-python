#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TW${name}.h>

struct Py${name}Object {
    PyObject_HEAD
    TW${name} value;
};

bool PyInit_${name}(PyObject *module);