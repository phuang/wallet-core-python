// This is a GENERATED FILE, changes made here WILL BE LOST.

#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWAESPaddingMode.h>

extern PyTypeObject PyAESPaddingModeType;

struct PyAESPaddingModeObject {
  PyObject_HEAD const TWAESPaddingMode value;
};

bool PyAESPaddingMode_Check(PyObject *object);

PyObject *PyAESPaddingMode_FromTWAESPaddingMode(TWAESPaddingMode value);

bool PyInit_AESPaddingMode(PyObject *module);