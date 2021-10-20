// This is a GENERATED FILE, changes made here WILL BE LOST.

#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWStellarMemoType.h>

struct PyStellarMemoTypeObject {
  PyObject_HEAD;
  const TWStellarMemoType value;
};

// Returns true if the object is a PyStellarMemoType.
bool PyStellarMemoType_Check(PyObject* object);

// Create PyStellarMemoType from an enum TWStellarMemoType value.
// Note: it returns the same PyStellarMemoType instance for the same enum
// TWStellarMemoType value. the caller should release the reference after using.
PyObject* PyStellarMemoType_FromTWStellarMemoType(TWStellarMemoType value);

// Get enum TWStellarMemoType value from a PyStellarMemoType object.
TWStellarMemoType PyStellarMemoType_GetTWStellarMemoType(PyObject* object);

// Initialize for PyStellarMemoType. It is called by python module init
// function.
bool PyInit_StellarMemoType(PyObject* module);