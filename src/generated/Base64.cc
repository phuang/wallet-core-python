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

#include "generated/Base64.h"

#include "Data.h"
#include "String.h"

struct PyBase64Object {
  PyObject_HEAD;
};

static PyTypeObject PyBase64Type = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.Base64",    /* tp_name */
    sizeof(PyBase64Object), /* tp_basicsize */
    0,                      /* tp_itemsize */
    0,                      /* tp_dealloc */
    0,                      /* tp_print */
    0,                      /* tp_getattr */
    0,                      /* tp_setattr */
    0,                      /* tp_reserved */
    0,                      /* tp_repr */
    0,                      /* tp_as_number */
    0,                      /* tp_as_sequence */
    0,                      /* tp_as_mapping */
    0,                      /* tp_hash  */
    0,                      /* tp_call */
    0,                      /* tp_str */
    0,                      /* tp_getattro */
    0,                      /* tp_setattro */
    0,                      /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,     /* tp_flags */
    nullptr,                /* tp_doc */
};

// static method function for Decode
static const char PyBase64Decode_doc[] =
    "TWData* TWBase64Decode(TWString* string)";
static PyObject* PyBase64Decode(PyBase64Object* self,
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

  TWDataPtr result(TWBase64Decode(arg0.get()));
  return PyBytes_FromTWData(result);
}

// static method function for DecodeUrl
static const char PyBase64DecodeUrl_doc[] =
    "TWData* TWBase64DecodeUrl(TWString* string)";
static PyObject* PyBase64DecodeUrl(PyBase64Object* self,
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

  TWDataPtr result(TWBase64DecodeUrl(arg0.get()));
  return PyBytes_FromTWData(result);
}

// static method function for Encode
static const char PyBase64Encode_doc[] =
    "TWString* TWBase64Encode(TWData* data)";
static PyObject* PyBase64Encode(PyBase64Object* self,
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

  TWStringPtr result(TWBase64Encode(arg0.get()));
  return PyUnicode_FromTWString(result);
}

// static method function for EncodeUrl
static const char PyBase64EncodeUrl_doc[] =
    "TWString* TWBase64EncodeUrl(TWData* data)";
static PyObject* PyBase64EncodeUrl(PyBase64Object* self,
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

  TWStringPtr result(TWBase64EncodeUrl(arg0.get()));
  return PyUnicode_FromTWString(result);
}

// properties

static const PyGetSetDef get_set_defs[] = {{}};

static const PyMethodDef method_defs[] = {
    {"decode", (PyCFunction)PyBase64Decode, METH_FASTCALL | METH_STATIC,
     PyBase64Decode_doc},
    {"decode_url", (PyCFunction)PyBase64DecodeUrl, METH_FASTCALL | METH_STATIC,
     PyBase64DecodeUrl_doc},
    {"encode", (PyCFunction)PyBase64Encode, METH_FASTCALL | METH_STATIC,
     PyBase64Encode_doc},
    {"encode_url", (PyCFunction)PyBase64EncodeUrl, METH_FASTCALL | METH_STATIC,
     PyBase64EncodeUrl_doc},
    {}};

bool PyInit_Base64(PyObject* module) {
  PyBase64Type.tp_getset = (PyGetSetDef*)get_set_defs;
  PyBase64Type.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyBase64Type) < 0)
    return false;

  Py_INCREF(&PyBase64Type);
  if (PyModule_AddObject(module, "Base64", (PyObject*)&PyBase64Type) < 0) {
    Py_DECREF(&PyBase64Type);
    return false;
  }

  return true;
}