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

#include "generated/StoredKeyEncryptionLevel.h"

#include <algorithm>
#include <iterator>

static PyTypeObject PyStoredKeyEncryptionLevelType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.StoredKeyEncryptionLevel",    /* tp_name */
    sizeof(PyStoredKeyEncryptionLevelObject), /* tp_basicsize */
    0,                                        /* tp_itemsize */
    0,                                        /* tp_dealloc */
    0,                                        /* tp_print */
    0,                                        /* tp_getattr */
    0,                                        /* tp_setattr */
    0,                                        /* tp_reserved */
    0,                                        /* tp_repr */
    0,                                        /* tp_as_number */
    0,                                        /* tp_as_sequence */
    0,                                        /* tp_as_mapping */
    0,                                        /* tp_hash  */
    0,                                        /* tp_call */
    0,                                        /* tp_str */
    0,                                        /* tp_getattro */
    0,                                        /* tp_setattro */
    0,                                        /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                       /* tp_flags */
    nullptr,                                  /* tp_doc */
};

bool PyStoredKeyEncryptionLevel_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyStoredKeyEncryptionLevelType) != 0;
}

struct Constant {
  const TWStoredKeyEncryptionLevel value;
  const char* name;
  PyObject* pyvalue;
};

static Constant constants[] = {
    // clang-format off
    { TWStoredKeyEncryptionLevelDefault, "Default", nullptr },
    { TWStoredKeyEncryptionLevelWeak, "Weak", nullptr },
    { TWStoredKeyEncryptionLevelStandard, "Standard", nullptr },
    // clang-format on
};

// Create PyStoredKeyEncryptionLevel from enum TWStoredKeyEncryptionLevel. It
// returns the same PyStoredKeyEncryptionLevel instance for the same enum
// TWStoredKeyEncryptionLevel value.
PyObject* PyStoredKeyEncryptionLevel_FromTWStoredKeyEncryptionLevel(
    TWStoredKeyEncryptionLevel value) {
  Constant* constant =
      std::find_if(std::begin(constants), std::end(constants),
                   [value](const Constant& v) { return v.value == value; });

  if (!constant) {
    PyErr_Format(PyExc_ValueError, "Invalid StoredKeyEncryptionLevel value: %d",
                 value);
    return nullptr;
  }

  if (!constant->pyvalue) {
    auto* pyvalue = PyObject_New(PyStoredKeyEncryptionLevelObject,
                                 &PyStoredKeyEncryptionLevelType);
    *const_cast<TWStoredKeyEncryptionLevel*>(&pyvalue->value) = value;
    constant->pyvalue = (PyObject*)pyvalue;
  }

  Py_INCREF(constant->pyvalue);
  return constant->pyvalue;
}

TWStoredKeyEncryptionLevel
PyStoredKeyEncryptionLevel_GetTWStoredKeyEncryptionLevel(PyObject* object) {
  assert(PyStoredKeyEncryptionLevel_Check(object));
  return ((PyStoredKeyEncryptionLevelObject*)object)->value;
}

static int PyStoredKeyEncryptionLevel_init(
    PyStoredKeyEncryptionLevelObject* self,
    PyObject* args,
    PyObject* kwds) {
  return 0;
}

static PyObject* PyStoredKeyEncryptionLevel_new(PyTypeObject* subtype,
                                                PyObject* args,
                                                PyObject* kwds) {
  int value = 0;
  if (!PyArg_ParseTuple(args, "|i", &value)) {
    return nullptr;
  }
  return PyStoredKeyEncryptionLevel_FromTWStoredKeyEncryptionLevel(
      (TWStoredKeyEncryptionLevel)value);
}

static PyObject* PyStoredKeyEncryptionLevel_str(
    PyStoredKeyEncryptionLevelObject* self) {
  Constant* constant = std::find_if(
      std::begin(constants), std::end(constants),
      [self](const Constant& v) { return v.value == self->value; });

  return PyUnicode_FromString(constant ? constant->name : "Unknown");
}

// properties

static const PyGetSetDef get_set_defs[] = {{}};

static const PyMethodDef method_defs[] = {{}};

bool PyInit_StoredKeyEncryptionLevel(PyObject* module) {
  PyStoredKeyEncryptionLevelType.tp_new = PyStoredKeyEncryptionLevel_new;
  PyStoredKeyEncryptionLevelType.tp_init =
      (initproc)PyStoredKeyEncryptionLevel_init;
  PyStoredKeyEncryptionLevelType.tp_str =
      (reprfunc)PyStoredKeyEncryptionLevel_str;
  PyStoredKeyEncryptionLevelType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyStoredKeyEncryptionLevelType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyStoredKeyEncryptionLevelType) < 0)
    return false;

  Py_INCREF(&PyStoredKeyEncryptionLevelType);
  if (PyModule_AddObject(module, "StoredKeyEncryptionLevel",
                         (PyObject*)&PyStoredKeyEncryptionLevelType) < 0) {
    Py_DECREF(&PyStoredKeyEncryptionLevelType);
    return false;
  }

  PyObject* dict = PyStoredKeyEncryptionLevelType.tp_dict;
  (void)dict;

  for (const Constant& constant : constants) {
    PyDict_SetItemString(
        dict, constant.name,
        PyStoredKeyEncryptionLevel_FromTWStoredKeyEncryptionLevel(
            constant.value));
  }

  return true;
}