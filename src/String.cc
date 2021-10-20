#include "String.h"

PyObject* PyUnicode_FromTWString(const TWStringPtr& str) {
  if (!str)
    return nullptr;

  return PyUnicode_FromStringAndSize(TWStringUTF8Bytes(str.get()),
                                     TWStringSize(str.get()));
}

TWStringPtr PyUnicode_GetTWString(PyObject* object) {
  if (!PyUnicode_Check(object))
    return nullptr;

  Py_ssize_t size = 0;
  const char* str = PyUnicode_AsUTF8AndSize(object, &size);
  return WRAPS(TWStringCreateWithRawBytes((const uint8_t*)str, size));
}