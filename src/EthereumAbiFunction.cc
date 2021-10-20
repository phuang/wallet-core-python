// This is a GENERATED FILE, changes made here WILL BE LOST.

#include "EthereumAbiFunction.h"

#include "Bool.h"
#include "Data.h"
#include "String.h"

static PyTypeObject PyEthereumAbiFunctionType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.EthereumAbiFunction",    /* tp_name */
    sizeof(PyEthereumAbiFunctionObject), /* tp_basicsize */
    0,                                   /* tp_itemsize */
    0,                                   /* tp_dealloc */
    0,                                   /* tp_print */
    0,                                   /* tp_getattr */
    0,                                   /* tp_setattr */
    0,                                   /* tp_reserved */
    0,                                   /* tp_repr */
    0,                                   /* tp_as_number */
    0,                                   /* tp_as_sequence */
    0,                                   /* tp_as_mapping */
    0,                                   /* tp_hash  */
    0,                                   /* tp_call */
    0,                                   /* tp_str */
    0,                                   /* tp_getattro */
    0,                                   /* tp_setattro */
    0,                                   /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                  /* tp_flags */
    nullptr,                             /* tp_doc */
};

bool PyEthereumAbiFunction_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyEthereumAbiFunctionType) != 0;
}

// Create PyEthereumAbiFunction from enum TWEthereumAbiFunction.
PyObject* PyEthereumAbiFunction_FromTWEthereumAbiFunction(
    TWEthereumAbiFunction* value) {
  if (!value)
    return nullptr;

  PyEthereumAbiFunctionObject* object =
      PyObject_New(PyEthereumAbiFunctionObject, &PyEthereumAbiFunctionType);
  if (!object)
    return nullptr;

  object->value = value;

  return (PyObject*)object;
}

TWEthereumAbiFunction* PyEthereumAbiFunction_GetTWEthereumAbiFunction(
    PyObject* object) {
  assert(PyEthereumAbiFunction_Check(object));
  return ((PyEthereumAbiFunctionObject*)object)->value;
}

// static int PyEthereumAbiFunction_init(PyEthereumAbiFunctionObject *self,
// PyObject *args, PyObject *kwds) {
//   return 0;
// }

// static PyObject* PyEthereumAbiFunction_new(PyTypeObject *subtype, PyObject
// *args, PyObject *kwds) {
//   int value = 0;
//   if (!PyArg_ParseTuple(args, "|i", &value)) {
//     return nullptr;
//   }
//   return
//   PyEthereumAbiFunction_FromTWEthereumAbiFunction((TWEthereumAbiFunction)value);
// }

// static PyObject* PyEthereumAbiFunction_str(PyEthereumAbiFunctionObject *self)
// {
//   const char* str = "Unknown";
//   return PyUnicode_FromString(str);
// }

// method function for Delete
// void TWEthereumAbiFunctionDelete(struct TWEthereumAbiFunction* fn);
static PyObject* PyEthereumAbiFunctionDelete(PyEthereumAbiFunctionObject* self,
                                             PyObject* const* args,
                                             Py_ssize_t nargs) {
  if (nargs != 0) {
    PyErr_Format(PyExc_TypeError, "Expect 0 instead of %d.", nargs);
    return nullptr;
  }

  TWEthereumAbiFunctionDelete(self->value);
  return nullptr;
}

// method function for GetType
// TWString* TWEthereumAbiFunctionGetType(struct TWEthereumAbiFunction* fn);
static PyObject* PyEthereumAbiFunctionGetType(PyEthereumAbiFunctionObject* self,
                                              PyObject* const* args,
                                              Py_ssize_t nargs) {
  if (nargs != 0) {
    PyErr_Format(PyExc_TypeError, "Expect 0 instead of %d.", nargs);
    return nullptr;
  }

  TWStringPtr result = TWEthereumAbiFunctionGetType(self->value);
  return PyUnicode_FromTWString(result);
}

// method function for AddParamUInt8
// int TWEthereumAbiFunctionAddParamUInt8(struct TWEthereumAbiFunction* fn,
// uint8_t val, bool isOutput);
static PyObject* PyEthereumAbiFunctionAddParamUInt8(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyLong_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Long");
    return nullptr;
  }
  auto arg0 = PyLong_AsLong(args[0]);

  if (!PyBool_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bool");
    return nullptr;
  }
  auto arg1 = PyBool_IsTrue(args[1]);

  int result = TWEthereumAbiFunctionAddParamUInt8(self->value, arg0, arg1);
  return PyLong_FromLong(result);
}

// method function for AddParamUInt16
// int TWEthereumAbiFunctionAddParamUInt16(struct TWEthereumAbiFunction* fn,
// uint16_t val, bool isOutput);
static PyObject* PyEthereumAbiFunctionAddParamUInt16(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyLong_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Long");
    return nullptr;
  }
  auto arg0 = PyLong_AsLong(args[0]);

  if (!PyBool_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bool");
    return nullptr;
  }
  auto arg1 = PyBool_IsTrue(args[1]);

  int result = TWEthereumAbiFunctionAddParamUInt16(self->value, arg0, arg1);
  return PyLong_FromLong(result);
}

