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

#include "generated/PrivateKey.h"

#include "Bool.h"
#include "Data.h"
#include "generated/Curve.h"
#include "generated/PublicKey.h"

struct PyPrivateKeyObject {
  PyObject_HEAD;
  TWPrivateKey* value;
};

static PyTypeObject PyPrivateKeyType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.PrivateKey",    /* tp_name */
    sizeof(PyPrivateKeyObject), /* tp_basicsize */
    0,                          /* tp_itemsize */
    0,                          /* tp_dealloc */
    0,                          /* tp_print */
    0,                          /* tp_getattr */
    0,                          /* tp_setattr */
    0,                          /* tp_reserved */
    0,                          /* tp_repr */
    0,                          /* tp_as_number */
    0,                          /* tp_as_sequence */
    0,                          /* tp_as_mapping */
    0,                          /* tp_hash  */
    0,                          /* tp_call */
    0,                          /* tp_str */
    0,                          /* tp_getattro */
    0,                          /* tp_setattro */
    0,                          /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,         /* tp_flags */
    nullptr,                    /* tp_doc */
};

bool PyPrivateKey_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyPrivateKeyType) != 0;
}

// Create PyPrivateKey from enum TWPrivateKey.
PyObject* PyPrivateKey_FromTWPrivateKey(TWPrivateKey* value) {
  if (!value)
    Py_RETURN_NONE;

  PyPrivateKeyObject* object =
      PyObject_New(PyPrivateKeyObject, &PyPrivateKeyType);
  if (!object)
    return nullptr;

  object->value = value;

  return (PyObject*)object;
}

TWPrivateKey* PyPrivateKey_GetTWPrivateKey(PyObject* object) {
  assert(PyPrivateKey_Check(object));
  return ((PyPrivateKeyObject*)object)->value;
}

static void PyPrivateKey_dealloc(PyPrivateKeyObject* self) {
  if (self->value) {
    TWPrivateKeyDelete(self->value);
  }
  Py_TYPE(self)->tp_free(self);
}

// getter function for Data
static const char PyPrivateKeyData_doc[] =
    "TWData* TWPrivateKeyData(struct TWPrivateKey* pk)";
static PyObject* PyPrivateKeyData(PyPrivateKeyObject* self, void*) {
  TWDataPtr prop(TWPrivateKeyData(self->value));
  return PyBytes_FromTWData(prop);
}

// method function for GetPublicKeySecp256k1
static const char PyPrivateKeyGetPublicKeySecp256k1_doc[] =
    "struct TWPublicKey* TWPrivateKeyGetPublicKeySecp256k1(struct "
    "TWPrivateKey* pk, bool compressed)";
static PyObject* PyPrivateKeyGetPublicKeySecp256k1(PyPrivateKeyObject* self,
                                                   PyObject* const* args,
                                                   Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  if (!PyBool_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Bool");
    return nullptr;
  }
  auto arg0 = PyBool_IsTrue(args[0]);

  TWPublicKey* result = TWPrivateKeyGetPublicKeySecp256k1(self->value, arg0);
  return PyPublicKey_FromTWPublicKey(result);
}

// method function for GetPublicKeyNist256p1
static const char PyPrivateKeyGetPublicKeyNist256p1_doc[] =
    "struct TWPublicKey* TWPrivateKeyGetPublicKeyNist256p1(struct "
    "TWPrivateKey* pk)";
