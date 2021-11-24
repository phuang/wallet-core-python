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

#include "generated/StoredKey.h"

#include "Data.h"
#include "Number.h"
#include "String.h"
#include "generated/Account.h"
#include "generated/CoinType.h"
#include "generated/HDWallet.h"
#include "generated/PrivateKey.h"
#include "generated/StoredKeyEncryptionLevel.h"

struct PyStoredKeyObject {
  PyObject_HEAD;
  TWStoredKey* value;
};

static PyTypeObject PyStoredKeyType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.StoredKey",    /* tp_name */
    sizeof(PyStoredKeyObject), /* tp_basicsize */
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

bool PyStoredKey_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyStoredKeyType) != 0;
}

// Create PyStoredKey from enum TWStoredKey.
PyObject* PyStoredKey_FromTWStoredKey(TWStoredKey* value) {
  if (!value)
    Py_RETURN_NONE;

  PyStoredKeyObject* object = PyObject_New(PyStoredKeyObject, &PyStoredKeyType);
  if (!object)
    return nullptr;

  object->value = value;

  return (PyObject*)object;
}

TWStoredKey* PyStoredKey_GetTWStoredKey(PyObject* object) {
  assert(PyStoredKey_Check(object));
  return ((PyStoredKeyObject*)object)->value;
}

static void PyStoredKey_dealloc(PyStoredKeyObject* self) {
  if (self->value) {
    TWStoredKeyDelete(self->value);
  }
  Py_TYPE(self)->tp_free(self);
}

// getter function for Identifier
static const char PyStoredKeyIdentifier_doc[] =
    "TWString* TWStoredKeyIdentifier(struct TWStoredKey* key)";
static PyObject* PyStoredKeyIdentifier(PyStoredKeyObject* self, void*) {
  TWStringPtr prop(TWStoredKeyIdentifier(self->value));
  return PyUnicode_FromTWString(prop);
}

// getter function for Name
static const char PyStoredKeyName_doc[] =
    "TWString* TWStoredKeyName(struct TWStoredKey* key)";
static PyObject* PyStoredKeyName(PyStoredKeyObject* self, void*) {
  TWStringPtr prop(TWStoredKeyName(self->value));
  return PyUnicode_FromTWString(prop);
}

// getter function for IsMnemonic
static const char PyStoredKeyIsMnemonic_doc[] =
    "bool TWStoredKeyIsMnemonic(struct TWStoredKey* key)";
static PyObject* PyStoredKeyIsMnemonic(PyStoredKeyObject* self, void*) {
  bool prop = TWStoredKeyIsMnemonic(self->value);
  return PyBool_FromLong(prop);
}

// getter function for AccountCount
static const char PyStoredKeyAccountCount_doc[] =
    "size_t TWStoredKeyAccountCount(struct TWStoredKey* key)";
static PyObject* PyStoredKeyAccountCount(PyStoredKeyObject* self, void*) {
  size_t prop = TWStoredKeyAccountCount(self->value);
  return PyLong_FromLong(prop);
}

// getter function for EncryptionParameters
static const char PyStoredKeyEncryptionParameters_doc[] =
    "TWString* TWStoredKeyEncryptionParameters(struct TWStoredKey* key)";
static PyObject* PyStoredKeyEncryptionParameters(PyStoredKeyObject* self,
                                                 void*) {
  TWStringPtr prop(TWStoredKeyEncryptionParameters(self->value));
  return PyUnicode_FromTWString(prop);
}

// method function for Account
static const char PyStoredKeyAccount_doc[] =
    "struct TWAccount* TWStoredKeyAccount(struct TWStoredKey* key, size_t "
    "index)";
static PyObject* PyStoredKeyAccount(PyStoredKeyObject* self,
                                    PyObject* const* args,
                                    Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  auto checked_arg0 = PyLongArg_ToNumber<size_t>(args[0], 0, "size_t");
  if (!checked_arg0)
    return nullptr;
  const auto& arg0 = checked_arg0.value();

  TWAccount* result = TWStoredKeyAccount(self->value, arg0);
  return PyAccount_FromTWAccount(result);
}

// method function for AccountForCoin
static const char PyStoredKeyAccountForCoin_doc[] =
    "struct TWAccount* TWStoredKeyAccountForCoin(struct TWStoredKey* key, enum "
    "TWCoinType coin, struct TWHDWallet* wallet)";
