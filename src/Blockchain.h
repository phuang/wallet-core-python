// This is a GENERATED FILE, changes made here WILL BE LOST.

#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWBlockchain.h>

struct PyBlockchainObject {
  PyObject_HEAD;
  const TWBlockchain value;
};

// Returns true if the object is a PyBlockchain.
bool PyBlockchain_Check(PyObject* object);

// Create PyBlockchain from an enum TWBlockchain value.
// Note: it returns the same PyBlockchain instance for the same enum
// TWBlockchain value. the caller should release the reference after using.
PyObject* PyBlockchain_FromTWBlockchain(TWBlockchain value);

// Initialize for PyBlockchain. It is called by python module init function.
bool PyInit_Blockchain(PyObject* module);