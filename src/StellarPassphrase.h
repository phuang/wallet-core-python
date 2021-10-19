// This is a GENERATED FILE, changes made here WILL BE LOST.

#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWStellarPassphrase.h>

extern PyTypeObject PyStellarPassphraseType;

struct PyStellarPassphraseObject {
  PyObject_HEAD const TWStellarPassphrase value;
};

bool PyStellarPassphrase_Check(PyObject *object);

PyObject *
PyStellarPassphrase_FromTWStellarPassphrase(TWStellarPassphrase value);

bool PyInit_StellarPassphrase(PyObject *module);