// method function for AddParamUInt32
// int TWEthereumAbiFunctionAddParamUInt32(struct TWEthereumAbiFunction* fn,
// uint32_t val, bool isOutput);
static PyObject* PyEthereumAbiFunctionAddParamUInt32(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyLong_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Long");
    return nullptr;
  }
  auto arg0 = PyLong_AsLong(args[0]);

  if (!PyBool_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bool");
    return nullptr;
  }
  auto arg1 = PyBool_IsTrue(args[1]);

  int result = TWEthereumAbiFunctionAddParamUInt32(self->value, arg0, arg1);
  return PyLong_FromLong(result);
}

// method function for AddParamUInt64
// int TWEthereumAbiFunctionAddParamUInt64(struct TWEthereumAbiFunction* fn,
// uint64_t val, bool isOutput);
static PyObject* PyEthereumAbiFunctionAddParamUInt64(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyLong_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Long");
    return nullptr;
  }
  auto arg0 = PyLong_AsLongLong(args[0]);

  if (!PyBool_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bool");
    return nullptr;
  }
  auto arg1 = PyBool_IsTrue(args[1]);

  int result = TWEthereumAbiFunctionAddParamUInt64(self->value, arg0, arg1);
  return PyLong_FromLong(result);
}

// method function for AddParamUInt256
// int TWEthereumAbiFunctionAddParamUInt256(struct TWEthereumAbiFunction* fn,
// TWData* val, bool isOutput);
static PyObject* PyEthereumAbiFunctionAddParamUInt256(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyByteArray_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type ByteArray");
    return nullptr;
  }
  auto arg0 = PyByteArray_GetTWData(args[0]);

  if (!PyBool_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bool");
    return nullptr;
  }
  auto arg1 = PyBool_IsTrue(args[1]);

  int result =
      TWEthereumAbiFunctionAddParamUInt256(self->value, arg0.get(), arg1);
  return PyLong_FromLong(result);
}

// method function for AddParamUIntN
// int TWEthereumAbiFunctionAddParamUIntN(struct TWEthereumAbiFunction* fn, int
// bits, TWData* val, bool isOutput);
static PyObject* PyEthereumAbiFunctionAddParamUIntN(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 3) {
    PyErr_Format(PyExc_TypeError, "Expect 3 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyLong_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Long");
    return nullptr;
  }
  auto arg0 = PyLong_AsLong(args[0]);

  if (!PyByteArray_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type ByteArray");
    return nullptr;
  }
  auto arg1 = PyByteArray_GetTWData(args[1]);

  if (!PyBool_Check(args[2])) {
    PyErr_SetString(PyExc_TypeError, "The arg 2 is not in type Bool");
    return nullptr;
  }
  auto arg2 = PyBool_IsTrue(args[2]);

  int result =
      TWEthereumAbiFunctionAddParamUIntN(self->value, arg0, arg1.get(), arg2);
  return PyLong_FromLong(result);
}

// method function for AddParamInt8
// int TWEthereumAbiFunctionAddParamInt8(struct TWEthereumAbiFunction* fn,
// int8_t val, bool isOutput);
static PyObject* PyEthereumAbiFunctionAddParamInt8(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyLong_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Long");
    return nullptr;
  }
  auto arg0 = PyLong_AsLong(args[0]);

  if (!PyBool_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bool");
    return nullptr;
  }
  auto arg1 = PyBool_IsTrue(args[1]);

  int result = TWEthereumAbiFunctionAddParamInt8(self->value, arg0, arg1);
  return PyLong_FromLong(result);
}

// method function for AddParamInt16
// int TWEthereumAbiFunctionAddParamInt16(struct TWEthereumAbiFunction* fn,
// int16_t val, bool isOutput);
static PyObject* PyEthereumAbiFunctionAddParamInt16(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyLong_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Long");
    return nullptr;
  }
  auto arg0 = PyLong_AsLong(args[0]);

  if (!PyBool_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bool");
    return nullptr;
  }
  auto arg1 = PyBool_IsTrue(args[1]);

  int result = TWEthereumAbiFunctionAddParamInt16(self->value, arg0, arg1);
  return PyLong_FromLong(result);
}

// method function for AddParamInt32
// int TWEthereumAbiFunctionAddParamInt32(struct TWEthereumAbiFunction* fn,
// int32_t val, bool isOutput);
static PyObject* PyEthereumAbiFunctionAddParamInt32(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyLong_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Long");
    return nullptr;
  }
  auto arg0 = PyLong_AsLong(args[0]);

  if (!PyBool_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bool");
    return nullptr;
  }
  auto arg1 = PyBool_IsTrue(args[1]);

  int result = TWEthereumAbiFunctionAddParamInt32(self->value, arg0, arg1);
  return PyLong_FromLong(result);
}

