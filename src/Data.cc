#include "Data.h"

PyObject *PyByteArray_FromTWData(TWData *data) {
  if (!data)
    return nullptr;

  return PyByteArray_FromStringAndSize((const char *)TWDataBytes(data),
                                       TWDataSize(data));
}

TWData *PyByteArray_GetTWData(PyObject *object) {
  if (!PyByteArray_Check(object))
    return nullptr;

  return TWDataCreateWithBytes((const uint8_t *)PyByteArray_AS_STRING(object),
                               PyByteArray_GET_SIZE(object));
}