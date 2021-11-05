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

#include "generated/StellarPassphrase.h"

#include <algorithm>
#include <iterator>

static PyTypeObject PyStellarPassphraseType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.StellarPassphrase",    /* tp_name */
    sizeof(PyStellarPassphraseObject), /* tp_basicsize */
    0,                                 /* tp_itemsize */
    0,                                 /* tp_dealloc */
    0,                                 /* tp_print */
    0,                                 /* tp_getattr */
    0,                                 /* tp_setattr */
    0,                                 /* tp_reserved */
    0,                                 /* tp_repr */
    0,                                 /* tp_as_number */
    0,                                 /* tp_as_sequence */
    0,                                 /* tp_as_mapping */
    0,                                 /* tp_hash  */
    0,                                 /* tp_call */
    0,                                 /* tp_str */
    0,                                 /* tp_getattro */
    0,                                 /* tp_setattro */
    0,                                 /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                /* tp_flags */
    nullptr,                           /* tp_doc */
};

bool PyStellarPassphrase_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyStellarPassphraseType) != 0;
}

struct Constant {
  const TWStellarPassphrase value;
  const char* name;
  PyObject* pyvalue;
};

static Constant constants[] = {
    // clang-format off
    { TWStellarPassphraseStellar, "Stellar", nullptr },
    { TWStellarPassphraseKin, "Kin", nullptr },
    // clang-format on
};

// Create PyStellarPassphrase from enum TWStellarPassphrase. It returns the same
// PyStellarPassphrase instance for the same enum TWStellarPassphrase value.
PyObject* PyStellarPassphrase_FromTWStellarPassphrase(
    TWStellarPassphrase value) {
  Constant* constant =
      std::find_if(std::begin(constants), std::end(constants),
                   [value](const Constant& v) { return v.value == value; });

  if (!constant) {
    PyErr_Format(PyExc_ValueError, "Invalid StellarPassphrase value: %d",
                 value);
    return nullptr;
  }

  if (!constant->pyvalue) {
    auto* pyvalue =
        PyObject_New(PyStellarPassphraseObject, &PyStellarPassphraseType);
    *const_cast<TWStellarPassphrase*>(&pyvalue->value) = value;
    constant->pyvalue = (PyObject*)pyvalue;
  }

  Py_INCREF(constant->pyvalue);
  return constant->pyvalue;
}

TWStellarPassphrase PyStellarPassphrase_GetTWStellarPassphrase(
    PyObject* object) {
  assert(PyStellarPassphrase_Check(object));
  return ((PyStellarPassphraseObject*)object)->value;
}

static int PyStellarPassphrase_init(PyStellarPassphraseObject* self,
                                    PyObject* args,
                                    PyObject* kwds) {
  return 0;
}

static PyObject* PyStellarPassphrase_new(PyTypeObject* subtype,
                                         PyObject* args,
                                         PyObject* kwds) {
  int value = 0;
  if (!PyArg_ParseTuple(args, "|i", &value)) {
    return nullptr;
  }
  return PyStellarPassphrase_FromTWStellarPassphrase(
      (TWStellarPassphrase)value);
}

static PyObject* PyStellarPassphrase_str(PyStellarPassphraseObject* self) {
  Constant* constant = std::find_if(
      std::begin(constants), std::end(constants),
      [self](const Constant& v) { return v.value == self->value; });

  return PyUnicode_FromString(constant ? constant->name : "Unknown");
}

// properties

static const PyGetSetDef get_set_defs[] = {{}};

static const PyMethodDef method_defs[] = {{}};

bool PyInit_StellarPassphrase(PyObject* module) {
  PyStellarPassphraseType.tp_new = PyStellarPassphrase_new;
  PyStellarPassphraseType.tp_init = (initproc)PyStellarPassphrase_init;
  PyStellarPassphraseType.tp_str = (reprfunc)PyStellarPassphrase_str;
  PyStellarPassphraseType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyStellarPassphraseType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyStellarPassphraseType) < 0)
    return false;

  Py_INCREF(&PyStellarPassphraseType);
  if (PyModule_AddObject(module, "StellarPassphrase",
                         (PyObject*)&PyStellarPassphraseType) < 0) {
    Py_DECREF(&PyStellarPassphraseType);
    return false;
  }

  PyObject* dict = PyStellarPassphraseType.tp_dict;
  (void)dict;

  for (const Constant& constant : constants) {
    PyDict_SetItemString(
        dict, constant.name,
        PyStellarPassphrase_FromTWStellarPassphrase(constant.value));
  }

  return true;
}