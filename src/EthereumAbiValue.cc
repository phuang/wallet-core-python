// Copyright 2021 Peng Huang <shawn.p.huang@gmail.com>
// This file is part of wallet-core-python.
//
// Foobar is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Foobar is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Foobar.  If not, see <https://www.gnu.org/licenses/>.
//
// NOTE: this is a GENERATED FILE, changes made here WILL BE LOST.

#include "EthereumAbiValue.h"

#include "Bool.h"
#include "Data.h"
#include "String.h"

static PyTypeObject PyEthereumAbiValueType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.EthereumAbiValue",    /* tp_name */
    sizeof(PyEthereumAbiValueObject), /* tp_basicsize */
    0,                                /* tp_itemsize */
    0,                                /* tp_dealloc */
    0,                                /* tp_print */
    0,                                /* tp_getattr */
    0,                                /* tp_setattr */
    0,                                /* tp_reserved */
    0,                                /* tp_repr */
    0,                                /* tp_as_number */
    0,                                /* tp_as_sequence */
    0,                                /* tp_as_mapping */
    0,                                /* tp_hash  */
    0,                                /* tp_call */
    0,                                /* tp_str */
    0,                                /* tp_getattro */
    0,                                /* tp_setattro */
    0,                                /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,               /* tp_flags */
    nullptr,                          /* tp_doc */
};

bool PyEthereumAbiValue_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyEthereumAbiValueType) != 0;
}

// Create PyEthereumAbiValue from enum TWEthereumAbiValue.
PyObject* PyEthereumAbiValue_FromTWEthereumAbiValue(TWEthereumAbiValue* value) {
  if (!value)
    return nullptr;

  PyEthereumAbiValueObject* object =
      PyObject_New(PyEthereumAbiValueObject, &PyEthereumAbiValueType);
  if (!object)
    return nullptr;

  object->value = value;

  return (PyObject*)object;
}

TWEthereumAbiValue* PyEthereumAbiValue_GetTWEthereumAbiValue(PyObject* object) {
  assert(PyEthereumAbiValue_Check(object));
  return ((PyEthereumAbiValueObject*)object)->value;
}

// static method function for EncodeBool
static const char PyEthereumAbiValueEncodeBool_doc[] =
    "TWData* TWEthereumAbiValueEncodeBool(bool value)";
static PyObject* PyEthereumAbiValueEncodeBool(PyEthereumAbiValueObject* self,
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

  TWDataPtr result = TWEthereumAbiValueEncodeBool(arg0);
  return PyByteArray_FromTWData(result);
}

// static method function for EncodeInt32
static const char PyEthereumAbiValueEncodeInt32_doc[] =
    "TWData* TWEthereumAbiValueEncodeInt32(int32_t value)";
static PyObject* PyEthereumAbiValueEncodeInt32(PyEthereumAbiValueObject* self,
                                               PyObject* const* args,
                                               Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  if (!PyLong_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Long");
    return nullptr;
  }
  auto arg0 = PyLong_AsLong(args[0]);

  TWDataPtr result = TWEthereumAbiValueEncodeInt32(arg0);
  return PyByteArray_FromTWData(result);
}

// static method function for EncodeUInt32
static const char PyEthereumAbiValueEncodeUInt32_doc[] =
    "TWData* TWEthereumAbiValueEncodeUInt32(uint32_t value)";
static PyObject* PyEthereumAbiValueEncodeUInt32(PyEthereumAbiValueObject* self,
                                                PyObject* const* args,
                                                Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  if (!PyLong_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Long");
    return nullptr;
  }
  auto arg0 = PyLong_AsLong(args[0]);

  TWDataPtr result = TWEthereumAbiValueEncodeUInt32(arg0);
  return PyByteArray_FromTWData(result);
}

// static method function for EncodeInt256
static const char PyEthereumAbiValueEncodeInt256_doc[] =
    "TWData* TWEthereumAbiValueEncodeInt256(TWData* value)";
static PyObject* PyEthereumAbiValueEncodeInt256(PyEthereumAbiValueObject* self,
                                                PyObject* const* args,
                                                Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  if (!PyByteArray_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type ByteArray");
    return nullptr;
  }
  auto arg0 = PyByteArray_GetTWData(args[0]);

  TWDataPtr result = TWEthereumAbiValueEncodeInt256(arg0.get());
  return PyByteArray_FromTWData(result);
}

