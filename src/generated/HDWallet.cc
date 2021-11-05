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

#include "generated/HDWallet.h"

#include "Bool.h"
#include "Data.h"
#include "Number.h"
#include "String.h"
#include "generated/CoinType.h"
#include "generated/Curve.h"
#include "generated/HDVersion.h"
#include "generated/PrivateKey.h"
#include "generated/PublicKey.h"
#include "generated/Purpose.h"

struct PyHDWalletObject {
  PyObject_HEAD;
  TWHDWallet* value;
};

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
    Py_RETURN_NONE;

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

static void PyHDWallet_dealloc(PyHDWalletObject* self) {
  if (self->value) {
    TWHDWalletDelete(self->value);
  }
  Py_TYPE(self)->tp_free(self);
}

// getter function for Seed
static const char PyHDWalletSeed_doc[] =
    "TWData* TWHDWalletSeed(struct TWHDWallet* wallet)";
static PyObject* PyHDWalletSeed(PyHDWalletObject* self, void*) {
  TWDataPtr prop(TWHDWalletSeed(self->value));
  return PyBytes_FromTWData(prop);
}

// getter function for Mnemonic
static const char PyHDWalletMnemonic_doc[] =
    "TWString* TWHDWalletMnemonic(struct TWHDWallet* wallet)";
static PyObject* PyHDWalletMnemonic(PyHDWalletObject* self, void*) {
  TWStringPtr prop(TWHDWalletMnemonic(self->value));
  return PyUnicode_FromTWString(prop);
}

// getter function for Entropy
static const char PyHDWalletEntropy_doc[] =
    "TWData* TWHDWalletEntropy(struct TWHDWallet* wallet)";
static PyObject* PyHDWalletEntropy(PyHDWalletObject* self, void*) {
  TWDataPtr prop(TWHDWalletEntropy(self->value));
  return PyBytes_FromTWData(prop);
}

// method function for GetMasterKey
static const char PyHDWalletGetMasterKey_doc[] =
    "struct TWPrivateKey* TWHDWalletGetMasterKey(struct TWHDWallet* wallet, "
    "enum TWCurve curve)";
static PyObject* PyHDWalletGetMasterKey(PyHDWalletObject* self,
                                        PyObject* const* args,
                                        Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 args, but %d args are passed in.",
                 nargs);
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
static const char PyHDWalletGetKeyForCoin_doc[] =
    "struct TWPrivateKey* TWHDWalletGetKeyForCoin(struct TWHDWallet* wallet, "
    "enum TWCoinType coin)";
static PyObject* PyHDWalletGetKeyForCoin(PyHDWalletObject* self,
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

  TWPrivateKey* result = TWHDWalletGetKeyForCoin(self->value, arg0);
  return PyPrivateKey_FromTWPrivateKey(result);
}

// method function for GetAddressForCoin
static const char PyHDWalletGetAddressForCoin_doc[] =
    "TWString* TWHDWalletGetAddressForCoin(struct TWHDWallet* wallet, enum "
    "TWCoinType coin)";
static PyObject* PyHDWalletGetAddressForCoin(PyHDWalletObject* self,
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

  TWStringPtr result(TWHDWalletGetAddressForCoin(self->value, arg0));
  return PyUnicode_FromTWString(result);
}

// method function for GetKey
static const char PyHDWalletGetKey_doc[] =
    "struct TWPrivateKey* TWHDWalletGetKey(struct TWHDWallet* wallet, enum "
    "TWCoinType coin, TWString* derivationPath)";
static PyObject* PyHDWalletGetKey(PyHDWalletObject* self,
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

  if (!PyUnicode_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Unicode");
    return nullptr;
  }
  auto arg1 = PyUnicode_GetTWString(args[1]);

  TWPrivateKey* result = TWHDWalletGetKey(self->value, arg0, arg1.get());
  return PyPrivateKey_FromTWPrivateKey(result);
}

// method function for GetDerivedKey
static const char PyHDWalletGetDerivedKey_doc[] =
    "struct TWPrivateKey* TWHDWalletGetDerivedKey(struct TWHDWallet* wallet, "
    "enum TWCoinType coin, uint32_t account, uint32_t change, uint32_t "
    "address)";
