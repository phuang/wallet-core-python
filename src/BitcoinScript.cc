// Copyright 2021 Peng Huang <shawn.p.huang@gmail.com>
// This file is part of wallet-core-python.
//
// Foobar is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Foobar is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Foobar.  If not, see <https://www.gnu.org/licenses/>.
//
// NOTE: this is a GENERATED FILE, changes made here WILL BE LOST.

#include "BitcoinScript.h"

#include "CoinType.h"
#include "Data.h"
#include "String.h"

static PyTypeObject PyBitcoinScriptType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.BitcoinScript",    /* tp_name */
    sizeof(PyBitcoinScriptObject), /* tp_basicsize */
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

bool PyBitcoinScript_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyBitcoinScriptType) != 0;
}

// Create PyBitcoinScript from enum TWBitcoinScript.
PyObject* PyBitcoinScript_FromTWBitcoinScript(TWBitcoinScript* value) {
  if (!value)
    return nullptr;

  PyBitcoinScriptObject* object =
      PyObject_New(PyBitcoinScriptObject, &PyBitcoinScriptType);
  if (!object)
    return nullptr;

  object->value = value;

  return (PyObject*)object;
}

TWBitcoinScript* PyBitcoinScript_GetTWBitcoinScript(PyObject* object) {
  assert(PyBitcoinScript_Check(object));
  return ((PyBitcoinScriptObject*)object)->value;
}

static void PyBitcoinScript_dealloc(PyBitcoinScriptObject* self) {
  if (self->value) {
    TWBitcoinScriptDelete(self->value);
  }
  Py_TYPE(self)->tp_free(self);
}

// getter function for Data
static const char PyBitcoinScriptData_doc[] =
    "TWData* TWBitcoinScriptData(const struct TWBitcoinScript* script)";
static PyObject* PyBitcoinScriptData(PyBitcoinScriptObject* self, void*) {
  return PyByteArray_FromTWData(TWBitcoinScriptData(self->value));
}

// getter function for ScriptHash
static const char PyBitcoinScriptScriptHash_doc[] =
    "TWData* TWBitcoinScriptScriptHash(const struct TWBitcoinScript* script)";
static PyObject* PyBitcoinScriptScriptHash(PyBitcoinScriptObject* self, void*) {
  return PyByteArray_FromTWData(TWBitcoinScriptScriptHash(self->value));
}

// getter function for IsPayToScriptHash
static const char PyBitcoinScriptIsPayToScriptHash_doc[] =
    "bool TWBitcoinScriptIsPayToScriptHash(const struct TWBitcoinScript* "
    "script)";
static PyObject* PyBitcoinScriptIsPayToScriptHash(PyBitcoinScriptObject* self,
                                                  void*) {
  return PyBool_FromLong(TWBitcoinScriptIsPayToScriptHash(self->value));
}

// getter function for IsPayToWitnessScriptHash
static const char PyBitcoinScriptIsPayToWitnessScriptHash_doc[] =
    "bool TWBitcoinScriptIsPayToWitnessScriptHash(const struct "
    "TWBitcoinScript* script)";
static PyObject* PyBitcoinScriptIsPayToWitnessScriptHash(
    PyBitcoinScriptObject* self,
    void*) {
  return PyBool_FromLong(TWBitcoinScriptIsPayToWitnessScriptHash(self->value));
}

// getter function for IsPayToWitnessPublicKeyHash
static const char PyBitcoinScriptIsPayToWitnessPublicKeyHash_doc[] =
    "bool TWBitcoinScriptIsPayToWitnessPublicKeyHash(const struct "
    "TWBitcoinScript* script)";
static PyObject* PyBitcoinScriptIsPayToWitnessPublicKeyHash(
    PyBitcoinScriptObject* self,
    void*) {
  return PyBool_FromLong(
      TWBitcoinScriptIsPayToWitnessPublicKeyHash(self->value));
}

// getter function for IsWitnessProgram
static const char PyBitcoinScriptIsWitnessProgram_doc[] =
    "bool TWBitcoinScriptIsWitnessProgram(const struct TWBitcoinScript* "
    "script)";
static PyObject* PyBitcoinScriptIsWitnessProgram(PyBitcoinScriptObject* self,
                                                 void*) {
  return PyBool_FromLong(TWBitcoinScriptIsWitnessProgram(self->value));
}

// method function for Delete
static const char PyBitcoinScriptDelete_doc[] =
    "void TWBitcoinScriptDelete(struct TWBitcoinScript* script)";