// static method function for EncodeUInt256
static const char PyEthereumAbiValueEncodeUInt256_doc[] =
    "TWData* TWEthereumAbiValueEncodeUInt256(TWData* value)";
static PyObject* PyEthereumAbiValueEncodeUInt256(PyEthereumAbiValueObject* self,
                                                 PyObject* const* args,
                                                 Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  if (!PyByteArray_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type ByteArray");
    return nullptr;
  }
  auto arg0 = PyByteArray_GetTWData(args[0]);

  TWDataPtr result = TWEthereumAbiValueEncodeUInt256(arg0.get());
  return PyByteArray_FromTWData(result);
}

// static method function for EncodeAddress
static const char PyEthereumAbiValueEncodeAddress_doc[] =
    "TWData* TWEthereumAbiValueEncodeAddress(TWData* value)";
static PyObject* PyEthereumAbiValueEncodeAddress(PyEthereumAbiValueObject* self,
                                                 PyObject* const* args,
                                                 Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  if (!PyByteArray_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type ByteArray");
    return nullptr;
  }
  auto arg0 = PyByteArray_GetTWData(args[0]);

  TWDataPtr result = TWEthereumAbiValueEncodeAddress(arg0.get());
  return PyByteArray_FromTWData(result);
}

// static method function for EncodeString
static const char PyEthereumAbiValueEncodeString_doc[] =
    "TWData* TWEthereumAbiValueEncodeString(TWString* value)";
static PyObject* PyEthereumAbiValueEncodeString(PyEthereumAbiValueObject* self,
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

  TWDataPtr result = TWEthereumAbiValueEncodeString(arg0.get());
  return PyByteArray_FromTWData(result);
}

// static method function for EncodeBytes
static const char PyEthereumAbiValueEncodeBytes_doc[] =
    "TWData* TWEthereumAbiValueEncodeBytes(TWData* value)";
static PyObject* PyEthereumAbiValueEncodeBytes(PyEthereumAbiValueObject* self,
                                               PyObject* const* args,
                                               Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  if (!PyByteArray_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type ByteArray");
    return nullptr;
  }
  auto arg0 = PyByteArray_GetTWData(args[0]);

  TWDataPtr result = TWEthereumAbiValueEncodeBytes(arg0.get());
  return PyByteArray_FromTWData(result);
}

// static method function for EncodeBytesDyn
static const char PyEthereumAbiValueEncodeBytesDyn_doc[] =
    "TWData* TWEthereumAbiValueEncodeBytesDyn(TWData* value)";
static PyObject* PyEthereumAbiValueEncodeBytesDyn(
    PyEthereumAbiValueObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  if (!PyByteArray_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type ByteArray");
    return nullptr;
  }
  auto arg0 = PyByteArray_GetTWData(args[0]);

  TWDataPtr result = TWEthereumAbiValueEncodeBytesDyn(arg0.get());
  return PyByteArray_FromTWData(result);
}

// static method function for DecodeUInt256
static const char PyEthereumAbiValueDecodeUInt256_doc[] =
    "TWString* TWEthereumAbiValueDecodeUInt256(TWData* input)";
static PyObject* PyEthereumAbiValueDecodeUInt256(PyEthereumAbiValueObject* self,
                                                 PyObject* const* args,
                                                 Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  if (!PyByteArray_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type ByteArray");
    return nullptr;
  }
  auto arg0 = PyByteArray_GetTWData(args[0]);

  TWStringPtr result = TWEthereumAbiValueDecodeUInt256(arg0.get());
  return PyUnicode_FromTWString(result);
}

// static method function for DecodeValue
static const char PyEthereumAbiValueDecodeValue_doc[] =
    "TWString* TWEthereumAbiValueDecodeValue(TWData* input, TWString* type)";
