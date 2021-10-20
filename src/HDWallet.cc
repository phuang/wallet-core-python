// This is a GENERATED FILE, changes made here WILL BE LOST.

#include "HDWallet.h"

#include "Bool.h"
#include "CoinType.h"
#include "Curve.h"
#include "Data.h"
#include "HDVersion.h"
#include "PrivateKey.h"
#include "PublicKey.h"
#include "Purpose.h"
#include "String.h"

static PyTypeObject PyHDWalletType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.HDWallet",    /* tp_name */
    sizeof(PyHDWalletObject), /* tp_basicsize */
    0,                        /* tp_itemsize */
    0,                        /* tp_dealloc */
    0,                        /* tp_print */
    0,                        /* tp_getattr */
    0,                        /* tp_setattr */
    0,                        /* tp_reserved */
    0,                        /* tp_repr */
    0,                        /* tp_as_number */
    0,                        /* tp_as_sequence */
    0,                        /* tp_as_mapping */
    0,                        /* tp_hash  */
    0,                        /* tp_call */
    0,                        /* tp_str */
    0,                        /* tp_getattro */
    0,                        /* tp_setattro */
    0,                        /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,       /* tp_flags */
    nullptr,                  /* tp_doc */
};

bool PyHDWallet_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyHDWalletType) != 0;
}

// Create PyHDWallet from enum TWHDWallet.
PyObject* PyHDWallet_FromTWHDWallet(TWHDWallet* value) {
  if (!value)
    return nullptr;

  PyHDWalletObject* object = PyObject_New(PyHDWalletObject, &PyHDWalletType);
  if (!object)
    return nullptr;

  object->value = value;

  return (PyObject*)object;
}

TWHDWallet* PyHDWallet_GetTWHDWallet(PyObject* object) {
  assert(PyHDWallet_Check(object));
  return ((PyHDWalletObject*)object)->value;
}

// static int PyHDWallet_init(PyHDWalletObject *self, PyObject *args, PyObject
// *kwds) {
//   return 0;
// }

// static PyObject* PyHDWallet_new(PyTypeObject *subtype, PyObject *args,
// PyObject *kwds) {
//   int value = 0;
//   if (!PyArg_ParseTuple(args, "|i", &value)) {
//     return nullptr;
//   }
//   return PyHDWallet_FromTWHDWallet((TWHDWallet)value);
// }

// static PyObject* PyHDWallet_str(PyHDWalletObject *self) {
//   const char* str = "Unknown";
//   return PyUnicode_FromString(str);
// }

// method function for Delete
// void TWHDWalletDelete(struct TWHDWallet* wallet);
static PyObject* PyHDWalletDelete(PyHDWalletObject* self,
                                  PyObject* const* args,
                                  Py_ssize_t nargs) {
  if (nargs != 0) {
    PyErr_Format(PyExc_TypeError, "Expect 0 instead of %d.", nargs);
    return nullptr;
  }

  TWHDWalletDelete(self->value);
  return nullptr;
}

// method function for GetMasterKey
// struct TWPrivateKey* TWHDWalletGetMasterKey(struct TWHDWallet* wallet, enum
// TWCurve curve);
static PyObject* PyHDWalletGetMasterKey(PyHDWalletObject* self,
                                        PyObject* const* args,
                                        Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyCurve_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Curve");
    return nullptr;
  }
  auto arg0 = PyCurve_GetTWCurve(args[0]);

  TWPrivateKey* result = TWHDWalletGetMasterKey(self->value, arg0);
  return PyPrivateKey_FromTWPrivateKey(result);
}

// method function for GetKeyForCoin
// struct TWPrivateKey* TWHDWalletGetKeyForCoin(struct TWHDWallet* wallet, enum
// TWCoinType coin);
static PyObject* PyHDWalletGetKeyForCoin(PyHDWalletObject* self,
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

  TWPrivateKey* result = TWHDWalletGetKeyForCoin(self->value, arg0);
  return PyPrivateKey_FromTWPrivateKey(result);
}

// method function for GetAddressForCoin
// TWString* TWHDWalletGetAddressForCoin(struct TWHDWallet* wallet, enum
// TWCoinType coin);
static PyObject* PyHDWalletGetAddressForCoin(PyHDWalletObject* self,
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

  TWStringPtr result = TWHDWalletGetAddressForCoin(self->value, arg0);
  return PyUnicode_FromTWString(result);
}

// method function for GetKey
// struct TWPrivateKey* TWHDWalletGetKey(struct TWHDWallet* wallet, enum
// TWCoinType coin, TWString* derivationPath);
static PyObject* PyHDWalletGetKey(PyHDWalletObject* self,
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

  if (!PyUnicode_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Unicode");
    return nullptr;
  }
  auto arg1 = PyUnicode_GetTWString(args[1]);

  TWPrivateKey* result = TWHDWalletGetKey(self->value, arg0, arg1.get());
  return PyPrivateKey_FromTWPrivateKey(result);
}

