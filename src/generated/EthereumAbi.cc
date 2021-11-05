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

#include "generated/EthereumAbi.h"

#include "Data.h"
#include "String.h"
#include "generated/EthereumAbiFunction.h"

struct PyEthereumAbiObject {
  PyObject_HEAD;
};

static PyTypeObject PyEthereumAbiType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.EthereumAbi",    /* tp_name */
    sizeof(PyEthereumAbiObject), /* tp_basicsize */
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

// static method function for Encode
static const char PyEthereumAbiEncode_doc[] =
    "TWData* TWEthereumAbiEncode(struct TWEthereumAbiFunction* fn)";
static PyObject* PyEthereumAbiEncode(PyEthereumAbiObject* self,
                                     PyObject* const* args,
                                     Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  if (!PyEthereumAbiFunction_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError,
                    "The arg 0 is not in type EthereumAbiFunction");
    return nullptr;
  }
  auto arg0 = PyEthereumAbiFunction_GetTWEthereumAbiFunction(args[0]);

  TWDataPtr result(TWEthereumAbiEncode(arg0));
  return PyBytes_FromTWData(result);
}

// static method function for DecodeOutput
static const char PyEthereumAbiDecodeOutput_doc[] =
    "bool TWEthereumAbiDecodeOutput(struct TWEthereumAbiFunction* fn, TWData* "
    "encoded)";
static PyObject* PyEthereumAbiDecodeOutput(PyEthereumAbiObject* self,
                                           PyObject* const* args,
                                           Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  if (!PyEthereumAbiFunction_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError,
                    "The arg 0 is not in type EthereumAbiFunction");
    return nullptr;
  }
  auto arg0 = PyEthereumAbiFunction_GetTWEthereumAbiFunction(args[0]);

  if (!PyBytes_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bytes");
    return nullptr;
  }
  auto arg1 = PyBytes_GetTWData(args[1]);

  bool result = TWEthereumAbiDecodeOutput(arg0, arg1.get());
  return PyBool_FromLong(result);
}

// static method function for DecodeCall
static const char PyEthereumAbiDecodeCall_doc[] =
    "TWString* TWEthereumAbiDecodeCall(TWData* data, TWString* abi)";
static PyObject* PyEthereumAbiDecodeCall(PyEthereumAbiObject* self,
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

  if (!PyUnicode_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Unicode");
    return nullptr;
  }
  auto arg1 = PyUnicode_GetTWString(args[1]);

  TWStringPtr result(TWEthereumAbiDecodeCall(arg0.get(), arg1.get()));
  return PyUnicode_FromTWString(result);
}

// static method function for EncodeTyped
static const char PyEthereumAbiEncodeTyped_doc[] =
    "TWData* TWEthereumAbiEncodeTyped(TWString* messageJson)";
static PyObject* PyEthereumAbiEncodeTyped(PyEthereumAbiObject* self,
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

  TWDataPtr result(TWEthereumAbiEncodeTyped(arg0.get()));
  return PyBytes_FromTWData(result);
}

// properties

static const PyGetSetDef get_set_defs[] = {{}};

static const PyMethodDef method_defs[] = {
    {"encode", (PyCFunction)PyEthereumAbiEncode, METH_FASTCALL | METH_STATIC,
     PyEthereumAbiEncode_doc},
    {"decode_output", (PyCFunction)PyEthereumAbiDecodeOutput,
     METH_FASTCALL | METH_STATIC, PyEthereumAbiDecodeOutput_doc},
    {"decode_call", (PyCFunction)PyEthereumAbiDecodeCall,
     METH_FASTCALL | METH_STATIC, PyEthereumAbiDecodeCall_doc},
    {"encode_typed", (PyCFunction)PyEthereumAbiEncodeTyped,
     METH_FASTCALL | METH_STATIC, PyEthereumAbiEncodeTyped_doc},
    {}};

bool PyInit_EthereumAbi(PyObject* module) {
  PyEthereumAbiType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyEthereumAbiType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyEthereumAbiType) < 0)
    return false;

  Py_INCREF(&PyEthereumAbiType);
  if (PyModule_AddObject(module, "EthereumAbi", (PyObject*)&PyEthereumAbiType) <
      0) {
    Py_DECREF(&PyEthereumAbiType);
    return false;
  }

  return true;
}