static PyObject* PyEthereumAbiValueDecodeValue(PyEthereumAbiValueObject* self,
                                               PyObject* const* args,
                                               Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  if (!PyByteArray_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type ByteArray");
    return nullptr;
  }
  auto arg0 = PyByteArray_GetTWData(args[0]);

  if (!PyUnicode_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Unicode");
    return nullptr;
  }
  auto arg1 = PyUnicode_GetTWString(args[1]);

  TWStringPtr result = TWEthereumAbiValueDecodeValue(arg0.get(), arg1.get());
  return PyUnicode_FromTWString(result);
}

// static method function for DecodeArray
static const char PyEthereumAbiValueDecodeArray_doc[] =
    "TWString* TWEthereumAbiValueDecodeArray(TWData* input, TWString* type)";
static PyObject* PyEthereumAbiValueDecodeArray(PyEthereumAbiValueObject* self,
                                               PyObject* const* args,
                                               Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  if (!PyByteArray_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type ByteArray");
    return nullptr;
  }
  auto arg0 = PyByteArray_GetTWData(args[0]);

  if (!PyUnicode_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Unicode");
    return nullptr;
  }
  auto arg1 = PyUnicode_GetTWString(args[1]);

  TWStringPtr result = TWEthereumAbiValueDecodeArray(arg0.get(), arg1.get());
  return PyUnicode_FromTWString(result);
}

static const PyGetSetDef get_set_defs[] = {{}};

static const PyMethodDef method_defs[] = {
    {"EncodeBool", (PyCFunction)PyEthereumAbiValueEncodeBool,
     METH_FASTCALL | METH_STATIC, PyEthereumAbiValueEncodeBool_doc},
    {"EncodeInt32", (PyCFunction)PyEthereumAbiValueEncodeInt32,
     METH_FASTCALL | METH_STATIC, PyEthereumAbiValueEncodeInt32_doc},
    {"EncodeUInt32", (PyCFunction)PyEthereumAbiValueEncodeUInt32,
     METH_FASTCALL | METH_STATIC, PyEthereumAbiValueEncodeUInt32_doc},
    {"EncodeInt256", (PyCFunction)PyEthereumAbiValueEncodeInt256,
     METH_FASTCALL | METH_STATIC, PyEthereumAbiValueEncodeInt256_doc},
    {"EncodeUInt256", (PyCFunction)PyEthereumAbiValueEncodeUInt256,
     METH_FASTCALL | METH_STATIC, PyEthereumAbiValueEncodeUInt256_doc},
    {"EncodeAddress", (PyCFunction)PyEthereumAbiValueEncodeAddress,
     METH_FASTCALL | METH_STATIC, PyEthereumAbiValueEncodeAddress_doc},
    {"EncodeString", (PyCFunction)PyEthereumAbiValueEncodeString,
     METH_FASTCALL | METH_STATIC, PyEthereumAbiValueEncodeString_doc},
    {"EncodeBytes", (PyCFunction)PyEthereumAbiValueEncodeBytes,
     METH_FASTCALL | METH_STATIC, PyEthereumAbiValueEncodeBytes_doc},
    {"EncodeBytesDyn", (PyCFunction)PyEthereumAbiValueEncodeBytesDyn,
     METH_FASTCALL | METH_STATIC, PyEthereumAbiValueEncodeBytesDyn_doc},
    {"DecodeUInt256", (PyCFunction)PyEthereumAbiValueDecodeUInt256,
     METH_FASTCALL | METH_STATIC, PyEthereumAbiValueDecodeUInt256_doc},
    {"DecodeValue", (PyCFunction)PyEthereumAbiValueDecodeValue,
     METH_FASTCALL | METH_STATIC, PyEthereumAbiValueDecodeValue_doc},
    {"DecodeArray", (PyCFunction)PyEthereumAbiValueDecodeArray,
     METH_FASTCALL | METH_STATIC, PyEthereumAbiValueDecodeArray_doc},
    {}};

bool PyInit_EthereumAbiValue(PyObject* module) {
  PyEthereumAbiValueType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyEthereumAbiValueType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyEthereumAbiValueType) < 0)
    return false;

  Py_INCREF(&PyEthereumAbiValueType);
  if (PyModule_AddObject(module, "EthereumAbiValue",
                         (PyObject*)&PyEthereumAbiValueType) < 0) {
    Py_DECREF(&PyEthereumAbiValueType);
    return false;
  }

  return true;
}