// This is a GENERATED FILE, changes made here WILL BE LOST.

#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWStellarVersionByte.h>

struct PyStellarVersionByteObject {
  PyObject_HEAD const TWStellarVersionByte value;
};

// Returns true if the object is a PyStellarVersionByte.
bool PyStellarVersionByte_Check(PyObject *object);

// Create PyStellarVersionByte from an enum TWStellarVersionByte value.
// Note: it returns the same PyStellarVersionByte instance for the same enum
// TWStellarVersionByte value. the caller should release the reference after
// using.
PyObject *
PyStellarVersionByte_FromTWStellarVersionByte(TWStellarVersionByte value);

bool PyInit_StellarVersionByte(PyObject *module);