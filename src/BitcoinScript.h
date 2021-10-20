// This is a GENERATED FILE, changes made here WILL BE LOST.

#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWBitcoinScript.h>

struct PyBitcoinScriptObject {
  PyObject_HEAD;
  TWBitcoinScript* value;
};

// Returns true if the object is a PyBitcoinScript.
bool PyBitcoinScript_Check(PyObject* object);

// Create PyBitcoinScript from an TWBitcoinScript.
PyObject* PyBitcoinScript_FromTWBitcoinScript(TWBitcoinScript* value);

// Get enum TWBitcoinScript value from a PyBitcoinScript object.
TWBitcoinScript* PyBitcoinScript_GetTWBitcoinScript(PyObject* object);

// Initialize for PyBitcoinScript. It is called by python module init function.
bool PyInit_BitcoinScript(PyObject* module);