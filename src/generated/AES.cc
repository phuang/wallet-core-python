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

#include "generated/AES.h"

#include "Data.h"
#include "generated/AESPaddingMode.h"

struct PyAESObject {
  PyObject_HEAD;
};

static PyTypeObject PyAESType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.AES",    /* tp_name */
    sizeof(PyAESObject), /* tp_basicsize */
    0,                   /* tp_itemsize */
    0,                   /* tp_dealloc */
    0,                   /* tp_print */
    0,                   /* tp_getattr */
    0,                   /* tp_setattr */
    0,                   /* tp_reserved */
    0,                   /* tp_repr */
    0,                   /* tp_as_number */
    0,                   /* tp_as_sequence */
    0,                   /* tp_as_mapping */
    0,                   /* tp_hash  */
    0,                   /* tp_call */
    0,                   /* tp_str */
    0,                   /* tp_getattro */
    0,                   /* tp_setattro */
    0,                   /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,  /* tp_flags */
    nullptr,             /* tp_doc */
};

// static method function for EncryptCBC
static const char PyAESEncryptCBC_doc[] =
    "TWData* TWAESEncryptCBC(TWData* key, TWData* data, TWData* iv, enum "
    "TWAESPaddingMode mode)";
static PyObject* PyAESEncryptCBC(PyAESObject* self,
                                 PyObject* const* args,
                                 Py_ssize_t nargs) {
  if (nargs != 4) {
    PyErr_Format(PyExc_TypeError, "Expect 4 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  if (!PyBytes_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Bytes");
    return nullptr;
  }
  auto arg0 = PyBytes_GetTWData(args[0]);

  if (!PyBytes_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bytes");
    return nullptr;
  }
  auto arg1 = PyBytes_GetTWData(args[1]);

  if (!PyBytes_Check(args[2])) {
    PyErr_SetString(PyExc_TypeError, "The arg 2 is not in type Bytes");
    return nullptr;
  }
  auto arg2 = PyBytes_GetTWData(args[2]);

  if (!PyAESPaddingMode_Check(args[3])) {
    PyErr_SetString(PyExc_TypeError, "The arg 3 is not in type AESPaddingMode");
    return nullptr;
  }
  auto arg3 = PyAESPaddingMode_GetTWAESPaddingMode(args[3]);

  TWDataPtr result(TWAESEncryptCBC(arg0.get(), arg1.get(), arg2.get(), arg3));
  return PyBytes_FromTWData(result);
}

// static method function for DecryptCBC
static const char PyAESDecryptCBC_doc[] =
    "TWData* TWAESDecryptCBC(TWData* key, TWData* data, TWData* iv, enum "
    "TWAESPaddingMode mode)";
static PyObject* PyAESDecryptCBC(PyAESObject* self,
                                 PyObject* const* args,
                                 Py_ssize_t nargs) {
  if (nargs != 4) {
    PyErr_Format(PyExc_TypeError, "Expect 4 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  if (!PyBytes_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Bytes");
    return nullptr;
  }
  auto arg0 = PyBytes_GetTWData(args[0]);

  if (!PyBytes_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bytes");
    return nullptr;
  }
  auto arg1 = PyBytes_GetTWData(args[1]);

  if (!PyBytes_Check(args[2])) {
    PyErr_SetString(PyExc_TypeError, "The arg 2 is not in type Bytes");
    return nullptr;
  }
  auto arg2 = PyBytes_GetTWData(args[2]);

  if (!PyAESPaddingMode_Check(args[3])) {
    PyErr_SetString(PyExc_TypeError, "The arg 3 is not in type AESPaddingMode");
    return nullptr;
  }
  auto arg3 = PyAESPaddingMode_GetTWAESPaddingMode(args[3]);

  TWDataPtr result(TWAESDecryptCBC(arg0.get(), arg1.get(), arg2.get(), arg3));
  return PyBytes_FromTWData(result);
}

// static method function for EncryptCTR
static const char PyAESEncryptCTR_doc[] =
    "TWData* TWAESEncryptCTR(TWData* key, TWData* data, TWData* iv)";
static PyObject* PyAESEncryptCTR(PyAESObject* self,
                                 PyObject* const* args,
                                 Py_ssize_t nargs) {
  if (nargs != 3) {
    PyErr_Format(PyExc_TypeError, "Expect 3 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  if (!PyBytes_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Bytes");
    return nullptr;
  }
  auto arg0 = PyBytes_GetTWData(args[0]);

  if (!PyBytes_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bytes");
    return nullptr;
  }
  auto arg1 = PyBytes_GetTWData(args[1]);

  if (!PyBytes_Check(args[2])) {
    PyErr_SetString(PyExc_TypeError, "The arg 2 is not in type Bytes");
    return nullptr;
  }
  auto arg2 = PyBytes_GetTWData(args[2]);

  TWDataPtr result(TWAESEncryptCTR(arg0.get(), arg1.get(), arg2.get()));
  return PyBytes_FromTWData(result);
}

// static method function for DecryptCTR
static const char PyAESDecryptCTR_doc[] =
    "TWData* TWAESDecryptCTR(TWData* key, TWData* data, TWData* iv)";
static PyObject* PyAESDecryptCTR(PyAESObject* self,
                                 PyObject* const* args,
                                 Py_ssize_t nargs) {
  if (nargs != 3) {
    PyErr_Format(PyExc_TypeError, "Expect 3 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  if (!PyBytes_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Bytes");
    return nullptr;
  }
  auto arg0 = PyBytes_GetTWData(args[0]);

  if (!PyBytes_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bytes");
    return nullptr;
  }
  auto arg1 = PyBytes_GetTWData(args[1]);

  if (!PyBytes_Check(args[2])) {
    PyErr_SetString(PyExc_TypeError, "The arg 2 is not in type Bytes");
    return nullptr;
  }
  auto arg2 = PyBytes_GetTWData(args[2]);

  TWDataPtr result(TWAESDecryptCTR(arg0.get(), arg1.get(), arg2.get()));
  return PyBytes_FromTWData(result);
}

// properties

static const PyGetSetDef get_set_defs[] = {{}};

static const PyMethodDef method_defs[] = {
    {"encrypt_cbc", (PyCFunction)PyAESEncryptCBC, METH_FASTCALL | METH_STATIC,
     PyAESEncryptCBC_doc},
    {"decrypt_cbc", (PyCFunction)PyAESDecryptCBC, METH_FASTCALL | METH_STATIC,
     PyAESDecryptCBC_doc},
    {"encrypt_ctr", (PyCFunction)PyAESEncryptCTR, METH_FASTCALL | METH_STATIC,
     PyAESEncryptCTR_doc},
    {"decrypt_ctr", (PyCFunction)PyAESDecryptCTR, METH_FASTCALL | METH_STATIC,
     PyAESDecryptCTR_doc},
    {}};

bool PyInit_AES(PyObject* module) {
  PyAESType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyAESType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyAESType) < 0)
    return false;

  Py_INCREF(&PyAESType);
  if (PyModule_AddObject(module, "AES", (PyObject*)&PyAESType) < 0) {
    Py_DECREF(&PyAESType);
    return false;
  }

  return true;
}