static PyObject* PyBitcoinScriptDelete(PyBitcoinScriptObject* self,
                                       PyObject* const* args,
                                       Py_ssize_t nargs) {
  if (nargs != 0) {
    PyErr_Format(PyExc_TypeError, "Expect 0 instead of %d.", nargs);
    return nullptr;
  }

  TWBitcoinScriptDelete(self->value);
  return nullptr;
}

// method function for MatchPayToPubkey
static const char PyBitcoinScriptMatchPayToPubkey_doc[] =
    "TWData* TWBitcoinScriptMatchPayToPubkey(const struct TWBitcoinScript* "
    "script)";
static PyObject* PyBitcoinScriptMatchPayToPubkey(PyBitcoinScriptObject* self,
                                                 PyObject* const* args,
                                                 Py_ssize_t nargs) {
  if (nargs != 0) {
    PyErr_Format(PyExc_TypeError, "Expect 0 instead of %d.", nargs);
    return nullptr;
  }

  TWDataPtr result = TWBitcoinScriptMatchPayToPubkey(self->value);
  return PyByteArray_FromTWData(result);
}

// method function for MatchPayToPubkeyHash
static const char PyBitcoinScriptMatchPayToPubkeyHash_doc[] =
    "TWData* TWBitcoinScriptMatchPayToPubkeyHash(const struct TWBitcoinScript* "
    "script)";
static PyObject* PyBitcoinScriptMatchPayToPubkeyHash(
    PyBitcoinScriptObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 0) {
    PyErr_Format(PyExc_TypeError, "Expect 0 instead of %d.", nargs);
    return nullptr;
  }

  TWDataPtr result = TWBitcoinScriptMatchPayToPubkeyHash(self->value);
  return PyByteArray_FromTWData(result);
}

// method function for MatchPayToScriptHash
static const char PyBitcoinScriptMatchPayToScriptHash_doc[] =
    "TWData* TWBitcoinScriptMatchPayToScriptHash(const struct TWBitcoinScript* "
    "script)";
static PyObject* PyBitcoinScriptMatchPayToScriptHash(
    PyBitcoinScriptObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 0) {
    PyErr_Format(PyExc_TypeError, "Expect 0 instead of %d.", nargs);
    return nullptr;
  }

  TWDataPtr result = TWBitcoinScriptMatchPayToScriptHash(self->value);
  return PyByteArray_FromTWData(result);
}

// method function for MatchPayToWitnessPublicKeyHash
static const char PyBitcoinScriptMatchPayToWitnessPublicKeyHash_doc[] =
    "TWData* TWBitcoinScriptMatchPayToWitnessPublicKeyHash(const struct "
    "TWBitcoinScript* script)";
static PyObject* PyBitcoinScriptMatchPayToWitnessPublicKeyHash(
    PyBitcoinScriptObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 0) {
    PyErr_Format(PyExc_TypeError, "Expect 0 instead of %d.", nargs);
    return nullptr;
  }

  TWDataPtr result = TWBitcoinScriptMatchPayToWitnessPublicKeyHash(self->value);
  return PyByteArray_FromTWData(result);
}

// method function for MatchPayToWitnessScriptHash
static const char PyBitcoinScriptMatchPayToWitnessScriptHash_doc[] =
    "TWData* TWBitcoinScriptMatchPayToWitnessScriptHash(const struct "
    "TWBitcoinScript* script)";
static PyObject* PyBitcoinScriptMatchPayToWitnessScriptHash(
    PyBitcoinScriptObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 0) {
    PyErr_Format(PyExc_TypeError, "Expect 0 instead of %d.", nargs);
    return nullptr;
  }

  TWDataPtr result = TWBitcoinScriptMatchPayToWitnessScriptHash(self->value);
  return PyByteArray_FromTWData(result);
}

// method function for Encode
static const char PyBitcoinScriptEncode_doc[] =
    "TWData* TWBitcoinScriptEncode(const struct TWBitcoinScript* script)";
static PyObject* PyBitcoinScriptEncode(PyBitcoinScriptObject* self,
                                       PyObject* const* args,
                                       Py_ssize_t nargs) {
  if (nargs != 0) {
    PyErr_Format(PyExc_TypeError, "Expect 0 instead of %d.", nargs);
    return nullptr;
  }

  TWDataPtr result = TWBitcoinScriptEncode(self->value);
  return PyByteArray_FromTWData(result);
}

