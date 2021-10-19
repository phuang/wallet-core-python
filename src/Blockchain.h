// This is a GENERATED FILE, changes made here WILL BE LOST.

#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWBlockchain.h>

extern PyTypeObject PyBlockchainType;

struct PyBlockchainObject {
  PyObject_HEAD const TWBlockchain value;
};

bool PyBlockchain_Check(PyObject *object);

PyObject *PyBlockchain_FromTWBlockchain(TWBlockchain value);

bool PyInit_Blockchain(PyObject *module);