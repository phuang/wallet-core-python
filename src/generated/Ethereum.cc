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

#include "generated/Ethereum.h"

#include "String.h"

struct PyEthereumObject {
  PyObject_HEAD;
};

static PyTypeObject PyEthereumType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.Ethereum",    /* tp_name */
    sizeof(PyEthereumObject), /* tp_basicsize */
    0,                        /* tp_itemsize */
    0,                        /* tp_dealloc */
    0,                        /* tp_print */
    0,                        /* tp_getattr */
    0,                        /* tp_setattr */
    0,                        /* tp_reserved */
    0,                        /* tp_repr */
    0,                        /* tp_as_number */
    0,                        /* tp_as_sequence */
    0,                        /* tp_as_mapping */
    0,                        /* tp_hash  */
    0,                        /* tp_call */
    0,                        /* tp_str */
    0,                        /* tp_getattro */
    0,                        /* tp_setattro */
    0,                        /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,       /* tp_flags */
    nullptr,                  /* tp_doc */
};

// static method function for Eip2645GetPath
static const char PyEthereumEip2645GetPath_doc[] =
    "TWString* TWEthereumEip2645GetPath(TWString* ethAddress, TWString* layer, "
    "TWString* application, TWString* index)";
static PyObject* PyEthereumEip2645GetPath(PyEthereumObject* self,
                                          PyObject* const* args,
                                          Py_ssize_t nargs) {
  if (nargs != 4) {
    PyErr_Format(PyExc_TypeError, "Expect 4 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  if (!PyUnicode_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Unicode");
    return nullptr;
  }
  auto arg0 = PyUnicode_GetTWString(args[0]);

  if (!PyUnicode_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Unicode");
    return nullptr;
  }
  auto arg1 = PyUnicode_GetTWString(args[1]);

  if (!PyUnicode_Check(args[2])) {
    PyErr_SetString(PyExc_TypeError, "The arg 2 is not in type Unicode");
    return nullptr;
  }
  auto arg2 = PyUnicode_GetTWString(args[2]);

  if (!PyUnicode_Check(args[3])) {
    PyErr_SetString(PyExc_TypeError, "The arg 3 is not in type Unicode");
    return nullptr;
  }
  auto arg3 = PyUnicode_GetTWString(args[3]);

  TWStringPtr result(
      TWEthereumEip2645GetPath(arg0.get(), arg1.get(), arg2.get(), arg3.get()));
  return PyUnicode_FromTWString(result);
}

// static method function for Eip4337GetDeploymentAddress
static const char PyEthereumEip4337GetDeploymentAddress_doc[] =
    "TWString* TWEthereumEip4337GetDeploymentAddress(TWString* factoryAddress, "
    "TWString* logicAddress, TWString* ownerAddress)";
static PyObject* PyEthereumEip4337GetDeploymentAddress(PyEthereumObject* self,
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

  if (!PyUnicode_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Unicode");
    return nullptr;
  }
  auto arg1 = PyUnicode_GetTWString(args[1]);

  if (!PyUnicode_Check(args[2])) {
    PyErr_SetString(PyExc_TypeError, "The arg 2 is not in type Unicode");
    return nullptr;
  }
  auto arg2 = PyUnicode_GetTWString(args[2]);

  TWStringPtr result(TWEthereumEip4337GetDeploymentAddress(
      arg0.get(), arg1.get(), arg2.get()));
  return PyUnicode_FromTWString(result);
}

// properties

static const PyGetSetDef get_set_defs[] = {{}};

static const PyMethodDef method_defs[] = {
    {"eip2645_get_path", (PyCFunction)PyEthereumEip2645GetPath,
     METH_FASTCALL | METH_STATIC, PyEthereumEip2645GetPath_doc},
    {"eip4337_get_deployment_address",
     (PyCFunction)PyEthereumEip4337GetDeploymentAddress,
     METH_FASTCALL | METH_STATIC, PyEthereumEip4337GetDeploymentAddress_doc},
    {}};

bool PyInit_Ethereum(PyObject* module) {
  PyEthereumType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyEthereumType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyEthereumType) < 0)
    return false;

  Py_INCREF(&PyEthereumType);
  if (PyModule_AddObject(module, "Ethereum", (PyObject*)&PyEthereumType) < 0) {
    Py_DECREF(&PyEthereumType);
    return false;
  }

  return true;
}