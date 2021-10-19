// This is a GENERATED FILE, changes made here WILL BE LOST.

#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWCurve.h>

struct PyCurveObject {
  PyObject_HEAD const TWCurve value;
};

// Returns true if the object is a PyCurve.
bool PyCurve_Check(PyObject *object);

// Create PyCurve from an enum TWCurve value.
// Note: it returns the same PyCurve instance for the same enum TWCurve value.
// the caller should release the reference after using.
PyObject *PyCurve_FromTWCurve(TWCurve value);

bool PyInit_Curve(PyObject *module);