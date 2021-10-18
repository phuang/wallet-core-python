// This is a GENERATED FILE, changes made here WILL BE LOST.

#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWStellarMemoType.h>

struct PyStellarMemoTypeObject {
    PyObject_HEAD
    const TWStellarMemoType value;
};

PyObject* PyStellarMemoType_FromTWStellarMemoType(TWStellarMemoType value);
bool PyInit_StellarMemoType(PyObject *module);