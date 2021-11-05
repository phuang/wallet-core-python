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

#include "generated/BitcoinAddress.h"

#include "Data.h"
#include "Number.h"
#include "String.h"
#include "generated/PublicKey.h"

struct PyBitcoinAddressObject {
  PyObject_HEAD;
  TWBitcoinAddress* value;
};

static PyTypeObject PyBitcoinAddressType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.BitcoinAddress",    /* tp_name */
    sizeof(PyBitcoinAddressObject), /* tp_basicsize */
    0,                              /* tp_itemsize */
    0,                              /* tp_dealloc */
    0,                              /* tp_print */
    0,                              /* tp_getattr */
    0,                              /* tp_setattr */
    0,                              /* tp_reserved */
    0,                              /* tp_repr */
    0,                              /* tp_as_number */
    0,                              /* tp_as_sequence */
    0,                              /* tp_as_mapping */
    0,                              /* tp_hash  */
    0,                              /* tp_call */
    0,                              /* tp_str */
    0,                              /* tp_getattro */
    0,                              /* tp_setattro */
    0,                              /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,             /* tp_flags */
    nullptr,                        /* tp_doc */
};

bool PyBitcoinAddress_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyBitcoinAddressType) != 0;
}

// Create PyBitcoinAddress from enum TWBitcoinAddress.
PyObject* PyBitcoinAddress_FromTWBitcoinAddress(TWBitcoinAddress* value) {
  if (!value)
    Py_RETURN_NONE;

  PyBitcoinAddressObject* object =
      PyObject_New(PyBitcoinAddressObject, &PyBitcoinAddressType);
  if (!object)
    return nullptr;

  object->value = value;

  return (PyObject*)object;
}

TWBitcoinAddress* PyBitcoinAddress_GetTWBitcoinAddress(PyObject* object) {
  assert(PyBitcoinAddress_Check(object));
  return ((PyBitcoinAddressObject*)object)->value;
}

static void PyBitcoinAddress_dealloc(PyBitcoinAddressObject* self) {
  if (self->value) {
    TWBitcoinAddressDelete(self->value);
  }
  Py_TYPE(self)->tp_free(self);
}

// getter function for Description
static const char PyBitcoinAddressDescription_doc[] =
    "TWString* TWBitcoinAddressDescription(struct TWBitcoinAddress* address)";
static PyObject* PyBitcoinAddressDescription(PyBitcoinAddressObject* self,
                                             void*) {
  TWStringPtr prop(TWBitcoinAddressDescription(self->value));
  return PyUnicode_FromTWString(prop);
}

// getter function for Prefix
static const char PyBitcoinAddressPrefix_doc[] =
    "uint8_t TWBitcoinAddressPrefix(struct TWBitcoinAddress* address)";
static PyObject* PyBitcoinAddressPrefix(PyBitcoinAddressObject* self, void*) {
  uint8_t prop = TWBitcoinAddressPrefix(self->value);
  return PyLong_FromLong(prop);
}

// getter function for Keyhash
static const char PyBitcoinAddressKeyhash_doc[] =
    "TWData* TWBitcoinAddressKeyhash(struct TWBitcoinAddress* address)";
static PyObject* PyBitcoinAddressKeyhash(PyBitcoinAddressObject* self, void*) {
  TWDataPtr prop(TWBitcoinAddressKeyhash(self->value));
  return PyBytes_FromTWData(prop);
}

// static method function for Equal
static const char PyBitcoinAddressEqual_doc[] =
    "bool TWBitcoinAddressEqual(struct TWBitcoinAddress* lhs, struct "
    "TWBitcoinAddress* rhs)";
static PyObject* PyBitcoinAddressEqual(PyBitcoinAddressObject* self,
                                       PyObject* const* args,
                                       Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  if (!PyBitcoinAddress_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type BitcoinAddress");
    return nullptr;
  }
  auto arg0 = PyBitcoinAddress_GetTWBitcoinAddress(args[0]);

  if (!PyBitcoinAddress_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type BitcoinAddress");
    return nullptr;
  }
  auto arg1 = PyBitcoinAddress_GetTWBitcoinAddress(args[1]);

  bool result = TWBitcoinAddressEqual(arg0, arg1);
  return PyBool_FromLong(result);
}

// static method function for IsValid
static const char PyBitcoinAddressIsValid_doc[] =
    "bool TWBitcoinAddressIsValid(TWData* data)";
static PyObject* PyBitcoinAddressIsValid(PyBitcoinAddressObject* self,
                                         PyObject* const* args,
                                         Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  if (!PyBytes_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Bytes");
    return nullptr;
  }
  auto arg0 = PyBytes_GetTWData(args[0]);

  bool result = TWBitcoinAddressIsValid(arg0.get());
  return PyBool_FromLong(result);
}

