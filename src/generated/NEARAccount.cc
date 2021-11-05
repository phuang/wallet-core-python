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

#include "generated/NEARAccount.h"

#include "String.h"

struct PyNEARAccountObject {
  PyObject_HEAD;
  TWNEARAccount* value;
};

static PyTypeObject PyNEARAccountType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.NEARAccount",    /* tp_name */
    sizeof(PyNEARAccountObject), /* tp_basicsize */
    0,                           /* tp_itemsize */
    0,                           /* tp_dealloc */
    0,                           /* tp_print */
    0,                           /* tp_getattr */
    0,                           /* tp_setattr */
    0,                           /* tp_reserved */
    0,                           /* tp_repr */
    0,                           /* tp_as_number */
    0,                           /* tp_as_sequence */
    0,                           /* tp_as_mapping */
    0,                           /* tp_hash  */
    0,                           /* tp_call */
    0,                           /* tp_str */
    0,                           /* tp_getattro */
    0,                           /* tp_setattro */
    0,                           /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,          /* tp_flags */
    nullptr,                     /* tp_doc */
};

bool PyNEARAccount_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyNEARAccountType) != 0;
}

// Create PyNEARAccount from enum TWNEARAccount.
PyObject* PyNEARAccount_FromTWNEARAccount(TWNEARAccount* value) {
  if (!value)
    Py_RETURN_NONE;

  PyNEARAccountObject* object =
      PyObject_New(PyNEARAccountObject, &PyNEARAccountType);
  if (!object)
    return nullptr;

  object->value = value;

  return (PyObject*)object;
}

TWNEARAccount* PyNEARAccount_GetTWNEARAccount(PyObject* object) {
  assert(PyNEARAccount_Check(object));
  return ((PyNEARAccountObject*)object)->value;
}

static void PyNEARAccount_dealloc(PyNEARAccountObject* self) {
  if (self->value) {
    TWNEARAccountDelete(self->value);
  }
  Py_TYPE(self)->tp_free(self);
}

// getter function for Description
static const char PyNEARAccountDescription_doc[] =
    "TWString* TWNEARAccountDescription(struct TWNEARAccount* account)";
static PyObject* PyNEARAccountDescription(PyNEARAccountObject* self, void*) {
  TWStringPtr prop(TWNEARAccountDescription(self->value));
  return PyUnicode_FromTWString(prop);
}

// static method function for CreateWithString
static const char PyNEARAccountCreateWithString_doc[] =
    "struct TWNEARAccount* TWNEARAccountCreateWithString(TWString* string)";
static PyObject* PyNEARAccountCreateWithString(PyNEARAccountObject* self,
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

  TWNEARAccount* result = TWNEARAccountCreateWithString(arg0.get());
  return PyNEARAccount_FromTWNEARAccount(result);
}

// properties

static const PyGetSetDef get_set_defs[] = {
    {"description", (getter)PyNEARAccountDescription, nullptr,
     PyNEARAccountDescription_doc},
    {}};

static const PyMethodDef method_defs[] = {
    {"create_with_string", (PyCFunction)PyNEARAccountCreateWithString,
     METH_FASTCALL | METH_STATIC, PyNEARAccountCreateWithString_doc},
    {}};

bool PyInit_NEARAccount(PyObject* module) {
  PyNEARAccountType.tp_dealloc = (destructor)PyNEARAccount_dealloc;
  PyNEARAccountType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyNEARAccountType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyNEARAccountType) < 0)
    return false;

  Py_INCREF(&PyNEARAccountType);
  if (PyModule_AddObject(module, "NEARAccount", (PyObject*)&PyNEARAccountType) <
      0) {
    Py_DECREF(&PyNEARAccountType);
    return false;
  }

  return true;
}