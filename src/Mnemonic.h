// This is a GENERATED FILE, changes made here WILL BE LOST.

#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWMnemonic.h>

struct PyMnemonicObject {
  PyObject_HEAD;
  TWMnemonic* value;
};

// Returns true if the object is a PyMnemonic.
bool PyMnemonic_Check(PyObject* object);

// Create PyMnemonic from an TWMnemonic.
PyObject* PyMnemonic_FromTWMnemonic(TWMnemonic* value);

// Initialize for PyMnemonic. It is called by python module init function.
bool PyInit_Mnemonic(PyObject* module);