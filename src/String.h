#pragma once

#include <memory>

#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <TrustWalletCore/TWString.h>

class TWStringPtr
    : public std::unique_ptr<TWString, decltype(&TWStringDelete)> {
 public:
  TWStringPtr(TWString* p)
      : std::unique_ptr<TWString, decltype(&TWStringDelete)>(p,
                                                             &TWStringDelete) {}
};

#define WRAPS(s) TWStringPtr(s)

// Create a PyUnicode from a TWString.
PyObject* PyUnicode_FromTWString(const TWStringPtr& str);

// Get content of PyUnicode in a new allocated TWString, the caller should
// release after using.
TWStringPtr PyUnicode_GetTWString(PyObject* object);