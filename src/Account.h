// This is a GENERATED FILE, changes made here WILL BE LOST.

#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWAccount.h>

struct PyAccountObject {
  PyObject_HEAD;
  TWAccount* value;
};

// Returns true if the object is a PyAccount.
bool PyAccount_Check(PyObject* object);

// Create PyAccount from an TWAccount.
PyObject* PyAccount_FromTWAccount(TWAccount* value);

// Get enum TWAccount value from a PyAccount object.
TWAccount* PyAccount_GetTWAccount(PyObject* object);

// Initialize for PyAccount. It is called by python module init function.
bool PyInit_Account(PyObject* module);