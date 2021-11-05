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

#include "generated/AESPaddingMode.h"

#include <algorithm>
#include <iterator>

static PyTypeObject PyAESPaddingModeType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.AESPaddingMode",    /* tp_name */
    sizeof(PyAESPaddingModeObject), /* tp_basicsize */
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

bool PyAESPaddingMode_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyAESPaddingModeType) != 0;
}

struct Constant {
  const TWAESPaddingMode value;
  const char* name;
  PyObject* pyvalue;
};

static Constant constants[] = {
    // clang-format off
    { TWAESPaddingModeZero, "Zero", nullptr },
    { TWAESPaddingModePKCS7, "PKCS7", nullptr },
    // clang-format on
};

// Create PyAESPaddingMode from enum TWAESPaddingMode. It returns the same
// PyAESPaddingMode instance for the same enum TWAESPaddingMode value.
PyObject* PyAESPaddingMode_FromTWAESPaddingMode(TWAESPaddingMode value) {
  Constant* constant =
      std::find_if(std::begin(constants), std::end(constants),
                   [value](const Constant& v) { return v.value == value; });

  if (!constant) {
    PyErr_Format(PyExc_ValueError, "Invalid AESPaddingMode value: %d", value);
    return nullptr;
  }

  if (!constant->pyvalue) {
    auto* pyvalue = PyObject_New(PyAESPaddingModeObject, &PyAESPaddingModeType);
    *const_cast<TWAESPaddingMode*>(&pyvalue->value) = value;
    constant->pyvalue = (PyObject*)pyvalue;
  }

  Py_INCREF(constant->pyvalue);
  return constant->pyvalue;
}

TWAESPaddingMode PyAESPaddingMode_GetTWAESPaddingMode(PyObject* object) {
  assert(PyAESPaddingMode_Check(object));
  return ((PyAESPaddingModeObject*)object)->value;
}

static int PyAESPaddingMode_init(PyAESPaddingModeObject* self,
                                 PyObject* args,
                                 PyObject* kwds) {
  return 0;
}

static PyObject* PyAESPaddingMode_new(PyTypeObject* subtype,
                                      PyObject* args,
                                      PyObject* kwds) {
  int value = 0;
  if (!PyArg_ParseTuple(args, "|i", &value)) {
    return nullptr;
  }
  return PyAESPaddingMode_FromTWAESPaddingMode((TWAESPaddingMode)value);
}

static PyObject* PyAESPaddingMode_str(PyAESPaddingModeObject* self) {
  Constant* constant = std::find_if(
      std::begin(constants), std::end(constants),
      [self](const Constant& v) { return v.value == self->value; });

  return PyUnicode_FromString(constant ? constant->name : "Unknown");
}

// properties

static const PyGetSetDef get_set_defs[] = {{}};

static const PyMethodDef method_defs[] = {{}};

bool PyInit_AESPaddingMode(PyObject* module) {
  PyAESPaddingModeType.tp_new = PyAESPaddingMode_new;
  PyAESPaddingModeType.tp_init = (initproc)PyAESPaddingMode_init;
  PyAESPaddingModeType.tp_str = (reprfunc)PyAESPaddingMode_str;
  PyAESPaddingModeType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyAESPaddingModeType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyAESPaddingModeType) < 0)
    return false;

  Py_INCREF(&PyAESPaddingModeType);
  if (PyModule_AddObject(module, "AESPaddingMode",
                         (PyObject*)&PyAESPaddingModeType) < 0) {
    Py_DECREF(&PyAESPaddingModeType);
    return false;
  }

  PyObject* dict = PyAESPaddingModeType.tp_dict;
  (void)dict;

  for (const Constant& constant : constants) {
    PyDict_SetItemString(dict, constant.name,
                         PyAESPaddingMode_FromTWAESPaddingMode(constant.value));
  }

  return true;
}