// method function for AddParamInt64
// int TWEthereumAbiFunctionAddParamInt64(struct TWEthereumAbiFunction* fn,
// int64_t val, bool isOutput);
static PyObject* PyEthereumAbiFunctionAddParamInt64(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyLong_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Long");
    return nullptr;
  }
  auto arg0 = PyLong_AsLongLong(args[0]);

  if (!PyBool_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bool");
    return nullptr;
  }
  auto arg1 = PyBool_IsTrue(args[1]);

  int result = TWEthereumAbiFunctionAddParamInt64(self->value, arg0, arg1);
  return PyLong_FromLong(result);
}

// method function for AddParamInt256
// int TWEthereumAbiFunctionAddParamInt256(struct TWEthereumAbiFunction* fn,
// TWData* val, bool isOutput);
static PyObject* PyEthereumAbiFunctionAddParamInt256(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyByteArray_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type ByteArray");
    return nullptr;
  }
  auto arg0 = PyByteArray_GetTWData(args[0]);

  if (!PyBool_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bool");
    return nullptr;
  }
  auto arg1 = PyBool_IsTrue(args[1]);

  int result =
      TWEthereumAbiFunctionAddParamInt256(self->value, arg0.get(), arg1);
  return PyLong_FromLong(result);
}

// method function for AddParamIntN
// int TWEthereumAbiFunctionAddParamIntN(struct TWEthereumAbiFunction* fn, int
// bits, TWData* val, bool isOutput);
static PyObject* PyEthereumAbiFunctionAddParamIntN(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 3) {
    PyErr_Format(PyExc_TypeError, "Expect 3 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyLong_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Long");
    return nullptr;
  }
  auto arg0 = PyLong_AsLong(args[0]);

  if (!PyByteArray_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type ByteArray");
    return nullptr;
  }
  auto arg1 = PyByteArray_GetTWData(args[1]);

  if (!PyBool_Check(args[2])) {
    PyErr_SetString(PyExc_TypeError, "The arg 2 is not in type Bool");
    return nullptr;
  }
  auto arg2 = PyBool_IsTrue(args[2]);

  int result =
      TWEthereumAbiFunctionAddParamIntN(self->value, arg0, arg1.get(), arg2);
  return PyLong_FromLong(result);
}

// method function for AddParamBool
// int TWEthereumAbiFunctionAddParamBool(struct TWEthereumAbiFunction* fn, bool
// val, bool isOutput);
static PyObject* PyEthereumAbiFunctionAddParamBool(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyBool_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Bool");
    return nullptr;
  }
  auto arg0 = PyBool_IsTrue(args[0]);

  if (!PyBool_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bool");
    return nullptr;
  }
  auto arg1 = PyBool_IsTrue(args[1]);

  int result = TWEthereumAbiFunctionAddParamBool(self->value, arg0, arg1);
  return PyLong_FromLong(result);
}

// method function for AddParamString
// int TWEthereumAbiFunctionAddParamString(struct TWEthereumAbiFunction* fn,
// TWString* val, bool isOutput);
static PyObject* PyEthereumAbiFunctionAddParamString(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyUnicode_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Unicode");
    return nullptr;
  }
  auto arg0 = PyUnicode_GetTWString(args[0]);

  if (!PyBool_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bool");
    return nullptr;
  }
  auto arg1 = PyBool_IsTrue(args[1]);

  int result =
      TWEthereumAbiFunctionAddParamString(self->value, arg0.get(), arg1);
  return PyLong_FromLong(result);
}

// method function for AddParamAddress
// int TWEthereumAbiFunctionAddParamAddress(struct TWEthereumAbiFunction* fn,
// TWData* val, bool isOutput);
static PyObject* PyEthereumAbiFunctionAddParamAddress(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyByteArray_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type ByteArray");
    return nullptr;
  }
  auto arg0 = PyByteArray_GetTWData(args[0]);

  if (!PyBool_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bool");
    return nullptr;
  }
  auto arg1 = PyBool_IsTrue(args[1]);

  int result =
      TWEthereumAbiFunctionAddParamAddress(self->value, arg0.get(), arg1);
  return PyLong_FromLong(result);
}

// method function for AddParamBytes
// int TWEthereumAbiFunctionAddParamBytes(struct TWEthereumAbiFunction* fn,
// TWData* val, bool isOutput);
static PyObject* PyEthereumAbiFunctionAddParamBytes(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyByteArray_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type ByteArray");
    return nullptr;
  }
  auto arg0 = PyByteArray_GetTWData(args[0]);

  if (!PyBool_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bool");
    return nullptr;
  }
  auto arg1 = PyBool_IsTrue(args[1]);

  int result =
      TWEthereumAbiFunctionAddParamBytes(self->value, arg0.get(), arg1);
  return PyLong_FromLong(result);
}

