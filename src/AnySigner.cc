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

#include "AnySigner.h"

#include "Data.h"
#include "String.h"
#include "generated/CoinType.h"

struct PyAnySignerObject {
  PyObject_HEAD;
};

static PyTypeObject PyAnySignerType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.AnySigner",    /* tp_name */
    sizeof(PyAnySignerObject), /* tp_basicsize */
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

// static method function for Sign
static const char PyAnySignerSign_doc[] =
    "TWData* TWAnySignerSign(TWData* input, enum TWCoinType coin)";
static PyObject* PyAnySignerSign(PyAnySignerObject* self,
                                 PyObject* const* args,
                                 Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  if (!PyBytes_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Bytes");
    return nullptr;
  }
  auto arg0 = PyBytes_GetTWData(args[0]);

  if (!PyCoinType_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type CoinType");
    return nullptr;
  }
  auto arg1 = PyCoinType_GetTWCoinType(args[1]);

  TWDataPtr result(TWAnySignerSign(arg0.get(), arg1));
  return PyBytes_FromTWData(result);
}

// static method function for SignJSON
static const char PyAnySignerSignJSON_doc[] =
    "TWString* TWAnySignerSignJSON(TWString* json, TWData* key, enum "
    "TWCoinType coin)";
static PyObject* PyAnySignerSignJSON(PyAnySignerObject* self,
                                     PyObject* const* args,
                                     Py_ssize_t nargs) {
  if (nargs != 3) {
    PyErr_Format(PyExc_TypeError, "Expect 3 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  if (!PyUnicode_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Unicode");
    return nullptr;
  }
  auto arg0 = PyUnicode_GetTWString(args[0]);

  if (!PyBytes_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bytes");
    return nullptr;
  }
  auto arg1 = PyBytes_GetTWData(args[1]);

  if (!PyCoinType_Check(args[2])) {
    PyErr_SetString(PyExc_TypeError, "The arg 2 is not in type CoinType");
    return nullptr;
  }
  auto arg2 = PyCoinType_GetTWCoinType(args[2]);

  TWStringPtr result(TWAnySignerSignJSON(arg0.get(), arg1.get(), arg2));
  return PyUnicode_FromTWString(result);
}

// static method function for SupportsJSON
static const char PyAnySignerSupportsJSON_doc[] =
    "bool TWAnySignerSupportsJSON(enum TWCoinType coin)";
static PyObject* PyAnySignerSupportsJSON(PyAnySignerObject* self,
                                         PyObject* const* args,
                                         Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  if (!PyCoinType_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type CoinType");
    return nullptr;
  }
  auto arg0 = PyCoinType_GetTWCoinType(args[0]);

  bool result = TWAnySignerSupportsJSON(arg0);
  return PyBool_FromLong(result);
}

// static method function for Plan
static const char PyAnySignerPlan_doc[] =
    "TWData* TWAnySignerPlan(TWData* input, enum TWCoinType coin)";
static PyObject* PyAnySignerPlan(PyAnySignerObject* self,
                                 PyObject* const* args,
                                 Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  if (!PyBytes_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Bytes");
    return nullptr;
  }
  auto arg0 = PyBytes_GetTWData(args[0]);

  if (!PyCoinType_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type CoinType");
    return nullptr;
  }
  auto arg1 = PyCoinType_GetTWCoinType(args[1]);

  TWDataPtr result(TWAnySignerPlan(arg0.get(), arg1));
  return PyBytes_FromTWData(result);
}

static const PyGetSetDef get_set_defs[] = {{}};

static const PyMethodDef method_defs[] = {
    {"sign", (PyCFunction)PyAnySignerSign, METH_FASTCALL | METH_STATIC,
     PyAnySignerSign_doc},
    {"sign_json", (PyCFunction)PyAnySignerSignJSON, METH_FASTCALL | METH_STATIC,
     PyAnySignerSignJSON_doc},
    {"supports_json", (PyCFunction)PyAnySignerSupportsJSON,
     METH_FASTCALL | METH_STATIC, PyAnySignerSupportsJSON_doc},
    {"plan", (PyCFunction)PyAnySignerPlan, METH_FASTCALL | METH_STATIC,
     PyAnySignerPlan_doc},
    {}};

bool PyInit_AnySigner(PyObject* module) {
  PyAnySignerType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyAnySignerType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyAnySignerType) < 0)
    return false;

  Py_INCREF(&PyAnySignerType);
  if (PyModule_AddObject(module, "AnySigner", (PyObject*)&PyAnySignerType) <
      0) {
    Py_DECREF(&PyAnySignerType);
    return false;
  }

  return true;
}