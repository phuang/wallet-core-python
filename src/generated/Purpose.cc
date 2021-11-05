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

#include "generated/Purpose.h"

#include <algorithm>
#include <iterator>

static PyTypeObject PyPurposeType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.Purpose",    /* tp_name */
    sizeof(PyPurposeObject), /* tp_basicsize */
    0,                       /* tp_itemsize */
    0,                       /* tp_dealloc */
    0,                       /* tp_print */
    0,                       /* tp_getattr */
    0,                       /* tp_setattr */
    0,                       /* tp_reserved */
    0,                       /* tp_repr */
    0,                       /* tp_as_number */
    0,                       /* tp_as_sequence */
    0,                       /* tp_as_mapping */
    0,                       /* tp_hash  */
    0,                       /* tp_call */
    0,                       /* tp_str */
    0,                       /* tp_getattro */
    0,                       /* tp_setattro */
    0,                       /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,      /* tp_flags */
    nullptr,                 /* tp_doc */
};

bool PyPurpose_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyPurposeType) != 0;
}

struct Constant {
  const TWPurpose value;
  const char* name;
  PyObject* pyvalue;
};

static Constant constants[] = {
    // clang-format off
    { TWPurposeBIP44, "BIP44", nullptr },
    { TWPurposeBIP49, "BIP49", nullptr },
    { TWPurposeBIP84, "BIP84", nullptr },
    { TWPurposeBIP1852, "BIP1852", nullptr },
    // clang-format on
};

// Create PyPurpose from enum TWPurpose. It returns the same PyPurpose instance
// for the same enum TWPurpose value.
PyObject* PyPurpose_FromTWPurpose(TWPurpose value) {
  Constant* constant =
      std::find_if(std::begin(constants), std::end(constants),
                   [value](const Constant& v) { return v.value == value; });

  if (!constant) {
    PyErr_Format(PyExc_ValueError, "Invalid Purpose value: %d", value);
    return nullptr;
  }

  if (!constant->pyvalue) {
    auto* pyvalue = PyObject_New(PyPurposeObject, &PyPurposeType);
    *const_cast<TWPurpose*>(&pyvalue->value) = value;
    constant->pyvalue = (PyObject*)pyvalue;
  }

  Py_INCREF(constant->pyvalue);
  return constant->pyvalue;
}

TWPurpose PyPurpose_GetTWPurpose(PyObject* object) {
  assert(PyPurpose_Check(object));
  return ((PyPurposeObject*)object)->value;
}

static int PyPurpose_init(PyPurposeObject* self,
                          PyObject* args,
                          PyObject* kwds) {
  return 0;
}

static PyObject* PyPurpose_new(PyTypeObject* subtype,
                               PyObject* args,
                               PyObject* kwds) {
  int value = 0;
  if (!PyArg_ParseTuple(args, "|i", &value)) {
    return nullptr;
  }
  return PyPurpose_FromTWPurpose((TWPurpose)value);
}

static PyObject* PyPurpose_str(PyPurposeObject* self) {
  Constant* constant = std::find_if(
      std::begin(constants), std::end(constants),
      [self](const Constant& v) { return v.value == self->value; });

  return PyUnicode_FromString(constant ? constant->name : "Unknown");
}

// properties

static const PyGetSetDef get_set_defs[] = {{}};

static const PyMethodDef method_defs[] = {{}};

bool PyInit_Purpose(PyObject* module) {
  PyPurposeType.tp_new = PyPurpose_new;
  PyPurposeType.tp_init = (initproc)PyPurpose_init;
  PyPurposeType.tp_str = (reprfunc)PyPurpose_str;
  PyPurposeType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyPurposeType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyPurposeType) < 0)
    return false;

  Py_INCREF(&PyPurposeType);
  if (PyModule_AddObject(module, "Purpose", (PyObject*)&PyPurposeType) < 0) {
    Py_DECREF(&PyPurposeType);
    return false;
  }

  PyObject* dict = PyPurposeType.tp_dict;
  (void)dict;

  for (const Constant& constant : constants) {
    PyDict_SetItemString(dict, constant.name,
                         PyPurpose_FromTWPurpose(constant.value));
  }

  return true;
}