// method function for AddParamBytesFix
// int TWEthereumAbiFunctionAddParamBytesFix(struct TWEthereumAbiFunction* fn,
// size_t size, TWData* val, bool isOutput);
static PyObject* PyEthereumAbiFunctionAddParamBytesFix(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 3) {
    PyErr_Format(PyExc_TypeError, "Expect 3 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyLong_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Long");
    return nullptr;
  }
  auto arg0 = PyLong_AsLong(args[0]);

  if (!PyByteArray_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type ByteArray");
    return nullptr;
  }
  auto arg1 = PyByteArray_GetTWData(args[1]);

  if (!PyBool_Check(args[2])) {
    PyErr_SetString(PyExc_TypeError, "The arg 2 is not in type Bool");
    return nullptr;
  }
  auto arg2 = PyBool_IsTrue(args[2]);

  int result = TWEthereumAbiFunctionAddParamBytesFix(self->value, arg0,
                                                     arg1.get(), arg2);
  return PyLong_FromLong(result);
}

// method function for AddParamArray
// int TWEthereumAbiFunctionAddParamArray(struct TWEthereumAbiFunction* fn, bool
// isOutput);
static PyObject* PyEthereumAbiFunctionAddParamArray(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyBool_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Bool");
    return nullptr;
  }
  auto arg0 = PyBool_IsTrue(args[0]);

  int result = TWEthereumAbiFunctionAddParamArray(self->value, arg0);
  return PyLong_FromLong(result);
}

// method function for GetParamUInt8
// uint8_t TWEthereumAbiFunctionGetParamUInt8(struct TWEthereumAbiFunction* fn,
// int idx, bool isOutput);
static PyObject* PyEthereumAbiFunctionGetParamUInt8(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyLong_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Long");
    return nullptr;
  }
  auto arg0 = PyLong_AsLong(args[0]);

  if (!PyBool_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bool");
    return nullptr;
  }
  auto arg1 = PyBool_IsTrue(args[1]);

  uint8_t result = TWEthereumAbiFunctionGetParamUInt8(self->value, arg0, arg1);
  return PyLong_FromLong(result);
}

// method function for GetParamUInt64
// uint64_t TWEthereumAbiFunctionGetParamUInt64(struct TWEthereumAbiFunction*
// fn, int idx, bool isOutput);
static PyObject* PyEthereumAbiFunctionGetParamUInt64(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyLong_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Long");
    return nullptr;
  }
  auto arg0 = PyLong_AsLong(args[0]);

  if (!PyBool_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bool");
    return nullptr;
  }
  auto arg1 = PyBool_IsTrue(args[1]);

  uint64_t result =
      TWEthereumAbiFunctionGetParamUInt64(self->value, arg0, arg1);
  return PyLong_FromLongLong(result);
}

// method function for GetParamUInt256
// TWData* TWEthereumAbiFunctionGetParamUInt256(struct TWEthereumAbiFunction*
// fn, int idx, bool isOutput);
static PyObject* PyEthereumAbiFunctionGetParamUInt256(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyLong_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Long");
    return nullptr;
  }
  auto arg0 = PyLong_AsLong(args[0]);

  if (!PyBool_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bool");
    return nullptr;
  }
  auto arg1 = PyBool_IsTrue(args[1]);

  TWDataPtr result =
      TWEthereumAbiFunctionGetParamUInt256(self->value, arg0, arg1);
  return PyByteArray_FromTWData(result);
}

// method function for GetParamBool
// bool TWEthereumAbiFunctionGetParamBool(struct TWEthereumAbiFunction* fn, int
// idx, bool isOutput);
static PyObject* PyEthereumAbiFunctionGetParamBool(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyLong_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Long");
    return nullptr;
  }
  auto arg0 = PyLong_AsLong(args[0]);

  if (!PyBool_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bool");
    return nullptr;
  }
  auto arg1 = PyBool_IsTrue(args[1]);

  bool result = TWEthereumAbiFunctionGetParamBool(self->value, arg0, arg1);
  return PyBool_FromLong(result);
}

// method function for GetParamString
// TWString* TWEthereumAbiFunctionGetParamString(struct TWEthereumAbiFunction*
// fn, int idx, bool isOutput);
static PyObject* PyEthereumAbiFunctionGetParamString(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyLong_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Long");
    return nullptr;
  }
  auto arg0 = PyLong_AsLong(args[0]);

  if (!PyBool_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bool");
    return nullptr;
  }
  auto arg1 = PyBool_IsTrue(args[1]);

  TWStringPtr result =
      TWEthereumAbiFunctionGetParamString(self->value, arg0, arg1);
  return PyUnicode_FromTWString(result);
}

// method function for GetParamAddress
// TWData* TWEthereumAbiFunctionGetParamAddress(struct TWEthereumAbiFunction*
// fn, int idx, bool isOutput);
static PyObject* PyEthereumAbiFunctionGetParamAddress(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyLong_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Long");
    return nullptr;
  }
  auto arg0 = PyLong_AsLong(args[0]);

  if (!PyBool_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bool");
    return nullptr;
  }
  auto arg1 = PyBool_IsTrue(args[1]);

  TWDataPtr result =
      TWEthereumAbiFunctionGetParamAddress(self->value, arg0, arg1);
  return PyByteArray_FromTWData(result);
}

