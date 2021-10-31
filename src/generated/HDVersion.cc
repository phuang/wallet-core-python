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

#include "generated/HDVersion.h"

#include <algorithm>
#include <iterator>

#define CONSTANTS(I) \
  I(None)            \
  I(XPUB)            \
  I(XPRV)            \
  I(YPUB)            \
  I(YPRV)            \
  I(ZPUB)            \
  I(ZPRV)            \
  I(LTUB)            \
  I(LTPV)            \
  I(MTUB)            \
  I(MTPV)            \
  I(DPUB)            \
  I(DPRV)            \
  I(DGUB)            \
  I(DGPV)

static PyTypeObject PyHDVersionType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.HDVersion",    /* tp_name */
    sizeof(PyHDVersionObject), /* tp_basicsize */
    0,                         /* tp_itemsize */
    0,                         /* tp_dealloc */
    0,                         /* tp_print */
    0,                         /* tp_getattr */
    0,                         /* tp_setattr */
    0,                         /* tp_reserved */
    0,                         /* tp_repr */
    0,                         /* tp_as_number */
    0,                         /* tp_as_sequence */
    0,                         /* tp_as_mapping */
    0,                         /* tp_hash  */
    0,                         /* tp_call */
    0,                         /* tp_str */
    0,                         /* tp_getattro */
    0,                         /* tp_setattro */
    0,                         /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,        /* tp_flags */
    nullptr,                   /* tp_doc */
};

bool PyHDVersion_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyHDVersionType) != 0;
}

// Create PyHDVersion from enum TWHDVersion. It returns the same PyHDVersion
// instance for the same enum TWHDVersion value.
PyObject* PyHDVersion_FromTWHDVersion(TWHDVersion value) {
  struct ValuePair {
    const TWHDVersion value;
    PyObject* pyvalue;
  };
#define I(name) {TWHDVersion##name, nullptr},
  static ValuePair constants[] = {CONSTANTS(I)};
#undef I

  ValuePair* value_pair =
      std::find_if(std::begin(constants), std::end(constants),
                   [&value](const ValuePair& v) { return v.value == value; });

  if (!value_pair) {
    PyErr_Format(PyExc_ValueError, "Invalid HDVersion value: %d", value);
    return nullptr;
  }

  if (!value_pair->pyvalue) {
    auto* pyvalue = PyObject_New(PyHDVersionObject, &PyHDVersionType);
    *const_cast<TWHDVersion*>(&pyvalue->value) = value;
    value_pair->pyvalue = (PyObject*)pyvalue;
  }

  Py_INCREF(value_pair->pyvalue);
  return value_pair->pyvalue;
}

TWHDVersion PyHDVersion_GetTWHDVersion(PyObject* object) {
  assert(PyHDVersion_Check(object));
  return ((PyHDVersionObject*)object)->value;
}

static int PyHDVersion_init(PyHDVersionObject* self,
                            PyObject* args,
                            PyObject* kwds) {
  return 0;
}

static PyObject* PyHDVersion_new(PyTypeObject* subtype,
                                 PyObject* args,
                                 PyObject* kwds) {
  int value = 0;
  if (!PyArg_ParseTuple(args, "|i", &value)) {
    return nullptr;
  }
  return PyHDVersion_FromTWHDVersion((TWHDVersion)value);
}

static PyObject* PyHDVersion_str(PyHDVersionObject* self) {
  const char* str = "Unknown";
  switch (self->value) {
#define I(name)           \
  case TWHDVersion##name: \
    str = #name;          \
    break;
    CONSTANTS(I)
#undef I
  }
  return PyUnicode_FromString(str);
}

// getter function for IsPublic
static const char PyHDVersionIsPublic_doc[] =
    "bool TWHDVersionIsPublic(enum TWHDVersion version)";
static PyObject* PyHDVersionIsPublic(PyHDVersionObject* self, void*) {
  bool prop(TWHDVersionIsPublic(self->value));
  return PyBool_FromLong(prop);
}

// getter function for IsPrivate
static const char PyHDVersionIsPrivate_doc[] =
    "bool TWHDVersionIsPrivate(enum TWHDVersion version)";
static PyObject* PyHDVersionIsPrivate(PyHDVersionObject* self, void*) {
  bool prop(TWHDVersionIsPrivate(self->value));
  return PyBool_FromLong(prop);
}

static const PyGetSetDef get_set_defs[] = {
    {"is_public", (getter)PyHDVersionIsPublic, nullptr,
     PyHDVersionIsPublic_doc},
    {"is_private", (getter)PyHDVersionIsPrivate, nullptr,
     PyHDVersionIsPrivate_doc},
    {}};

static const PyMethodDef method_defs[] = {{}};

bool PyInit_HDVersion(PyObject* module) {
  PyHDVersionType.tp_new = PyHDVersion_new;
  PyHDVersionType.tp_init = (initproc)PyHDVersion_init;
  PyHDVersionType.tp_str = (reprfunc)PyHDVersion_str;
  PyHDVersionType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyHDVersionType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyHDVersionType) < 0)
    return false;

  Py_INCREF(&PyHDVersionType);
  if (PyModule_AddObject(module, "HDVersion", (PyObject*)&PyHDVersionType) <
      0) {
    Py_DECREF(&PyHDVersionType);
    return false;
  }

  PyObject* dict = PyHDVersionType.tp_dict;
  (void)dict;

#define I(name)                     \
  PyDict_SetItemString(dict, #name, \
                       PyHDVersion_FromTWHDVersion(TWHDVersion##name));
  CONSTANTS(I)
#undef I

  return true;
}