// static method function for Create
static const char PyBitcoinScriptCreate_doc[] =
    "struct TWBitcoinScript* TWBitcoinScriptCreate()";
static PyObject* PyBitcoinScriptCreate(PyBitcoinScriptObject* self,
                                       PyObject* const* args,
                                       Py_ssize_t nargs) {
  if (nargs != 0) {
    PyErr_Format(PyExc_TypeError, "Expect 0 instead of %d.", nargs);
    return nullptr;
  }

  TWBitcoinScript* result = TWBitcoinScriptCreate();
  return PyBitcoinScript_FromTWBitcoinScript(result);
}

// static method function for CreateWithData
static const char PyBitcoinScriptCreateWithData_doc[] =
    "struct TWBitcoinScript* TWBitcoinScriptCreateWithData(TWData* data)";
static PyObject* PyBitcoinScriptCreateWithData(PyBitcoinScriptObject* self,
                                               PyObject* const* args,
                                               Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyByteArray_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type ByteArray");
    return nullptr;
  }
  auto arg0 = PyByteArray_GetTWData(args[0]);

  TWBitcoinScript* result = TWBitcoinScriptCreateWithData(arg0.get());
  return PyBitcoinScript_FromTWBitcoinScript(result);
}

// static method function for CreateCopy
static const char PyBitcoinScriptCreateCopy_doc[] =
    "struct TWBitcoinScript* TWBitcoinScriptCreateCopy(const struct "
    "TWBitcoinScript* script)";
static PyObject* PyBitcoinScriptCreateCopy(PyBitcoinScriptObject* self,
                                           PyObject* const* args,
                                           Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyBitcoinScript_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type BitcoinScript");
    return nullptr;
  }
  auto arg0 = PyBitcoinScript_GetTWBitcoinScript(args[0]);

  TWBitcoinScript* result = TWBitcoinScriptCreateCopy(arg0);
  return PyBitcoinScript_FromTWBitcoinScript(result);
}

// static method function for Equal
static const char PyBitcoinScriptEqual_doc[] =
    "bool TWBitcoinScriptEqual(const struct TWBitcoinScript* lhs, const struct "
    "TWBitcoinScript* rhs)";
static PyObject* PyBitcoinScriptEqual(PyBitcoinScriptObject* self,
                                      PyObject* const* args,
                                      Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyBitcoinScript_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type BitcoinScript");
    return nullptr;
  }
  auto arg0 = PyBitcoinScript_GetTWBitcoinScript(args[0]);

  if (!PyBitcoinScript_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type BitcoinScript");
    return nullptr;
  }
  auto arg1 = PyBitcoinScript_GetTWBitcoinScript(args[1]);

  bool result = TWBitcoinScriptEqual(arg0, arg1);
  return PyBool_FromLong(result);
}

// static method function for BuildPayToPublicKey
static const char PyBitcoinScriptBuildPayToPublicKey_doc[] =
    "struct TWBitcoinScript* TWBitcoinScriptBuildPayToPublicKey(TWData* "
    "pubkey)";
static PyObject* PyBitcoinScriptBuildPayToPublicKey(PyBitcoinScriptObject* self,
                                                    PyObject* const* args,
                                                    Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyByteArray_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type ByteArray");
    return nullptr;
  }
  auto arg0 = PyByteArray_GetTWData(args[0]);

  TWBitcoinScript* result = TWBitcoinScriptBuildPayToPublicKey(arg0.get());
  return PyBitcoinScript_FromTWBitcoinScript(result);
}

// static method function for BuildPayToPublicKeyHash
static const char PyBitcoinScriptBuildPayToPublicKeyHash_doc[] =
    "struct TWBitcoinScript* TWBitcoinScriptBuildPayToPublicKeyHash(TWData* "
    "hash)";
static PyObject* PyBitcoinScriptBuildPayToPublicKeyHash(
    PyBitcoinScriptObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyByteArray_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type ByteArray");
    return nullptr;
  }
  auto arg0 = PyByteArray_GetTWData(args[0]);

  TWBitcoinScript* result = TWBitcoinScriptBuildPayToPublicKeyHash(arg0.get());
  return PyBitcoinScript_FromTWBitcoinScript(result);
}

// static method function for BuildPayToScriptHash
static const char PyBitcoinScriptBuildPayToScriptHash_doc[] =
    "struct TWBitcoinScript* TWBitcoinScriptBuildPayToScriptHash(TWData* "
    "scriptHash)";
