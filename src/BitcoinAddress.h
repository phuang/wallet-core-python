// This is a GENERATED FILE, changes made here WILL BE LOST.

#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWBitcoinAddress.h>

struct PyBitcoinAddressObject {
  PyObject_HEAD;
  TWBitcoinAddress* value;
};

// Returns true if the object is a PyBitcoinAddress.
bool PyBitcoinAddress_Check(PyObject* object);

// Create PyBitcoinAddress from an TWBitcoinAddress.
PyObject* PyBitcoinAddress_FromTWBitcoinAddress(TWBitcoinAddress* value);

// Initialize for PyBitcoinAddress. It is called by python module init function.
bool PyInit_BitcoinAddress(PyObject* module);