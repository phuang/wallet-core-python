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

#include "generated/EthereumEip2645.h"

#include "String.h"

struct PyEthereumEip2645Object {
  PyObject_HEAD;
};

static PyTypeObject PyEthereumEip2645Type = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.EthereumEip2645",    /* tp_name */
    sizeof(PyEthereumEip2645Object), /* tp_basicsize */
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

// static method function for GetPath
static const char PyEthereumEip2645GetPath_doc[] =
    "TWString* TWEthereumEip2645GetPath(TWString* ethAddress, TWString* layer, "
    "TWString* application, TWString* index)";
static PyObject* PyEthereumEip2645GetPath(PyEthereumEip2645Object* self,
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

// properties

static const PyGetSetDef get_set_defs[] = {{}};

static const PyMethodDef method_defs[] = {
    {"get_path", (PyCFunction)PyEthereumEip2645GetPath,
     METH_FASTCALL | METH_STATIC, PyEthereumEip2645GetPath_doc},
    {}};

bool PyInit_EthereumEip2645(PyObject* module) {
  PyEthereumEip2645Type.tp_getset = (PyGetSetDef*)get_set_defs;
  PyEthereumEip2645Type.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyEthereumEip2645Type) < 0)
    return false;

  Py_INCREF(&PyEthereumEip2645Type);
  if (PyModule_AddObject(module, "EthereumEip2645",
                         (PyObject*)&PyEthereumEip2645Type) < 0) {
    Py_DECREF(&PyEthereumEip2645Type);
    return false;
  }

  return true;
}