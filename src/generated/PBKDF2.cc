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

#include "generated/PBKDF2.h"

#include "Data.h"
#include "Number.h"

struct PyPBKDF2Object {
  PyObject_HEAD;
};

static PyTypeObject PyPBKDF2Type = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.PBKDF2",    /* tp_name */
    sizeof(PyPBKDF2Object), /* tp_basicsize */
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

// static method function for HmacSha256
static const char PyPBKDF2HmacSha256_doc[] =
    "TWData* TWPBKDF2HmacSha256(TWData* password, TWData* salt, uint32_t "
    "iterations, uint32_t dkLen)";
static PyObject* PyPBKDF2HmacSha256(PyPBKDF2Object* self,
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

  auto checked_arg2 = PyLongArg_ToNumber<uint32_t>(args[2], 2, "uint32_t");
  if (!checked_arg2)
    return nullptr;
  const auto& arg2 = checked_arg2.value();

  auto checked_arg3 = PyLongArg_ToNumber<uint32_t>(args[3], 3, "uint32_t");
  if (!checked_arg3)
    return nullptr;
  const auto& arg3 = checked_arg3.value();

  TWDataPtr result(TWPBKDF2HmacSha256(arg0.get(), arg1.get(), arg2, arg3));
  return PyBytes_FromTWData(result);
}

// static method function for HmacSha512
static const char PyPBKDF2HmacSha512_doc[] =
    "TWData* TWPBKDF2HmacSha512(TWData* password, TWData* salt, uint32_t "
    "iterations, uint32_t dkLen)";
static PyObject* PyPBKDF2HmacSha512(PyPBKDF2Object* self,
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

  auto checked_arg2 = PyLongArg_ToNumber<uint32_t>(args[2], 2, "uint32_t");
  if (!checked_arg2)
    return nullptr;
  const auto& arg2 = checked_arg2.value();

  auto checked_arg3 = PyLongArg_ToNumber<uint32_t>(args[3], 3, "uint32_t");
  if (!checked_arg3)
    return nullptr;
  const auto& arg3 = checked_arg3.value();

  TWDataPtr result(TWPBKDF2HmacSha512(arg0.get(), arg1.get(), arg2, arg3));
  return PyBytes_FromTWData(result);
}

// properties

static const PyGetSetDef get_set_defs[] = {{}};

static const PyMethodDef method_defs[] = {
    {"hmac_sha256", (PyCFunction)PyPBKDF2HmacSha256,
     METH_FASTCALL | METH_STATIC, PyPBKDF2HmacSha256_doc},
    {"hmac_sha512", (PyCFunction)PyPBKDF2HmacSha512,
     METH_FASTCALL | METH_STATIC, PyPBKDF2HmacSha512_doc},
    {}};

bool PyInit_PBKDF2(PyObject* module) {
  PyPBKDF2Type.tp_getset = (PyGetSetDef*)get_set_defs;
  PyPBKDF2Type.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyPBKDF2Type) < 0)
    return false;

  Py_INCREF(&PyPBKDF2Type);
  if (PyModule_AddObject(module, "PBKDF2", (PyObject*)&PyPBKDF2Type) < 0) {
    Py_DECREF(&PyPBKDF2Type);
    return false;
  }

  return true;
}