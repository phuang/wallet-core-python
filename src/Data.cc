#include "Data.h"

PyObject* PyByteArray_FromTWData(const TWDataPtr& data) {
  if (!data)
    return nullptr;

  return PyByteArray_FromStringAndSize((const char*)TWDataBytes(data.get()),
                                       TWDataSize(data.get()));
}

TWDataPtr PyByteArray_GetTWData(PyObject* object) {
  if (!PyByteArray_Check(object))
    return nullptr;

  return TWDataCreateWithBytes((const uint8_t*)PyByteArray_AS_STRING(object),
                               PyByteArray_GET_SIZE(object));
}