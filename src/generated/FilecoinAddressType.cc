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

#include "generated/FilecoinAddressType.h"

#include <algorithm>
#include <iterator>

static PyTypeObject PyFilecoinAddressTypeType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.FilecoinAddressType",    /* tp_name */
    sizeof(PyFilecoinAddressTypeObject), /* tp_basicsize */
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

bool PyFilecoinAddressType_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyFilecoinAddressTypeType) != 0;
}

struct Constant {
  const TWFilecoinAddressType value;
  const char* name;
  PyObject* pyvalue;
};

static Constant constants[] = {
    // clang-format off
    { TWFilecoinAddressTypeDefault, "Default", nullptr },
    { TWFilecoinAddressTypeDelegated, "Delegated", nullptr },
    // clang-format on
};

// Create PyFilecoinAddressType from enum TWFilecoinAddressType. It returns the
// same PyFilecoinAddressType instance for the same enum TWFilecoinAddressType
// value.
PyObject* PyFilecoinAddressType_FromTWFilecoinAddressType(
    TWFilecoinAddressType value) {
  Constant* constant =
      std::find_if(std::begin(constants), std::end(constants),
                   [value](const Constant& v) { return v.value == value; });

  if (!constant) {
    PyErr_Format(PyExc_ValueError, "Invalid FilecoinAddressType value: %d",
                 value);
    return nullptr;
  }

  if (!constant->pyvalue) {
    auto* pyvalue =
        PyObject_New(PyFilecoinAddressTypeObject, &PyFilecoinAddressTypeType);
    *const_cast<TWFilecoinAddressType*>(&pyvalue->value) = value;
    constant->pyvalue = (PyObject*)pyvalue;
  }

  Py_INCREF(constant->pyvalue);
  return constant->pyvalue;
}

TWFilecoinAddressType PyFilecoinAddressType_GetTWFilecoinAddressType(
    PyObject* object) {
  assert(PyFilecoinAddressType_Check(object));
  return ((PyFilecoinAddressTypeObject*)object)->value;
}

static int PyFilecoinAddressType_init(PyFilecoinAddressTypeObject* self,
                                      PyObject* args,
                                      PyObject* kwds) {
  return 0;
}

static PyObject* PyFilecoinAddressType_new(PyTypeObject* subtype,
                                           PyObject* args,
                                           PyObject* kwds) {
  int value = 0;
  if (!PyArg_ParseTuple(args, "|i", &value)) {
    return nullptr;
  }
  return PyFilecoinAddressType_FromTWFilecoinAddressType(
      (TWFilecoinAddressType)value);
}

static PyObject* PyFilecoinAddressType_str(PyFilecoinAddressTypeObject* self) {
  Constant* constant = std::find_if(
      std::begin(constants), std::end(constants),
      [self](const Constant& v) { return v.value == self->value; });

  return PyUnicode_FromString(constant ? constant->name : "Unknown");
}

// properties

static const PyGetSetDef get_set_defs[] = {{}};

static const PyMethodDef method_defs[] = {{}};

bool PyInit_FilecoinAddressType(PyObject* module) {
  PyFilecoinAddressTypeType.tp_new = PyFilecoinAddressType_new;
  PyFilecoinAddressTypeType.tp_init = (initproc)PyFilecoinAddressType_init;
  PyFilecoinAddressTypeType.tp_str = (reprfunc)PyFilecoinAddressType_str;
  PyFilecoinAddressTypeType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyFilecoinAddressTypeType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyFilecoinAddressTypeType) < 0)
    return false;

  Py_INCREF(&PyFilecoinAddressTypeType);
  if (PyModule_AddObject(module, "FilecoinAddressType",
                         (PyObject*)&PyFilecoinAddressTypeType) < 0) {
    Py_DECREF(&PyFilecoinAddressTypeType);
    return false;
  }

  PyObject* dict = PyFilecoinAddressTypeType.tp_dict;
  (void)dict;

  for (const Constant& constant : constants) {
    PyDict_SetItemString(
        dict, constant.name,
        PyFilecoinAddressType_FromTWFilecoinAddressType(constant.value));
  }

  return true;
}