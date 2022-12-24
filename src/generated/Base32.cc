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

#include "generated/Base32.h"

#include "Data.h"
#include "String.h"

struct PyBase32Object {
  PyObject_HEAD;
};

static PyTypeObject PyBase32Type = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.Base32",    /* tp_name */
    sizeof(PyBase32Object), /* tp_basicsize */
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

// static method function for DecodeWithAlphabet
static const char PyBase32DecodeWithAlphabet_doc[] =
    "TWData* TWBase32DecodeWithAlphabet(TWString* string, TWString* alphabet)";
static PyObject* PyBase32DecodeWithAlphabet(PyBase32Object* self,
                                            PyObject* const* args,
                                            Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 args, but %d args are passed in.",
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

  TWDataPtr result(TWBase32DecodeWithAlphabet(arg0.get(), arg1.get()));
  return PyBytes_FromTWData(result);
}

// static method function for Decode
static const char PyBase32Decode_doc[] =
    "TWData* TWBase32Decode(TWString* string)";
static PyObject* PyBase32Decode(PyBase32Object* self,
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

  TWDataPtr result(TWBase32Decode(arg0.get()));
  return PyBytes_FromTWData(result);
}

// static method function for EncodeWithAlphabet
static const char PyBase32EncodeWithAlphabet_doc[] =
    "TWString* TWBase32EncodeWithAlphabet(TWData* data, TWString* alphabet)";
static PyObject* PyBase32EncodeWithAlphabet(PyBase32Object* self,
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

  TWStringPtr result(TWBase32EncodeWithAlphabet(arg0.get(), arg1.get()));
  return PyUnicode_FromTWString(result);
}

// static method function for Encode
static const char PyBase32Encode_doc[] =
    "TWString* TWBase32Encode(TWData* data)";
static PyObject* PyBase32Encode(PyBase32Object* self,
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

  TWStringPtr result(TWBase32Encode(arg0.get()));
  return PyUnicode_FromTWString(result);
}

// properties

static const PyGetSetDef get_set_defs[] = {{}};

static const PyMethodDef method_defs[] = {
    {"decode_with_alphabet", (PyCFunction)PyBase32DecodeWithAlphabet,
     METH_FASTCALL | METH_STATIC, PyBase32DecodeWithAlphabet_doc},
    {"decode", (PyCFunction)PyBase32Decode, METH_FASTCALL | METH_STATIC,
     PyBase32Decode_doc},
    {"encode_with_alphabet", (PyCFunction)PyBase32EncodeWithAlphabet,
     METH_FASTCALL | METH_STATIC, PyBase32EncodeWithAlphabet_doc},
    {"encode", (PyCFunction)PyBase32Encode, METH_FASTCALL | METH_STATIC,
     PyBase32Encode_doc},
    {}};

bool PyInit_Base32(PyObject* module) {
  PyBase32Type.tp_getset = (PyGetSetDef*)get_set_defs;
  PyBase32Type.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyBase32Type) < 0)
    return false;

  Py_INCREF(&PyBase32Type);
  if (PyModule_AddObject(module, "Base32", (PyObject*)&PyBase32Type) < 0) {
    Py_DECREF(&PyBase32Type);
    return false;
  }

  return true;
}