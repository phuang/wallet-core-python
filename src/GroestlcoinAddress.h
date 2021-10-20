// This is a GENERATED FILE, changes made here WILL BE LOST.

#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWGroestlcoinAddress.h>

struct PyGroestlcoinAddressObject {
  PyObject_HEAD;
  TWGroestlcoinAddress* value;
};

// Returns true if the object is a PyGroestlcoinAddress.
bool PyGroestlcoinAddress_Check(PyObject* object);

// Create PyGroestlcoinAddress from an TWGroestlcoinAddress.
PyObject* PyGroestlcoinAddress_FromTWGroestlcoinAddress(
    TWGroestlcoinAddress* value);

// Initialize for PyGroestlcoinAddress. It is called by python module init
// function.
bool PyInit_GroestlcoinAddress(PyObject* module);