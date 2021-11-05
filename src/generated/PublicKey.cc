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

#include "generated/PublicKey.h"

#include "Data.h"
#include "String.h"
#include "generated/PublicKey.h"
#include "generated/PublicKeyType.h"

struct PyPublicKeyObject {
  PyObject_HEAD;
  TWPublicKey* value;
};

static PyTypeObject PyPublicKeyType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.PublicKey",    /* tp_name */
    sizeof(PyPublicKeyObject), /* tp_basicsize */
    0,                         /* tp_itemsize */
    0,                         /* tp_dealloc */
    0,                         /* tp_print */
    0,                         /* tp_getattr */
    0,                         /* tp_setattr */
    0,                         /* tp_reserved */
    0,                         /* tp_repr */
    0,                         /* tp_as_number */
    0,                         /* tp_as_sequence */
    0,                         /* tp_as_mapping */
    0,                         /* tp_hash  */
    0,                         /* tp_call */
    0,                         /* tp_str */
    0,                         /* tp_getattro */
    0,                         /* tp_setattro */
    0,                         /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,        /* tp_flags */
    nullptr,                   /* tp_doc */
};

bool PyPublicKey_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyPublicKeyType) != 0;
}

// Create PyPublicKey from enum TWPublicKey.
PyObject* PyPublicKey_FromTWPublicKey(TWPublicKey* value) {
  if (!value)
    Py_RETURN_NONE;

  PyPublicKeyObject* object = PyObject_New(PyPublicKeyObject, &PyPublicKeyType);
  if (!object)
    return nullptr;

  object->value = value;

  return (PyObject*)object;
}

TWPublicKey* PyPublicKey_GetTWPublicKey(PyObject* object) {
  assert(PyPublicKey_Check(object));
  return ((PyPublicKeyObject*)object)->value;
}

static void PyPublicKey_dealloc(PyPublicKeyObject* self) {
  if (self->value) {
    TWPublicKeyDelete(self->value);
  }
  Py_TYPE(self)->tp_free(self);
}

// getter function for IsCompressed
static const char PyPublicKeyIsCompressed_doc[] =
    "bool TWPublicKeyIsCompressed(struct TWPublicKey* pk)";
static PyObject* PyPublicKeyIsCompressed(PyPublicKeyObject* self, void*) {
  bool prop = TWPublicKeyIsCompressed(self->value);
  return PyBool_FromLong(prop);
}

// getter function for Compressed
static const char PyPublicKeyCompressed_doc[] =
    "struct TWPublicKey* TWPublicKeyCompressed(struct TWPublicKey* from)";
static PyObject* PyPublicKeyCompressed(PyPublicKeyObject* self, void*) {
  TWPublicKey* prop = TWPublicKeyCompressed(self->value);
  return PyPublicKey_FromTWPublicKey(prop);
}

// getter function for Uncompressed
static const char PyPublicKeyUncompressed_doc[] =
    "struct TWPublicKey* TWPublicKeyUncompressed(struct TWPublicKey* from)";
static PyObject* PyPublicKeyUncompressed(PyPublicKeyObject* self, void*) {
  TWPublicKey* prop = TWPublicKeyUncompressed(self->value);
  return PyPublicKey_FromTWPublicKey(prop);
}

// getter function for Data
static const char PyPublicKeyData_doc[] =
    "TWData* TWPublicKeyData(struct TWPublicKey* pk)";
static PyObject* PyPublicKeyData(PyPublicKeyObject* self, void*) {
  TWDataPtr prop(TWPublicKeyData(self->value));
  return PyBytes_FromTWData(prop);
}

// getter function for KeyType
static const char PyPublicKeyKeyType_doc[] =
    "enum TWPublicKeyType TWPublicKeyKeyType(struct TWPublicKey* publicKey)";
static PyObject* PyPublicKeyKeyType(PyPublicKeyObject* self, void*) {
  TWPublicKeyType prop = TWPublicKeyKeyType(self->value);
  return PyPublicKeyType_FromTWPublicKeyType(prop);
}

// getter function for Description
static const char PyPublicKeyDescription_doc[] =
    "TWString* TWPublicKeyDescription(struct TWPublicKey* publicKey)";
static PyObject* PyPublicKeyDescription(PyPublicKeyObject* self, void*) {
  TWStringPtr prop(TWPublicKeyDescription(self->value));
  return PyUnicode_FromTWString(prop);
}

// method function for Verify
static const char PyPublicKeyVerify_doc[] =
    "bool TWPublicKeyVerify(struct TWPublicKey* pk, TWData* signature, TWData* "
    "message)";
