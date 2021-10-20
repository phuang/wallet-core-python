// This is a GENERATED FILE, changes made here WILL BE LOST.

#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWStellarPassphrase.h>

struct PyStellarPassphraseObject {
  PyObject_HEAD;
  const TWStellarPassphrase value;
};

// Returns true if the object is a PyStellarPassphrase.
bool PyStellarPassphrase_Check(PyObject* object);

// Create PyStellarPassphrase from an enum TWStellarPassphrase value.
// Note: it returns the same PyStellarPassphrase instance for the same enum
// TWStellarPassphrase value. the caller should release the reference after
// using.
PyObject* PyStellarPassphrase_FromTWStellarPassphrase(
    TWStellarPassphrase value);

// Initialize for PyStellarPassphrase. It is called by python module init
// function.
bool PyInit_StellarPassphrase(PyObject* module);