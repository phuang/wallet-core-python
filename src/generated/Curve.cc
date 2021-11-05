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

#include "generated/Curve.h"

#include <algorithm>
#include <iterator>

static PyTypeObject PyCurveType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.Curve",    /* tp_name */
    sizeof(PyCurveObject), /* tp_basicsize */
    0,                     /* tp_itemsize */
    0,                     /* tp_dealloc */
    0,                     /* tp_print */
    0,                     /* tp_getattr */
    0,                     /* tp_setattr */
    0,                     /* tp_reserved */
    0,                     /* tp_repr */
    0,                     /* tp_as_number */
    0,                     /* tp_as_sequence */
    0,                     /* tp_as_mapping */
    0,                     /* tp_hash  */
    0,                     /* tp_call */
    0,                     /* tp_str */
    0,                     /* tp_getattro */
    0,                     /* tp_setattro */
    0,                     /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,    /* tp_flags */
    nullptr,               /* tp_doc */
};

bool PyCurve_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyCurveType) != 0;
}

struct Constant {
  const TWCurve value;
  const char* name;
  PyObject* pyvalue;
};

static Constant constants[] = {
    // clang-format off
    { TWCurveSECP256k1, "SECP256k1", nullptr },
    { TWCurveED25519, "ED25519", nullptr },
    { TWCurveED25519Blake2bNano, "ED25519Blake2bNano", nullptr },
    { TWCurveCurve25519, "Curve25519", nullptr },
    { TWCurveNIST256p1, "NIST256p1", nullptr },
    { TWCurveED25519Extended, "ED25519Extended", nullptr },
    { TWCurveNone, "None", nullptr },
    // clang-format on
};

// Create PyCurve from enum TWCurve. It returns the same PyCurve instance
// for the same enum TWCurve value.
PyObject* PyCurve_FromTWCurve(TWCurve value) {
  Constant* constant =
      std::find_if(std::begin(constants), std::end(constants),
                   [value](const Constant& v) { return v.value == value; });

  if (!constant) {
    PyErr_Format(PyExc_ValueError, "Invalid Curve value: %d", value);
    return nullptr;
  }

  if (!constant->pyvalue) {
    auto* pyvalue = PyObject_New(PyCurveObject, &PyCurveType);
    *const_cast<TWCurve*>(&pyvalue->value) = value;
    constant->pyvalue = (PyObject*)pyvalue;
  }

  Py_INCREF(constant->pyvalue);
  return constant->pyvalue;
}

TWCurve PyCurve_GetTWCurve(PyObject* object) {
  assert(PyCurve_Check(object));
  return ((PyCurveObject*)object)->value;
}

static int PyCurve_init(PyCurveObject* self, PyObject* args, PyObject* kwds) {
  return 0;
}

static PyObject* PyCurve_new(PyTypeObject* subtype,
                             PyObject* args,
                             PyObject* kwds) {
  int value = 0;
  if (!PyArg_ParseTuple(args, "|i", &value)) {
    return nullptr;
  }
  return PyCurve_FromTWCurve((TWCurve)value);
}

static PyObject* PyCurve_str(PyCurveObject* self) {
  Constant* constant = std::find_if(
      std::begin(constants), std::end(constants),
      [self](const Constant& v) { return v.value == self->value; });

  return PyUnicode_FromString(constant ? constant->name : "Unknown");
}

// properties

static const PyGetSetDef get_set_defs[] = {{}};

static const PyMethodDef method_defs[] = {{}};

bool PyInit_Curve(PyObject* module) {
  PyCurveType.tp_new = PyCurve_new;
  PyCurveType.tp_init = (initproc)PyCurve_init;
  PyCurveType.tp_str = (reprfunc)PyCurve_str;
  PyCurveType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyCurveType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyCurveType) < 0)
    return false;

  Py_INCREF(&PyCurveType);
  if (PyModule_AddObject(module, "Curve", (PyObject*)&PyCurveType) < 0) {
    Py_DECREF(&PyCurveType);
    return false;
  }

  PyObject* dict = PyCurveType.tp_dict;
  (void)dict;

  for (const Constant& constant : constants) {
    PyDict_SetItemString(dict, constant.name,
                         PyCurve_FromTWCurve(constant.value));
  }

  return true;
}