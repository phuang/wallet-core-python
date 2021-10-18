// This is a GENERATED FILE, changes made here WILL BE LOST.

#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWPublicKeyType.h>

struct PyPublicKeyTypeObject {
    PyObject_HEAD
    const TWPublicKeyType value;
};

PyObject* PyPublicKeyType_FromTWPublicKeyType(TWPublicKeyType value);
bool PyInit_PublicKeyType(PyObject *module);