static PyObject* PyHDWalletGetDerivedKey(PyHDWalletObject* self,
                                         PyObject* const* args,
                                         Py_ssize_t nargs) {
  if (nargs != 4) {
    PyErr_Format(PyExc_TypeError, "Expect 4 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  if (!PyCoinType_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type CoinType");
    return nullptr;
  }
  auto arg0 = PyCoinType_GetTWCoinType(args[0]);

  auto checked_arg1 = PyLongArg_ToNumber<uint32_t>(args[1], 1, "uint32_t");
  if (!checked_arg1)
    return nullptr;
  const auto& arg1 = checked_arg1.value();

  auto checked_arg2 = PyLongArg_ToNumber<uint32_t>(args[2], 2, "uint32_t");
  if (!checked_arg2)
    return nullptr;
  const auto& arg2 = checked_arg2.value();

  auto checked_arg3 = PyLongArg_ToNumber<uint32_t>(args[3], 3, "uint32_t");
  if (!checked_arg3)
    return nullptr;
  const auto& arg3 = checked_arg3.value();

  TWPrivateKey* result =
      TWHDWalletGetDerivedKey(self->value, arg0, arg1, arg2, arg3);
  return PyPrivateKey_FromTWPrivateKey(result);
}

// method function for GetExtendedPrivateKey
static const char PyHDWalletGetExtendedPrivateKey_doc[] =
    "TWString* TWHDWalletGetExtendedPrivateKey(struct TWHDWallet* wallet, enum "
    "TWPurpose purpose, enum TWCoinType coin, enum TWHDVersion version)";
