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

#include "generated/PrivateKeyType.h"

#include <algorithm>
#include <iterator>

static PyTypeObject PyPrivateKeyTypeType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.PrivateKeyType",    /* tp_name */
    sizeof(PyPrivateKeyTypeObject), /* tp_basicsize */
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

bool PyPrivateKeyType_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyPrivateKeyTypeType) != 0;
}

struct Constant {
  const TWPrivateKeyType value;
  const char* name;
  PyObject* pyvalue;
};

static Constant constants[] = {
    // clang-format off
    { TWPrivateKeyTypeDefault, "Default", nullptr },
    { TWPrivateKeyTypeCardano, "Cardano", nullptr },
    // clang-format on
};

// Create PyPrivateKeyType from enum TWPrivateKeyType. It returns the same
// PyPrivateKeyType instance for the same enum TWPrivateKeyType value.
PyObject* PyPrivateKeyType_FromTWPrivateKeyType(TWPrivateKeyType value) {
  Constant* constant =
      std::find_if(std::begin(constants), std::end(constants),
                   [value](const Constant& v) { return v.value == value; });

  if (!constant) {
    PyErr_Format(PyExc_ValueError, "Invalid PrivateKeyType value: %d", value);
    return nullptr;
  }

  if (!constant->pyvalue) {
    auto* pyvalue = PyObject_New(PyPrivateKeyTypeObject, &PyPrivateKeyTypeType);
    *const_cast<TWPrivateKeyType*>(&pyvalue->value) = value;
    constant->pyvalue = (PyObject*)pyvalue;
  }

  Py_INCREF(constant->pyvalue);
  return constant->pyvalue;
}

TWPrivateKeyType PyPrivateKeyType_GetTWPrivateKeyType(PyObject* object) {
  assert(PyPrivateKeyType_Check(object));
  return ((PyPrivateKeyTypeObject*)object)->value;
}

static int PyPrivateKeyType_init(PyPrivateKeyTypeObject* self,
                                 PyObject* args,
                                 PyObject* kwds) {
  return 0;
}

static PyObject* PyPrivateKeyType_new(PyTypeObject* subtype,
                                      PyObject* args,
                                      PyObject* kwds) {
  int value = 0;
  if (!PyArg_ParseTuple(args, "|i", &value)) {
    return nullptr;
  }
  return PyPrivateKeyType_FromTWPrivateKeyType((TWPrivateKeyType)value);
}

static PyObject* PyPrivateKeyType_str(PyPrivateKeyTypeObject* self) {
  Constant* constant = std::find_if(
      std::begin(constants), std::end(constants),
      [self](const Constant& v) { return v.value == self->value; });

  return PyUnicode_FromString(constant ? constant->name : "Unknown");
}

// properties

static const PyGetSetDef get_set_defs[] = {{}};

static const PyMethodDef method_defs[] = {{}};

bool PyInit_PrivateKeyType(PyObject* module) {
  PyPrivateKeyTypeType.tp_new = PyPrivateKeyType_new;
  PyPrivateKeyTypeType.tp_init = (initproc)PyPrivateKeyType_init;
  PyPrivateKeyTypeType.tp_str = (reprfunc)PyPrivateKeyType_str;
  PyPrivateKeyTypeType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyPrivateKeyTypeType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyPrivateKeyTypeType) < 0)
    return false;

  Py_INCREF(&PyPrivateKeyTypeType);
  if (PyModule_AddObject(module, "PrivateKeyType",
                         (PyObject*)&PyPrivateKeyTypeType) < 0) {
    Py_DECREF(&PyPrivateKeyTypeType);
    return false;
  }

  PyObject* dict = PyPrivateKeyTypeType.tp_dict;
  (void)dict;

  for (const Constant& constant : constants) {
    PyDict_SetItemString(dict, constant.name,
                         PyPrivateKeyType_FromTWPrivateKeyType(constant.value));
  }

  return true;
}