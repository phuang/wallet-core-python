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

#include "generated/StellarVersionByte.h"

#include <algorithm>
#include <iterator>

static PyTypeObject PyStellarVersionByteType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.StellarVersionByte",    /* tp_name */
    sizeof(PyStellarVersionByteObject), /* tp_basicsize */
    0,                                  /* tp_itemsize */
    0,                                  /* tp_dealloc */
    0,                                  /* tp_print */
    0,                                  /* tp_getattr */
    0,                                  /* tp_setattr */
    0,                                  /* tp_reserved */
    0,                                  /* tp_repr */
    0,                                  /* tp_as_number */
    0,                                  /* tp_as_sequence */
    0,                                  /* tp_as_mapping */
    0,                                  /* tp_hash  */
    0,                                  /* tp_call */
    0,                                  /* tp_str */
    0,                                  /* tp_getattro */
    0,                                  /* tp_setattro */
    0,                                  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                 /* tp_flags */
    nullptr,                            /* tp_doc */
};

bool PyStellarVersionByte_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyStellarVersionByteType) != 0;
}

struct Constant {
  const TWStellarVersionByte value;
  const char* name;
  PyObject* pyvalue;
};

static Constant constants[] = {
    // clang-format off
    { TWStellarVersionByteAccountID, "AccountID", nullptr },
    { TWStellarVersionByteSeed, "Seed", nullptr },
    { TWStellarVersionBytePreAuthTX, "PreAuthTX", nullptr },
    { TWStellarVersionByteSHA256Hash, "SHA256Hash", nullptr },
    // clang-format on
};

// Create PyStellarVersionByte from enum TWStellarVersionByte. It returns the
// same PyStellarVersionByte instance for the same enum TWStellarVersionByte
// value.
PyObject* PyStellarVersionByte_FromTWStellarVersionByte(
    TWStellarVersionByte value) {
  Constant* constant =
      std::find_if(std::begin(constants), std::end(constants),
                   [value](const Constant& v) { return v.value == value; });

  if (!constant) {
    PyErr_Format(PyExc_ValueError, "Invalid StellarVersionByte value: %d",
                 value);
    return nullptr;
  }

  if (!constant->pyvalue) {
    auto* pyvalue =
        PyObject_New(PyStellarVersionByteObject, &PyStellarVersionByteType);
    *const_cast<TWStellarVersionByte*>(&pyvalue->value) = value;
    constant->pyvalue = (PyObject*)pyvalue;
  }

  Py_INCREF(constant->pyvalue);
  return constant->pyvalue;
}

TWStellarVersionByte PyStellarVersionByte_GetTWStellarVersionByte(
    PyObject* object) {
  assert(PyStellarVersionByte_Check(object));
  return ((PyStellarVersionByteObject*)object)->value;
}

static int PyStellarVersionByte_init(PyStellarVersionByteObject* self,
                                     PyObject* args,
                                     PyObject* kwds) {
  return 0;
}

static PyObject* PyStellarVersionByte_new(PyTypeObject* subtype,
                                          PyObject* args,
                                          PyObject* kwds) {
  int value = 0;
  if (!PyArg_ParseTuple(args, "|i", &value)) {
    return nullptr;
  }
  return PyStellarVersionByte_FromTWStellarVersionByte(
      (TWStellarVersionByte)value);
}

static PyObject* PyStellarVersionByte_str(PyStellarVersionByteObject* self) {
  Constant* constant = std::find_if(
      std::begin(constants), std::end(constants),
      [self](const Constant& v) { return v.value == self->value; });

  return PyUnicode_FromString(constant ? constant->name : "Unknown");
}

// properties

static const PyGetSetDef get_set_defs[] = {{}};

static const PyMethodDef method_defs[] = {{}};

bool PyInit_StellarVersionByte(PyObject* module) {
  PyStellarVersionByteType.tp_new = PyStellarVersionByte_new;
  PyStellarVersionByteType.tp_init = (initproc)PyStellarVersionByte_init;
  PyStellarVersionByteType.tp_str = (reprfunc)PyStellarVersionByte_str;
  PyStellarVersionByteType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyStellarVersionByteType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyStellarVersionByteType) < 0)
    return false;

  Py_INCREF(&PyStellarVersionByteType);
  if (PyModule_AddObject(module, "StellarVersionByte",
                         (PyObject*)&PyStellarVersionByteType) < 0) {
    Py_DECREF(&PyStellarVersionByteType);
    return false;
  }

  PyObject* dict = PyStellarVersionByteType.tp_dict;
  (void)dict;

  for (const Constant& constant : constants) {
    PyDict_SetItemString(
        dict, constant.name,
        PyStellarVersionByte_FromTWStellarVersionByte(constant.value));
  }

  return true;
}