// static method function for IsValidString
static const char PyBitcoinAddressIsValidString_doc[] =
    "bool TWBitcoinAddressIsValidString(TWString* string)";
static PyObject* PyBitcoinAddressIsValidString(PyBitcoinAddressObject* self,
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

  bool result = TWBitcoinAddressIsValidString(arg0.get());
  return PyBool_FromLong(result);
}

// static method function for CreateWithString
static const char PyBitcoinAddressCreateWithString_doc[] =
    "struct TWBitcoinAddress* TWBitcoinAddressCreateWithString(TWString* "
    "string)";
static PyObject* PyBitcoinAddressCreateWithString(PyBitcoinAddressObject* self,
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

  TWBitcoinAddress* result = TWBitcoinAddressCreateWithString(arg0.get());
  return PyBitcoinAddress_FromTWBitcoinAddress(result);
}

// static method function for CreateWithData
static const char PyBitcoinAddressCreateWithData_doc[] =
    "struct TWBitcoinAddress* TWBitcoinAddressCreateWithData(TWData* data)";
static PyObject* PyBitcoinAddressCreateWithData(PyBitcoinAddressObject* self,
                                                PyObject* const* args,
                                                Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  if (!PyBytes_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Bytes");
    return nullptr;
  }
  auto arg0 = PyBytes_GetTWData(args[0]);

  TWBitcoinAddress* result = TWBitcoinAddressCreateWithData(arg0.get());
  return PyBitcoinAddress_FromTWBitcoinAddress(result);
}

// static method function for CreateWithPublicKey
static const char PyBitcoinAddressCreateWithPublicKey_doc[] =
    "struct TWBitcoinAddress* TWBitcoinAddressCreateWithPublicKey(struct "
    "TWPublicKey* publicKey, uint8_t prefix)";
static PyObject* PyBitcoinAddressCreateWithPublicKey(
    PyBitcoinAddressObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  if (!PyPublicKey_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type PublicKey");
    return nullptr;
  }
  auto arg0 = PyPublicKey_GetTWPublicKey(args[0]);

  auto checked_arg1 = PyLongArg_ToNumber<uint8_t>(args[1], 1, "uint8_t");
  if (!checked_arg1)
    return nullptr;
  const auto& arg1 = checked_arg1.value();

  TWBitcoinAddress* result = TWBitcoinAddressCreateWithPublicKey(arg0, arg1);
  return PyBitcoinAddress_FromTWBitcoinAddress(result);
}

// properties

static const PyGetSetDef get_set_defs[] = {
    {"description", (getter)PyBitcoinAddressDescription, nullptr,
     PyBitcoinAddressDescription_doc},
    {"prefix", (getter)PyBitcoinAddressPrefix, nullptr,
     PyBitcoinAddressPrefix_doc},
    {"keyhash", (getter)PyBitcoinAddressKeyhash, nullptr,
     PyBitcoinAddressKeyhash_doc},
    {}};

static const PyMethodDef method_defs[] = {
    {"equal", (PyCFunction)PyBitcoinAddressEqual, METH_FASTCALL | METH_STATIC,
     PyBitcoinAddressEqual_doc},
    {"is_valid", (PyCFunction)PyBitcoinAddressIsValid,
     METH_FASTCALL | METH_STATIC, PyBitcoinAddressIsValid_doc},
    {"is_valid_string", (PyCFunction)PyBitcoinAddressIsValidString,
     METH_FASTCALL | METH_STATIC, PyBitcoinAddressIsValidString_doc},
    {"create_with_string", (PyCFunction)PyBitcoinAddressCreateWithString,
     METH_FASTCALL | METH_STATIC, PyBitcoinAddressCreateWithString_doc},
    {"create_with_data", (PyCFunction)PyBitcoinAddressCreateWithData,
     METH_FASTCALL | METH_STATIC, PyBitcoinAddressCreateWithData_doc},
    {"create_with_public_key", (PyCFunction)PyBitcoinAddressCreateWithPublicKey,
     METH_FASTCALL | METH_STATIC, PyBitcoinAddressCreateWithPublicKey_doc},
    {}};

bool PyInit_BitcoinAddress(PyObject* module) {
  PyBitcoinAddressType.tp_dealloc = (destructor)PyBitcoinAddress_dealloc;
  PyBitcoinAddressType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyBitcoinAddressType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyBitcoinAddressType) < 0)
    return false;

  Py_INCREF(&PyBitcoinAddressType);
  if (PyModule_AddObject(module, "BitcoinAddress",
                         (PyObject*)&PyBitcoinAddressType) < 0) {
    Py_DECREF(&PyBitcoinAddressType);
    return false;
  }

  return true;
}