// method function for AddInArrayParamUInt8
// int TWEthereumAbiFunctionAddInArrayParamUInt8(struct TWEthereumAbiFunction*
// fn, int arrayIdx, uint8_t val);
static PyObject* PyEthereumAbiFunctionAddInArrayParamUInt8(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyLong_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Long");
    return nullptr;
  }
  auto arg0 = PyLong_AsLong(args[0]);

  if (!PyLong_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Long");
    return nullptr;
  }
  auto arg1 = PyLong_AsLong(args[1]);

  int result =
      TWEthereumAbiFunctionAddInArrayParamUInt8(self->value, arg0, arg1);
  return PyLong_FromLong(result);
}

// method function for AddInArrayParamUInt16
// int TWEthereumAbiFunctionAddInArrayParamUInt16(struct TWEthereumAbiFunction*
// fn, int arrayIdx, uint16_t val);
static PyObject* PyEthereumAbiFunctionAddInArrayParamUInt16(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyLong_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Long");
    return nullptr;
  }
  auto arg0 = PyLong_AsLong(args[0]);

  if (!PyLong_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Long");
    return nullptr;
  }
  auto arg1 = PyLong_AsLong(args[1]);

  int result =
      TWEthereumAbiFunctionAddInArrayParamUInt16(self->value, arg0, arg1);
  return PyLong_FromLong(result);
}

// method function for AddInArrayParamUInt32
// int TWEthereumAbiFunctionAddInArrayParamUInt32(struct TWEthereumAbiFunction*
// fn, int arrayIdx, uint32_t val);
static PyObject* PyEthereumAbiFunctionAddInArrayParamUInt32(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyLong_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Long");
    return nullptr;
  }
  auto arg0 = PyLong_AsLong(args[0]);

  if (!PyLong_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Long");
    return nullptr;
  }
  auto arg1 = PyLong_AsLong(args[1]);

  int result =
      TWEthereumAbiFunctionAddInArrayParamUInt32(self->value, arg0, arg1);
  return PyLong_FromLong(result);
}

// method function for AddInArrayParamUInt64
// int TWEthereumAbiFunctionAddInArrayParamUInt64(struct TWEthereumAbiFunction*
// fn, int arrayIdx, uint64_t val);
static PyObject* PyEthereumAbiFunctionAddInArrayParamUInt64(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyLong_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Long");
    return nullptr;
  }
  auto arg0 = PyLong_AsLong(args[0]);

  if (!PyLong_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Long");
    return nullptr;
  }
  auto arg1 = PyLong_AsLongLong(args[1]);

  int result =
      TWEthereumAbiFunctionAddInArrayParamUInt64(self->value, arg0, arg1);
  return PyLong_FromLong(result);
}

// method function for AddInArrayParamUInt256
// int TWEthereumAbiFunctionAddInArrayParamUInt256(struct TWEthereumAbiFunction*
// fn, int arrayIdx, TWData* val);
static PyObject* PyEthereumAbiFunctionAddInArrayParamUInt256(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyLong_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Long");
    return nullptr;
  }
  auto arg0 = PyLong_AsLong(args[0]);

  if (!PyByteArray_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type ByteArray");
    return nullptr;
  }
  auto arg1 = PyByteArray_GetTWData(args[1]);

  int result = TWEthereumAbiFunctionAddInArrayParamUInt256(self->value, arg0,
                                                           arg1.get());
  return PyLong_FromLong(result);
}

// method function for AddInArrayParamUIntN
// int TWEthereumAbiFunctionAddInArrayParamUIntN(struct TWEthereumAbiFunction*
// fn, int arrayIdx, int bits, TWData* val);
static PyObject* PyEthereumAbiFunctionAddInArrayParamUIntN(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 3) {
    PyErr_Format(PyExc_TypeError, "Expect 3 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyLong_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Long");
    return nullptr;
  }
  auto arg0 = PyLong_AsLong(args[0]);

  if (!PyLong_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Long");
    return nullptr;
  }
  auto arg1 = PyLong_AsLong(args[1]);

  if (!PyByteArray_Check(args[2])) {
    PyErr_SetString(PyExc_TypeError, "The arg 2 is not in type ByteArray");
    return nullptr;
  }
  auto arg2 = PyByteArray_GetTWData(args[2]);

  int result = TWEthereumAbiFunctionAddInArrayParamUIntN(self->value, arg0,
                                                         arg1, arg2.get());
  return PyLong_FromLong(result);
}

// method function for AddInArrayParamInt8
// int TWEthereumAbiFunctionAddInArrayParamInt8(struct TWEthereumAbiFunction*
// fn, int arrayIdx, int8_t val);
static PyObject* PyEthereumAbiFunctionAddInArrayParamInt8(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyLong_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Long");
    return nullptr;
  }
  auto arg0 = PyLong_AsLong(args[0]);

  if (!PyLong_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Long");
    return nullptr;
  }
  auto arg1 = PyLong_AsLong(args[1]);

  int result =
      TWEthereumAbiFunctionAddInArrayParamInt8(self->value, arg0, arg1);
  return PyLong_FromLong(result);
}

