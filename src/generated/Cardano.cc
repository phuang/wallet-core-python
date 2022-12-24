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

#include "generated/Cardano.h"

#include "Data.h"
#include "String.h"

struct PyCardanoObject {
  PyObject_HEAD;
};

static PyTypeObject PyCardanoType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.Cardano",    /* tp_name */
    sizeof(PyCardanoObject), /* tp_basicsize */
    0,                       /* tp_itemsize */
    0,                       /* tp_dealloc */
    0,                       /* tp_print */
    0,                       /* tp_getattr */
    0,                       /* tp_setattr */
    0,                       /* tp_reserved */
    0,                       /* tp_repr */
    0,                       /* tp_as_number */
    0,                       /* tp_as_sequence */
    0,                       /* tp_as_mapping */
    0,                       /* tp_hash  */
    0,                       /* tp_call */
    0,                       /* tp_str */
    0,                       /* tp_getattro */
    0,                       /* tp_setattro */
    0,                       /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,      /* tp_flags */
    nullptr,                 /* tp_doc */
};

// static method function for MinAdaAmount
static const char PyCardanoMinAdaAmount_doc[] =
    "uint64_t TWCardanoMinAdaAmount(TWData* tokenBundle)";
static PyObject* PyCardanoMinAdaAmount(PyCardanoObject* self,
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

  uint64_t result = TWCardanoMinAdaAmount(arg0.get());
  return PyLong_FromLong(result);
}

// static method function for GetStakingAddress
static const char PyCardanoGetStakingAddress_doc[] =
    "TWString* TWCardanoGetStakingAddress(TWString* baseAddress)";
static PyObject* PyCardanoGetStakingAddress(PyCardanoObject* self,
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

  TWStringPtr result(TWCardanoGetStakingAddress(arg0.get()));
  return PyUnicode_FromTWString(result);
}

// properties

static const PyGetSetDef get_set_defs[] = {{}};

static const PyMethodDef method_defs[] = {
    {"min_ada_amount", (PyCFunction)PyCardanoMinAdaAmount,
     METH_FASTCALL | METH_STATIC, PyCardanoMinAdaAmount_doc},
    {"get_staking_address", (PyCFunction)PyCardanoGetStakingAddress,
     METH_FASTCALL | METH_STATIC, PyCardanoGetStakingAddress_doc},
    {}};

bool PyInit_Cardano(PyObject* module) {
  PyCardanoType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyCardanoType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyCardanoType) < 0)
    return false;

  Py_INCREF(&PyCardanoType);
  if (PyModule_AddObject(module, "Cardano", (PyObject*)&PyCardanoType) < 0) {
    Py_DECREF(&PyCardanoType);
    return false;
  }

  return true;
}