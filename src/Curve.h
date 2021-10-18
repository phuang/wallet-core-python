#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWCurve.h>

struct PyCurveObject {
    PyObject_HEAD
    const TWCurve value;
};

PyObject* PyCurve_FromTWCurve(TWCurve value);
bool PyInit_Curve(PyObject *module);