// method function for AddInArrayParamInt16
// int TWEthereumAbiFunctionAddInArrayParamInt16(struct TWEthereumAbiFunction*
// fn, int arrayIdx, int16_t val);
static PyObject* PyEthereumAbiFunctionAddInArrayParamInt16(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyLong_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Long");
    return nullptr;
  }
  auto arg0 = PyLong_AsLong(args[0]);

  if (!PyLong_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Long");
    return nullptr;
  }
  auto arg1 = PyLong_AsLong(args[1]);

  int result =
      TWEthereumAbiFunctionAddInArrayParamInt16(self->value, arg0, arg1);
  return PyLong_FromLong(result);
}

// method function for AddInArrayParamInt32
// int TWEthereumAbiFunctionAddInArrayParamInt32(struct TWEthereumAbiFunction*
// fn, int arrayIdx, int32_t val);
static PyObject* PyEthereumAbiFunctionAddInArrayParamInt32(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyLong_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Long");
    return nullptr;
  }
  auto arg0 = PyLong_AsLong(args[0]);

  if (!PyLong_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Long");
    return nullptr;
  }
  auto arg1 = PyLong_AsLong(args[1]);

  int result =
      TWEthereumAbiFunctionAddInArrayParamInt32(self->value, arg0, arg1);
  return PyLong_FromLong(result);
}

// method function for AddInArrayParamInt64
// int TWEthereumAbiFunctionAddInArrayParamInt64(struct TWEthereumAbiFunction*
// fn, int arrayIdx, int64_t val);
static PyObject* PyEthereumAbiFunctionAddInArrayParamInt64(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyLong_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Long");
    return nullptr;
  }
  auto arg0 = PyLong_AsLong(args[0]);

  if (!PyLong_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Long");
    return nullptr;
  }
  auto arg1 = PyLong_AsLongLong(args[1]);

  int result =
      TWEthereumAbiFunctionAddInArrayParamInt64(self->value, arg0, arg1);
  return PyLong_FromLong(result);
}

// method function for AddInArrayParamInt256
// int TWEthereumAbiFunctionAddInArrayParamInt256(struct TWEthereumAbiFunction*
// fn, int arrayIdx, TWData* val);
static PyObject* PyEthereumAbiFunctionAddInArrayParamInt256(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyLong_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Long");
    return nullptr;
  }
  auto arg0 = PyLong_AsLong(args[0]);

  if (!PyByteArray_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type ByteArray");
    return nullptr;
  }
  auto arg1 = PyByteArray_GetTWData(args[1]);

  int result =
      TWEthereumAbiFunctionAddInArrayParamInt256(self->value, arg0, arg1.get());
  return PyLong_FromLong(result);
}

// method function for AddInArrayParamIntN
// int TWEthereumAbiFunctionAddInArrayParamIntN(struct TWEthereumAbiFunction*
// fn, int arrayIdx, int bits, TWData* val);
static PyObject* PyEthereumAbiFunctionAddInArrayParamIntN(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 3) {
    PyErr_Format(PyExc_TypeError, "Expect 3 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyLong_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Long");
    return nullptr;
  }
  auto arg0 = PyLong_AsLong(args[0]);

  if (!PyLong_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Long");
    return nullptr;
  }
  auto arg1 = PyLong_AsLong(args[1]);

  if (!PyByteArray_Check(args[2])) {
    PyErr_SetString(PyExc_TypeError, "The arg 2 is not in type ByteArray");
    return nullptr;
  }
  auto arg2 = PyByteArray_GetTWData(args[2]);

  int result = TWEthereumAbiFunctionAddInArrayParamIntN(self->value, arg0, arg1,
                                                        arg2.get());
  return PyLong_FromLong(result);
}

// method function for AddInArrayParamBool
// int TWEthereumAbiFunctionAddInArrayParamBool(struct TWEthereumAbiFunction*
// fn, int arrayIdx, bool val);
static PyObject* PyEthereumAbiFunctionAddInArrayParamBool(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyLong_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Long");
    return nullptr;
  }
  auto arg0 = PyLong_AsLong(args[0]);

  if (!PyBool_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bool");
    return nullptr;
  }
  auto arg1 = PyBool_IsTrue(args[1]);

  int result =
      TWEthereumAbiFunctionAddInArrayParamBool(self->value, arg0, arg1);
  return PyLong_FromLong(result);
}

// method function for AddInArrayParamString
// int TWEthereumAbiFunctionAddInArrayParamString(struct TWEthereumAbiFunction*
// fn, int arrayIdx, TWString* val);
static PyObject* PyEthereumAbiFunctionAddInArrayParamString(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyLong_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Long");
    return nullptr;
  }
  auto arg0 = PyLong_AsLong(args[0]);

  if (!PyUnicode_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Unicode");
    return nullptr;
  }
  auto arg1 = PyUnicode_GetTWString(args[1]);

  int result =
      TWEthereumAbiFunctionAddInArrayParamString(self->value, arg0, arg1.get());
  return PyLong_FromLong(result);
}

