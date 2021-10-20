// This is a GENERATED FILE, changes made here WILL BE LOST.

#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWBitcoinSigHashType.h>

struct PyBitcoinSigHashTypeObject {
  PyObject_HEAD;
  const TWBitcoinSigHashType value;
};

// Returns true if the object is a PyBitcoinSigHashType.
bool PyBitcoinSigHashType_Check(PyObject* object);

// Create PyBitcoinSigHashType from an enum TWBitcoinSigHashType value.
// Note: it returns the same PyBitcoinSigHashType instance for the same enum
// TWBitcoinSigHashType value. the caller should release the reference after
// using.
PyObject* PyBitcoinSigHashType_FromTWBitcoinSigHashType(
    TWBitcoinSigHashType value);

// Initialize for PyBitcoinSigHashType. It is called by python module init
// function.
bool PyInit_BitcoinSigHashType(PyObject* module);