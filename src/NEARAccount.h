// This is a GENERATED FILE, changes made here WILL BE LOST.

#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWNEARAccount.h>

struct PyNEARAccountObject {
  PyObject_HEAD;
  TWNEARAccount* value;
};

// Returns true if the object is a PyNEARAccount.
bool PyNEARAccount_Check(PyObject* object);

// Create PyNEARAccount from an TWNEARAccount.
PyObject* PyNEARAccount_FromTWNEARAccount(TWNEARAccount* value);

// Initialize for PyNEARAccount. It is called by python module init function.
bool PyInit_NEARAccount(PyObject* module);