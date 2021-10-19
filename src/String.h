#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWString.h>

PyObject* PyUnicode_FromTWString(TWString* str);

TWString* PyUnicode_GetTWString(PyObject* object);