static PyObject* PyStoredKeyAccountForCoin(PyStoredKeyObject* self,
                                           PyObject* const* args,
                                           Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  if (!PyCoinType_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type CoinType");
    return nullptr;
  }
  auto arg0 = PyCoinType_GetTWCoinType(args[0]);

  if (!PyHDWallet_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type HDWallet");
    return nullptr;
  }
  auto arg1 = PyHDWallet_GetTWHDWallet(args[1]);

  TWAccount* result = TWStoredKeyAccountForCoin(self->value, arg0, arg1);
  return PyAccount_FromTWAccount(result);
}

// method function for RemoveAccountForCoin
static const char PyStoredKeyRemoveAccountForCoin_doc[] =
    "void TWStoredKeyRemoveAccountForCoin(struct TWStoredKey* key, enum "
    "TWCoinType coin)";
static PyObject* PyStoredKeyRemoveAccountForCoin(PyStoredKeyObject* self,
                                                 PyObject* const* args,
                                                 Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  if (!PyCoinType_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type CoinType");
    return nullptr;
  }
  auto arg0 = PyCoinType_GetTWCoinType(args[0]);

  TWStoredKeyRemoveAccountForCoin(self->value, arg0);
  return nullptr;
}

// method function for AddAccount
static const char PyStoredKeyAddAccount_doc[] =
    "void TWStoredKeyAddAccount(struct TWStoredKey* key, TWString* address, "
    "enum TWCoinType coin, TWString* derivationPath, TWString* "
    "extetndedPublicKey)";
static PyObject* PyStoredKeyAddAccount(PyStoredKeyObject* self,
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

  if (!PyCoinType_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type CoinType");
    return nullptr;
  }
  auto arg1 = PyCoinType_GetTWCoinType(args[1]);

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

  TWStoredKeyAddAccount(self->value, arg0.get(), arg1, arg2.get(), arg3.get());
  return nullptr;
}

// method function for Store
static const char PyStoredKeyStore_doc[] =
    "bool TWStoredKeyStore(struct TWStoredKey* key, TWString* path)";
static PyObject* PyStoredKeyStore(PyStoredKeyObject* self,
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

  bool result = TWStoredKeyStore(self->value, arg0.get());
  return PyBool_FromLong(result);
}

// method function for DecryptPrivateKey
static const char PyStoredKeyDecryptPrivateKey_doc[] =
    "TWData* TWStoredKeyDecryptPrivateKey(struct TWStoredKey* key, TWData* "
    "password)";
static PyObject* PyStoredKeyDecryptPrivateKey(PyStoredKeyObject* self,
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

  TWDataPtr result(TWStoredKeyDecryptPrivateKey(self->value, arg0.get()));
  return PyBytes_FromTWData(result);
}

// method function for DecryptMnemonic
static const char PyStoredKeyDecryptMnemonic_doc[] =
    "TWString* TWStoredKeyDecryptMnemonic(struct TWStoredKey* key, TWData* "
    "password)";
static PyObject* PyStoredKeyDecryptMnemonic(PyStoredKeyObject* self,
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

  TWStringPtr result(TWStoredKeyDecryptMnemonic(self->value, arg0.get()));
  return PyUnicode_FromTWString(result);
}

// method function for PrivateKey
static const char PyStoredKeyPrivateKey_doc[] =
    "struct TWPrivateKey* TWStoredKeyPrivateKey(struct TWStoredKey* key, enum "
    "TWCoinType coin, TWData* password)";
static PyObject* PyStoredKeyPrivateKey(PyStoredKeyObject* self,
                                       PyObject* const* args,
                                       Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  if (!PyCoinType_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type CoinType");
    return nullptr;
  }
  auto arg0 = PyCoinType_GetTWCoinType(args[0]);

  if (!PyBytes_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bytes");
    return nullptr;
  }
  auto arg1 = PyBytes_GetTWData(args[1]);

  TWPrivateKey* result = TWStoredKeyPrivateKey(self->value, arg0, arg1.get());
  return PyPrivateKey_FromTWPrivateKey(result);
}

// method function for Wallet
static const char PyStoredKeyWallet_doc[] =
    "struct TWHDWallet* TWStoredKeyWallet(struct TWStoredKey* key, TWData* "
    "password)";
static PyObject* PyStoredKeyWallet(PyStoredKeyObject* self,
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

  TWHDWallet* result = TWStoredKeyWallet(self->value, arg0.get());
  return PyHDWallet_FromTWHDWallet(result);
}

// method function for ExportJSON
static const char PyStoredKeyExportJSON_doc[] =
    "TWData* TWStoredKeyExportJSON(struct TWStoredKey* key)";
