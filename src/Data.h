#pragma once

#include <memory>

#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <TrustWalletCore/TWData.h>

class TWDataPtr : public std::unique_ptr<TWData, decltype(&TWDataDelete)> {
 public:
  TWDataPtr(TWData* p)
      : std::unique_ptr<TWData, decltype(&TWDataDelete)>(p, &TWDataDelete) {}
};

PyObject* PyByteArray_FromTWData(const TWDataPtr& data);

TWDataPtr PyByteArray_GetTWData(PyObject* object);