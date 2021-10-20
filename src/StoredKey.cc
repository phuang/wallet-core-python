// This is a GENERATED FILE, changes made here WILL BE LOST.

#include "StoredKey.h"

#include "Account.h"
#include "CoinType.h"
#include "Data.h"
#include "HDWallet.h"
#include "PrivateKey.h"
#include "String.h"

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
    return nullptr;

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

// static int PyStoredKey_init(PyStoredKeyObject *self, PyObject *args, PyObject
// *kwds) {
//   return 0;
// }

// static PyObject* PyStoredKey_new(PyTypeObject *subtype, PyObject *args,
// PyObject *kwds) {
//   int value = 0;
//   if (!PyArg_ParseTuple(args, "|i", &value)) {
//     return nullptr;
//   }
//   return PyStoredKey_FromTWStoredKey((TWStoredKey)value);
// }

// static PyObject* PyStoredKey_str(PyStoredKeyObject *self) {
//   const char* str = "Unknown";
//   return PyUnicode_FromString(str);
// }

// getter function for IsMnemonic
// bool TWStoredKeyIsMnemonic(struct TWStoredKey* key);
static PyObject* PyStoredKeyIsMnemonic(PyStoredKeyObject* self, void*) {
  return PyBool_FromLong(TWStoredKeyIsMnemonic(self->value));
}

// method function for Delete
// void TWStoredKeyDelete(struct TWStoredKey* key);
static PyObject* PyStoredKeyDelete(PyStoredKeyObject* self,
                                   PyObject* const* args,
                                   Py_ssize_t nargs) {
  if (nargs != 0) {
    PyErr_Format(PyExc_TypeError, "Expect 0 instead of %d.", nargs);
    return nullptr;
  }

  TWStoredKeyDelete(self->value);
  return nullptr;
}

// method function for Account
// struct TWAccount* TWStoredKeyAccount(struct TWStoredKey* key, size_t index);
static PyObject* PyStoredKeyAccount(PyStoredKeyObject* self,
                                    PyObject* const* args,
                                    Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyLong_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Long");
    return nullptr;
  }
  auto arg0 = PyLong_AsLong(args[0]);

  TWAccount* result = TWStoredKeyAccount(self->value, arg0);
  return PyAccount_FromTWAccount(result);
}

