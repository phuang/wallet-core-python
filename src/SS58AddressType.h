// This is a GENERATED FILE, changes made here WILL BE LOST.

#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWSS58AddressType.h>

struct PySS58AddressTypeObject {
  PyObject_HEAD const TWSS58AddressType value;
};

// Returns true if the object is a PySS58AddressType.
bool PySS58AddressType_Check(PyObject *object);

// Create PySS58AddressType from an enum TWSS58AddressType value.
// Note: it returns the same PySS58AddressType instance for the same enum
// TWSS58AddressType value. the caller should release the reference after using.
PyObject *PySS58AddressType_FromTWSS58AddressType(TWSS58AddressType value);

bool PyInit_SS58AddressType(PyObject *module);