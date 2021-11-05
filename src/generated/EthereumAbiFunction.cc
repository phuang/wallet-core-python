// Copyright 2021 Peng Huang <shawn.p.huang@gmail.com>
// This file is part of Wallet-core-python.
//
// Wallet-core-python is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Wallet-core-python is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Wallet-core-python.  If not, see <https://www.gnu.org/licenses/>.
//
// NOTE: this is a GENERATED FILE, changes made here WILL BE LOST.

#include "generated/EthereumAbiFunction.h"

#include "Bool.h"
#include "Data.h"
#include "Number.h"
#include "String.h"

struct PyEthereumAbiFunctionObject {
  PyObject_HEAD;
  TWEthereumAbiFunction* value;
};

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
    Py_RETURN_NONE;

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

static void PyEthereumAbiFunction_dealloc(PyEthereumAbiFunctionObject* self) {
  if (self->value) {
    TWEthereumAbiFunctionDelete(self->value);
  }
  Py_TYPE(self)->tp_free(self);
}

// method function for GetType
static const char PyEthereumAbiFunctionGetType_doc[] =
    "TWString* TWEthereumAbiFunctionGetType(struct TWEthereumAbiFunction* fn)";
static PyObject* PyEthereumAbiFunctionGetType(PyEthereumAbiFunctionObject* self,
                                              PyObject* const* args,
                                              Py_ssize_t nargs) {
  if (nargs != 0) {
    PyErr_Format(PyExc_TypeError, "Expect 0 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  TWStringPtr result(TWEthereumAbiFunctionGetType(self->value));
  return PyUnicode_FromTWString(result);
}

// method function for AddParamUInt8
static const char PyEthereumAbiFunctionAddParamUInt8_doc[] =
    "int32_t TWEthereumAbiFunctionAddParamUInt8(struct TWEthereumAbiFunction* "
    "fn, uint8_t val, bool isOutput)";
static PyObject* PyEthereumAbiFunctionAddParamUInt8(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  auto checked_arg0 = PyLongArg_ToNumber<uint8_t>(args[0], 0, "uint8_t");
  if (!checked_arg0)
    return nullptr;
  const auto& arg0 = checked_arg0.value();

  if (!PyBool_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bool");
    return nullptr;
  }
  auto arg1 = PyBool_IsTrue(args[1]);

  int32_t result = TWEthereumAbiFunctionAddParamUInt8(self->value, arg0, arg1);
  return PyLong_FromLong(result);
}

// method function for AddParamUInt16
static const char PyEthereumAbiFunctionAddParamUInt16_doc[] =
    "int32_t TWEthereumAbiFunctionAddParamUInt16(struct TWEthereumAbiFunction* "
    "fn, uint16_t val, bool isOutput)";
static PyObject* PyEthereumAbiFunctionAddParamUInt16(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  auto checked_arg0 = PyLongArg_ToNumber<uint16_t>(args[0], 0, "uint16_t");
  if (!checked_arg0)
    return nullptr;
  const auto& arg0 = checked_arg0.value();

  if (!PyBool_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bool");
    return nullptr;
  }
  auto arg1 = PyBool_IsTrue(args[1]);

  int32_t result = TWEthereumAbiFunctionAddParamUInt16(self->value, arg0, arg1);
  return PyLong_FromLong(result);
}

// method function for AddParamUInt32
static const char PyEthereumAbiFunctionAddParamUInt32_doc[] =
    "int32_t TWEthereumAbiFunctionAddParamUInt32(struct TWEthereumAbiFunction* "
    "fn, uint32_t val, bool isOutput)";
static PyObject* PyEthereumAbiFunctionAddParamUInt32(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  auto checked_arg0 = PyLongArg_ToNumber<uint32_t>(args[0], 0, "uint32_t");
  if (!checked_arg0)
    return nullptr;
  const auto& arg0 = checked_arg0.value();

  if (!PyBool_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bool");
    return nullptr;
  }
  auto arg1 = PyBool_IsTrue(args[1]);

  int32_t result = TWEthereumAbiFunctionAddParamUInt32(self->value, arg0, arg1);
  return PyLong_FromLong(result);
}

// method function for AddParamUInt64
static const char PyEthereumAbiFunctionAddParamUInt64_doc[] =
    "int32_t TWEthereumAbiFunctionAddParamUInt64(struct TWEthereumAbiFunction* "
    "fn, uint64_t val, bool isOutput)";
static PyObject* PyEthereumAbiFunctionAddParamUInt64(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  auto checked_arg0 = PyLongArg_ToNumber<uint64_t>(args[0], 0, "uint64_t");
  if (!checked_arg0)
    return nullptr;
  const auto& arg0 = checked_arg0.value();

  if (!PyBool_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bool");
    return nullptr;
  }
  auto arg1 = PyBool_IsTrue(args[1]);

  int32_t result = TWEthereumAbiFunctionAddParamUInt64(self->value, arg0, arg1);
  return PyLong_FromLong(result);
}

// method function for AddParamUInt256
static const char PyEthereumAbiFunctionAddParamUInt256_doc[] =
    "int32_t TWEthereumAbiFunctionAddParamUInt256(struct "
    "TWEthereumAbiFunction* fn, TWData* val, bool isOutput)";
static PyObject* PyEthereumAbiFunctionAddParamUInt256(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  if (!PyBytes_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Bytes");
    return nullptr;
  }
  auto arg0 = PyBytes_GetTWData(args[0]);

  if (!PyBool_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bool");
    return nullptr;
  }
  auto arg1 = PyBool_IsTrue(args[1]);

  int32_t result =
      TWEthereumAbiFunctionAddParamUInt256(self->value, arg0.get(), arg1);
  return PyLong_FromLong(result);
}

// method function for AddParamUIntN
static const char PyEthereumAbiFunctionAddParamUIntN_doc[] =
    "int32_t TWEthereumAbiFunctionAddParamUIntN(struct TWEthereumAbiFunction* "
    "fn, int32_t bits, TWData* val, bool isOutput)";
static PyObject* PyEthereumAbiFunctionAddParamUIntN(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 3) {
    PyErr_Format(PyExc_TypeError, "Expect 3 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  auto checked_arg0 = PyLongArg_ToNumber<int32_t>(args[0], 0, "int32_t");
  if (!checked_arg0)
    return nullptr;
  const auto& arg0 = checked_arg0.value();

  if (!PyBytes_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bytes");
    return nullptr;
  }
  auto arg1 = PyBytes_GetTWData(args[1]);

  if (!PyBool_Check(args[2])) {
    PyErr_SetString(PyExc_TypeError, "The arg 2 is not in type Bool");
    return nullptr;
  }
  auto arg2 = PyBool_IsTrue(args[2]);

  int32_t result =
      TWEthereumAbiFunctionAddParamUIntN(self->value, arg0, arg1.get(), arg2);
  return PyLong_FromLong(result);
}

// method function for AddParamInt8
static const char PyEthereumAbiFunctionAddParamInt8_doc[] =
    "int32_t TWEthereumAbiFunctionAddParamInt8(struct TWEthereumAbiFunction* "
    "fn, int8_t val, bool isOutput)";
static PyObject* PyEthereumAbiFunctionAddParamInt8(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  auto checked_arg0 = PyLongArg_ToNumber<int8_t>(args[0], 0, "int8_t");
  if (!checked_arg0)
    return nullptr;
  const auto& arg0 = checked_arg0.value();

  if (!PyBool_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bool");
    return nullptr;
  }
  auto arg1 = PyBool_IsTrue(args[1]);

  int32_t result = TWEthereumAbiFunctionAddParamInt8(self->value, arg0, arg1);
  return PyLong_FromLong(result);
}

// method function for AddParamInt16
static const char PyEthereumAbiFunctionAddParamInt16_doc[] =
    "int32_t TWEthereumAbiFunctionAddParamInt16(struct TWEthereumAbiFunction* "
    "fn, int16_t val, bool isOutput)";
static PyObject* PyEthereumAbiFunctionAddParamInt16(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  auto checked_arg0 = PyLongArg_ToNumber<int16_t>(args[0], 0, "int16_t");
  if (!checked_arg0)
    return nullptr;
  const auto& arg0 = checked_arg0.value();

  if (!PyBool_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bool");
    return nullptr;
  }
  auto arg1 = PyBool_IsTrue(args[1]);

  int32_t result = TWEthereumAbiFunctionAddParamInt16(self->value, arg0, arg1);
  return PyLong_FromLong(result);
}

// method function for AddParamInt32
static const char PyEthereumAbiFunctionAddParamInt32_doc[] =
    "int32_t TWEthereumAbiFunctionAddParamInt32(struct TWEthereumAbiFunction* "
    "fn, int32_t val, bool isOutput)";
static PyObject* PyEthereumAbiFunctionAddParamInt32(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  auto checked_arg0 = PyLongArg_ToNumber<int32_t>(args[0], 0, "int32_t");
  if (!checked_arg0)
    return nullptr;
  const auto& arg0 = checked_arg0.value();

  if (!PyBool_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bool");
    return nullptr;
  }
  auto arg1 = PyBool_IsTrue(args[1]);

  int32_t result = TWEthereumAbiFunctionAddParamInt32(self->value, arg0, arg1);
  return PyLong_FromLong(result);
}

// method function for AddParamInt64
static const char PyEthereumAbiFunctionAddParamInt64_doc[] =
    "int32_t TWEthereumAbiFunctionAddParamInt64(struct TWEthereumAbiFunction* "
    "fn, int64_t val, bool isOutput)";
static PyObject* PyEthereumAbiFunctionAddParamInt64(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  auto checked_arg0 = PyLongArg_ToNumber<int64_t>(args[0], 0, "int64_t");
  if (!checked_arg0)
    return nullptr;
  const auto& arg0 = checked_arg0.value();

  if (!PyBool_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bool");
    return nullptr;
  }
  auto arg1 = PyBool_IsTrue(args[1]);

  int32_t result = TWEthereumAbiFunctionAddParamInt64(self->value, arg0, arg1);
  return PyLong_FromLong(result);
}

// method function for AddParamInt256
static const char PyEthereumAbiFunctionAddParamInt256_doc[] =
    "int32_t TWEthereumAbiFunctionAddParamInt256(struct TWEthereumAbiFunction* "
    "fn, TWData* val, bool isOutput)";
static PyObject* PyEthereumAbiFunctionAddParamInt256(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  if (!PyBytes_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Bytes");
    return nullptr;
  }
  auto arg0 = PyBytes_GetTWData(args[0]);

  if (!PyBool_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bool");
    return nullptr;
  }
  auto arg1 = PyBool_IsTrue(args[1]);

  int32_t result =
      TWEthereumAbiFunctionAddParamInt256(self->value, arg0.get(), arg1);
  return PyLong_FromLong(result);
}

// method function for AddParamIntN
static const char PyEthereumAbiFunctionAddParamIntN_doc[] =
    "int32_t TWEthereumAbiFunctionAddParamIntN(struct TWEthereumAbiFunction* "
    "fn, int32_t bits, TWData* val, bool isOutput)";
static PyObject* PyEthereumAbiFunctionAddParamIntN(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 3) {
    PyErr_Format(PyExc_TypeError, "Expect 3 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  auto checked_arg0 = PyLongArg_ToNumber<int32_t>(args[0], 0, "int32_t");
  if (!checked_arg0)
    return nullptr;
  const auto& arg0 = checked_arg0.value();

  if (!PyBytes_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bytes");
    return nullptr;
  }
  auto arg1 = PyBytes_GetTWData(args[1]);

  if (!PyBool_Check(args[2])) {
    PyErr_SetString(PyExc_TypeError, "The arg 2 is not in type Bool");
    return nullptr;
  }
  auto arg2 = PyBool_IsTrue(args[2]);

  int32_t result =
      TWEthereumAbiFunctionAddParamIntN(self->value, arg0, arg1.get(), arg2);
  return PyLong_FromLong(result);
}

// method function for AddParamBool
static const char PyEthereumAbiFunctionAddParamBool_doc[] =
    "int32_t TWEthereumAbiFunctionAddParamBool(struct TWEthereumAbiFunction* "
    "fn, bool val, bool isOutput)";
static PyObject* PyEthereumAbiFunctionAddParamBool(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 args, but %d args are passed in.",
                 nargs);
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

  int32_t result = TWEthereumAbiFunctionAddParamBool(self->value, arg0, arg1);
  return PyLong_FromLong(result);
}

// method function for AddParamString
static const char PyEthereumAbiFunctionAddParamString_doc[] =
    "int32_t TWEthereumAbiFunctionAddParamString(struct TWEthereumAbiFunction* "
    "fn, TWString* val, bool isOutput)";
static PyObject* PyEthereumAbiFunctionAddParamString(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 args, but %d args are passed in.",
                 nargs);
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

  int32_t result =
      TWEthereumAbiFunctionAddParamString(self->value, arg0.get(), arg1);
  return PyLong_FromLong(result);
}

// method function for AddParamAddress
static const char PyEthereumAbiFunctionAddParamAddress_doc[] =
    "int32_t TWEthereumAbiFunctionAddParamAddress(struct "
    "TWEthereumAbiFunction* fn, TWData* val, bool isOutput)";
static PyObject* PyEthereumAbiFunctionAddParamAddress(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  if (!PyBytes_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Bytes");
    return nullptr;
  }
  auto arg0 = PyBytes_GetTWData(args[0]);

  if (!PyBool_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bool");
    return nullptr;
  }
  auto arg1 = PyBool_IsTrue(args[1]);

  int32_t result =
      TWEthereumAbiFunctionAddParamAddress(self->value, arg0.get(), arg1);
  return PyLong_FromLong(result);
}

// method function for AddParamBytes
static const char PyEthereumAbiFunctionAddParamBytes_doc[] =
    "int32_t TWEthereumAbiFunctionAddParamBytes(struct TWEthereumAbiFunction* "
    "fn, TWData* val, bool isOutput)";
static PyObject* PyEthereumAbiFunctionAddParamBytes(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  if (!PyBytes_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Bytes");
    return nullptr;
  }
  auto arg0 = PyBytes_GetTWData(args[0]);

  if (!PyBool_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bool");
    return nullptr;
  }
  auto arg1 = PyBool_IsTrue(args[1]);

  int32_t result =
      TWEthereumAbiFunctionAddParamBytes(self->value, arg0.get(), arg1);
  return PyLong_FromLong(result);
}

// method function for AddParamBytesFix
static const char PyEthereumAbiFunctionAddParamBytesFix_doc[] =
    "int32_t TWEthereumAbiFunctionAddParamBytesFix(struct "
    "TWEthereumAbiFunction* fn, size_t size, TWData* val, bool isOutput)";
static PyObject* PyEthereumAbiFunctionAddParamBytesFix(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 3) {
    PyErr_Format(PyExc_TypeError, "Expect 3 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  auto checked_arg0 = PyLongArg_ToNumber<size_t>(args[0], 0, "size_t");
  if (!checked_arg0)
    return nullptr;
  const auto& arg0 = checked_arg0.value();

  if (!PyBytes_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bytes");
    return nullptr;
  }
  auto arg1 = PyBytes_GetTWData(args[1]);

  if (!PyBool_Check(args[2])) {
    PyErr_SetString(PyExc_TypeError, "The arg 2 is not in type Bool");
    return nullptr;
  }
  auto arg2 = PyBool_IsTrue(args[2]);

  int32_t result = TWEthereumAbiFunctionAddParamBytesFix(self->value, arg0,
                                                         arg1.get(), arg2);
  return PyLong_FromLong(result);
}

// method function for AddParamArray
static const char PyEthereumAbiFunctionAddParamArray_doc[] =
    "int32_t TWEthereumAbiFunctionAddParamArray(struct TWEthereumAbiFunction* "
    "fn, bool isOutput)";
static PyObject* PyEthereumAbiFunctionAddParamArray(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  if (!PyBool_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Bool");
    return nullptr;
  }
  auto arg0 = PyBool_IsTrue(args[0]);

  int32_t result = TWEthereumAbiFunctionAddParamArray(self->value, arg0);
  return PyLong_FromLong(result);
}

// method function for GetParamUInt8
static const char PyEthereumAbiFunctionGetParamUInt8_doc[] =
    "uint8_t TWEthereumAbiFunctionGetParamUInt8(struct TWEthereumAbiFunction* "
    "fn, int32_t idx, bool isOutput)";
static PyObject* PyEthereumAbiFunctionGetParamUInt8(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  auto checked_arg0 = PyLongArg_ToNumber<int32_t>(args[0], 0, "int32_t");
  if (!checked_arg0)
    return nullptr;
  const auto& arg0 = checked_arg0.value();

  if (!PyBool_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bool");
    return nullptr;
  }
  auto arg1 = PyBool_IsTrue(args[1]);

  uint8_t result = TWEthereumAbiFunctionGetParamUInt8(self->value, arg0, arg1);
  return PyLong_FromLong(result);
}

// method function for GetParamUInt64
static const char PyEthereumAbiFunctionGetParamUInt64_doc[] =
    "uint64_t TWEthereumAbiFunctionGetParamUInt64(struct "
    "TWEthereumAbiFunction* fn, int32_t idx, bool isOutput)";
static PyObject* PyEthereumAbiFunctionGetParamUInt64(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  auto checked_arg0 = PyLongArg_ToNumber<int32_t>(args[0], 0, "int32_t");
  if (!checked_arg0)
    return nullptr;
  const auto& arg0 = checked_arg0.value();

  if (!PyBool_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bool");
    return nullptr;
  }
  auto arg1 = PyBool_IsTrue(args[1]);

  uint64_t result =
      TWEthereumAbiFunctionGetParamUInt64(self->value, arg0, arg1);
  return PyLong_FromLong(result);
}

// method function for GetParamUInt256
static const char PyEthereumAbiFunctionGetParamUInt256_doc[] =
    "TWData* TWEthereumAbiFunctionGetParamUInt256(struct "
    "TWEthereumAbiFunction* fn, int32_t idx, bool isOutput)";
static PyObject* PyEthereumAbiFunctionGetParamUInt256(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  auto checked_arg0 = PyLongArg_ToNumber<int32_t>(args[0], 0, "int32_t");
  if (!checked_arg0)
    return nullptr;
  const auto& arg0 = checked_arg0.value();

  if (!PyBool_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bool");
    return nullptr;
  }
  auto arg1 = PyBool_IsTrue(args[1]);

  TWDataPtr result(
      TWEthereumAbiFunctionGetParamUInt256(self->value, arg0, arg1));
  return PyBytes_FromTWData(result);
}

// method function for GetParamBool
static const char PyEthereumAbiFunctionGetParamBool_doc[] =
    "bool TWEthereumAbiFunctionGetParamBool(struct TWEthereumAbiFunction* fn, "
    "int32_t idx, bool isOutput)";
static PyObject* PyEthereumAbiFunctionGetParamBool(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  auto checked_arg0 = PyLongArg_ToNumber<int32_t>(args[0], 0, "int32_t");
  if (!checked_arg0)
    return nullptr;
  const auto& arg0 = checked_arg0.value();

  if (!PyBool_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bool");
    return nullptr;
  }
  auto arg1 = PyBool_IsTrue(args[1]);

  bool result = TWEthereumAbiFunctionGetParamBool(self->value, arg0, arg1);
  return PyBool_FromLong(result);
}

// method function for GetParamString
static const char PyEthereumAbiFunctionGetParamString_doc[] =
    "TWString* TWEthereumAbiFunctionGetParamString(struct "
    "TWEthereumAbiFunction* fn, int32_t idx, bool isOutput)";
static PyObject* PyEthereumAbiFunctionGetParamString(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  auto checked_arg0 = PyLongArg_ToNumber<int32_t>(args[0], 0, "int32_t");
  if (!checked_arg0)
    return nullptr;
  const auto& arg0 = checked_arg0.value();

  if (!PyBool_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bool");
    return nullptr;
  }
  auto arg1 = PyBool_IsTrue(args[1]);

  TWStringPtr result(
      TWEthereumAbiFunctionGetParamString(self->value, arg0, arg1));
  return PyUnicode_FromTWString(result);
}

// method function for GetParamAddress
static const char PyEthereumAbiFunctionGetParamAddress_doc[] =
    "TWData* TWEthereumAbiFunctionGetParamAddress(struct "
    "TWEthereumAbiFunction* fn, int32_t idx, bool isOutput)";
static PyObject* PyEthereumAbiFunctionGetParamAddress(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  auto checked_arg0 = PyLongArg_ToNumber<int32_t>(args[0], 0, "int32_t");
  if (!checked_arg0)
    return nullptr;
  const auto& arg0 = checked_arg0.value();

  if (!PyBool_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bool");
    return nullptr;
  }
  auto arg1 = PyBool_IsTrue(args[1]);

  TWDataPtr result(
      TWEthereumAbiFunctionGetParamAddress(self->value, arg0, arg1));
  return PyBytes_FromTWData(result);
}

// method function for AddInArrayParamUInt8
static const char PyEthereumAbiFunctionAddInArrayParamUInt8_doc[] =
    "int32_t TWEthereumAbiFunctionAddInArrayParamUInt8(struct "
    "TWEthereumAbiFunction* fn, int32_t arrayIdx, uint8_t val)";
static PyObject* PyEthereumAbiFunctionAddInArrayParamUInt8(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  auto checked_arg0 = PyLongArg_ToNumber<int32_t>(args[0], 0, "int32_t");
  if (!checked_arg0)
    return nullptr;
  const auto& arg0 = checked_arg0.value();

  auto checked_arg1 = PyLongArg_ToNumber<uint8_t>(args[1], 1, "uint8_t");
  if (!checked_arg1)
    return nullptr;
  const auto& arg1 = checked_arg1.value();

  int32_t result =
      TWEthereumAbiFunctionAddInArrayParamUInt8(self->value, arg0, arg1);
  return PyLong_FromLong(result);
}

// method function for AddInArrayParamUInt16
static const char PyEthereumAbiFunctionAddInArrayParamUInt16_doc[] =
    "int32_t TWEthereumAbiFunctionAddInArrayParamUInt16(struct "
    "TWEthereumAbiFunction* fn, int32_t arrayIdx, uint16_t val)";
static PyObject* PyEthereumAbiFunctionAddInArrayParamUInt16(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  auto checked_arg0 = PyLongArg_ToNumber<int32_t>(args[0], 0, "int32_t");
  if (!checked_arg0)
    return nullptr;
  const auto& arg0 = checked_arg0.value();

  auto checked_arg1 = PyLongArg_ToNumber<uint16_t>(args[1], 1, "uint16_t");
  if (!checked_arg1)
    return nullptr;
  const auto& arg1 = checked_arg1.value();

  int32_t result =
      TWEthereumAbiFunctionAddInArrayParamUInt16(self->value, arg0, arg1);
  return PyLong_FromLong(result);
}

// method function for AddInArrayParamUInt32
static const char PyEthereumAbiFunctionAddInArrayParamUInt32_doc[] =
    "int32_t TWEthereumAbiFunctionAddInArrayParamUInt32(struct "
    "TWEthereumAbiFunction* fn, int32_t arrayIdx, uint32_t val)";
static PyObject* PyEthereumAbiFunctionAddInArrayParamUInt32(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  auto checked_arg0 = PyLongArg_ToNumber<int32_t>(args[0], 0, "int32_t");
  if (!checked_arg0)
    return nullptr;
  const auto& arg0 = checked_arg0.value();

  auto checked_arg1 = PyLongArg_ToNumber<uint32_t>(args[1], 1, "uint32_t");
  if (!checked_arg1)
    return nullptr;
  const auto& arg1 = checked_arg1.value();

  int32_t result =
      TWEthereumAbiFunctionAddInArrayParamUInt32(self->value, arg0, arg1);
  return PyLong_FromLong(result);
}

// method function for AddInArrayParamUInt64
static const char PyEthereumAbiFunctionAddInArrayParamUInt64_doc[] =
    "int32_t TWEthereumAbiFunctionAddInArrayParamUInt64(struct "
    "TWEthereumAbiFunction* fn, int32_t arrayIdx, uint64_t val)";
static PyObject* PyEthereumAbiFunctionAddInArrayParamUInt64(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  auto checked_arg0 = PyLongArg_ToNumber<int32_t>(args[0], 0, "int32_t");
  if (!checked_arg0)
    return nullptr;
  const auto& arg0 = checked_arg0.value();

  auto checked_arg1 = PyLongArg_ToNumber<uint64_t>(args[1], 1, "uint64_t");
  if (!checked_arg1)
    return nullptr;
  const auto& arg1 = checked_arg1.value();

  int32_t result =
      TWEthereumAbiFunctionAddInArrayParamUInt64(self->value, arg0, arg1);
  return PyLong_FromLong(result);
}

// method function for AddInArrayParamUInt256
static const char PyEthereumAbiFunctionAddInArrayParamUInt256_doc[] =
    "int32_t TWEthereumAbiFunctionAddInArrayParamUInt256(struct "
    "TWEthereumAbiFunction* fn, int32_t arrayIdx, TWData* val)";
static PyObject* PyEthereumAbiFunctionAddInArrayParamUInt256(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  auto checked_arg0 = PyLongArg_ToNumber<int32_t>(args[0], 0, "int32_t");
  if (!checked_arg0)
    return nullptr;
  const auto& arg0 = checked_arg0.value();

  if (!PyBytes_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bytes");
    return nullptr;
  }
  auto arg1 = PyBytes_GetTWData(args[1]);

  int32_t result = TWEthereumAbiFunctionAddInArrayParamUInt256(
      self->value, arg0, arg1.get());
  return PyLong_FromLong(result);
}

// method function for AddInArrayParamUIntN
static const char PyEthereumAbiFunctionAddInArrayParamUIntN_doc[] =
    "int32_t TWEthereumAbiFunctionAddInArrayParamUIntN(struct "
    "TWEthereumAbiFunction* fn, int32_t arrayIdx, int32_t bits, TWData* val)";
static PyObject* PyEthereumAbiFunctionAddInArrayParamUIntN(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 3) {
    PyErr_Format(PyExc_TypeError, "Expect 3 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  auto checked_arg0 = PyLongArg_ToNumber<int32_t>(args[0], 0, "int32_t");
  if (!checked_arg0)
    return nullptr;
  const auto& arg0 = checked_arg0.value();

  auto checked_arg1 = PyLongArg_ToNumber<int32_t>(args[1], 1, "int32_t");
  if (!checked_arg1)
    return nullptr;
  const auto& arg1 = checked_arg1.value();

  if (!PyBytes_Check(args[2])) {
    PyErr_SetString(PyExc_TypeError, "The arg 2 is not in type Bytes");
    return nullptr;
  }
  auto arg2 = PyBytes_GetTWData(args[2]);

  int32_t result = TWEthereumAbiFunctionAddInArrayParamUIntN(self->value, arg0,
                                                             arg1, arg2.get());
  return PyLong_FromLong(result);
}

// method function for AddInArrayParamInt8
static const char PyEthereumAbiFunctionAddInArrayParamInt8_doc[] =
    "int32_t TWEthereumAbiFunctionAddInArrayParamInt8(struct "
    "TWEthereumAbiFunction* fn, int32_t arrayIdx, int8_t val)";
static PyObject* PyEthereumAbiFunctionAddInArrayParamInt8(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  auto checked_arg0 = PyLongArg_ToNumber<int32_t>(args[0], 0, "int32_t");
  if (!checked_arg0)
    return nullptr;
  const auto& arg0 = checked_arg0.value();

  auto checked_arg1 = PyLongArg_ToNumber<int8_t>(args[1], 1, "int8_t");
  if (!checked_arg1)
    return nullptr;
  const auto& arg1 = checked_arg1.value();

  int32_t result =
      TWEthereumAbiFunctionAddInArrayParamInt8(self->value, arg0, arg1);
  return PyLong_FromLong(result);
}

// method function for AddInArrayParamInt16
static const char PyEthereumAbiFunctionAddInArrayParamInt16_doc[] =
    "int32_t TWEthereumAbiFunctionAddInArrayParamInt16(struct "
    "TWEthereumAbiFunction* fn, int32_t arrayIdx, int16_t val)";
static PyObject* PyEthereumAbiFunctionAddInArrayParamInt16(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  auto checked_arg0 = PyLongArg_ToNumber<int32_t>(args[0], 0, "int32_t");
  if (!checked_arg0)
    return nullptr;
  const auto& arg0 = checked_arg0.value();

  auto checked_arg1 = PyLongArg_ToNumber<int16_t>(args[1], 1, "int16_t");
  if (!checked_arg1)
    return nullptr;
  const auto& arg1 = checked_arg1.value();

  int32_t result =
      TWEthereumAbiFunctionAddInArrayParamInt16(self->value, arg0, arg1);
  return PyLong_FromLong(result);
}

// method function for AddInArrayParamInt32
static const char PyEthereumAbiFunctionAddInArrayParamInt32_doc[] =
    "int32_t TWEthereumAbiFunctionAddInArrayParamInt32(struct "
    "TWEthereumAbiFunction* fn, int32_t arrayIdx, int32_t val)";
static PyObject* PyEthereumAbiFunctionAddInArrayParamInt32(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  auto checked_arg0 = PyLongArg_ToNumber<int32_t>(args[0], 0, "int32_t");
  if (!checked_arg0)
    return nullptr;
  const auto& arg0 = checked_arg0.value();

  auto checked_arg1 = PyLongArg_ToNumber<int32_t>(args[1], 1, "int32_t");
  if (!checked_arg1)
    return nullptr;
  const auto& arg1 = checked_arg1.value();

  int32_t result =
      TWEthereumAbiFunctionAddInArrayParamInt32(self->value, arg0, arg1);
  return PyLong_FromLong(result);
}

// method function for AddInArrayParamInt64
static const char PyEthereumAbiFunctionAddInArrayParamInt64_doc[] =
    "int32_t TWEthereumAbiFunctionAddInArrayParamInt64(struct "
    "TWEthereumAbiFunction* fn, int32_t arrayIdx, int64_t val)";
static PyObject* PyEthereumAbiFunctionAddInArrayParamInt64(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  auto checked_arg0 = PyLongArg_ToNumber<int32_t>(args[0], 0, "int32_t");
  if (!checked_arg0)
    return nullptr;
  const auto& arg0 = checked_arg0.value();

  auto checked_arg1 = PyLongArg_ToNumber<int64_t>(args[1], 1, "int64_t");
  if (!checked_arg1)
    return nullptr;
  const auto& arg1 = checked_arg1.value();

  int32_t result =
      TWEthereumAbiFunctionAddInArrayParamInt64(self->value, arg0, arg1);
  return PyLong_FromLong(result);
}

// method function for AddInArrayParamInt256
static const char PyEthereumAbiFunctionAddInArrayParamInt256_doc[] =
    "int32_t TWEthereumAbiFunctionAddInArrayParamInt256(struct "
    "TWEthereumAbiFunction* fn, int32_t arrayIdx, TWData* val)";
static PyObject* PyEthereumAbiFunctionAddInArrayParamInt256(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  auto checked_arg0 = PyLongArg_ToNumber<int32_t>(args[0], 0, "int32_t");
  if (!checked_arg0)
    return nullptr;
  const auto& arg0 = checked_arg0.value();

  if (!PyBytes_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bytes");
    return nullptr;
  }
  auto arg1 = PyBytes_GetTWData(args[1]);

  int32_t result =
      TWEthereumAbiFunctionAddInArrayParamInt256(self->value, arg0, arg1.get());
  return PyLong_FromLong(result);
}

// method function for AddInArrayParamIntN
static const char PyEthereumAbiFunctionAddInArrayParamIntN_doc[] =
    "int32_t TWEthereumAbiFunctionAddInArrayParamIntN(struct "
    "TWEthereumAbiFunction* fn, int32_t arrayIdx, int32_t bits, TWData* val)";
static PyObject* PyEthereumAbiFunctionAddInArrayParamIntN(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 3) {
    PyErr_Format(PyExc_TypeError, "Expect 3 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  auto checked_arg0 = PyLongArg_ToNumber<int32_t>(args[0], 0, "int32_t");
  if (!checked_arg0)
    return nullptr;
  const auto& arg0 = checked_arg0.value();

  auto checked_arg1 = PyLongArg_ToNumber<int32_t>(args[1], 1, "int32_t");
  if (!checked_arg1)
    return nullptr;
  const auto& arg1 = checked_arg1.value();

  if (!PyBytes_Check(args[2])) {
    PyErr_SetString(PyExc_TypeError, "The arg 2 is not in type Bytes");
    return nullptr;
  }
  auto arg2 = PyBytes_GetTWData(args[2]);

  int32_t result = TWEthereumAbiFunctionAddInArrayParamIntN(self->value, arg0,
                                                            arg1, arg2.get());
  return PyLong_FromLong(result);
}

// method function for AddInArrayParamBool
static const char PyEthereumAbiFunctionAddInArrayParamBool_doc[] =
    "int32_t TWEthereumAbiFunctionAddInArrayParamBool(struct "
    "TWEthereumAbiFunction* fn, int32_t arrayIdx, bool val)";
static PyObject* PyEthereumAbiFunctionAddInArrayParamBool(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  auto checked_arg0 = PyLongArg_ToNumber<int32_t>(args[0], 0, "int32_t");
  if (!checked_arg0)
    return nullptr;
  const auto& arg0 = checked_arg0.value();

  if (!PyBool_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bool");
    return nullptr;
  }
  auto arg1 = PyBool_IsTrue(args[1]);

  int32_t result =
      TWEthereumAbiFunctionAddInArrayParamBool(self->value, arg0, arg1);
  return PyLong_FromLong(result);
}

// method function for AddInArrayParamString
static const char PyEthereumAbiFunctionAddInArrayParamString_doc[] =
    "int32_t TWEthereumAbiFunctionAddInArrayParamString(struct "
    "TWEthereumAbiFunction* fn, int32_t arrayIdx, TWString* val)";
static PyObject* PyEthereumAbiFunctionAddInArrayParamString(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  auto checked_arg0 = PyLongArg_ToNumber<int32_t>(args[0], 0, "int32_t");
  if (!checked_arg0)
    return nullptr;
  const auto& arg0 = checked_arg0.value();

  if (!PyUnicode_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Unicode");
    return nullptr;
  }
  auto arg1 = PyUnicode_GetTWString(args[1]);

  int32_t result =
      TWEthereumAbiFunctionAddInArrayParamString(self->value, arg0, arg1.get());
  return PyLong_FromLong(result);
}

// method function for AddInArrayParamAddress
static const char PyEthereumAbiFunctionAddInArrayParamAddress_doc[] =
    "int32_t TWEthereumAbiFunctionAddInArrayParamAddress(struct "
    "TWEthereumAbiFunction* fn, int32_t arrayIdx, TWData* val)";
static PyObject* PyEthereumAbiFunctionAddInArrayParamAddress(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  auto checked_arg0 = PyLongArg_ToNumber<int32_t>(args[0], 0, "int32_t");
  if (!checked_arg0)
    return nullptr;
  const auto& arg0 = checked_arg0.value();

  if (!PyBytes_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bytes");
    return nullptr;
  }
  auto arg1 = PyBytes_GetTWData(args[1]);

  int32_t result = TWEthereumAbiFunctionAddInArrayParamAddress(
      self->value, arg0, arg1.get());
  return PyLong_FromLong(result);
}

// method function for AddInArrayParamBytes
static const char PyEthereumAbiFunctionAddInArrayParamBytes_doc[] =
    "int32_t TWEthereumAbiFunctionAddInArrayParamBytes(struct "
    "TWEthereumAbiFunction* fn, int32_t arrayIdx, TWData* val)";
static PyObject* PyEthereumAbiFunctionAddInArrayParamBytes(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  auto checked_arg0 = PyLongArg_ToNumber<int32_t>(args[0], 0, "int32_t");
  if (!checked_arg0)
    return nullptr;
  const auto& arg0 = checked_arg0.value();

  if (!PyBytes_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bytes");
    return nullptr;
  }
  auto arg1 = PyBytes_GetTWData(args[1]);

  int32_t result =
      TWEthereumAbiFunctionAddInArrayParamBytes(self->value, arg0, arg1.get());
  return PyLong_FromLong(result);
}

// method function for AddInArrayParamBytesFix
static const char PyEthereumAbiFunctionAddInArrayParamBytesFix_doc[] =
    "int32_t TWEthereumAbiFunctionAddInArrayParamBytesFix(struct "
    "TWEthereumAbiFunction* fn, int32_t arrayIdx, size_t size, TWData* val)";
static PyObject* PyEthereumAbiFunctionAddInArrayParamBytesFix(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 3) {
    PyErr_Format(PyExc_TypeError, "Expect 3 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  auto checked_arg0 = PyLongArg_ToNumber<int32_t>(args[0], 0, "int32_t");
  if (!checked_arg0)
    return nullptr;
  const auto& arg0 = checked_arg0.value();

  auto checked_arg1 = PyLongArg_ToNumber<size_t>(args[1], 1, "size_t");
  if (!checked_arg1)
    return nullptr;
  const auto& arg1 = checked_arg1.value();

  if (!PyBytes_Check(args[2])) {
    PyErr_SetString(PyExc_TypeError, "The arg 2 is not in type Bytes");
    return nullptr;
  }
  auto arg2 = PyBytes_GetTWData(args[2]);

  int32_t result = TWEthereumAbiFunctionAddInArrayParamBytesFix(
      self->value, arg0, arg1, arg2.get());
  return PyLong_FromLong(result);
}

// static method function for CreateWithString
static const char PyEthereumAbiFunctionCreateWithString_doc[] =
    "struct TWEthereumAbiFunction* "
    "TWEthereumAbiFunctionCreateWithString(TWString* name)";
static PyObject* PyEthereumAbiFunctionCreateWithString(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 args, but %d args are passed in.",
                 nargs);
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

// properties

static const PyGetSetDef get_set_defs[] = {{}};

static const PyMethodDef method_defs[] = {
    {"get_type", (PyCFunction)PyEthereumAbiFunctionGetType, METH_FASTCALL,
     PyEthereumAbiFunctionGetType_doc},
    {"add_param_uint8", (PyCFunction)PyEthereumAbiFunctionAddParamUInt8,
     METH_FASTCALL, PyEthereumAbiFunctionAddParamUInt8_doc},
    {"add_param_uint16", (PyCFunction)PyEthereumAbiFunctionAddParamUInt16,
     METH_FASTCALL, PyEthereumAbiFunctionAddParamUInt16_doc},
    {"add_param_uint32", (PyCFunction)PyEthereumAbiFunctionAddParamUInt32,
     METH_FASTCALL, PyEthereumAbiFunctionAddParamUInt32_doc},
    {"add_param_uint64", (PyCFunction)PyEthereumAbiFunctionAddParamUInt64,
     METH_FASTCALL, PyEthereumAbiFunctionAddParamUInt64_doc},
    {"add_param_uint256", (PyCFunction)PyEthereumAbiFunctionAddParamUInt256,
     METH_FASTCALL, PyEthereumAbiFunctionAddParamUInt256_doc},
    {"add_param_uint_n", (PyCFunction)PyEthereumAbiFunctionAddParamUIntN,
     METH_FASTCALL, PyEthereumAbiFunctionAddParamUIntN_doc},
    {"add_param_int8", (PyCFunction)PyEthereumAbiFunctionAddParamInt8,
     METH_FASTCALL, PyEthereumAbiFunctionAddParamInt8_doc},
    {"add_param_int16", (PyCFunction)PyEthereumAbiFunctionAddParamInt16,
     METH_FASTCALL, PyEthereumAbiFunctionAddParamInt16_doc},
    {"add_param_int32", (PyCFunction)PyEthereumAbiFunctionAddParamInt32,
     METH_FASTCALL, PyEthereumAbiFunctionAddParamInt32_doc},
    {"add_param_int64", (PyCFunction)PyEthereumAbiFunctionAddParamInt64,
     METH_FASTCALL, PyEthereumAbiFunctionAddParamInt64_doc},
    {"add_param_int256", (PyCFunction)PyEthereumAbiFunctionAddParamInt256,
     METH_FASTCALL, PyEthereumAbiFunctionAddParamInt256_doc},
    {"add_param_int_n", (PyCFunction)PyEthereumAbiFunctionAddParamIntN,
     METH_FASTCALL, PyEthereumAbiFunctionAddParamIntN_doc},
    {"add_param_bool", (PyCFunction)PyEthereumAbiFunctionAddParamBool,
     METH_FASTCALL, PyEthereumAbiFunctionAddParamBool_doc},
    {"add_param_string", (PyCFunction)PyEthereumAbiFunctionAddParamString,
     METH_FASTCALL, PyEthereumAbiFunctionAddParamString_doc},
    {"add_param_address", (PyCFunction)PyEthereumAbiFunctionAddParamAddress,
     METH_FASTCALL, PyEthereumAbiFunctionAddParamAddress_doc},
    {"add_param_bytes", (PyCFunction)PyEthereumAbiFunctionAddParamBytes,
     METH_FASTCALL, PyEthereumAbiFunctionAddParamBytes_doc},
    {"add_param_bytes_fix", (PyCFunction)PyEthereumAbiFunctionAddParamBytesFix,
     METH_FASTCALL, PyEthereumAbiFunctionAddParamBytesFix_doc},
    {"add_param_array", (PyCFunction)PyEthereumAbiFunctionAddParamArray,
     METH_FASTCALL, PyEthereumAbiFunctionAddParamArray_doc},
    {"get_param_uint8", (PyCFunction)PyEthereumAbiFunctionGetParamUInt8,
     METH_FASTCALL, PyEthereumAbiFunctionGetParamUInt8_doc},
    {"get_param_uint64", (PyCFunction)PyEthereumAbiFunctionGetParamUInt64,
     METH_FASTCALL, PyEthereumAbiFunctionGetParamUInt64_doc},
    {"get_param_uint256", (PyCFunction)PyEthereumAbiFunctionGetParamUInt256,
     METH_FASTCALL, PyEthereumAbiFunctionGetParamUInt256_doc},
    {"get_param_bool", (PyCFunction)PyEthereumAbiFunctionGetParamBool,
     METH_FASTCALL, PyEthereumAbiFunctionGetParamBool_doc},
    {"get_param_string", (PyCFunction)PyEthereumAbiFunctionGetParamString,
     METH_FASTCALL, PyEthereumAbiFunctionGetParamString_doc},
    {"get_param_address", (PyCFunction)PyEthereumAbiFunctionGetParamAddress,
     METH_FASTCALL, PyEthereumAbiFunctionGetParamAddress_doc},
    {"add_in_array_param_uint8",
     (PyCFunction)PyEthereumAbiFunctionAddInArrayParamUInt8, METH_FASTCALL,
     PyEthereumAbiFunctionAddInArrayParamUInt8_doc},
    {"add_in_array_param_uint16",
     (PyCFunction)PyEthereumAbiFunctionAddInArrayParamUInt16, METH_FASTCALL,
     PyEthereumAbiFunctionAddInArrayParamUInt16_doc},
    {"add_in_array_param_uint32",
     (PyCFunction)PyEthereumAbiFunctionAddInArrayParamUInt32, METH_FASTCALL,
     PyEthereumAbiFunctionAddInArrayParamUInt32_doc},
    {"add_in_array_param_uint64",
     (PyCFunction)PyEthereumAbiFunctionAddInArrayParamUInt64, METH_FASTCALL,
     PyEthereumAbiFunctionAddInArrayParamUInt64_doc},
    {"add_in_array_param_uint256",
     (PyCFunction)PyEthereumAbiFunctionAddInArrayParamUInt256, METH_FASTCALL,
     PyEthereumAbiFunctionAddInArrayParamUInt256_doc},
    {"add_in_array_param_uint_n",
     (PyCFunction)PyEthereumAbiFunctionAddInArrayParamUIntN, METH_FASTCALL,
     PyEthereumAbiFunctionAddInArrayParamUIntN_doc},
    {"add_in_array_param_int8",
     (PyCFunction)PyEthereumAbiFunctionAddInArrayParamInt8, METH_FASTCALL,
     PyEthereumAbiFunctionAddInArrayParamInt8_doc},
    {"add_in_array_param_int16",
     (PyCFunction)PyEthereumAbiFunctionAddInArrayParamInt16, METH_FASTCALL,
     PyEthereumAbiFunctionAddInArrayParamInt16_doc},
    {"add_in_array_param_int32",
     (PyCFunction)PyEthereumAbiFunctionAddInArrayParamInt32, METH_FASTCALL,
     PyEthereumAbiFunctionAddInArrayParamInt32_doc},
    {"add_in_array_param_int64",
     (PyCFunction)PyEthereumAbiFunctionAddInArrayParamInt64, METH_FASTCALL,
     PyEthereumAbiFunctionAddInArrayParamInt64_doc},
    {"add_in_array_param_int256",
     (PyCFunction)PyEthereumAbiFunctionAddInArrayParamInt256, METH_FASTCALL,
     PyEthereumAbiFunctionAddInArrayParamInt256_doc},
    {"add_in_array_param_int_n",
     (PyCFunction)PyEthereumAbiFunctionAddInArrayParamIntN, METH_FASTCALL,
     PyEthereumAbiFunctionAddInArrayParamIntN_doc},
    {"add_in_array_param_bool",
     (PyCFunction)PyEthereumAbiFunctionAddInArrayParamBool, METH_FASTCALL,
     PyEthereumAbiFunctionAddInArrayParamBool_doc},
    {"add_in_array_param_string",
     (PyCFunction)PyEthereumAbiFunctionAddInArrayParamString, METH_FASTCALL,
     PyEthereumAbiFunctionAddInArrayParamString_doc},
    {"add_in_array_param_address",
     (PyCFunction)PyEthereumAbiFunctionAddInArrayParamAddress, METH_FASTCALL,
     PyEthereumAbiFunctionAddInArrayParamAddress_doc},
    {"add_in_array_param_bytes",
     (PyCFunction)PyEthereumAbiFunctionAddInArrayParamBytes, METH_FASTCALL,
     PyEthereumAbiFunctionAddInArrayParamBytes_doc},
    {"add_in_array_param_bytes_fix",
     (PyCFunction)PyEthereumAbiFunctionAddInArrayParamBytesFix, METH_FASTCALL,
     PyEthereumAbiFunctionAddInArrayParamBytesFix_doc},
    {"create_with_string", (PyCFunction)PyEthereumAbiFunctionCreateWithString,
     METH_FASTCALL | METH_STATIC, PyEthereumAbiFunctionCreateWithString_doc},
    {}};

bool PyInit_EthereumAbiFunction(PyObject* module) {
  PyEthereumAbiFunctionType.tp_dealloc =
      (destructor)PyEthereumAbiFunction_dealloc;
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