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

#include "generated/FIOAccount.h"

#include "String.h"

struct PyFIOAccountObject {
  PyObject_HEAD;
  TWFIOAccount* value;
};

static PyTypeObject PyFIOAccountType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.FIOAccount",    /* tp_name */
    sizeof(PyFIOAccountObject), /* tp_basicsize */
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

bool PyFIOAccount_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyFIOAccountType) != 0;
}

// Create PyFIOAccount from enum TWFIOAccount.
PyObject* PyFIOAccount_FromTWFIOAccount(TWFIOAccount* value) {
  if (!value)
    Py_RETURN_NONE;

  PyFIOAccountObject* object =
      PyObject_New(PyFIOAccountObject, &PyFIOAccountType);
  if (!object)
    return nullptr;

  object->value = value;

  return (PyObject*)object;
}

TWFIOAccount* PyFIOAccount_GetTWFIOAccount(PyObject* object) {
  assert(PyFIOAccount_Check(object));
  return ((PyFIOAccountObject*)object)->value;
}

static void PyFIOAccount_dealloc(PyFIOAccountObject* self) {
  if (self->value) {
    TWFIOAccountDelete(self->value);
  }
  Py_TYPE(self)->tp_free(self);
}

// getter function for Description
static const char PyFIOAccountDescription_doc[] =
    "TWString* TWFIOAccountDescription(struct TWFIOAccount* account)";
static PyObject* PyFIOAccountDescription(PyFIOAccountObject* self, void*) {
  TWStringPtr prop(TWFIOAccountDescription(self->value));
  return PyUnicode_FromTWString(prop);
}

// static method function for CreateWithString
static const char PyFIOAccountCreateWithString_doc[] =
    "struct TWFIOAccount* TWFIOAccountCreateWithString(TWString* string)";
static PyObject* PyFIOAccountCreateWithString(PyFIOAccountObject* self,
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

  TWFIOAccount* result = TWFIOAccountCreateWithString(arg0.get());
  return PyFIOAccount_FromTWFIOAccount(result);
}

// properties

static const PyGetSetDef get_set_defs[] = {
    {"description", (getter)PyFIOAccountDescription, nullptr,
     PyFIOAccountDescription_doc},
    {}};

static const PyMethodDef method_defs[] = {
    {"create_with_string", (PyCFunction)PyFIOAccountCreateWithString,
     METH_FASTCALL | METH_STATIC, PyFIOAccountCreateWithString_doc},
    {}};

bool PyInit_FIOAccount(PyObject* module) {
  PyFIOAccountType.tp_dealloc = (destructor)PyFIOAccount_dealloc;
  PyFIOAccountType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyFIOAccountType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyFIOAccountType) < 0)
    return false;

  Py_INCREF(&PyFIOAccountType);
  if (PyModule_AddObject(module, "FIOAccount", (PyObject*)&PyFIOAccountType) <
      0) {
    Py_DECREF(&PyFIOAccountType);
    return false;
  }

  return true;
}