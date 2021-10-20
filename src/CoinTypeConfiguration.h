// This is a GENERATED FILE, changes made here WILL BE LOST.

#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWCoinTypeConfiguration.h>

struct PyCoinTypeConfigurationObject {
  PyObject_HEAD;
  TWCoinTypeConfiguration* value;
};

// Returns true if the object is a PyCoinTypeConfiguration.
bool PyCoinTypeConfiguration_Check(PyObject* object);

// Create PyCoinTypeConfiguration from an TWCoinTypeConfiguration.
PyObject* PyCoinTypeConfiguration_FromTWCoinTypeConfiguration(
    TWCoinTypeConfiguration* value);

// Get enum TWCoinTypeConfiguration value from a PyCoinTypeConfiguration object.
TWCoinTypeConfiguration* PyCoinTypeConfiguration_GetTWCoinTypeConfiguration(
    PyObject* object);

// Initialize for PyCoinTypeConfiguration. It is called by python module init
// function.
bool PyInit_CoinTypeConfiguration(PyObject* module);