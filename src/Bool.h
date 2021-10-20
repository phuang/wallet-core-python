#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <TrustWalletCore/TWData.h>

#define PyBool_IsTrue(o) (o == Py_True)
