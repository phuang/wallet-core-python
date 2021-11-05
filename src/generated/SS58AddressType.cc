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

#include "generated/SS58AddressType.h"

#include <algorithm>
#include <iterator>

static PyTypeObject PySS58AddressTypeType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.SS58AddressType",    /* tp_name */
    sizeof(PySS58AddressTypeObject), /* tp_basicsize */
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

bool PySS58AddressType_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PySS58AddressTypeType) != 0;
}

struct Constant {
  const TWSS58AddressType value;
  const char* name;
  PyObject* pyvalue;
};

static Constant constants[] = {
    // clang-format off
    { TWSS58AddressTypePolkadot, "Polkadot", nullptr },
    { TWSS58AddressTypeKusama, "Kusama", nullptr },
    // clang-format on
};

// Create PySS58AddressType from enum TWSS58AddressType. It returns the same
// PySS58AddressType instance for the same enum TWSS58AddressType value.
PyObject* PySS58AddressType_FromTWSS58AddressType(TWSS58AddressType value) {
  Constant* constant =
      std::find_if(std::begin(constants), std::end(constants),
                   [value](const Constant& v) { return v.value == value; });

  if (!constant) {
    PyErr_Format(PyExc_ValueError, "Invalid SS58AddressType value: %d", value);
    return nullptr;
  }

  if (!constant->pyvalue) {
    auto* pyvalue =
        PyObject_New(PySS58AddressTypeObject, &PySS58AddressTypeType);
    *const_cast<TWSS58AddressType*>(&pyvalue->value) = value;
    constant->pyvalue = (PyObject*)pyvalue;
  }

  Py_INCREF(constant->pyvalue);
  return constant->pyvalue;
}

TWSS58AddressType PySS58AddressType_GetTWSS58AddressType(PyObject* object) {
  assert(PySS58AddressType_Check(object));
  return ((PySS58AddressTypeObject*)object)->value;
}

static int PySS58AddressType_init(PySS58AddressTypeObject* self,
                                  PyObject* args,
                                  PyObject* kwds) {
  return 0;
}

static PyObject* PySS58AddressType_new(PyTypeObject* subtype,
                                       PyObject* args,
                                       PyObject* kwds) {
  int value = 0;
  if (!PyArg_ParseTuple(args, "|i", &value)) {
    return nullptr;
  }
  return PySS58AddressType_FromTWSS58AddressType((TWSS58AddressType)value);
}

static PyObject* PySS58AddressType_str(PySS58AddressTypeObject* self) {
  Constant* constant = std::find_if(
      std::begin(constants), std::end(constants),
      [self](const Constant& v) { return v.value == self->value; });

  return PyUnicode_FromString(constant ? constant->name : "Unknown");
}

// properties

static const PyGetSetDef get_set_defs[] = {{}};

static const PyMethodDef method_defs[] = {{}};

bool PyInit_SS58AddressType(PyObject* module) {
  PySS58AddressTypeType.tp_new = PySS58AddressType_new;
  PySS58AddressTypeType.tp_init = (initproc)PySS58AddressType_init;
  PySS58AddressTypeType.tp_str = (reprfunc)PySS58AddressType_str;
  PySS58AddressTypeType.tp_getset = (PyGetSetDef*)get_set_defs;
  PySS58AddressTypeType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PySS58AddressTypeType) < 0)
    return false;

  Py_INCREF(&PySS58AddressTypeType);
  if (PyModule_AddObject(module, "SS58AddressType",
                         (PyObject*)&PySS58AddressTypeType) < 0) {
    Py_DECREF(&PySS58AddressTypeType);
    return false;
  }

  PyObject* dict = PySS58AddressTypeType.tp_dict;
  (void)dict;

  for (const Constant& constant : constants) {
    PyDict_SetItemString(
        dict, constant.name,
        PySS58AddressType_FromTWSS58AddressType(constant.value));
  }

  return true;
}