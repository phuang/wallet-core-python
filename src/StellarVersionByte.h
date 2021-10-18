// This is a GENERATED FILE, changes made here WILL BE LOST.

#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWStellarVersionByte.h>

extern PyTypeObject PyStellarVersionByteType;

struct PyStellarVersionByteObject {
    PyObject_HEAD
    const TWStellarVersionByte value;
};

PyObject* PyStellarVersionByte_FromTWStellarVersionByte(TWStellarVersionByte value);

bool PyInit_StellarVersionByte(PyObject *module);