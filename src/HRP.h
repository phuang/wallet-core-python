// This is a GENERATED FILE, changes made here WILL BE LOST.

#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWHRP.h>

extern PyTypeObject PyHRPType;

struct PyHRPObject {
    PyObject_HEAD
    const TWHRP value;
};

PyObject* PyHRP_FromTWHRP(TWHRP value);

bool PyInit_HRP(PyObject *module);