static PyObject* PyStoredKeyExportJSON(PyStoredKeyObject* self,
                                       PyObject* const* args,
                                       Py_ssize_t nargs) {
  if (nargs != 0) {
    PyErr_Format(PyExc_TypeError, "Expect 0 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  TWDataPtr result(TWStoredKeyExportJSON(self->value));
  return PyBytes_FromTWData(result);
}

// method function for FixAddresses
static const char PyStoredKeyFixAddresses_doc[] =
    "bool TWStoredKeyFixAddresses(struct TWStoredKey* key, TWData* password)";
static PyObject* PyStoredKeyFixAddresses(PyStoredKeyObject* self,
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

  bool result = TWStoredKeyFixAddresses(self->value, arg0.get());
  return PyBool_FromLong(result);
}

// static method function for Load
static const char PyStoredKeyLoad_doc[] =
    "struct TWStoredKey* TWStoredKeyLoad(TWString* path)";
static PyObject* PyStoredKeyLoad(PyStoredKeyObject* self,
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

  TWStoredKey* result = TWStoredKeyLoad(arg0.get());
  return PyStoredKey_FromTWStoredKey(result);
}

// static method function for ImportPrivateKey
static const char PyStoredKeyImportPrivateKey_doc[] =
    "struct TWStoredKey* TWStoredKeyImportPrivateKey(TWData* privateKey, "
    "TWString* name, TWData* password, enum TWCoinType coin)";
static PyObject* PyStoredKeyImportPrivateKey(PyStoredKeyObject* self,
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

  if (!PyUnicode_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Unicode");
    return nullptr;
  }
  auto arg1 = PyUnicode_GetTWString(args[1]);

  if (!PyBytes_Check(args[2])) {
    PyErr_SetString(PyExc_TypeError, "The arg 2 is not in type Bytes");
    return nullptr;
  }
  auto arg2 = PyBytes_GetTWData(args[2]);

  if (!PyCoinType_Check(args[3])) {
    PyErr_SetString(PyExc_TypeError, "The arg 3 is not in type CoinType");
    return nullptr;
  }
  auto arg3 = PyCoinType_GetTWCoinType(args[3]);

  TWStoredKey* result =
      TWStoredKeyImportPrivateKey(arg0.get(), arg1.get(), arg2.get(), arg3);
  return PyStoredKey_FromTWStoredKey(result);
}

// static method function for ImportHDWallet
static const char PyStoredKeyImportHDWallet_doc[] =
    "struct TWStoredKey* TWStoredKeyImportHDWallet(TWString* mnemonic, "
    "TWString* name, TWData* password, enum TWCoinType coin)";
static PyObject* PyStoredKeyImportHDWallet(PyStoredKeyObject* self,
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

  if (!PyBytes_Check(args[2])) {
    PyErr_SetString(PyExc_TypeError, "The arg 2 is not in type Bytes");
    return nullptr;
  }
  auto arg2 = PyBytes_GetTWData(args[2]);

  if (!PyCoinType_Check(args[3])) {
    PyErr_SetString(PyExc_TypeError, "The arg 3 is not in type CoinType");
    return nullptr;
  }
  auto arg3 = PyCoinType_GetTWCoinType(args[3]);

  TWStoredKey* result =
      TWStoredKeyImportHDWallet(arg0.get(), arg1.get(), arg2.get(), arg3);
  return PyStoredKey_FromTWStoredKey(result);
}

// static method function for ImportJSON
static const char PyStoredKeyImportJSON_doc[] =
    "struct TWStoredKey* TWStoredKeyImportJSON(TWData* json)";
static PyObject* PyStoredKeyImportJSON(PyStoredKeyObject* self,
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

  TWStoredKey* result = TWStoredKeyImportJSON(arg0.get());
  return PyStoredKey_FromTWStoredKey(result);
}

// static method function for CreateLevel
static const char PyStoredKeyCreateLevel_doc[] =
    "struct TWStoredKey* TWStoredKeyCreateLevel(TWString* name, TWData* "
    "password, enum TWStoredKeyEncryptionLevel encryptionLevel)";
static PyObject* PyStoredKeyCreateLevel(PyStoredKeyObject* self,
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

  if (!PyBytes_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bytes");
    return nullptr;
  }
  auto arg1 = PyBytes_GetTWData(args[1]);

  if (!PyStoredKeyEncryptionLevel_Check(args[2])) {
    PyErr_SetString(PyExc_TypeError,
                    "The arg 2 is not in type StoredKeyEncryptionLevel");
    return nullptr;
  }
  auto arg2 = PyStoredKeyEncryptionLevel_GetTWStoredKeyEncryptionLevel(args[2]);

  TWStoredKey* result = TWStoredKeyCreateLevel(arg0.get(), arg1.get(), arg2);
  return PyStoredKey_FromTWStoredKey(result);
}

// static method function for Create
static const char PyStoredKeyCreate_doc[] =
    "struct TWStoredKey* TWStoredKeyCreate(TWString* name, TWData* password)";
static PyObject* PyStoredKeyCreate(PyStoredKeyObject* self,
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

  if (!PyBytes_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bytes");
    return nullptr;
  }
  auto arg1 = PyBytes_GetTWData(args[1]);

  TWStoredKey* result = TWStoredKeyCreate(arg0.get(), arg1.get());
  return PyStoredKey_FromTWStoredKey(result);
}

// properties

static const PyGetSetDef get_set_defs[] = {
    {"identifier", (getter)PyStoredKeyIdentifier, nullptr,
     PyStoredKeyIdentifier_doc},
    {"name", (getter)PyStoredKeyName, nullptr, PyStoredKeyName_doc},
    {"is_mnemonic", (getter)PyStoredKeyIsMnemonic, nullptr,
     PyStoredKeyIsMnemonic_doc},
    {"account_count", (getter)PyStoredKeyAccountCount, nullptr,
     PyStoredKeyAccountCount_doc},
    {"encryption_parameters", (getter)PyStoredKeyEncryptionParameters, nullptr,
     PyStoredKeyEncryptionParameters_doc},
    {}};

static const PyMethodDef method_defs[] = {
    {"account", (PyCFunction)PyStoredKeyAccount, METH_FASTCALL,
     PyStoredKeyAccount_doc},
    {"account_for_coin", (PyCFunction)PyStoredKeyAccountForCoin, METH_FASTCALL,
     PyStoredKeyAccountForCoin_doc},
    {"remove_account_for_coin", (PyCFunction)PyStoredKeyRemoveAccountForCoin,
     METH_FASTCALL, PyStoredKeyRemoveAccountForCoin_doc},
    {"add_account", (PyCFunction)PyStoredKeyAddAccount, METH_FASTCALL,
     PyStoredKeyAddAccount_doc},
    {"store", (PyCFunction)PyStoredKeyStore, METH_FASTCALL,
     PyStoredKeyStore_doc},
    {"decrypt_private_key", (PyCFunction)PyStoredKeyDecryptPrivateKey,
     METH_FASTCALL, PyStoredKeyDecryptPrivateKey_doc},
    {"decrypt_mnemonic", (PyCFunction)PyStoredKeyDecryptMnemonic, METH_FASTCALL,
     PyStoredKeyDecryptMnemonic_doc},
    {"private_key", (PyCFunction)PyStoredKeyPrivateKey, METH_FASTCALL,
     PyStoredKeyPrivateKey_doc},
    {"wallet", (PyCFunction)PyStoredKeyWallet, METH_FASTCALL,
     PyStoredKeyWallet_doc},
    {"export_json", (PyCFunction)PyStoredKeyExportJSON, METH_FASTCALL,
     PyStoredKeyExportJSON_doc},
    {"fix_addresses", (PyCFunction)PyStoredKeyFixAddresses, METH_FASTCALL,
     PyStoredKeyFixAddresses_doc},
    {"load", (PyCFunction)PyStoredKeyLoad, METH_FASTCALL | METH_STATIC,
     PyStoredKeyLoad_doc},
    {"import_private_key", (PyCFunction)PyStoredKeyImportPrivateKey,
     METH_FASTCALL | METH_STATIC, PyStoredKeyImportPrivateKey_doc},
    {"import_hdwallet", (PyCFunction)PyStoredKeyImportHDWallet,
     METH_FASTCALL | METH_STATIC, PyStoredKeyImportHDWallet_doc},
    {"import_json", (PyCFunction)PyStoredKeyImportJSON,
     METH_FASTCALL | METH_STATIC, PyStoredKeyImportJSON_doc},
    {"create_level", (PyCFunction)PyStoredKeyCreateLevel,
     METH_FASTCALL | METH_STATIC, PyStoredKeyCreateLevel_doc},
    {"create", (PyCFunction)PyStoredKeyCreate, METH_FASTCALL | METH_STATIC,
     PyStoredKeyCreate_doc},
    {}};

bool PyInit_StoredKey(PyObject* module) {
  PyStoredKeyType.tp_dealloc = (destructor)PyStoredKey_dealloc;
  PyStoredKeyType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyStoredKeyType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyStoredKeyType) < 0)
    return false;

  Py_INCREF(&PyStoredKeyType);
  if (PyModule_AddObject(module, "StoredKey", (PyObject*)&PyStoredKeyType) <
      0) {
    Py_DECREF(&PyStoredKeyType);
    return false;
  }

  return true;
}