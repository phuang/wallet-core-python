// This is a GENERATED FILE, changes made here WILL BE LOST.

#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWCurve.h>

extern PyTypeObject PyCurveType;

struct PyCurveObject {
  PyObject_HEAD const TWCurve value;
};

bool PyCurve_Check(PyObject *object);

PyObject *PyCurve_FromTWCurve(TWCurve value);

bool PyInit_Curve(PyObject *module);