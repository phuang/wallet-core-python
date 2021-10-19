// This is a GENERATED FILE, changes made here WILL BE LOST.

#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWStellarMemoType.h>

extern PyTypeObject PyStellarMemoTypeType;

struct PyStellarMemoTypeObject {
  PyObject_HEAD const TWStellarMemoType value;
};

bool PyStellarMemoType_Check(PyObject *object);

PyObject *PyStellarMemoType_FromTWStellarMemoType(TWStellarMemoType value);

bool PyInit_StellarMemoType(PyObject *module);