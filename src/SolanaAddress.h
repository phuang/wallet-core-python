// This is a GENERATED FILE, changes made here WILL BE LOST.

#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWSolanaAddress.h>

struct PySolanaAddressObject {
  PyObject_HEAD;
  TWSolanaAddress* value;
};

// Returns true if the object is a PySolanaAddress.
bool PySolanaAddress_Check(PyObject* object);

// Create PySolanaAddress from an TWSolanaAddress.
PyObject* PySolanaAddress_FromTWSolanaAddress(TWSolanaAddress* value);

// Get enum TWSolanaAddress value from a PySolanaAddress object.
TWSolanaAddress* PySolanaAddress_GetTWSolanaAddress(PyObject* object);

// Initialize for PySolanaAddress. It is called by python module init function.
bool PyInit_SolanaAddress(PyObject* module);