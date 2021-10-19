#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWString.h>

// Create a PyUnicode from a TWString.
PyObject *PyUnicode_FromTWString(TWString *str);

// Get content of PyUnicode in a new allocated TWString, the caller should
// release after using.
TWString *PyUnicode_GetTWString(PyObject *object);