// method function for GetDerivedKey
// struct TWPrivateKey* TWHDWalletGetDerivedKey(struct TWHDWallet* wallet, enum
// TWCoinType coin, uint32_t account, uint32_t change, uint32_t address);
static PyObject* PyHDWalletGetDerivedKey(PyHDWalletObject* self,
                                         PyObject* const* args,
                                         Py_ssize_t nargs) {
  if (nargs != 4) {
    PyErr_Format(PyExc_TypeError, "Expect 4 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyCoinType_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type CoinType");
    return nullptr;
  }
  auto arg0 = PyCoinType_GetTWCoinType(args[0]);

  if (!PyLong_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Long");
    return nullptr;
  }
  auto arg1 = PyLong_AsLong(args[1]);

  if (!PyLong_Check(args[2])) {
    PyErr_SetString(PyExc_TypeError, "The arg 2 is not in type Long");
    return nullptr;
  }
  auto arg2 = PyLong_AsLong(args[2]);

  if (!PyLong_Check(args[3])) {
    PyErr_SetString(PyExc_TypeError, "The arg 3 is not in type Long");
    return nullptr;
  }
  auto arg3 = PyLong_AsLong(args[3]);

  TWPrivateKey* result =
      TWHDWalletGetDerivedKey(self->value, arg0, arg1, arg2, arg3);
  return PyPrivateKey_FromTWPrivateKey(result);
}

// method function for GetExtendedPrivateKey
// TWString* TWHDWalletGetExtendedPrivateKey(struct TWHDWallet* wallet, enum
// TWPurpose purpose, enum TWCoinType coin, enum TWHDVersion version);
static PyObject* PyHDWalletGetExtendedPrivateKey(PyHDWalletObject* self,
                                                 PyObject* const* args,
                                                 Py_ssize_t nargs) {
  if (nargs != 3) {
    PyErr_Format(PyExc_TypeError, "Expect 3 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyPurpose_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Purpose");
    return nullptr;
  }
  auto arg0 = PyPurpose_GetTWPurpose(args[0]);

  if (!PyCoinType_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type CoinType");
    return nullptr;
  }
  auto arg1 = PyCoinType_GetTWCoinType(args[1]);

  if (!PyHDVersion_Check(args[2])) {
    PyErr_SetString(PyExc_TypeError, "The arg 2 is not in type HDVersion");
    return nullptr;
  }
  auto arg2 = PyHDVersion_GetTWHDVersion(args[2]);

  TWStringPtr result =
      TWHDWalletGetExtendedPrivateKey(self->value, arg0, arg1, arg2);
  return PyUnicode_FromTWString(result);
}

// method function for GetExtendedPublicKey
// TWString* TWHDWalletGetExtendedPublicKey(struct TWHDWallet* wallet, enum
// TWPurpose purpose, enum TWCoinType coin, enum TWHDVersion version);
static PyObject* PyHDWalletGetExtendedPublicKey(PyHDWalletObject* self,
                                                PyObject* const* args,
                                                Py_ssize_t nargs) {
  if (nargs != 3) {
    PyErr_Format(PyExc_TypeError, "Expect 3 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyPurpose_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Purpose");
    return nullptr;
  }
  auto arg0 = PyPurpose_GetTWPurpose(args[0]);

  if (!PyCoinType_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type CoinType");
    return nullptr;
  }
  auto arg1 = PyCoinType_GetTWCoinType(args[1]);

  if (!PyHDVersion_Check(args[2])) {
    PyErr_SetString(PyExc_TypeError, "The arg 2 is not in type HDVersion");
    return nullptr;
  }
  auto arg2 = PyHDVersion_GetTWHDVersion(args[2]);

  TWStringPtr result =
      TWHDWalletGetExtendedPublicKey(self->value, arg0, arg1, arg2);
  return PyUnicode_FromTWString(result);
}

// static method function for Create
// struct TWHDWallet* TWHDWalletCreate(int strength, TWString* passphrase);
static PyObject* PyHDWalletCreate(PyHDWalletObject* self,
                                  PyObject* const* args,
                                  Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyLong_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Long");
    return nullptr;
  }
  auto arg0 = PyLong_AsLong(args[0]);

  if (!PyUnicode_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Unicode");
    return nullptr;
  }
  auto arg1 = PyUnicode_GetTWString(args[1]);

  TWHDWallet* result = TWHDWalletCreate(arg0, arg1.get());
  return PyHDWallet_FromTWHDWallet(result);
}