static PyObject* PyPublicKeyVerify(PyPublicKeyObject* self,
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

  if (!PyBytes_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bytes");
    return nullptr;
  }
  auto arg1 = PyBytes_GetTWData(args[1]);

  bool result = TWPublicKeyVerify(self->value, arg0.get(), arg1.get());
  return PyBool_FromLong(result);
}

// method function for VerifySchnorr
static const char PyPublicKeyVerifySchnorr_doc[] =
    "bool TWPublicKeyVerifySchnorr(struct TWPublicKey* pk, TWData* signature, "
    "TWData* message)";
static PyObject* PyPublicKeyVerifySchnorr(PyPublicKeyObject* self,
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

  if (!PyBytes_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bytes");
    return nullptr;
  }
  auto arg1 = PyBytes_GetTWData(args[1]);

  bool result = TWPublicKeyVerifySchnorr(self->value, arg0.get(), arg1.get());
  return PyBool_FromLong(result);
}

// static method function for CreateWithData
static const char PyPublicKeyCreateWithData_doc[] =
    "struct TWPublicKey* TWPublicKeyCreateWithData(TWData* data, enum "
    "TWPublicKeyType type)";
static PyObject* PyPublicKeyCreateWithData(PyPublicKeyObject* self,
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

  if (!PyPublicKeyType_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type PublicKeyType");
    return nullptr;
  }
  auto arg1 = PyPublicKeyType_GetTWPublicKeyType(args[1]);

  TWPublicKey* result = TWPublicKeyCreateWithData(arg0.get(), arg1);
  return PyPublicKey_FromTWPublicKey(result);
}

// static method function for IsValid
static const char PyPublicKeyIsValid_doc[] =
    "bool TWPublicKeyIsValid(TWData* data, enum TWPublicKeyType type)";
static PyObject* PyPublicKeyIsValid(PyPublicKeyObject* self,
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

  if (!PyPublicKeyType_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type PublicKeyType");
    return nullptr;
  }
  auto arg1 = PyPublicKeyType_GetTWPublicKeyType(args[1]);

  bool result = TWPublicKeyIsValid(arg0.get(), arg1);
  return PyBool_FromLong(result);
}

// static method function for Recover
static const char PyPublicKeyRecover_doc[] =
    "struct TWPublicKey* TWPublicKeyRecover(TWData* signature, TWData* "
    "message)";
static PyObject* PyPublicKeyRecover(PyPublicKeyObject* self,
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

  if (!PyBytes_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bytes");
    return nullptr;
  }
  auto arg1 = PyBytes_GetTWData(args[1]);

  TWPublicKey* result = TWPublicKeyRecover(arg0.get(), arg1.get());
  return PyPublicKey_FromTWPublicKey(result);
}

// properties

static const PyGetSetDef get_set_defs[] = {
    {"is_compressed", (getter)PyPublicKeyIsCompressed, nullptr,
     PyPublicKeyIsCompressed_doc},
    {"compressed", (getter)PyPublicKeyCompressed, nullptr,
     PyPublicKeyCompressed_doc},
    {"uncompressed", (getter)PyPublicKeyUncompressed, nullptr,
     PyPublicKeyUncompressed_doc},
    {"data", (getter)PyPublicKeyData, nullptr, PyPublicKeyData_doc},
    {"key_type", (getter)PyPublicKeyKeyType, nullptr, PyPublicKeyKeyType_doc},
    {"description", (getter)PyPublicKeyDescription, nullptr,
     PyPublicKeyDescription_doc},
    {}};

static const PyMethodDef method_defs[] = {
    {"verify", (PyCFunction)PyPublicKeyVerify, METH_FASTCALL,
     PyPublicKeyVerify_doc},
    {"verify_schnorr", (PyCFunction)PyPublicKeyVerifySchnorr, METH_FASTCALL,
     PyPublicKeyVerifySchnorr_doc},
    {"create_with_data", (PyCFunction)PyPublicKeyCreateWithData,
     METH_FASTCALL | METH_STATIC, PyPublicKeyCreateWithData_doc},
    {"is_valid", (PyCFunction)PyPublicKeyIsValid, METH_FASTCALL | METH_STATIC,
     PyPublicKeyIsValid_doc},
    {"recover", (PyCFunction)PyPublicKeyRecover, METH_FASTCALL | METH_STATIC,
     PyPublicKeyRecover_doc},
    {}};

bool PyInit_PublicKey(PyObject* module) {
  PyPublicKeyType.tp_dealloc = (destructor)PyPublicKey_dealloc;
  PyPublicKeyType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyPublicKeyType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyPublicKeyType) < 0)
    return false;

  Py_INCREF(&PyPublicKeyType);
  if (PyModule_AddObject(module, "PublicKey", (PyObject*)&PyPublicKeyType) <
      0) {
    Py_DECREF(&PyPublicKeyType);
    return false;
  }

  return true;
}