static PyObject* PyHDWalletGetExtendedPrivateKey(PyHDWalletObject* self,
                                                 PyObject* const* args,
                                                 Py_ssize_t nargs) {
  if (nargs != 3) {
    PyErr_Format(PyExc_TypeError, "Expect 3 args, but %d args are passed in.",
                 nargs);
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

  TWStringPtr result(
      TWHDWalletGetExtendedPrivateKey(self->value, arg0, arg1, arg2));
  return PyUnicode_FromTWString(result);
}

// method function for GetExtendedPublicKey
static const char PyHDWalletGetExtendedPublicKey_doc[] =
    "TWString* TWHDWalletGetExtendedPublicKey(struct TWHDWallet* wallet, enum "
    "TWPurpose purpose, enum TWCoinType coin, enum TWHDVersion version)";
static PyObject* PyHDWalletGetExtendedPublicKey(PyHDWalletObject* self,
                                                PyObject* const* args,
                                                Py_ssize_t nargs) {
  if (nargs != 3) {
    PyErr_Format(PyExc_TypeError, "Expect 3 args, but %d args are passed in.",
                 nargs);
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

  TWStringPtr result(
      TWHDWalletGetExtendedPublicKey(self->value, arg0, arg1, arg2));
  return PyUnicode_FromTWString(result);
}

// static method function for Create
static const char PyHDWalletCreate_doc[] =
    "struct TWHDWallet* TWHDWalletCreate(int32_t strength, TWString* "
    "passphrase)";
static PyObject* PyHDWalletCreate(PyHDWalletObject* self,
                                  PyObject* const* args,
                                  Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  auto checked_arg0 = PyLongArg_ToNumber<int32_t>(args[0], 0, "int32_t");
  if (!checked_arg0)
    return nullptr;
  const auto& arg0 = checked_arg0.value();

  if (!PyUnicode_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Unicode");
    return nullptr;
  }
  auto arg1 = PyUnicode_GetTWString(args[1]);

  TWHDWallet* result = TWHDWalletCreate(arg0, arg1.get());
  return PyHDWallet_FromTWHDWallet(result);
}

// static method function for CreateWithMnemonic
static const char PyHDWalletCreateWithMnemonic_doc[] =
    "struct TWHDWallet* TWHDWalletCreateWithMnemonic(TWString* mnemonic, "
    "TWString* passphrase)";
static PyObject* PyHDWalletCreateWithMnemonic(PyHDWalletObject* self,
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

  TWHDWallet* result = TWHDWalletCreateWithMnemonic(arg0.get(), arg1.get());
  return PyHDWallet_FromTWHDWallet(result);
}

// static method function for CreateWithMnemonicCheck
static const char PyHDWalletCreateWithMnemonicCheck_doc[] =
    "struct TWHDWallet* TWHDWalletCreateWithMnemonicCheck(TWString* mnemonic, "
    "TWString* passphrase, bool check)";
static PyObject* PyHDWalletCreateWithMnemonicCheck(PyHDWalletObject* self,
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
static const char PyHDWalletCreateWithEntropy_doc[] =
    "struct TWHDWallet* TWHDWalletCreateWithEntropy(TWData* entropy, TWString* "
    "passphrase)";
static PyObject* PyHDWalletCreateWithEntropy(PyHDWalletObject* self,
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

  TWHDWallet* result = TWHDWalletCreateWithEntropy(arg0.get(), arg1.get());
  return PyHDWallet_FromTWHDWallet(result);
}

// static method function for GetPublicKeyFromExtended
static const char PyHDWalletGetPublicKeyFromExtended_doc[] =
    "struct TWPublicKey* TWHDWalletGetPublicKeyFromExtended(TWString* "
    "extended, enum TWCoinType coin, TWString* derivationPath)";
static PyObject* PyHDWalletGetPublicKeyFromExtended(PyHDWalletObject* self,
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

// properties

static const PyGetSetDef get_set_defs[] = {
    {"seed", (getter)PyHDWalletSeed, nullptr, PyHDWalletSeed_doc},
    {"mnemonic", (getter)PyHDWalletMnemonic, nullptr, PyHDWalletMnemonic_doc},
    {"entropy", (getter)PyHDWalletEntropy, nullptr, PyHDWalletEntropy_doc},
    {}};

static const PyMethodDef method_defs[] = {
    {"get_master_key", (PyCFunction)PyHDWalletGetMasterKey, METH_FASTCALL,
     PyHDWalletGetMasterKey_doc},
    {"get_key_for_coin", (PyCFunction)PyHDWalletGetKeyForCoin, METH_FASTCALL,
     PyHDWalletGetKeyForCoin_doc},
    {"get_address_for_coin", (PyCFunction)PyHDWalletGetAddressForCoin,
     METH_FASTCALL, PyHDWalletGetAddressForCoin_doc},
    {"get_key", (PyCFunction)PyHDWalletGetKey, METH_FASTCALL,
     PyHDWalletGetKey_doc},
    {"get_derived_key", (PyCFunction)PyHDWalletGetDerivedKey, METH_FASTCALL,
     PyHDWalletGetDerivedKey_doc},
    {"get_extended_private_key", (PyCFunction)PyHDWalletGetExtendedPrivateKey,
     METH_FASTCALL, PyHDWalletGetExtendedPrivateKey_doc},
    {"get_extended_public_key", (PyCFunction)PyHDWalletGetExtendedPublicKey,
     METH_FASTCALL, PyHDWalletGetExtendedPublicKey_doc},
    {"create", (PyCFunction)PyHDWalletCreate, METH_FASTCALL | METH_STATIC,
     PyHDWalletCreate_doc},
    {"create_with_mnemonic", (PyCFunction)PyHDWalletCreateWithMnemonic,
     METH_FASTCALL | METH_STATIC, PyHDWalletCreateWithMnemonic_doc},
    {"create_with_mnemonic_check",
     (PyCFunction)PyHDWalletCreateWithMnemonicCheck,
     METH_FASTCALL | METH_STATIC, PyHDWalletCreateWithMnemonicCheck_doc},
    {"create_with_entropy", (PyCFunction)PyHDWalletCreateWithEntropy,
     METH_FASTCALL | METH_STATIC, PyHDWalletCreateWithEntropy_doc},
    {"get_public_key_from_extended",
     (PyCFunction)PyHDWalletGetPublicKeyFromExtended,
     METH_FASTCALL | METH_STATIC, PyHDWalletGetPublicKeyFromExtended_doc},
    {}};

bool PyInit_HDWallet(PyObject* module) {
  PyHDWalletType.tp_dealloc = (destructor)PyHDWallet_dealloc;
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