static PyObject* PyBitcoinScriptBuildPayToScriptHash(
    PyBitcoinScriptObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyByteArray_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type ByteArray");
    return nullptr;
  }
  auto arg0 = PyByteArray_GetTWData(args[0]);

  TWBitcoinScript* result = TWBitcoinScriptBuildPayToScriptHash(arg0.get());
  return PyBitcoinScript_FromTWBitcoinScript(result);
}

// static method function for BuildPayToWitnessPubkeyHash
static const char PyBitcoinScriptBuildPayToWitnessPubkeyHash_doc[] =
    "struct TWBitcoinScript* "
    "TWBitcoinScriptBuildPayToWitnessPubkeyHash(TWData* hash)";
static PyObject* PyBitcoinScriptBuildPayToWitnessPubkeyHash(
    PyBitcoinScriptObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyByteArray_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type ByteArray");
    return nullptr;
  }
  auto arg0 = PyByteArray_GetTWData(args[0]);

  TWBitcoinScript* result =
      TWBitcoinScriptBuildPayToWitnessPubkeyHash(arg0.get());
  return PyBitcoinScript_FromTWBitcoinScript(result);
}

// static method function for BuildPayToWitnessScriptHash
static const char PyBitcoinScriptBuildPayToWitnessScriptHash_doc[] =
    "struct TWBitcoinScript* "
    "TWBitcoinScriptBuildPayToWitnessScriptHash(TWData* scriptHash)";
static PyObject* PyBitcoinScriptBuildPayToWitnessScriptHash(
    PyBitcoinScriptObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyByteArray_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type ByteArray");
    return nullptr;
  }
  auto arg0 = PyByteArray_GetTWData(args[0]);

  TWBitcoinScript* result =
      TWBitcoinScriptBuildPayToWitnessScriptHash(arg0.get());
  return PyBitcoinScript_FromTWBitcoinScript(result);
}

// static method function for LockScriptForAddress
static const char PyBitcoinScriptLockScriptForAddress_doc[] =
    "struct TWBitcoinScript* TWBitcoinScriptLockScriptForAddress(TWString* "
    "address, enum TWCoinType coin)";
static PyObject* PyBitcoinScriptLockScriptForAddress(
    PyBitcoinScriptObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyUnicode_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Unicode");
    return nullptr;
  }
  auto arg0 = PyUnicode_GetTWString(args[0]);

  if (!PyCoinType_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type CoinType");
    return nullptr;
  }
  auto arg1 = PyCoinType_GetTWCoinType(args[1]);

  TWBitcoinScript* result =
      TWBitcoinScriptLockScriptForAddress(arg0.get(), arg1);
  return PyBitcoinScript_FromTWBitcoinScript(result);
}

// static method function for HashTypeForCoin
static const char PyBitcoinScriptHashTypeForCoin_doc[] =
    "uint32_t TWBitcoinScriptHashTypeForCoin(enum TWCoinType coinType)";
static PyObject* PyBitcoinScriptHashTypeForCoin(PyBitcoinScriptObject* self,
                                                PyObject* const* args,
                                                Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyCoinType_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type CoinType");
    return nullptr;
  }
  auto arg0 = PyCoinType_GetTWCoinType(args[0]);

  uint32_t result = TWBitcoinScriptHashTypeForCoin(arg0);
  return PyLong_FromLong(result);
}

static const PyGetSetDef get_set_defs[] = {
    {"Data", (getter)PyBitcoinScriptData, nullptr, PyBitcoinScriptData_doc},
    {"ScriptHash", (getter)PyBitcoinScriptScriptHash, nullptr,
     PyBitcoinScriptScriptHash_doc},
    {"IsPayToScriptHash", (getter)PyBitcoinScriptIsPayToScriptHash, nullptr,
     PyBitcoinScriptIsPayToScriptHash_doc},
    {"IsPayToWitnessScriptHash",
     (getter)PyBitcoinScriptIsPayToWitnessScriptHash, nullptr,
     PyBitcoinScriptIsPayToWitnessScriptHash_doc},
    {"IsPayToWitnessPublicKeyHash",
     (getter)PyBitcoinScriptIsPayToWitnessPublicKeyHash, nullptr,
     PyBitcoinScriptIsPayToWitnessPublicKeyHash_doc},
    {"IsWitnessProgram", (getter)PyBitcoinScriptIsWitnessProgram, nullptr,
     PyBitcoinScriptIsWitnessProgram_doc},
    {}};

