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

#include "generated/GroestlcoinAddress.h"

#include "Number.h"
#include "String.h"
#include "generated/PublicKey.h"

struct PyGroestlcoinAddressObject {
  PyObject_HEAD;
  TWGroestlcoinAddress* value;
};

static PyTypeObject PyGroestlcoinAddressType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.GroestlcoinAddress",    /* tp_name */
    sizeof(PyGroestlcoinAddressObject), /* tp_basicsize */
    0,                                  /* tp_itemsize */
    0,                                  /* tp_dealloc */
    0,                                  /* tp_print */
    0,                                  /* tp_getattr */
    0,                                  /* tp_setattr */
    0,                                  /* tp_reserved */
    0,                                  /* tp_repr */
    0,                                  /* tp_as_number */
    0,                                  /* tp_as_sequence */
    0,                                  /* tp_as_mapping */
    0,                                  /* tp_hash  */
    0,                                  /* tp_call */
    0,                                  /* tp_str */
    0,                                  /* tp_getattro */
    0,                                  /* tp_setattro */
    0,                                  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                 /* tp_flags */
    nullptr,                            /* tp_doc */
};

bool PyGroestlcoinAddress_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyGroestlcoinAddressType) != 0;
}

// Create PyGroestlcoinAddress from enum TWGroestlcoinAddress.
PyObject* PyGroestlcoinAddress_FromTWGroestlcoinAddress(
    TWGroestlcoinAddress* value) {
  if (!value)
    Py_RETURN_NONE;

  PyGroestlcoinAddressObject* object =
      PyObject_New(PyGroestlcoinAddressObject, &PyGroestlcoinAddressType);
  if (!object)
    return nullptr;

  object->value = value;

  return (PyObject*)object;
}

TWGroestlcoinAddress* PyGroestlcoinAddress_GetTWGroestlcoinAddress(
    PyObject* object) {
  assert(PyGroestlcoinAddress_Check(object));
  return ((PyGroestlcoinAddressObject*)object)->value;
}

static void PyGroestlcoinAddress_dealloc(PyGroestlcoinAddressObject* self) {
  if (self->value) {
    TWGroestlcoinAddressDelete(self->value);
  }
  Py_TYPE(self)->tp_free(self);
}

// getter function for Description
static const char PyGroestlcoinAddressDescription_doc[] =
    "TWString* TWGroestlcoinAddressDescription(struct TWGroestlcoinAddress* "
    "address)";
static PyObject* PyGroestlcoinAddressDescription(
    PyGroestlcoinAddressObject* self,
    void*) {
  TWStringPtr prop(TWGroestlcoinAddressDescription(self->value));
  return PyUnicode_FromTWString(prop);
}

// static method function for Equal
static const char PyGroestlcoinAddressEqual_doc[] =
    "bool TWGroestlcoinAddressEqual(struct TWGroestlcoinAddress* lhs, struct "
    "TWGroestlcoinAddress* rhs)";
static PyObject* PyGroestlcoinAddressEqual(PyGroestlcoinAddressObject* self,
                                           PyObject* const* args,
                                           Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  if (!PyGroestlcoinAddress_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError,
                    "The arg 0 is not in type GroestlcoinAddress");
    return nullptr;
  }
  auto arg0 = PyGroestlcoinAddress_GetTWGroestlcoinAddress(args[0]);

  if (!PyGroestlcoinAddress_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError,
                    "The arg 1 is not in type GroestlcoinAddress");
    return nullptr;
  }
  auto arg1 = PyGroestlcoinAddress_GetTWGroestlcoinAddress(args[1]);

  bool result = TWGroestlcoinAddressEqual(arg0, arg1);
  return PyBool_FromLong(result);
}

// static method function for IsValidString
static const char PyGroestlcoinAddressIsValidString_doc[] =
    "bool TWGroestlcoinAddressIsValidString(TWString* string)";
static PyObject* PyGroestlcoinAddressIsValidString(
    PyGroestlcoinAddressObject* self,
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

  bool result = TWGroestlcoinAddressIsValidString(arg0.get());
  return PyBool_FromLong(result);
}

// static method function for CreateWithString
static const char PyGroestlcoinAddressCreateWithString_doc[] =
    "struct TWGroestlcoinAddress* "
    "TWGroestlcoinAddressCreateWithString(TWString* string)";
static PyObject* PyGroestlcoinAddressCreateWithString(
    PyGroestlcoinAddressObject* self,
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

  TWGroestlcoinAddress* result =
      TWGroestlcoinAddressCreateWithString(arg0.get());
  return PyGroestlcoinAddress_FromTWGroestlcoinAddress(result);
}

// static method function for CreateWithPublicKey
static const char PyGroestlcoinAddressCreateWithPublicKey_doc[] =
    "struct TWGroestlcoinAddress* "
    "TWGroestlcoinAddressCreateWithPublicKey(struct TWPublicKey* publicKey, "
    "uint8_t prefix)";
static PyObject* PyGroestlcoinAddressCreateWithPublicKey(
    PyGroestlcoinAddressObject* self,
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

  TWGroestlcoinAddress* result =
      TWGroestlcoinAddressCreateWithPublicKey(arg0, arg1);
  return PyGroestlcoinAddress_FromTWGroestlcoinAddress(result);
}

// properties

static const PyGetSetDef get_set_defs[] = {
    {"description", (getter)PyGroestlcoinAddressDescription, nullptr,
     PyGroestlcoinAddressDescription_doc},
    {}};

static const PyMethodDef method_defs[] = {
    {"equal", (PyCFunction)PyGroestlcoinAddressEqual,
     METH_FASTCALL | METH_STATIC, PyGroestlcoinAddressEqual_doc},
    {"is_valid_string", (PyCFunction)PyGroestlcoinAddressIsValidString,
     METH_FASTCALL | METH_STATIC, PyGroestlcoinAddressIsValidString_doc},
    {"create_with_string", (PyCFunction)PyGroestlcoinAddressCreateWithString,
     METH_FASTCALL | METH_STATIC, PyGroestlcoinAddressCreateWithString_doc},
    {"create_with_public_key",
     (PyCFunction)PyGroestlcoinAddressCreateWithPublicKey,
     METH_FASTCALL | METH_STATIC, PyGroestlcoinAddressCreateWithPublicKey_doc},
    {}};

bool PyInit_GroestlcoinAddress(PyObject* module) {
  PyGroestlcoinAddressType.tp_dealloc =
      (destructor)PyGroestlcoinAddress_dealloc;
  PyGroestlcoinAddressType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyGroestlcoinAddressType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyGroestlcoinAddressType) < 0)
    return false;

  Py_INCREF(&PyGroestlcoinAddressType);
  if (PyModule_AddObject(module, "GroestlcoinAddress",
                         (PyObject*)&PyGroestlcoinAddressType) < 0) {
    Py_DECREF(&PyGroestlcoinAddressType);
    return false;
  }

  return true;
}