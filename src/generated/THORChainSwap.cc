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

#include "generated/THORChainSwap.h"

#include "Data.h"

struct PyTHORChainSwapObject {
  PyObject_HEAD;
};

static PyTypeObject PyTHORChainSwapType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.THORChainSwap",    /* tp_name */
    sizeof(PyTHORChainSwapObject), /* tp_basicsize */
    0,                             /* tp_itemsize */
    0,                             /* tp_dealloc */
    0,                             /* tp_print */
    0,                             /* tp_getattr */
    0,                             /* tp_setattr */
    0,                             /* tp_reserved */
    0,                             /* tp_repr */
    0,                             /* tp_as_number */
    0,                             /* tp_as_sequence */
    0,                             /* tp_as_mapping */
    0,                             /* tp_hash  */
    0,                             /* tp_call */
    0,                             /* tp_str */
    0,                             /* tp_getattro */
    0,                             /* tp_setattro */
    0,                             /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,            /* tp_flags */
    nullptr,                       /* tp_doc */
};

// static method function for BuildSwap
static const char PyTHORChainSwapBuildSwap_doc[] =
    "TWData* TWTHORChainSwapBuildSwap(TWData* input)";
static PyObject* PyTHORChainSwapBuildSwap(PyTHORChainSwapObject* self,
                                          PyObject* const* args,
                                          Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  if (!PyBytes_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Bytes");
    return nullptr;
  }
  auto arg0 = PyBytes_GetTWData(args[0]);

  TWDataPtr result(TWTHORChainSwapBuildSwap(arg0.get()));
  return PyBytes_FromTWData(result);
}

// properties

static const PyGetSetDef get_set_defs[] = {{}};

static const PyMethodDef method_defs[] = {
    {"build_swap", (PyCFunction)PyTHORChainSwapBuildSwap,
     METH_FASTCALL | METH_STATIC, PyTHORChainSwapBuildSwap_doc},
    {}};

bool PyInit_THORChainSwap(PyObject* module) {
  PyTHORChainSwapType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyTHORChainSwapType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyTHORChainSwapType) < 0)
    return false;

  Py_INCREF(&PyTHORChainSwapType);
  if (PyModule_AddObject(module, "THORChainSwap",
                         (PyObject*)&PyTHORChainSwapType) < 0) {
    Py_DECREF(&PyTHORChainSwapType);
    return false;
  }

  return true;
}