// method function for AddInArrayParamAddress
// int TWEthereumAbiFunctionAddInArrayParamAddress(struct TWEthereumAbiFunction*
// fn, int arrayIdx, TWData* val);
static PyObject* PyEthereumAbiFunctionAddInArrayParamAddress(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyLong_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Long");
    return nullptr;
  }
  auto arg0 = PyLong_AsLong(args[0]);

  if (!PyByteArray_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type ByteArray");
    return nullptr;
  }
  auto arg1 = PyByteArray_GetTWData(args[1]);

  int result = TWEthereumAbiFunctionAddInArrayParamAddress(self->value, arg0,
                                                           arg1.get());
  return PyLong_FromLong(result);
}

// method function for AddInArrayParamBytes
// int TWEthereumAbiFunctionAddInArrayParamBytes(struct TWEthereumAbiFunction*
// fn, int arrayIdx, TWData* val);
static PyObject* PyEthereumAbiFunctionAddInArrayParamBytes(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyLong_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Long");
    return nullptr;
  }
  auto arg0 = PyLong_AsLong(args[0]);

  if (!PyByteArray_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type ByteArray");
    return nullptr;
  }
  auto arg1 = PyByteArray_GetTWData(args[1]);

  int result =
      TWEthereumAbiFunctionAddInArrayParamBytes(self->value, arg0, arg1.get());
  return PyLong_FromLong(result);
}

// method function for AddInArrayParamBytesFix
// int TWEthereumAbiFunctionAddInArrayParamBytesFix(struct
// TWEthereumAbiFunction* fn, int arrayIdx, size_t size, TWData* val);
static PyObject* PyEthereumAbiFunctionAddInArrayParamBytesFix(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 3) {
    PyErr_Format(PyExc_TypeError, "Expect 3 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyLong_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Long");
    return nullptr;
  }
  auto arg0 = PyLong_AsLong(args[0]);

  if (!PyLong_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Long");
    return nullptr;
  }
  auto arg1 = PyLong_AsLong(args[1]);

  if (!PyByteArray_Check(args[2])) {
    PyErr_SetString(PyExc_TypeError, "The arg 2 is not in type ByteArray");
    return nullptr;
  }
  auto arg2 = PyByteArray_GetTWData(args[2]);

  int result = TWEthereumAbiFunctionAddInArrayParamBytesFix(self->value, arg0,
                                                            arg1, arg2.get());
  return PyLong_FromLong(result);
}

// static method function for CreateWithString
// struct TWEthereumAbiFunction* TWEthereumAbiFunctionCreateWithString(TWString*
// name);
static PyObject* PyEthereumAbiFunctionCreateWithString(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyUnicode_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Unicode");
    return nullptr;
  }
  auto arg0 = PyUnicode_GetTWString(args[0]);

  TWEthereumAbiFunction* result =
      TWEthereumAbiFunctionCreateWithString(arg0.get());
  return PyEthereumAbiFunction_FromTWEthereumAbiFunction(result);
}

static const PyGetSetDef get_set_defs[] = {{}};

