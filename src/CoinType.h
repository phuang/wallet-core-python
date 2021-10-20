// This is a GENERATED FILE, changes made here WILL BE LOST.

#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWCoinType.h>

struct PyCoinTypeObject {
  PyObject_HEAD;
  const TWCoinType value;
};

// Returns true if the object is a PyCoinType.
bool PyCoinType_Check(PyObject* object);

// Create PyCoinType from an enum TWCoinType value.
// Note: it returns the same PyCoinType instance for the same enum TWCoinType
// value. the caller should release the reference after using.
PyObject* PyCoinType_FromTWCoinType(TWCoinType value);

// Initialize for PyCoinType. It is called by python module init function.
bool PyInit_CoinType(PyObject* module);