// This is a GENERATED FILE, changes made here WILL BE LOST.

#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWSS58AddressType.h>

extern PyTypeObject PySS58AddressTypeType;

struct PySS58AddressTypeObject {
  PyObject_HEAD const TWSS58AddressType value;
};

bool PySS58AddressType_Check(PyObject *object);

PyObject *PySS58AddressType_FromTWSS58AddressType(TWSS58AddressType value);

bool PyInit_SS58AddressType(PyObject *module);