static const PyMethodDef method_defs[] = {
    {"Delete", (PyCFunction)PyBitcoinScriptDelete, METH_FASTCALL,
     PyBitcoinScriptDelete_doc},
    {"MatchPayToPubkey", (PyCFunction)PyBitcoinScriptMatchPayToPubkey,
     METH_FASTCALL, PyBitcoinScriptMatchPayToPubkey_doc},
    {"MatchPayToPubkeyHash", (PyCFunction)PyBitcoinScriptMatchPayToPubkeyHash,
     METH_FASTCALL, PyBitcoinScriptMatchPayToPubkeyHash_doc},
    {"MatchPayToScriptHash", (PyCFunction)PyBitcoinScriptMatchPayToScriptHash,
     METH_FASTCALL, PyBitcoinScriptMatchPayToScriptHash_doc},
    {"MatchPayToWitnessPublicKeyHash",
     (PyCFunction)PyBitcoinScriptMatchPayToWitnessPublicKeyHash, METH_FASTCALL,
     PyBitcoinScriptMatchPayToWitnessPublicKeyHash_doc},
    {"MatchPayToWitnessScriptHash",
     (PyCFunction)PyBitcoinScriptMatchPayToWitnessScriptHash, METH_FASTCALL,
     PyBitcoinScriptMatchPayToWitnessScriptHash_doc},
    {"Encode", (PyCFunction)PyBitcoinScriptEncode, METH_FASTCALL,
     PyBitcoinScriptEncode_doc},
    {"Create", (PyCFunction)PyBitcoinScriptCreate, METH_FASTCALL | METH_STATIC,
     PyBitcoinScriptCreate_doc},
    {"CreateWithData", (PyCFunction)PyBitcoinScriptCreateWithData,
     METH_FASTCALL | METH_STATIC, PyBitcoinScriptCreateWithData_doc},
    {"CreateCopy", (PyCFunction)PyBitcoinScriptCreateCopy,
     METH_FASTCALL | METH_STATIC, PyBitcoinScriptCreateCopy_doc},
    {"Equal", (PyCFunction)PyBitcoinScriptEqual, METH_FASTCALL | METH_STATIC,
     PyBitcoinScriptEqual_doc},
    {"BuildPayToPublicKey", (PyCFunction)PyBitcoinScriptBuildPayToPublicKey,
     METH_FASTCALL | METH_STATIC, PyBitcoinScriptBuildPayToPublicKey_doc},
    {"BuildPayToPublicKeyHash",
     (PyCFunction)PyBitcoinScriptBuildPayToPublicKeyHash,
     METH_FASTCALL | METH_STATIC, PyBitcoinScriptBuildPayToPublicKeyHash_doc},
    {"BuildPayToScriptHash", (PyCFunction)PyBitcoinScriptBuildPayToScriptHash,
     METH_FASTCALL | METH_STATIC, PyBitcoinScriptBuildPayToScriptHash_doc},
    {"BuildPayToWitnessPubkeyHash",
     (PyCFunction)PyBitcoinScriptBuildPayToWitnessPubkeyHash,
     METH_FASTCALL | METH_STATIC,
     PyBitcoinScriptBuildPayToWitnessPubkeyHash_doc},
    {"BuildPayToWitnessScriptHash",
     (PyCFunction)PyBitcoinScriptBuildPayToWitnessScriptHash,
     METH_FASTCALL | METH_STATIC,
     PyBitcoinScriptBuildPayToWitnessScriptHash_doc},
    {"LockScriptForAddress", (PyCFunction)PyBitcoinScriptLockScriptForAddress,
     METH_FASTCALL | METH_STATIC, PyBitcoinScriptLockScriptForAddress_doc},
    {"HashTypeForCoin", (PyCFunction)PyBitcoinScriptHashTypeForCoin,
     METH_FASTCALL | METH_STATIC, PyBitcoinScriptHashTypeForCoin_doc},
    {}};

bool PyInit_BitcoinScript(PyObject* module) {
  PyBitcoinScriptType.tp_dealloc = (destructor)PyBitcoinScript_dealloc;
  PyBitcoinScriptType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyBitcoinScriptType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyBitcoinScriptType) < 0)
    return false;

  Py_INCREF(&PyBitcoinScriptType);
  if (PyModule_AddObject(module, "BitcoinScript",
                         (PyObject*)&PyBitcoinScriptType) < 0) {
    Py_DECREF(&PyBitcoinScriptType);
    return false;
  }

  return true;
}