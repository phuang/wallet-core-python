// This is a GENERATED FILE, changes made here WILL BE LOST.

#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWHDVersion.h>

extern PyTypeObject PyHDVersionType;

struct PyHDVersionObject {
  PyObject_HEAD const TWHDVersion value;
};

bool PyHDVersion_Check(PyObject *object);

PyObject *PyHDVersion_FromTWHDVersion(TWHDVersion value);

bool PyInit_HDVersion(PyObject *module);