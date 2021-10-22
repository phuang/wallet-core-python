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

#include "StellarMemoType.h"

#include <algorithm>
#include <iterator>

#define CONSTANTS(I) \
  I(None)            \
  I(Text)            \
  I(Id)              \
  I(Hash)            \
  I(Return)

static PyTypeObject PyStellarMemoTypeType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.StellarMemoType",    /* tp_name */
    sizeof(PyStellarMemoTypeObject), /* tp_basicsize */
    0,                               /* tp_itemsize */
    0,                               /* tp_dealloc */
    0,                               /* tp_print */
    0,                               /* tp_getattr */
    0,                               /* tp_setattr */
    0,                               /* tp_reserved */
    0,                               /* tp_repr */
    0,                               /* tp_as_number */
    0,                               /* tp_as_sequence */
    0,                               /* tp_as_mapping */
    0,                               /* tp_hash  */
    0,                               /* tp_call */
    0,                               /* tp_str */
    0,                               /* tp_getattro */
    0,                               /* tp_setattro */
    0,                               /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,              /* tp_flags */
    nullptr,                         /* tp_doc */
};

bool PyStellarMemoType_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyStellarMemoTypeType) != 0;
}

// Create PyStellarMemoType from enum TWStellarMemoType. It returns the same
// PyStellarMemoType instance for the same enum TWStellarMemoType value.
PyObject* PyStellarMemoType_FromTWStellarMemoType(TWStellarMemoType value) {
  struct ValuePair {
    const TWStellarMemoType value;
    PyObject* pyvalue;
  };
#define I(name) {TWStellarMemoType##name, nullptr},
  static ValuePair constants[] = {CONSTANTS(I)};
#undef I

  ValuePair* value_pair =
      std::find_if(std::begin(constants), std::end(constants),
                   [&value](const ValuePair& v) { return v.value == value; });

  if (!value_pair) {
    PyErr_Format(PyExc_ValueError, "Invalid StellarMemoType value: %d", value);
    return nullptr;
  }

  if (!value_pair->pyvalue) {
    auto* pyvalue =
        PyObject_New(PyStellarMemoTypeObject, &PyStellarMemoTypeType);
    *const_cast<TWStellarMemoType*>(&pyvalue->value) = value;
    value_pair->pyvalue = (PyObject*)pyvalue;
  }

  Py_INCREF(value_pair->pyvalue);
  return value_pair->pyvalue;
}

TWStellarMemoType PyStellarMemoType_GetTWStellarMemoType(PyObject* object) {
  assert(PyStellarMemoType_Check(object));
  return ((PyStellarMemoTypeObject*)object)->value;
}

static int PyStellarMemoType_init(PyStellarMemoTypeObject* self,
                                  PyObject* args,
                                  PyObject* kwds) {
  return 0;
}

static PyObject* PyStellarMemoType_new(PyTypeObject* subtype,
                                       PyObject* args,
                                       PyObject* kwds) {
  int value = 0;
  if (!PyArg_ParseTuple(args, "|i", &value)) {
    return nullptr;
  }
  return PyStellarMemoType_FromTWStellarMemoType((TWStellarMemoType)value);
}

static PyObject* PyStellarMemoType_str(PyStellarMemoTypeObject* self) {
  const char* str = "Unknown";
  switch (self->value) {
#define I(name)                 \
  case TWStellarMemoType##name: \
    str = #name;                \
    break;
    CONSTANTS(I)
#undef I
  }
  return PyUnicode_FromString(str);
}

static const PyGetSetDef get_set_defs[] = {{}};

static const PyMethodDef method_defs[] = {{}};

bool PyInit_StellarMemoType(PyObject* module) {
  PyStellarMemoTypeType.tp_new = PyStellarMemoType_new;
  PyStellarMemoTypeType.tp_init = (initproc)PyStellarMemoType_init;
  PyStellarMemoTypeType.tp_str = (reprfunc)PyStellarMemoType_str;
  PyStellarMemoTypeType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyStellarMemoTypeType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyStellarMemoTypeType) < 0)
    return false;

  Py_INCREF(&PyStellarMemoTypeType);
  if (PyModule_AddObject(module, "StellarMemoType",
                         (PyObject*)&PyStellarMemoTypeType) < 0) {
    Py_DECREF(&PyStellarMemoTypeType);
    return false;
  }

  PyObject* dict = PyStellarMemoTypeType.tp_dict;
  (void)dict;

#define I(name)         \
  PyDict_SetItemString( \
      dict, #name,      \
      PyStellarMemoType_FromTWStellarMemoType(TWStellarMemoType##name));
  CONSTANTS(I)
#undef I

  return true;
}