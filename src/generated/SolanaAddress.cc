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

#include "generated/SolanaAddress.h"

#include "String.h"

struct PySolanaAddressObject {
  PyObject_HEAD;
  TWSolanaAddress* value;
};

static PyTypeObject PySolanaAddressType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.SolanaAddress",    /* tp_name */
    sizeof(PySolanaAddressObject), /* tp_basicsize */
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

bool PySolanaAddress_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PySolanaAddressType) != 0;
}

// Create PySolanaAddress from enum TWSolanaAddress.
PyObject* PySolanaAddress_FromTWSolanaAddress(TWSolanaAddress* value) {
  if (!value)
    Py_RETURN_NONE;

  PySolanaAddressObject* object =
      PyObject_New(PySolanaAddressObject, &PySolanaAddressType);
  if (!object)
    return nullptr;

  object->value = value;

  return (PyObject*)object;
}

TWSolanaAddress* PySolanaAddress_GetTWSolanaAddress(PyObject* object) {
  assert(PySolanaAddress_Check(object));
  return ((PySolanaAddressObject*)object)->value;
}

static void PySolanaAddress_dealloc(PySolanaAddressObject* self) {
  if (self->value) {
    TWSolanaAddressDelete(self->value);
  }
  Py_TYPE(self)->tp_free(self);
}

// getter function for Description
static const char PySolanaAddressDescription_doc[] =
    "TWString* TWSolanaAddressDescription(struct TWSolanaAddress* address)";
static PyObject* PySolanaAddressDescription(PySolanaAddressObject* self,
                                            void*) {
  TWStringPtr prop(TWSolanaAddressDescription(self->value));
  return PyUnicode_FromTWString(prop);
}

// method function for DefaultTokenAddress
static const char PySolanaAddressDefaultTokenAddress_doc[] =
    "TWString* TWSolanaAddressDefaultTokenAddress(struct TWSolanaAddress* "
    "address, TWString* tokenMintAddress)";
static PyObject* PySolanaAddressDefaultTokenAddress(PySolanaAddressObject* self,
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

  TWStringPtr result(
      TWSolanaAddressDefaultTokenAddress(self->value, arg0.get()));
  return PyUnicode_FromTWString(result);
}

// static method function for CreateWithString
static const char PySolanaAddressCreateWithString_doc[] =
    "struct TWSolanaAddress* TWSolanaAddressCreateWithString(TWString* string)";
static PyObject* PySolanaAddressCreateWithString(PySolanaAddressObject* self,
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

  TWSolanaAddress* result = TWSolanaAddressCreateWithString(arg0.get());
  return PySolanaAddress_FromTWSolanaAddress(result);
}

// properties

static const PyGetSetDef get_set_defs[] = {
    {"description", (getter)PySolanaAddressDescription, nullptr,
     PySolanaAddressDescription_doc},
    {}};

static const PyMethodDef method_defs[] = {
    {"default_token_address", (PyCFunction)PySolanaAddressDefaultTokenAddress,
     METH_FASTCALL, PySolanaAddressDefaultTokenAddress_doc},
    {"create_with_string", (PyCFunction)PySolanaAddressCreateWithString,
     METH_FASTCALL | METH_STATIC, PySolanaAddressCreateWithString_doc},
    {}};

bool PyInit_SolanaAddress(PyObject* module) {
  PySolanaAddressType.tp_dealloc = (destructor)PySolanaAddress_dealloc;
  PySolanaAddressType.tp_getset = (PyGetSetDef*)get_set_defs;
  PySolanaAddressType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PySolanaAddressType) < 0)
    return false;

  Py_INCREF(&PySolanaAddressType);
  if (PyModule_AddObject(module, "SolanaAddress",
                         (PyObject*)&PySolanaAddressType) < 0) {
    Py_DECREF(&PySolanaAddressType);
    return false;
  }

  return true;
}