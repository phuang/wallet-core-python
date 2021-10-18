#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TW${name}.h>

struct ${name}Object {
    PyObject_HEAD
    TW${name} value;
};

bool ${name}_enum_init(PyObject *module);