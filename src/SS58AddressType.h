#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWSS58AddressType.h>

struct PySS58AddressTypeObject {
    PyObject_HEAD
    const TWSS58AddressType value;
};

PyObject* PySS58AddressType_FromTWSS58AddressType(TWSS58AddressType value);
bool PyInit_SS58AddressType(PyObject *module);