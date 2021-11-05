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

#include "generated/RippleXAddress.h"

#include "Number.h"
#include "String.h"
#include "generated/PublicKey.h"

struct PyRippleXAddressObject {
  PyObject_HEAD;
  TWRippleXAddress* value;
};

static PyTypeObject PyRippleXAddressType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.RippleXAddress",    /* tp_name */
    sizeof(PyRippleXAddressObject), /* tp_basicsize */
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

bool PyRippleXAddress_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyRippleXAddressType) != 0;
}

// Create PyRippleXAddress from enum TWRippleXAddress.
PyObject* PyRippleXAddress_FromTWRippleXAddress(TWRippleXAddress* value) {
  if (!value)
    Py_RETURN_NONE;

  PyRippleXAddressObject* object =
      PyObject_New(PyRippleXAddressObject, &PyRippleXAddressType);
  if (!object)
    return nullptr;

  object->value = value;

  return (PyObject*)object;
}

TWRippleXAddress* PyRippleXAddress_GetTWRippleXAddress(PyObject* object) {
  assert(PyRippleXAddress_Check(object));
  return ((PyRippleXAddressObject*)object)->value;
}

static void PyRippleXAddress_dealloc(PyRippleXAddressObject* self) {
  if (self->value) {
    TWRippleXAddressDelete(self->value);
  }
  Py_TYPE(self)->tp_free(self);
}

// getter function for Description
static const char PyRippleXAddressDescription_doc[] =
    "TWString* TWRippleXAddressDescription(struct TWRippleXAddress* address)";
static PyObject* PyRippleXAddressDescription(PyRippleXAddressObject* self,
                                             void*) {
  TWStringPtr prop(TWRippleXAddressDescription(self->value));
  return PyUnicode_FromTWString(prop);
}

// getter function for Tag
static const char PyRippleXAddressTag_doc[] =
    "uint32_t TWRippleXAddressTag(struct TWRippleXAddress* address)";
static PyObject* PyRippleXAddressTag(PyRippleXAddressObject* self, void*) {
  uint32_t prop = TWRippleXAddressTag(self->value);
  return PyLong_FromLong(prop);
}

// static method function for Equal
static const char PyRippleXAddressEqual_doc[] =
    "bool TWRippleXAddressEqual(struct TWRippleXAddress* lhs, struct "
    "TWRippleXAddress* rhs)";
static PyObject* PyRippleXAddressEqual(PyRippleXAddressObject* self,
                                       PyObject* const* args,
                                       Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  if (!PyRippleXAddress_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type RippleXAddress");
    return nullptr;
  }
  auto arg0 = PyRippleXAddress_GetTWRippleXAddress(args[0]);

  if (!PyRippleXAddress_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type RippleXAddress");
    return nullptr;
  }
  auto arg1 = PyRippleXAddress_GetTWRippleXAddress(args[1]);

  bool result = TWRippleXAddressEqual(arg0, arg1);
  return PyBool_FromLong(result);
}

// static method function for IsValidString
static const char PyRippleXAddressIsValidString_doc[] =
    "bool TWRippleXAddressIsValidString(TWString* string)";
static PyObject* PyRippleXAddressIsValidString(PyRippleXAddressObject* self,
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

  bool result = TWRippleXAddressIsValidString(arg0.get());
  return PyBool_FromLong(result);
}

// static method function for CreateWithString
static const char PyRippleXAddressCreateWithString_doc[] =
    "struct TWRippleXAddress* TWRippleXAddressCreateWithString(TWString* "
    "string)";
static PyObject* PyRippleXAddressCreateWithString(PyRippleXAddressObject* self,
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

  TWRippleXAddress* result = TWRippleXAddressCreateWithString(arg0.get());
  return PyRippleXAddress_FromTWRippleXAddress(result);
}

// static method function for CreateWithPublicKey
static const char PyRippleXAddressCreateWithPublicKey_doc[] =
    "struct TWRippleXAddress* TWRippleXAddressCreateWithPublicKey(struct "
    "TWPublicKey* publicKey, uint32_t tag)";
static PyObject* PyRippleXAddressCreateWithPublicKey(
    PyRippleXAddressObject* self,
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

  auto checked_arg1 = PyLongArg_ToNumber<uint32_t>(args[1], 1, "uint32_t");
  if (!checked_arg1)
    return nullptr;
  const auto& arg1 = checked_arg1.value();

  TWRippleXAddress* result = TWRippleXAddressCreateWithPublicKey(arg0, arg1);
  return PyRippleXAddress_FromTWRippleXAddress(result);
}

// properties

static const PyGetSetDef get_set_defs[] = {
    {"description", (getter)PyRippleXAddressDescription, nullptr,
     PyRippleXAddressDescription_doc},
    {"tag", (getter)PyRippleXAddressTag, nullptr, PyRippleXAddressTag_doc},
    {}};

static const PyMethodDef method_defs[] = {
    {"equal", (PyCFunction)PyRippleXAddressEqual, METH_FASTCALL | METH_STATIC,
     PyRippleXAddressEqual_doc},
    {"is_valid_string", (PyCFunction)PyRippleXAddressIsValidString,
     METH_FASTCALL | METH_STATIC, PyRippleXAddressIsValidString_doc},
    {"create_with_string", (PyCFunction)PyRippleXAddressCreateWithString,
     METH_FASTCALL | METH_STATIC, PyRippleXAddressCreateWithString_doc},
    {"create_with_public_key", (PyCFunction)PyRippleXAddressCreateWithPublicKey,
     METH_FASTCALL | METH_STATIC, PyRippleXAddressCreateWithPublicKey_doc},
    {}};

bool PyInit_RippleXAddress(PyObject* module) {
  PyRippleXAddressType.tp_dealloc = (destructor)PyRippleXAddress_dealloc;
  PyRippleXAddressType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyRippleXAddressType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyRippleXAddressType) < 0)
    return false;

  Py_INCREF(&PyRippleXAddressType);
  if (PyModule_AddObject(module, "RippleXAddress",
                         (PyObject*)&PyRippleXAddressType) < 0) {
    Py_DECREF(&PyRippleXAddressType);
    return false;
  }

  return true;
}