// static method function for CreateWithMnemonic
// struct TWHDWallet* TWHDWalletCreateWithMnemonic(TWString* mnemonic, TWString*
// passphrase);
static PyObject* PyHDWalletCreateWithMnemonic(PyHDWalletObject* self,
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

  if (!PyUnicode_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Unicode");
    return nullptr;
  }
  auto arg1 = PyUnicode_GetTWString(args[1]);

  TWHDWallet* result = TWHDWalletCreateWithMnemonic(arg0.get(), arg1.get());
  return PyHDWallet_FromTWHDWallet(result);
}

// static method function for CreateWithMnemonicCheck
// struct TWHDWallet* TWHDWalletCreateWithMnemonicCheck(TWString* mnemonic,
// TWString* passphrase, bool check);
static PyObject* PyHDWalletCreateWithMnemonicCheck(PyHDWalletObject* self,
                                                   PyObject* const* args,
                                                   Py_ssize_t nargs) {
  if (nargs != 3) {
    PyErr_Format(PyExc_TypeError, "Expect 3 instead of %d.", nargs);
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

  if (!PyBool_Check(args[2])) {
    PyErr_SetString(PyExc_TypeError, "The arg 2 is not in type Bool");
    return nullptr;
  }
  auto arg2 = PyBool_IsTrue(args[2]);

  TWHDWallet* result =
      TWHDWalletCreateWithMnemonicCheck(arg0.get(), arg1.get(), arg2);
  return PyHDWallet_FromTWHDWallet(result);
}

// static method function for CreateWithEntropy
// struct TWHDWallet* TWHDWalletCreateWithEntropy(TWData* entropy, TWString*
// passphrase);
static PyObject* PyHDWalletCreateWithEntropy(PyHDWalletObject* self,
                                             PyObject* const* args,
                                             Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
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

  TWHDWallet* result = TWHDWalletCreateWithEntropy(arg0.get(), arg1.get());
  return PyHDWallet_FromTWHDWallet(result);
}

// static method function for GetPublicKeyFromExtended
// struct TWPublicKey* TWHDWalletGetPublicKeyFromExtended(TWString* extended,
// enum TWCoinType coin, TWString* derivationPath);
static PyObject* PyHDWalletGetPublicKeyFromExtended(PyHDWalletObject* self,
                                                    PyObject* const* args,
                                                    Py_ssize_t nargs) {
  if (nargs != 3) {
    PyErr_Format(PyExc_TypeError, "Expect 3 instead of %d.", nargs);
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

  TWPublicKey* result =
      TWHDWalletGetPublicKeyFromExtended(arg0.get(), arg1, arg2.get());
  return PyPublicKey_FromTWPublicKey(result);
}

static const PyGetSetDef get_set_defs[] = {{}};

static const PyMethodDef method_defs[] = {
    {"Delete", (PyCFunction)PyHDWalletDelete, METH_FASTCALL},
    {"GetMasterKey", (PyCFunction)PyHDWalletGetMasterKey, METH_FASTCALL},
    {"GetKeyForCoin", (PyCFunction)PyHDWalletGetKeyForCoin, METH_FASTCALL},
    {"GetAddressForCoin", (PyCFunction)PyHDWalletGetAddressForCoin,
     METH_FASTCALL},
    {"GetKey", (PyCFunction)PyHDWalletGetKey, METH_FASTCALL},
    {"GetDerivedKey", (PyCFunction)PyHDWalletGetDerivedKey, METH_FASTCALL},
    {"GetExtendedPrivateKey", (PyCFunction)PyHDWalletGetExtendedPrivateKey,
     METH_FASTCALL},
    {"GetExtendedPublicKey", (PyCFunction)PyHDWalletGetExtendedPublicKey,
     METH_FASTCALL},
    {"Create", (PyCFunction)PyHDWalletCreate, METH_FASTCALL | METH_STATIC},
    {"CreateWithMnemonic", (PyCFunction)PyHDWalletCreateWithMnemonic,
     METH_FASTCALL | METH_STATIC},
    {"CreateWithMnemonicCheck", (PyCFunction)PyHDWalletCreateWithMnemonicCheck,
     METH_FASTCALL | METH_STATIC},
    {"CreateWithEntropy", (PyCFunction)PyHDWalletCreateWithEntropy,
     METH_FASTCALL | METH_STATIC},
    {"GetPublicKeyFromExtended",
     (PyCFunction)PyHDWalletGetPublicKeyFromExtended,
     METH_FASTCALL | METH_STATIC},
    {}};

bool PyInit_HDWallet(PyObject* module) {
  // PyHDWalletType.tp_new = PyHDWallet_new;
  // PyHDWalletType.tp_init = (initproc)PyHDWallet_init;
  // PyHDWalletType.tp_str = (reprfunc)PyHDWallet_str;
  PyHDWalletType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyHDWalletType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyHDWalletType) < 0)
    return false;

  Py_INCREF(&PyHDWalletType);
  if (PyModule_AddObject(module, "HDWallet", (PyObject*)&PyHDWalletType) < 0) {
    Py_DECREF(&PyHDWalletType);
    return false;
  }

  return true;
}