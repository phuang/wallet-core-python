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

#include "generated/Derivation.h"

#include <algorithm>
#include <iterator>

static PyTypeObject PyDerivationType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.Derivation",    /* tp_name */
    sizeof(PyDerivationObject), /* tp_basicsize */
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

bool PyDerivation_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyDerivationType) != 0;
}

struct Constant {
  const TWDerivation value;
  const char* name;
  PyObject* pyvalue;
};

static Constant constants[] = {
    // clang-format off
    { TWDerivationDefault, "Default", nullptr },
    { TWDerivationCustom, "Custom", nullptr },
    { TWDerivationBitcoinSegwit, "BitcoinSegwit", nullptr },
    { TWDerivationBitcoinLegacy, "BitcoinLegacy", nullptr },
    { TWDerivationLitecoinLegacy, "LitecoinLegacy", nullptr },
    { TWDerivationSolanaSolana, "SolanaSolana", nullptr },
    // clang-format on
};

// Create PyDerivation from enum TWDerivation. It returns the same PyDerivation
// instance for the same enum TWDerivation value.
PyObject* PyDerivation_FromTWDerivation(TWDerivation value) {
  Constant* constant =
      std::find_if(std::begin(constants), std::end(constants),
                   [value](const Constant& v) { return v.value == value; });

  if (!constant) {
    PyErr_Format(PyExc_ValueError, "Invalid Derivation value: %d", value);
    return nullptr;
  }

  if (!constant->pyvalue) {
    auto* pyvalue = PyObject_New(PyDerivationObject, &PyDerivationType);
    *const_cast<TWDerivation*>(&pyvalue->value) = value;
    constant->pyvalue = (PyObject*)pyvalue;
  }

  Py_INCREF(constant->pyvalue);
  return constant->pyvalue;
}

TWDerivation PyDerivation_GetTWDerivation(PyObject* object) {
  assert(PyDerivation_Check(object));
  return ((PyDerivationObject*)object)->value;
}

static int PyDerivation_init(PyDerivationObject* self,
                             PyObject* args,
                             PyObject* kwds) {
  return 0;
}

static PyObject* PyDerivation_new(PyTypeObject* subtype,
                                  PyObject* args,
                                  PyObject* kwds) {
  int value = 0;
  if (!PyArg_ParseTuple(args, "|i", &value)) {
    return nullptr;
  }
  return PyDerivation_FromTWDerivation((TWDerivation)value);
}

static PyObject* PyDerivation_str(PyDerivationObject* self) {
  Constant* constant = std::find_if(
      std::begin(constants), std::end(constants),
      [self](const Constant& v) { return v.value == self->value; });

  return PyUnicode_FromString(constant ? constant->name : "Unknown");
}

// properties

static const PyGetSetDef get_set_defs[] = {{}};

static const PyMethodDef method_defs[] = {{}};

bool PyInit_Derivation(PyObject* module) {
  PyDerivationType.tp_new = PyDerivation_new;
  PyDerivationType.tp_init = (initproc)PyDerivation_init;
  PyDerivationType.tp_str = (reprfunc)PyDerivation_str;
  PyDerivationType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyDerivationType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyDerivationType) < 0)
    return false;

  Py_INCREF(&PyDerivationType);
  if (PyModule_AddObject(module, "Derivation", (PyObject*)&PyDerivationType) <
      0) {
    Py_DECREF(&PyDerivationType);
    return false;
  }

  PyObject* dict = PyDerivationType.tp_dict;
  (void)dict;

  for (const Constant& constant : constants) {
    PyDict_SetItemString(dict, constant.name,
                         PyDerivation_FromTWDerivation(constant.value));
  }

  return true;
}