static const PyMethodDef method_defs[] = {
    {"Delete", (PyCFunction)PyEthereumAbiFunctionDelete, METH_FASTCALL},
    {"GetType", (PyCFunction)PyEthereumAbiFunctionGetType, METH_FASTCALL},
    {"AddParamUInt8", (PyCFunction)PyEthereumAbiFunctionAddParamUInt8,
     METH_FASTCALL},
    {"AddParamUInt16", (PyCFunction)PyEthereumAbiFunctionAddParamUInt16,
     METH_FASTCALL},
    {"AddParamUInt32", (PyCFunction)PyEthereumAbiFunctionAddParamUInt32,
     METH_FASTCALL},
    {"AddParamUInt64", (PyCFunction)PyEthereumAbiFunctionAddParamUInt64,
     METH_FASTCALL},
    {"AddParamUInt256", (PyCFunction)PyEthereumAbiFunctionAddParamUInt256,
     METH_FASTCALL},
    {"AddParamUIntN", (PyCFunction)PyEthereumAbiFunctionAddParamUIntN,
     METH_FASTCALL},
    {"AddParamInt8", (PyCFunction)PyEthereumAbiFunctionAddParamInt8,
     METH_FASTCALL},
    {"AddParamInt16", (PyCFunction)PyEthereumAbiFunctionAddParamInt16,
     METH_FASTCALL},
    {"AddParamInt32", (PyCFunction)PyEthereumAbiFunctionAddParamInt32,
     METH_FASTCALL},
    {"AddParamInt64", (PyCFunction)PyEthereumAbiFunctionAddParamInt64,
     METH_FASTCALL},
    {"AddParamInt256", (PyCFunction)PyEthereumAbiFunctionAddParamInt256,
     METH_FASTCALL},
    {"AddParamIntN", (PyCFunction)PyEthereumAbiFunctionAddParamIntN,
     METH_FASTCALL},
    {"AddParamBool", (PyCFunction)PyEthereumAbiFunctionAddParamBool,
     METH_FASTCALL},
    {"AddParamString", (PyCFunction)PyEthereumAbiFunctionAddParamString,
     METH_FASTCALL},
    {"AddParamAddress", (PyCFunction)PyEthereumAbiFunctionAddParamAddress,
     METH_FASTCALL},
    {"AddParamBytes", (PyCFunction)PyEthereumAbiFunctionAddParamBytes,
     METH_FASTCALL},
    {"AddParamBytesFix", (PyCFunction)PyEthereumAbiFunctionAddParamBytesFix,
     METH_FASTCALL},
    {"AddParamArray", (PyCFunction)PyEthereumAbiFunctionAddParamArray,
     METH_FASTCALL},
    {"GetParamUInt8", (PyCFunction)PyEthereumAbiFunctionGetParamUInt8,
     METH_FASTCALL},
    {"GetParamUInt64", (PyCFunction)PyEthereumAbiFunctionGetParamUInt64,
     METH_FASTCALL},
    {"GetParamUInt256", (PyCFunction)PyEthereumAbiFunctionGetParamUInt256,
     METH_FASTCALL},
    {"GetParamBool", (PyCFunction)PyEthereumAbiFunctionGetParamBool,
     METH_FASTCALL},
    {"GetParamString", (PyCFunction)PyEthereumAbiFunctionGetParamString,
     METH_FASTCALL},
    {"GetParamAddress", (PyCFunction)PyEthereumAbiFunctionGetParamAddress,
     METH_FASTCALL},
    {"AddInArrayParamUInt8",
     (PyCFunction)PyEthereumAbiFunctionAddInArrayParamUInt8, METH_FASTCALL},
    {"AddInArrayParamUInt16",
     (PyCFunction)PyEthereumAbiFunctionAddInArrayParamUInt16, METH_FASTCALL},
    {"AddInArrayParamUInt32",
     (PyCFunction)PyEthereumAbiFunctionAddInArrayParamUInt32, METH_FASTCALL},
    {"AddInArrayParamUInt64",
     (PyCFunction)PyEthereumAbiFunctionAddInArrayParamUInt64, METH_FASTCALL},
    {"AddInArrayParamUInt256",
     (PyCFunction)PyEthereumAbiFunctionAddInArrayParamUInt256, METH_FASTCALL},
    {"AddInArrayParamUIntN",
     (PyCFunction)PyEthereumAbiFunctionAddInArrayParamUIntN, METH_FASTCALL},
    {"AddInArrayParamInt8",
     (PyCFunction)PyEthereumAbiFunctionAddInArrayParamInt8, METH_FASTCALL},
    {"AddInArrayParamInt16",
     (PyCFunction)PyEthereumAbiFunctionAddInArrayParamInt16, METH_FASTCALL},
    {"AddInArrayParamInt32",
     (PyCFunction)PyEthereumAbiFunctionAddInArrayParamInt32, METH_FASTCALL},
    {"AddInArrayParamInt64",
     (PyCFunction)PyEthereumAbiFunctionAddInArrayParamInt64, METH_FASTCALL},
    {"AddInArrayParamInt256",
     (PyCFunction)PyEthereumAbiFunctionAddInArrayParamInt256, METH_FASTCALL},
    {"AddInArrayParamIntN",
     (PyCFunction)PyEthereumAbiFunctionAddInArrayParamIntN, METH_FASTCALL},
    {"AddInArrayParamBool",
     (PyCFunction)PyEthereumAbiFunctionAddInArrayParamBool, METH_FASTCALL},
    {"AddInArrayParamString",
     (PyCFunction)PyEthereumAbiFunctionAddInArrayParamString, METH_FASTCALL},
    {"AddInArrayParamAddress",
     (PyCFunction)PyEthereumAbiFunctionAddInArrayParamAddress, METH_FASTCALL},
    {"AddInArrayParamBytes",
     (PyCFunction)PyEthereumAbiFunctionAddInArrayParamBytes, METH_FASTCALL},
    {"AddInArrayParamBytesFix",
     (PyCFunction)PyEthereumAbiFunctionAddInArrayParamBytesFix, METH_FASTCALL},
    {"CreateWithString", (PyCFunction)PyEthereumAbiFunctionCreateWithString,
     METH_FASTCALL | METH_STATIC},
    {}};

bool PyInit_EthereumAbiFunction(PyObject* module) {
  // PyEthereumAbiFunctionType.tp_new = PyEthereumAbiFunction_new;
  // PyEthereumAbiFunctionType.tp_init = (initproc)PyEthereumAbiFunction_init;
  // PyEthereumAbiFunctionType.tp_str = (reprfunc)PyEthereumAbiFunction_str;
  PyEthereumAbiFunctionType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyEthereumAbiFunctionType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyEthereumAbiFunctionType) < 0)
    return false;

  Py_INCREF(&PyEthereumAbiFunctionType);
  if (PyModule_AddObject(module, "EthereumAbiFunction",
                         (PyObject*)&PyEthereumAbiFunctionType) < 0) {
    Py_DECREF(&PyEthereumAbiFunctionType);
    return false;
  }

  return true;
}