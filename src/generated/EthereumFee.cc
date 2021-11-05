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

#include "generated/EthereumFee.h"

#include "String.h"

struct PyEthereumFeeObject {
  PyObject_HEAD;
};

static PyTypeObject PyEthereumFeeType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.EthereumFee",    /* tp_name */
    sizeof(PyEthereumFeeObject), /* tp_basicsize */
    0,                           /* tp_itemsize */
    0,                           /* tp_dealloc */
    0,                           /* tp_print */
    0,                           /* tp_getattr */
    0,                           /* tp_setattr */
    0,                           /* tp_reserved */
    0,                           /* tp_repr */
    0,                           /* tp_as_number */
    0,                           /* tp_as_sequence */
    0,                           /* tp_as_mapping */
    0,                           /* tp_hash  */
    0,                           /* tp_call */
    0,                           /* tp_str */
    0,                           /* tp_getattro */
    0,                           /* tp_setattro */
    0,                           /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,          /* tp_flags */
    nullptr,                     /* tp_doc */
};

// static method function for Suggest
static const char PyEthereumFeeSuggest_doc[] =
    "TWString* TWEthereumFeeSuggest(TWString* feeHistory)";
static PyObject* PyEthereumFeeSuggest(PyEthereumFeeObject* self,
                                      PyObject* const* args,
                                      Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  if (!PyUnicode_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Unicode");
    return nullptr;
  }
  auto arg0 = PyUnicode_GetTWString(args[0]);

  TWStringPtr result(TWEthereumFeeSuggest(arg0.get()));
  return PyUnicode_FromTWString(result);
}

// properties

static const PyGetSetDef get_set_defs[] = {{}};

static const PyMethodDef method_defs[] = {
    {"suggest", (PyCFunction)PyEthereumFeeSuggest, METH_FASTCALL | METH_STATIC,
     PyEthereumFeeSuggest_doc},
    {}};

bool PyInit_EthereumFee(PyObject* module) {
  PyEthereumFeeType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyEthereumFeeType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyEthereumFeeType) < 0)
    return false;

  Py_INCREF(&PyEthereumFeeType);
  if (PyModule_AddObject(module, "EthereumFee", (PyObject*)&PyEthereumFeeType) <
      0) {
    Py_DECREF(&PyEthereumFeeType);
    return false;
  }

  return true;
}