// method function for AccountForCoin
// struct TWAccount* TWStoredKeyAccountForCoin(struct TWStoredKey* key, enum
// TWCoinType coin, struct TWHDWallet* wallet);
static PyObject* PyStoredKeyAccountForCoin(PyStoredKeyObject* self,
                                           PyObject* const* args,
                                           Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
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
// void TWStoredKeyRemoveAccountForCoin(struct TWStoredKey* key, enum TWCoinType
// coin);
static PyObject* PyStoredKeyRemoveAccountForCoin(PyStoredKeyObject* self,
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

  TWStoredKeyRemoveAccountForCoin(self->value, arg0);
  return nullptr;
}

// method function for AddAccount
// void TWStoredKeyAddAccount(struct TWStoredKey* key, TWString* address, enum
// TWCoinType coin, TWString* derivationPath, TWString* extetndedPublicKey);
static PyObject* PyStoredKeyAddAccount(PyStoredKeyObject* self,
                                       PyObject* const* args,
                                       Py_ssize_t nargs) {
  if (nargs != 4) {
    PyErr_Format(PyExc_TypeError, "Expect 4 instead of %d.", nargs);
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
// bool TWStoredKeyStore(struct TWStoredKey* key, TWString* path);
static PyObject* PyStoredKeyStore(PyStoredKeyObject* self,
                                  PyObject* const* args,
                                  Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 instead of %d.", nargs);
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
// TWData* TWStoredKeyDecryptPrivateKey(struct TWStoredKey* key, TWData*
// password);
static PyObject* PyStoredKeyDecryptPrivateKey(PyStoredKeyObject* self,
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

  TWDataPtr result = TWStoredKeyDecryptPrivateKey(self->value, arg0.get());
  return PyByteArray_FromTWData(result);
}

// method function for DecryptMnemonic
// TWString* TWStoredKeyDecryptMnemonic(struct TWStoredKey* key, TWData*
// password);
static PyObject* PyStoredKeyDecryptMnemonic(PyStoredKeyObject* self,
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

  TWStringPtr result = TWStoredKeyDecryptMnemonic(self->value, arg0.get());
  return PyUnicode_FromTWString(result);
}

// method function for PrivateKey
// struct TWPrivateKey* TWStoredKeyPrivateKey(struct TWStoredKey* key, enum
// TWCoinType coin, TWData* password);
static PyObject* PyStoredKeyPrivateKey(PyStoredKeyObject* self,
                                       PyObject* const* args,
                                       Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyCoinType_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type CoinType");
    return nullptr;
  }
  auto arg0 = PyCoinType_GetTWCoinType(args[0]);

  if (!PyByteArray_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type ByteArray");
    return nullptr;
  }
  auto arg1 = PyByteArray_GetTWData(args[1]);

  TWPrivateKey* result = TWStoredKeyPrivateKey(self->value, arg0, arg1.get());
  return PyPrivateKey_FromTWPrivateKey(result);
}

// method function for Wallet
// struct TWHDWallet* TWStoredKeyWallet(struct TWStoredKey* key, TWData*
// password);
static PyObject* PyStoredKeyWallet(PyStoredKeyObject* self,
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

  TWHDWallet* result = TWStoredKeyWallet(self->value, arg0.get());
  return PyHDWallet_FromTWHDWallet(result);
}

// method function for ExportJSON
// TWData* TWStoredKeyExportJSON(struct TWStoredKey* key);
static PyObject* PyStoredKeyExportJSON(PyStoredKeyObject* self,
                                       PyObject* const* args,
                                       Py_ssize_t nargs) {
  if (nargs != 0) {
    PyErr_Format(PyExc_TypeError, "Expect 0 instead of %d.", nargs);
    return nullptr;
  }

  TWDataPtr result = TWStoredKeyExportJSON(self->value);
  return PyByteArray_FromTWData(result);
}

// method function for FixAddresses
// bool TWStoredKeyFixAddresses(struct TWStoredKey* key, TWData* password);
static PyObject* PyStoredKeyFixAddresses(PyStoredKeyObject* self,
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

  bool result = TWStoredKeyFixAddresses(self->value, arg0.get());
  return PyBool_FromLong(result);
}

// static method function for Load
// struct TWStoredKey* TWStoredKeyLoad(TWString* path);
static PyObject* PyStoredKeyLoad(PyStoredKeyObject* self,
                                 PyObject* const* args,
                                 Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 instead of %d.", nargs);
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
// struct TWStoredKey* TWStoredKeyImportPrivateKey(TWData* privateKey, TWString*
// name, TWData* password, enum TWCoinType coin);
static PyObject* PyStoredKeyImportPrivateKey(PyStoredKeyObject* self,
                                             PyObject* const* args,
                                             Py_ssize_t nargs) {
  if (nargs != 4) {
    PyErr_Format(PyExc_TypeError, "Expect 4 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyByteArray_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type ByteArray");
    return nullptr;
  }
  auto arg0 = PyByteArray_GetTWData(args[0]);

  if (!PyUnicode_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Unicode");
    return nullptr;
  }
  auto arg1 = PyUnicode_GetTWString(args[1]);

  if (!PyByteArray_Check(args[2])) {
    PyErr_SetString(PyExc_TypeError, "The arg 2 is not in type ByteArray");
    return nullptr;
  }
  auto arg2 = PyByteArray_GetTWData(args[2]);

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
// struct TWStoredKey* TWStoredKeyImportHDWallet(TWString* mnemonic, TWString*
// name, TWData* password, enum TWCoinType coin);
static PyObject* PyStoredKeyImportHDWallet(PyStoredKeyObject* self,
                                           PyObject* const* args,
                                           Py_ssize_t nargs) {
  if (nargs != 4) {
    PyErr_Format(PyExc_TypeError, "Expect 4 instead of %d.", nargs);
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

  if (!PyByteArray_Check(args[2])) {
    PyErr_SetString(PyExc_TypeError, "The arg 2 is not in type ByteArray");
    return nullptr;
  }
  auto arg2 = PyByteArray_GetTWData(args[2]);

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
// struct TWStoredKey* TWStoredKeyImportJSON(TWData* json);
static PyObject* PyStoredKeyImportJSON(PyStoredKeyObject* self,
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

  TWStoredKey* result = TWStoredKeyImportJSON(arg0.get());
  return PyStoredKey_FromTWStoredKey(result);
}

// static method function for Create
// struct TWStoredKey* TWStoredKeyCreate(TWString* name, TWData* password);
static PyObject* PyStoredKeyCreate(PyStoredKeyObject* self,
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

  if (!PyByteArray_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type ByteArray");
    return nullptr;
  }
  auto arg1 = PyByteArray_GetTWData(args[1]);

  TWStoredKey* result = TWStoredKeyCreate(arg0.get(), arg1.get());
  return PyStoredKey_FromTWStoredKey(result);
}

static const PyGetSetDef get_set_defs[] = {
    {"IsMnemonic", (getter)PyStoredKeyIsMnemonic},
    {}};

static const PyMethodDef method_defs[] = {
    {"Delete", (PyCFunction)PyStoredKeyDelete, METH_FASTCALL},
    {"Account", (PyCFunction)PyStoredKeyAccount, METH_FASTCALL},
    {"AccountForCoin", (PyCFunction)PyStoredKeyAccountForCoin, METH_FASTCALL},
    {"RemoveAccountForCoin", (PyCFunction)PyStoredKeyRemoveAccountForCoin,
     METH_FASTCALL},
    {"AddAccount", (PyCFunction)PyStoredKeyAddAccount, METH_FASTCALL},
    {"Store", (PyCFunction)PyStoredKeyStore, METH_FASTCALL},
    {"DecryptPrivateKey", (PyCFunction)PyStoredKeyDecryptPrivateKey,
     METH_FASTCALL},
    {"DecryptMnemonic", (PyCFunction)PyStoredKeyDecryptMnemonic, METH_FASTCALL},
    {"PrivateKey", (PyCFunction)PyStoredKeyPrivateKey, METH_FASTCALL},
    {"Wallet", (PyCFunction)PyStoredKeyWallet, METH_FASTCALL},
    {"ExportJSON", (PyCFunction)PyStoredKeyExportJSON, METH_FASTCALL},
    {"FixAddresses", (PyCFunction)PyStoredKeyFixAddresses, METH_FASTCALL},
    {"Load", (PyCFunction)PyStoredKeyLoad, METH_FASTCALL | METH_STATIC},
    {"ImportPrivateKey", (PyCFunction)PyStoredKeyImportPrivateKey,
     METH_FASTCALL | METH_STATIC},
    {"ImportHDWallet", (PyCFunction)PyStoredKeyImportHDWallet,
     METH_FASTCALL | METH_STATIC},
    {"ImportJSON", (PyCFunction)PyStoredKeyImportJSON,
     METH_FASTCALL | METH_STATIC},
    {"Create", (PyCFunction)PyStoredKeyCreate, METH_FASTCALL | METH_STATIC},
    {}};

bool PyInit_StoredKey(PyObject* module) {
  // PyStoredKeyType.tp_new = PyStoredKey_new;
  // PyStoredKeyType.tp_init = (initproc)PyStoredKey_init;
  // PyStoredKeyType.tp_str = (reprfunc)PyStoredKey_str;
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