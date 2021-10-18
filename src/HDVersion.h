// This is a GENERATED FILE, changes made here WILL BE LOST.

#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWHDVersion.h>

struct PyHDVersionObject {
    PyObject_HEAD
    const TWHDVersion value;
};

PyObject* PyHDVersion_FromTWHDVersion(TWHDVersion value);
bool PyInit_HDVersion(PyObject *module);