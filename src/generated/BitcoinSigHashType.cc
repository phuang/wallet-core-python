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

#include "generated/BitcoinSigHashType.h"

#include <algorithm>
#include <iterator>

static PyTypeObject PyBitcoinSigHashTypeType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.BitcoinSigHashType",    /* tp_name */
    sizeof(PyBitcoinSigHashTypeObject), /* tp_basicsize */
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

bool PyBitcoinSigHashType_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyBitcoinSigHashTypeType) != 0;
}

struct Constant {
  const TWBitcoinSigHashType value;
  const char* name;
  PyObject* pyvalue;
};

static Constant constants[] = {
    // clang-format off
    { TWBitcoinSigHashTypeAll, "All", nullptr },
    { TWBitcoinSigHashTypeNone, "None", nullptr },
    { TWBitcoinSigHashTypeSingle, "Single", nullptr },
    { TWBitcoinSigHashTypeFork, "Fork", nullptr },
    { TWBitcoinSigHashTypeForkBTG, "ForkBTG", nullptr },
    { TWBitcoinSigHashTypeAnyoneCanPay, "AnyoneCanPay", nullptr },
    // clang-format on
};

// Create PyBitcoinSigHashType from enum TWBitcoinSigHashType. It returns the
// same PyBitcoinSigHashType instance for the same enum TWBitcoinSigHashType
// value.
PyObject* PyBitcoinSigHashType_FromTWBitcoinSigHashType(
    TWBitcoinSigHashType value) {
  Constant* constant =
      std::find_if(std::begin(constants), std::end(constants),
                   [value](const Constant& v) { return v.value == value; });

  if (!constant) {
    PyErr_Format(PyExc_ValueError, "Invalid BitcoinSigHashType value: %d",
                 value);
    return nullptr;
  }

  if (!constant->pyvalue) {
    auto* pyvalue =
        PyObject_New(PyBitcoinSigHashTypeObject, &PyBitcoinSigHashTypeType);
    *const_cast<TWBitcoinSigHashType*>(&pyvalue->value) = value;
    constant->pyvalue = (PyObject*)pyvalue;
  }

  Py_INCREF(constant->pyvalue);
  return constant->pyvalue;
}

TWBitcoinSigHashType PyBitcoinSigHashType_GetTWBitcoinSigHashType(
    PyObject* object) {
  assert(PyBitcoinSigHashType_Check(object));
  return ((PyBitcoinSigHashTypeObject*)object)->value;
}

static int PyBitcoinSigHashType_init(PyBitcoinSigHashTypeObject* self,
                                     PyObject* args,
                                     PyObject* kwds) {
  return 0;
}

static PyObject* PyBitcoinSigHashType_new(PyTypeObject* subtype,
                                          PyObject* args,
                                          PyObject* kwds) {
  int value = 0;
  if (!PyArg_ParseTuple(args, "|i", &value)) {
    return nullptr;
  }
  return PyBitcoinSigHashType_FromTWBitcoinSigHashType(
      (TWBitcoinSigHashType)value);
}

static PyObject* PyBitcoinSigHashType_str(PyBitcoinSigHashTypeObject* self) {
  Constant* constant = std::find_if(
      std::begin(constants), std::end(constants),
      [self](const Constant& v) { return v.value == self->value; });

  return PyUnicode_FromString(constant ? constant->name : "Unknown");
}

// method function for IsSingle
static const char PyBitcoinSigHashTypeIsSingle_doc[] =
    "bool TWBitcoinSigHashTypeIsSingle(enum TWBitcoinSigHashType type)";
static PyObject* PyBitcoinSigHashTypeIsSingle(PyBitcoinSigHashTypeObject* self,
                                              PyObject* const* args,
                                              Py_ssize_t nargs) {
  if (nargs != 0) {
    PyErr_Format(PyExc_TypeError, "Expect 0 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  bool result = TWBitcoinSigHashTypeIsSingle(self->value);
  return PyBool_FromLong(result);
}

// method function for IsNone
static const char PyBitcoinSigHashTypeIsNone_doc[] =
    "bool TWBitcoinSigHashTypeIsNone(enum TWBitcoinSigHashType type)";
static PyObject* PyBitcoinSigHashTypeIsNone(PyBitcoinSigHashTypeObject* self,
                                            PyObject* const* args,
                                            Py_ssize_t nargs) {
  if (nargs != 0) {
    PyErr_Format(PyExc_TypeError, "Expect 0 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  bool result = TWBitcoinSigHashTypeIsNone(self->value);
  return PyBool_FromLong(result);
}

// properties

static const PyGetSetDef get_set_defs[] = {{}};

static const PyMethodDef method_defs[] = {
    {"is_single", (PyCFunction)PyBitcoinSigHashTypeIsSingle, METH_FASTCALL,
     PyBitcoinSigHashTypeIsSingle_doc},
    {"is_none", (PyCFunction)PyBitcoinSigHashTypeIsNone, METH_FASTCALL,
     PyBitcoinSigHashTypeIsNone_doc},
    {}};

bool PyInit_BitcoinSigHashType(PyObject* module) {
  PyBitcoinSigHashTypeType.tp_new = PyBitcoinSigHashType_new;
  PyBitcoinSigHashTypeType.tp_init = (initproc)PyBitcoinSigHashType_init;
  PyBitcoinSigHashTypeType.tp_str = (reprfunc)PyBitcoinSigHashType_str;
  PyBitcoinSigHashTypeType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyBitcoinSigHashTypeType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyBitcoinSigHashTypeType) < 0)
    return false;

  Py_INCREF(&PyBitcoinSigHashTypeType);
  if (PyModule_AddObject(module, "BitcoinSigHashType",
                         (PyObject*)&PyBitcoinSigHashTypeType) < 0) {
    Py_DECREF(&PyBitcoinSigHashTypeType);
    return false;
  }

  PyObject* dict = PyBitcoinSigHashTypeType.tp_dict;
  (void)dict;

  for (const Constant& constant : constants) {
    PyDict_SetItemString(
        dict, constant.name,
        PyBitcoinSigHashType_FromTWBitcoinSigHashType(constant.value));
  }

  return true;
}