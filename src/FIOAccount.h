// This is a GENERATED FILE, changes made here WILL BE LOST.

#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWFIOAccount.h>

struct PyFIOAccountObject {
  PyObject_HEAD;
  TWFIOAccount* value;
};

// Returns true if the object is a PyFIOAccount.
bool PyFIOAccount_Check(PyObject* object);

// Create PyFIOAccount from an TWFIOAccount.
PyObject* PyFIOAccount_FromTWFIOAccount(TWFIOAccount* value);

// Initialize for PyFIOAccount. It is called by python module init function.
bool PyInit_FIOAccount(PyObject* module);