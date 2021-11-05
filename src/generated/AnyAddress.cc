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

#include "generated/AnyAddress.h"

#include "Data.h"
#include "String.h"
#include "generated/CoinType.h"
#include "generated/PublicKey.h"

struct PyAnyAddressObject {
  PyObject_HEAD;
  TWAnyAddress* value;
};

static PyTypeObject PyAnyAddressType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.AnyAddress",    /* tp_name */
    sizeof(PyAnyAddressObject), /* tp_basicsize */
    0,                          /* tp_itemsize */
    0,                          /* tp_dealloc */
    0,                          /* tp_print */
    0,                          /* tp_getattr */
    0,                          /* tp_setattr */
    0,                          /* tp_reserved */
    0,                          /* tp_repr */
    0,                          /* tp_as_number */
    0,                          /* tp_as_sequence */
    0,                          /* tp_as_mapping */
    0,                          /* tp_hash  */
    0,                          /* tp_call */
    0,                          /* tp_str */
    0,                          /* tp_getattro */
    0,                          /* tp_setattro */
    0,                          /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,         /* tp_flags */
    nullptr,                    /* tp_doc */
};

bool PyAnyAddress_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyAnyAddressType) != 0;
}

// Create PyAnyAddress from enum TWAnyAddress.
PyObject* PyAnyAddress_FromTWAnyAddress(TWAnyAddress* value) {
  if (!value)
    Py_RETURN_NONE;

  PyAnyAddressObject* object =
      PyObject_New(PyAnyAddressObject, &PyAnyAddressType);
  if (!object)
    return nullptr;

  object->value = value;

  return (PyObject*)object;
}

TWAnyAddress* PyAnyAddress_GetTWAnyAddress(PyObject* object) {
  assert(PyAnyAddress_Check(object));
  return ((PyAnyAddressObject*)object)->value;
}

static void PyAnyAddress_dealloc(PyAnyAddressObject* self) {
  if (self->value) {
    TWAnyAddressDelete(self->value);
  }
  Py_TYPE(self)->tp_free(self);
}

// getter function for Description
static const char PyAnyAddressDescription_doc[] =
    "TWString* TWAnyAddressDescription(struct TWAnyAddress* address)";
static PyObject* PyAnyAddressDescription(PyAnyAddressObject* self, void*) {
  TWStringPtr prop(TWAnyAddressDescription(self->value));
  return PyUnicode_FromTWString(prop);
}

// getter function for Coin
static const char PyAnyAddressCoin_doc[] =
    "enum TWCoinType TWAnyAddressCoin(struct TWAnyAddress* address)";
static PyObject* PyAnyAddressCoin(PyAnyAddressObject* self, void*) {
  TWCoinType prop = TWAnyAddressCoin(self->value);
  return PyCoinType_FromTWCoinType(prop);
}

// getter function for Data
static const char PyAnyAddressData_doc[] =
    "TWData* TWAnyAddressData(struct TWAnyAddress* address)";
static PyObject* PyAnyAddressData(PyAnyAddressObject* self, void*) {
  TWDataPtr prop(TWAnyAddressData(self->value));
  return PyBytes_FromTWData(prop);
}

// static method function for Equal
static const char PyAnyAddressEqual_doc[] =
    "bool TWAnyAddressEqual(struct TWAnyAddress* lhs, struct TWAnyAddress* "
    "rhs)";
static PyObject* PyAnyAddressEqual(PyAnyAddressObject* self,
                                   PyObject* const* args,
                                   Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  if (!PyAnyAddress_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type AnyAddress");
    return nullptr;
  }
  auto arg0 = PyAnyAddress_GetTWAnyAddress(args[0]);

  if (!PyAnyAddress_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type AnyAddress");
    return nullptr;
  }
  auto arg1 = PyAnyAddress_GetTWAnyAddress(args[1]);

  bool result = TWAnyAddressEqual(arg0, arg1);
  return PyBool_FromLong(result);
}

// static method function for IsValid
static const char PyAnyAddressIsValid_doc[] =
    "bool TWAnyAddressIsValid(TWString* string, enum TWCoinType coin)";
static PyObject* PyAnyAddressIsValid(PyAnyAddressObject* self,
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

  if (!PyCoinType_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type CoinType");
    return nullptr;
  }
  auto arg1 = PyCoinType_GetTWCoinType(args[1]);

  bool result = TWAnyAddressIsValid(arg0.get(), arg1);
  return PyBool_FromLong(result);
}

// static method function for CreateWithString
static const char PyAnyAddressCreateWithString_doc[] =
    "struct TWAnyAddress* TWAnyAddressCreateWithString(TWString* string, enum "
    "TWCoinType coin)";
static PyObject* PyAnyAddressCreateWithString(PyAnyAddressObject* self,
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

  if (!PyCoinType_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type CoinType");
    return nullptr;
  }
  auto arg1 = PyCoinType_GetTWCoinType(args[1]);

  TWAnyAddress* result = TWAnyAddressCreateWithString(arg0.get(), arg1);
  return PyAnyAddress_FromTWAnyAddress(result);
}

// static method function for CreateWithPublicKey
static const char PyAnyAddressCreateWithPublicKey_doc[] =
    "struct TWAnyAddress* TWAnyAddressCreateWithPublicKey(struct TWPublicKey* "
    "publicKey, enum TWCoinType coin)";
static PyObject* PyAnyAddressCreateWithPublicKey(PyAnyAddressObject* self,
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

  if (!PyCoinType_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type CoinType");
    return nullptr;
  }
  auto arg1 = PyCoinType_GetTWCoinType(args[1]);

  TWAnyAddress* result = TWAnyAddressCreateWithPublicKey(arg0, arg1);
  return PyAnyAddress_FromTWAnyAddress(result);
}

// properties

static const PyGetSetDef get_set_defs[] = {
    {"description", (getter)PyAnyAddressDescription, nullptr,
     PyAnyAddressDescription_doc},
    {"coin", (getter)PyAnyAddressCoin, nullptr, PyAnyAddressCoin_doc},
    {"data", (getter)PyAnyAddressData, nullptr, PyAnyAddressData_doc},
    {}};

static const PyMethodDef method_defs[] = {
    {"equal", (PyCFunction)PyAnyAddressEqual, METH_FASTCALL | METH_STATIC,
     PyAnyAddressEqual_doc},
    {"is_valid", (PyCFunction)PyAnyAddressIsValid, METH_FASTCALL | METH_STATIC,
     PyAnyAddressIsValid_doc},
    {"create_with_string", (PyCFunction)PyAnyAddressCreateWithString,
     METH_FASTCALL | METH_STATIC, PyAnyAddressCreateWithString_doc},
    {"create_with_public_key", (PyCFunction)PyAnyAddressCreateWithPublicKey,
     METH_FASTCALL | METH_STATIC, PyAnyAddressCreateWithPublicKey_doc},
    {}};

bool PyInit_AnyAddress(PyObject* module) {
  PyAnyAddressType.tp_dealloc = (destructor)PyAnyAddress_dealloc;
  PyAnyAddressType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyAnyAddressType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyAnyAddressType) < 0)
    return false;

  Py_INCREF(&PyAnyAddressType);
  if (PyModule_AddObject(module, "AnyAddress", (PyObject*)&PyAnyAddressType) <
      0) {
    Py_DECREF(&PyAnyAddressType);
    return false;
  }

  return true;
}