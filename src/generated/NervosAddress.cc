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

#include "generated/NervosAddress.h"

#include "Data.h"
#include "String.h"

struct PyNervosAddressObject {
  PyObject_HEAD;
  TWNervosAddress* value;
};

static PyTypeObject PyNervosAddressType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.NervosAddress",    /* tp_name */
    sizeof(PyNervosAddressObject), /* tp_basicsize */
    0,                             /* tp_itemsize */
    0,                             /* tp_dealloc */
    0,                             /* tp_print */
    0,                             /* tp_getattr */
    0,                             /* tp_setattr */
    0,                             /* tp_reserved */
    0,                             /* tp_repr */
    0,                             /* tp_as_number */
    0,                             /* tp_as_sequence */
    0,                             /* tp_as_mapping */
    0,                             /* tp_hash  */
    0,                             /* tp_call */
    0,                             /* tp_str */
    0,                             /* tp_getattro */
    0,                             /* tp_setattro */
    0,                             /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,            /* tp_flags */
    nullptr,                       /* tp_doc */
};

bool PyNervosAddress_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyNervosAddressType) != 0;
}

// Create PyNervosAddress from enum TWNervosAddress.
PyObject* PyNervosAddress_FromTWNervosAddress(TWNervosAddress* value) {
  if (!value)
    Py_RETURN_NONE;

  PyNervosAddressObject* object =
      PyObject_New(PyNervosAddressObject, &PyNervosAddressType);
  if (!object)
    return nullptr;

  object->value = value;

  return (PyObject*)object;
}

TWNervosAddress* PyNervosAddress_GetTWNervosAddress(PyObject* object) {
  assert(PyNervosAddress_Check(object));
  return ((PyNervosAddressObject*)object)->value;
}

static void PyNervosAddress_dealloc(PyNervosAddressObject* self) {
  if (self->value) {
    TWNervosAddressDelete(self->value);
  }
  Py_TYPE(self)->tp_free(self);
}

// getter function for Description
static const char PyNervosAddressDescription_doc[] =
    "TWString* TWNervosAddressDescription(struct TWNervosAddress* address)";
static PyObject* PyNervosAddressDescription(PyNervosAddressObject* self,
                                            void*) {
  TWStringPtr prop(TWNervosAddressDescription(self->value));
  return PyUnicode_FromTWString(prop);
}

// getter function for CodeHash
static const char PyNervosAddressCodeHash_doc[] =
    "TWData* TWNervosAddressCodeHash(struct TWNervosAddress* address)";
static PyObject* PyNervosAddressCodeHash(PyNervosAddressObject* self, void*) {
  TWDataPtr prop(TWNervosAddressCodeHash(self->value));
  return PyBytes_FromTWData(prop);
}

// getter function for HashType
static const char PyNervosAddressHashType_doc[] =
    "TWString* TWNervosAddressHashType(struct TWNervosAddress* address)";
static PyObject* PyNervosAddressHashType(PyNervosAddressObject* self, void*) {
  TWStringPtr prop(TWNervosAddressHashType(self->value));
  return PyUnicode_FromTWString(prop);
}

// getter function for Args
static const char PyNervosAddressArgs_doc[] =
    "TWData* TWNervosAddressArgs(struct TWNervosAddress* address)";
static PyObject* PyNervosAddressArgs(PyNervosAddressObject* self, void*) {
  TWDataPtr prop(TWNervosAddressArgs(self->value));
  return PyBytes_FromTWData(prop);
}

// static method function for Equal
static const char PyNervosAddressEqual_doc[] =
    "bool TWNervosAddressEqual(struct TWNervosAddress* lhs, struct "
    "TWNervosAddress* rhs)";
static PyObject* PyNervosAddressEqual(PyNervosAddressObject* self,
                                      PyObject* const* args,
                                      Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  if (!PyNervosAddress_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type NervosAddress");
    return nullptr;
  }
  auto arg0 = PyNervosAddress_GetTWNervosAddress(args[0]);

  if (!PyNervosAddress_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type NervosAddress");
    return nullptr;
  }
  auto arg1 = PyNervosAddress_GetTWNervosAddress(args[1]);

  bool result = TWNervosAddressEqual(arg0, arg1);
  return PyBool_FromLong(result);
}

// static method function for IsValidString
static const char PyNervosAddressIsValidString_doc[] =
    "bool TWNervosAddressIsValidString(TWString* string)";
static PyObject* PyNervosAddressIsValidString(PyNervosAddressObject* self,
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

  bool result = TWNervosAddressIsValidString(arg0.get());
  return PyBool_FromLong(result);
}

// static method function for CreateWithString
static const char PyNervosAddressCreateWithString_doc[] =
    "struct TWNervosAddress* TWNervosAddressCreateWithString(TWString* string)";
static PyObject* PyNervosAddressCreateWithString(PyNervosAddressObject* self,
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

  TWNervosAddress* result = TWNervosAddressCreateWithString(arg0.get());
  return PyNervosAddress_FromTWNervosAddress(result);
}

// properties

static const PyGetSetDef get_set_defs[] = {
    {"description", (getter)PyNervosAddressDescription, nullptr,
     PyNervosAddressDescription_doc},
    {"code_hash", (getter)PyNervosAddressCodeHash, nullptr,
     PyNervosAddressCodeHash_doc},
    {"hash_type", (getter)PyNervosAddressHashType, nullptr,
     PyNervosAddressHashType_doc},
    {"args", (getter)PyNervosAddressArgs, nullptr, PyNervosAddressArgs_doc},
    {}};

static const PyMethodDef method_defs[] = {
    {"equal", (PyCFunction)PyNervosAddressEqual, METH_FASTCALL | METH_STATIC,
     PyNervosAddressEqual_doc},
    {"is_valid_string", (PyCFunction)PyNervosAddressIsValidString,
     METH_FASTCALL | METH_STATIC, PyNervosAddressIsValidString_doc},
    {"create_with_string", (PyCFunction)PyNervosAddressCreateWithString,
     METH_FASTCALL | METH_STATIC, PyNervosAddressCreateWithString_doc},
    {}};

bool PyInit_NervosAddress(PyObject* module) {
  PyNervosAddressType.tp_dealloc = (destructor)PyNervosAddress_dealloc;
  PyNervosAddressType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyNervosAddressType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyNervosAddressType) < 0)
    return false;

  Py_INCREF(&PyNervosAddressType);
  if (PyModule_AddObject(module, "NervosAddress",
                         (PyObject*)&PyNervosAddressType) < 0) {
    Py_DECREF(&PyNervosAddressType);
    return false;
  }

  return true;
}