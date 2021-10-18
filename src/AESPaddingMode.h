// This is a GENERATED FILE, changes made here WILL BE LOST.

#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWAESPaddingMode.h>

struct PyAESPaddingModeObject {
    PyObject_HEAD
    const TWAESPaddingMode value;
};

PyObject* PyAESPaddingMode_FromTWAESPaddingMode(TWAESPaddingMode value);
bool PyInit_AESPaddingMode(PyObject *module);