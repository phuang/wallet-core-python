// This is a GENERATED FILE, changes made here WILL BE LOST.

#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWCoinType.h>

extern PyTypeObject PyCoinTypeType;

struct PyCoinTypeObject {
  PyObject_HEAD const TWCoinType value;
};

bool PyCoinType_Check(PyObject *object);

PyObject *PyCoinType_FromTWCoinType(TWCoinType value);

bool PyInit_CoinType(PyObject *module);