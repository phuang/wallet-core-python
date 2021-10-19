#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <TrustWalletCore/TWData.h>

PyObject* PyByteArray_FromTWData(TWData* data);

TWData* PyByteArray_GetTWData(PyObject* object);