static PyObject* PyPrivateKeyGetPublicKeyNist256p1(PyPrivateKeyObject* self,
                                                   PyObject* const* args,
                                                   Py_ssize_t nargs) {
  if (nargs != 0) {
    PyErr_Format(PyExc_TypeError, "Expect 0 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  TWPublicKey* result = TWPrivateKeyGetPublicKeyNist256p1(self->value);
  return PyPublicKey_FromTWPublicKey(result);
}

// method function for GetPublicKeyEd25519
static const char PyPrivateKeyGetPublicKeyEd25519_doc[] =
    "struct TWPublicKey* TWPrivateKeyGetPublicKeyEd25519(struct TWPrivateKey* "
    "pk)";
static PyObject* PyPrivateKeyGetPublicKeyEd25519(PyPrivateKeyObject* self,
                                                 PyObject* const* args,
                                                 Py_ssize_t nargs) {
  if (nargs != 0) {
    PyErr_Format(PyExc_TypeError, "Expect 0 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  TWPublicKey* result = TWPrivateKeyGetPublicKeyEd25519(self->value);
  return PyPublicKey_FromTWPublicKey(result);
}

// method function for GetPublicKeyEd25519Blake2b
static const char PyPrivateKeyGetPublicKeyEd25519Blake2b_doc[] =
    "struct TWPublicKey* TWPrivateKeyGetPublicKeyEd25519Blake2b(struct "
    "TWPrivateKey* pk)";
static PyObject* PyPrivateKeyGetPublicKeyEd25519Blake2b(
    PyPrivateKeyObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 0) {
    PyErr_Format(PyExc_TypeError, "Expect 0 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  TWPublicKey* result = TWPrivateKeyGetPublicKeyEd25519Blake2b(self->value);
  return PyPublicKey_FromTWPublicKey(result);
}

// method function for GetPublicKeyEd25519Extended
static const char PyPrivateKeyGetPublicKeyEd25519Extended_doc[] =
    "struct TWPublicKey* TWPrivateKeyGetPublicKeyEd25519Extended(struct "
    "TWPrivateKey* pk)";
static PyObject* PyPrivateKeyGetPublicKeyEd25519Extended(
    PyPrivateKeyObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 0) {
    PyErr_Format(PyExc_TypeError, "Expect 0 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  TWPublicKey* result = TWPrivateKeyGetPublicKeyEd25519Extended(self->value);
  return PyPublicKey_FromTWPublicKey(result);
}

// method function for GetPublicKeyCurve25519
static const char PyPrivateKeyGetPublicKeyCurve25519_doc[] =
    "struct TWPublicKey* TWPrivateKeyGetPublicKeyCurve25519(struct "
    "TWPrivateKey* pk)";
static PyObject* PyPrivateKeyGetPublicKeyCurve25519(PyPrivateKeyObject* self,
                                                    PyObject* const* args,
                                                    Py_ssize_t nargs) {
  if (nargs != 0) {
    PyErr_Format(PyExc_TypeError, "Expect 0 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  TWPublicKey* result = TWPrivateKeyGetPublicKeyCurve25519(self->value);
  return PyPublicKey_FromTWPublicKey(result);
}

// method function for GetSharedKey
static const char PyPrivateKeyGetSharedKey_doc[] =
    "TWData* TWPrivateKeyGetSharedKey(const struct TWPrivateKey* pk, const "
    "struct TWPublicKey* publicKey, enum TWCurve curve)";
static PyObject* PyPrivateKeyGetSharedKey(PyPrivateKeyObject* self,
                                          PyObject* const* args,
                                          Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  if (!PyPublicKey_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type PublicKey");
    return nullptr;
  }
  auto arg0 = PyPublicKey_GetTWPublicKey(args[0]);

  if (!PyCurve_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Curve");
    return nullptr;
  }
  auto arg1 = PyCurve_GetTWCurve(args[1]);

  TWDataPtr result(TWPrivateKeyGetSharedKey(self->value, arg0, arg1));
  return PyBytes_FromTWData(result);
}

// method function for Sign
static const char PyPrivateKeySign_doc[] =
    "TWData* TWPrivateKeySign(struct TWPrivateKey* pk, TWData* digest, enum "
    "TWCurve curve)";
static PyObject* PyPrivateKeySign(PyPrivateKeyObject* self,
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

  if (!PyCurve_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Curve");
    return nullptr;
  }
  auto arg1 = PyCurve_GetTWCurve(args[1]);

  TWDataPtr result(TWPrivateKeySign(self->value, arg0.get(), arg1));
  return PyBytes_FromTWData(result);
}

// method function for SignAsDER
static const char PyPrivateKeySignAsDER_doc[] =
    "TWData* TWPrivateKeySignAsDER(struct TWPrivateKey* pk, TWData* digest, "
    "enum TWCurve curve)";
static PyObject* PyPrivateKeySignAsDER(PyPrivateKeyObject* self,
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

  if (!PyCurve_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Curve");
    return nullptr;
  }
  auto arg1 = PyCurve_GetTWCurve(args[1]);

  TWDataPtr result(TWPrivateKeySignAsDER(self->value, arg0.get(), arg1));
  return PyBytes_FromTWData(result);
}

// method function for SignSchnorr
static const char PyPrivateKeySignSchnorr_doc[] =
    "TWData* TWPrivateKeySignSchnorr(struct TWPrivateKey* pk, TWData* message, "
    "enum TWCurve curve)";
static PyObject* PyPrivateKeySignSchnorr(PyPrivateKeyObject* self,
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

  if (!PyCurve_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Curve");
    return nullptr;
  }
  auto arg1 = PyCurve_GetTWCurve(args[1]);

  TWDataPtr result(TWPrivateKeySignSchnorr(self->value, arg0.get(), arg1));
  return PyBytes_FromTWData(result);
}

// static method function for Create
static const char PyPrivateKeyCreate_doc[] =
    "struct TWPrivateKey* TWPrivateKeyCreate()";
static PyObject* PyPrivateKeyCreate(PyPrivateKeyObject* self,
                                    PyObject* const* args,
                                    Py_ssize_t nargs) {
  if (nargs != 0) {
    PyErr_Format(PyExc_TypeError, "Expect 0 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  TWPrivateKey* result = TWPrivateKeyCreate();
  return PyPrivateKey_FromTWPrivateKey(result);
}

// static method function for CreateWithData
static const char PyPrivateKeyCreateWithData_doc[] =
    "struct TWPrivateKey* TWPrivateKeyCreateWithData(TWData* data)";
static PyObject* PyPrivateKeyCreateWithData(PyPrivateKeyObject* self,
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

  TWPrivateKey* result = TWPrivateKeyCreateWithData(arg0.get());
  return PyPrivateKey_FromTWPrivateKey(result);
}

// static method function for CreateCopy
static const char PyPrivateKeyCreateCopy_doc[] =
    "struct TWPrivateKey* TWPrivateKeyCreateCopy(struct TWPrivateKey* key)";
static PyObject* PyPrivateKeyCreateCopy(PyPrivateKeyObject* self,
                                        PyObject* const* args,
                                        Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  if (!PyPrivateKey_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type PrivateKey");
    return nullptr;
  }
  auto arg0 = PyPrivateKey_GetTWPrivateKey(args[0]);

  TWPrivateKey* result = TWPrivateKeyCreateCopy(arg0);
  return PyPrivateKey_FromTWPrivateKey(result);
}

// static method function for IsValid
static const char PyPrivateKeyIsValid_doc[] =
    "bool TWPrivateKeyIsValid(TWData* data, enum TWCurve curve)";
static PyObject* PyPrivateKeyIsValid(PyPrivateKeyObject* self,
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

  if (!PyCurve_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Curve");
    return nullptr;
  }
  auto arg1 = PyCurve_GetTWCurve(args[1]);

  bool result = TWPrivateKeyIsValid(arg0.get(), arg1);
  return PyBool_FromLong(result);
}

// properties

static const PyGetSetDef get_set_defs[] = {
    {"data", (getter)PyPrivateKeyData, nullptr, PyPrivateKeyData_doc},
    {}};

static const PyMethodDef method_defs[] = {
    {"get_public_key_secp256k1", (PyCFunction)PyPrivateKeyGetPublicKeySecp256k1,
     METH_FASTCALL, PyPrivateKeyGetPublicKeySecp256k1_doc},
    {"get_public_key_nist256p1", (PyCFunction)PyPrivateKeyGetPublicKeyNist256p1,
     METH_FASTCALL, PyPrivateKeyGetPublicKeyNist256p1_doc},
    {"get_public_key_ed25519", (PyCFunction)PyPrivateKeyGetPublicKeyEd25519,
     METH_FASTCALL, PyPrivateKeyGetPublicKeyEd25519_doc},
    {"get_public_key_ed25519_blake2b",
     (PyCFunction)PyPrivateKeyGetPublicKeyEd25519Blake2b, METH_FASTCALL,
     PyPrivateKeyGetPublicKeyEd25519Blake2b_doc},
    {"get_public_key_ed25519_extended",
     (PyCFunction)PyPrivateKeyGetPublicKeyEd25519Extended, METH_FASTCALL,
     PyPrivateKeyGetPublicKeyEd25519Extended_doc},
    {"get_public_key_curve25519",
     (PyCFunction)PyPrivateKeyGetPublicKeyCurve25519, METH_FASTCALL,
     PyPrivateKeyGetPublicKeyCurve25519_doc},
    {"get_shared_key", (PyCFunction)PyPrivateKeyGetSharedKey, METH_FASTCALL,
     PyPrivateKeyGetSharedKey_doc},
    {"sign", (PyCFunction)PyPrivateKeySign, METH_FASTCALL,
     PyPrivateKeySign_doc},
    {"sign_as_der", (PyCFunction)PyPrivateKeySignAsDER, METH_FASTCALL,
     PyPrivateKeySignAsDER_doc},
    {"sign_schnorr", (PyCFunction)PyPrivateKeySignSchnorr, METH_FASTCALL,
     PyPrivateKeySignSchnorr_doc},
    {"create", (PyCFunction)PyPrivateKeyCreate, METH_FASTCALL | METH_STATIC,
     PyPrivateKeyCreate_doc},
    {"create_with_data", (PyCFunction)PyPrivateKeyCreateWithData,
     METH_FASTCALL | METH_STATIC, PyPrivateKeyCreateWithData_doc},
    {"create_copy", (PyCFunction)PyPrivateKeyCreateCopy,
     METH_FASTCALL | METH_STATIC, PyPrivateKeyCreateCopy_doc},
    {"is_valid", (PyCFunction)PyPrivateKeyIsValid, METH_FASTCALL | METH_STATIC,
     PyPrivateKeyIsValid_doc},
    {}};

bool PyInit_PrivateKey(PyObject* module) {
  PyPrivateKeyType.tp_dealloc = (destructor)PyPrivateKey_dealloc;
  PyPrivateKeyType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyPrivateKeyType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyPrivateKeyType) < 0)
    return false;

  Py_INCREF(&PyPrivateKeyType);
  if (PyModule_AddObject(module, "PrivateKey", (PyObject*)&PyPrivateKeyType) <
      0) {
    Py_DECREF(&PyPrivateKeyType);
    return false;
  }

  return true;
}