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

#include "generated/CoinType.h"

#include "String.h"
#include "generated/Blockchain.h"
#include "generated/Curve.h"
#include "generated/HDVersion.h"
#include "generated/HRP.h"
#include "generated/PrivateKey.h"
#include "generated/PublicKey.h"
#include "generated/Purpose.h"

#include <algorithm>
#include <iterator>

static PyTypeObject PyCoinTypeType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.CoinType",    /* tp_name */
    sizeof(PyCoinTypeObject), /* tp_basicsize */
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

bool PyCoinType_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyCoinTypeType) != 0;
}

struct Constant {
  const TWCoinType value;
  const char* name;
  PyObject* pyvalue;
};

static Constant constants[] = {
    // clang-format off
    { TWCoinTypeAeternity, "Aeternity", nullptr },
    { TWCoinTypeAion, "Aion", nullptr },
    { TWCoinTypeBinance, "Binance", nullptr },
    { TWCoinTypeBitcoin, "Bitcoin", nullptr },
    { TWCoinTypeBitcoinCash, "BitcoinCash", nullptr },
    { TWCoinTypeBitcoinGold, "BitcoinGold", nullptr },
    { TWCoinTypeCallisto, "Callisto", nullptr },
    { TWCoinTypeCardano, "Cardano", nullptr },
    { TWCoinTypeCosmos, "Cosmos", nullptr },
    { TWCoinTypeDash, "Dash", nullptr },
    { TWCoinTypeDecred, "Decred", nullptr },
    { TWCoinTypeDigiByte, "DigiByte", nullptr },
    { TWCoinTypeDogecoin, "Dogecoin", nullptr },
    { TWCoinTypeEOS, "EOS", nullptr },
    { TWCoinTypeEthereum, "Ethereum", nullptr },
    { TWCoinTypeEthereumClassic, "EthereumClassic", nullptr },
    { TWCoinTypeFIO, "FIO", nullptr },
    { TWCoinTypeGoChain, "GoChain", nullptr },
    { TWCoinTypeGroestlcoin, "Groestlcoin", nullptr },
    { TWCoinTypeICON, "ICON", nullptr },
    { TWCoinTypeIoTeX, "IoTeX", nullptr },
    { TWCoinTypeKava, "Kava", nullptr },
    { TWCoinTypeKin, "Kin", nullptr },
    { TWCoinTypeLitecoin, "Litecoin", nullptr },
    { TWCoinTypeMonacoin, "Monacoin", nullptr },
    { TWCoinTypeNebulas, "Nebulas", nullptr },
    { TWCoinTypeNULS, "NULS", nullptr },
    { TWCoinTypeNano, "Nano", nullptr },
    { TWCoinTypeNEAR, "NEAR", nullptr },
    { TWCoinTypeNimiq, "Nimiq", nullptr },
    { TWCoinTypeOntology, "Ontology", nullptr },
    { TWCoinTypePOANetwork, "POANetwork", nullptr },
    { TWCoinTypeQtum, "Qtum", nullptr },
    { TWCoinTypeXRP, "XRP", nullptr },
    { TWCoinTypeSolana, "Solana", nullptr },
    { TWCoinTypeStellar, "Stellar", nullptr },
    { TWCoinTypeTezos, "Tezos", nullptr },
    { TWCoinTypeTheta, "Theta", nullptr },
    { TWCoinTypeThunderToken, "ThunderToken", nullptr },
    { TWCoinTypeNEO, "NEO", nullptr },
    { TWCoinTypeTomoChain, "TomoChain", nullptr },
    { TWCoinTypeTron, "Tron", nullptr },
    { TWCoinTypeVeChain, "VeChain", nullptr },
    { TWCoinTypeViacoin, "Viacoin", nullptr },
    { TWCoinTypeWanchain, "Wanchain", nullptr },
    { TWCoinTypeZcash, "Zcash", nullptr },
    { TWCoinTypeZcoin, "Zcoin", nullptr },
    { TWCoinTypeZilliqa, "Zilliqa", nullptr },
    { TWCoinTypeZelcash, "Zelcash", nullptr },
    { TWCoinTypeRavencoin, "Ravencoin", nullptr },
    { TWCoinTypeWaves, "Waves", nullptr },
    { TWCoinTypeTerra, "Terra", nullptr },
    { TWCoinTypeHarmony, "Harmony", nullptr },
    { TWCoinTypeAlgorand, "Algorand", nullptr },
    { TWCoinTypeKusama, "Kusama", nullptr },
    { TWCoinTypePolkadot, "Polkadot", nullptr },
    { TWCoinTypeFilecoin, "Filecoin", nullptr },
    { TWCoinTypeElrond, "Elrond", nullptr },
    { TWCoinTypeBandChain, "BandChain", nullptr },
    { TWCoinTypeSmartChainLegacy, "SmartChainLegacy", nullptr },
    { TWCoinTypeSmartChain, "SmartChain", nullptr },
    { TWCoinTypeOasis, "Oasis", nullptr },
    { TWCoinTypePolygon, "Polygon", nullptr },
    { TWCoinTypeTHORChain, "THORChain", nullptr },
    { TWCoinTypeBluzelle, "Bluzelle", nullptr },
    { TWCoinTypeOptimism, "Optimism", nullptr },
    { TWCoinTypeArbitrum, "Arbitrum", nullptr },
    { TWCoinTypeECOChain, "ECOChain", nullptr },
    { TWCoinTypeAvalancheCChain, "AvalancheCChain", nullptr },
    { TWCoinTypeXDai, "XDai", nullptr },
    { TWCoinTypeFantom, "Fantom", nullptr },
    { TWCoinTypeCryptoOrg, "CryptoOrg", nullptr },
    { TWCoinTypeCelo, "Celo", nullptr },
    { TWCoinTypeRonin, "Ronin", nullptr },
    { TWCoinTypeOsmosis, "Osmosis", nullptr },
    // clang-format on
};

// Create PyCoinType from enum TWCoinType. It returns the same PyCoinType
// instance for the same enum TWCoinType value.
PyObject* PyCoinType_FromTWCoinType(TWCoinType value) {
  Constant* constant =
      std::find_if(std::begin(constants), std::end(constants),
                   [value](const Constant& v) { return v.value == value; });

  if (!constant) {
    PyErr_Format(PyExc_ValueError, "Invalid CoinType value: %d", value);
    return nullptr;
  }

  if (!constant->pyvalue) {
    auto* pyvalue = PyObject_New(PyCoinTypeObject, &PyCoinTypeType);
    *const_cast<TWCoinType*>(&pyvalue->value) = value;
    constant->pyvalue = (PyObject*)pyvalue;
  }

  Py_INCREF(constant->pyvalue);
  return constant->pyvalue;
}

TWCoinType PyCoinType_GetTWCoinType(PyObject* object) {
  assert(PyCoinType_Check(object));
  return ((PyCoinTypeObject*)object)->value;
}

static int PyCoinType_init(PyCoinTypeObject* self,
                           PyObject* args,
                           PyObject* kwds) {
  return 0;
}

static PyObject* PyCoinType_new(PyTypeObject* subtype,
                                PyObject* args,
                                PyObject* kwds) {
  int value = 0;
  if (!PyArg_ParseTuple(args, "|i", &value)) {
    return nullptr;
  }
  return PyCoinType_FromTWCoinType((TWCoinType)value);
}

static PyObject* PyCoinType_str(PyCoinTypeObject* self) {
  Constant* constant = std::find_if(
      std::begin(constants), std::end(constants),
      [self](const Constant& v) { return v.value == self->value; });

  return PyUnicode_FromString(constant ? constant->name : "Unknown");
}

// getter function for Blockchain
static const char PyCoinTypeBlockchain_doc[] =
    "enum TWBlockchain TWCoinTypeBlockchain(enum TWCoinType coin)";
static PyObject* PyCoinTypeBlockchain(PyCoinTypeObject* self, void*) {
  TWBlockchain prop = TWCoinTypeBlockchain(self->value);
  return PyBlockchain_FromTWBlockchain(prop);
}

// getter function for Purpose
static const char PyCoinTypePurpose_doc[] =
    "enum TWPurpose TWCoinTypePurpose(enum TWCoinType coin)";
static PyObject* PyCoinTypePurpose(PyCoinTypeObject* self, void*) {
  TWPurpose prop = TWCoinTypePurpose(self->value);
  return PyPurpose_FromTWPurpose(prop);
}

// getter function for Curve
static const char PyCoinTypeCurve_doc[] =
    "enum TWCurve TWCoinTypeCurve(enum TWCoinType coin)";
static PyObject* PyCoinTypeCurve(PyCoinTypeObject* self, void*) {
  TWCurve prop = TWCoinTypeCurve(self->value);
  return PyCurve_FromTWCurve(prop);
}

// getter function for XpubVersion
static const char PyCoinTypeXpubVersion_doc[] =
    "enum TWHDVersion TWCoinTypeXpubVersion(enum TWCoinType coin)";
static PyObject* PyCoinTypeXpubVersion(PyCoinTypeObject* self, void*) {
  TWHDVersion prop = TWCoinTypeXpubVersion(self->value);
  return PyHDVersion_FromTWHDVersion(prop);
}

// getter function for XprvVersion
static const char PyCoinTypeXprvVersion_doc[] =
    "enum TWHDVersion TWCoinTypeXprvVersion(enum TWCoinType coin)";
static PyObject* PyCoinTypeXprvVersion(PyCoinTypeObject* self, void*) {
  TWHDVersion prop = TWCoinTypeXprvVersion(self->value);
  return PyHDVersion_FromTWHDVersion(prop);
}

// getter function for HRP
static const char PyCoinTypeHRP_doc[] =
    "enum TWHRP TWCoinTypeHRP(enum TWCoinType coin)";
static PyObject* PyCoinTypeHRP(PyCoinTypeObject* self, void*) {
  TWHRP prop = TWCoinTypeHRP(self->value);
  return PyHRP_FromTWHRP(prop);
}

// getter function for P2pkhPrefix
static const char PyCoinTypeP2pkhPrefix_doc[] =
    "uint8_t TWCoinTypeP2pkhPrefix(enum TWCoinType coin)";
static PyObject* PyCoinTypeP2pkhPrefix(PyCoinTypeObject* self, void*) {
  uint8_t prop = TWCoinTypeP2pkhPrefix(self->value);
  return PyLong_FromLong(prop);
}

// getter function for P2shPrefix
static const char PyCoinTypeP2shPrefix_doc[] =
    "uint8_t TWCoinTypeP2shPrefix(enum TWCoinType coin)";
static PyObject* PyCoinTypeP2shPrefix(PyCoinTypeObject* self, void*) {
  uint8_t prop = TWCoinTypeP2shPrefix(self->value);
  return PyLong_FromLong(prop);
}

// getter function for StaticPrefix
static const char PyCoinTypeStaticPrefix_doc[] =
    "uint8_t TWCoinTypeStaticPrefix(enum TWCoinType coin)";
static PyObject* PyCoinTypeStaticPrefix(PyCoinTypeObject* self, void*) {
  uint8_t prop = TWCoinTypeStaticPrefix(self->value);
  return PyLong_FromLong(prop);
}

// getter function for Slip44Id
static const char PyCoinTypeSlip44Id_doc[] =
    "uint32_t TWCoinTypeSlip44Id(enum TWCoinType coin)";
static PyObject* PyCoinTypeSlip44Id(PyCoinTypeObject* self, void*) {
  uint32_t prop = TWCoinTypeSlip44Id(self->value);
  return PyLong_FromLong(prop);
}

// method function for Validate
static const char PyCoinTypeValidate_doc[] =
    "bool TWCoinTypeValidate(enum TWCoinType coin, TWString* address)";
static PyObject* PyCoinTypeValidate(PyCoinTypeObject* self,
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

  bool result = TWCoinTypeValidate(self->value, arg0.get());
  return PyBool_FromLong(result);
}

// method function for DerivationPath
static const char PyCoinTypeDerivationPath_doc[] =
    "TWString* TWCoinTypeDerivationPath(enum TWCoinType coin)";
static PyObject* PyCoinTypeDerivationPath(PyCoinTypeObject* self,
                                          PyObject* const* args,
                                          Py_ssize_t nargs) {
  if (nargs != 0) {
    PyErr_Format(PyExc_TypeError, "Expect 0 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  TWStringPtr result(TWCoinTypeDerivationPath(self->value));
  return PyUnicode_FromTWString(result);
}

// method function for DeriveAddress
static const char PyCoinTypeDeriveAddress_doc[] =
    "TWString* TWCoinTypeDeriveAddress(enum TWCoinType coin, struct "
    "TWPrivateKey* privateKey)";
static PyObject* PyCoinTypeDeriveAddress(PyCoinTypeObject* self,
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

  TWStringPtr result(TWCoinTypeDeriveAddress(self->value, arg0));
  return PyUnicode_FromTWString(result);
}

// method function for DeriveAddressFromPublicKey
static const char PyCoinTypeDeriveAddressFromPublicKey_doc[] =
    "TWString* TWCoinTypeDeriveAddressFromPublicKey(enum TWCoinType coin, "
    "struct TWPublicKey* publicKey)";
static PyObject* PyCoinTypeDeriveAddressFromPublicKey(PyCoinTypeObject* self,
                                                      PyObject* const* args,
                                                      Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  if (!PyPublicKey_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type PublicKey");
    return nullptr;
  }
  auto arg0 = PyPublicKey_GetTWPublicKey(args[0]);

  TWStringPtr result(TWCoinTypeDeriveAddressFromPublicKey(self->value, arg0));
  return PyUnicode_FromTWString(result);
}

// properties

static const PyGetSetDef get_set_defs[] = {
    {"blockchain", (getter)PyCoinTypeBlockchain, nullptr,
     PyCoinTypeBlockchain_doc},
    {"purpose", (getter)PyCoinTypePurpose, nullptr, PyCoinTypePurpose_doc},
    {"curve", (getter)PyCoinTypeCurve, nullptr, PyCoinTypeCurve_doc},
    {"xpub_version", (getter)PyCoinTypeXpubVersion, nullptr,
     PyCoinTypeXpubVersion_doc},
    {"xprv_version", (getter)PyCoinTypeXprvVersion, nullptr,
     PyCoinTypeXprvVersion_doc},
    {"hrp", (getter)PyCoinTypeHRP, nullptr, PyCoinTypeHRP_doc},
    {"p2pkh_prefix", (getter)PyCoinTypeP2pkhPrefix, nullptr,
     PyCoinTypeP2pkhPrefix_doc},
    {"p2sh_prefix", (getter)PyCoinTypeP2shPrefix, nullptr,
     PyCoinTypeP2shPrefix_doc},
    {"static_prefix", (getter)PyCoinTypeStaticPrefix, nullptr,
     PyCoinTypeStaticPrefix_doc},
    {"slip44_id", (getter)PyCoinTypeSlip44Id, nullptr, PyCoinTypeSlip44Id_doc},
    {}};

static const PyMethodDef method_defs[] = {
    {"validate", (PyCFunction)PyCoinTypeValidate, METH_FASTCALL,
     PyCoinTypeValidate_doc},
    {"derivation_path", (PyCFunction)PyCoinTypeDerivationPath, METH_FASTCALL,
     PyCoinTypeDerivationPath_doc},
    {"derive_address", (PyCFunction)PyCoinTypeDeriveAddress, METH_FASTCALL,
     PyCoinTypeDeriveAddress_doc},
    {"derive_address_from_public_key",
     (PyCFunction)PyCoinTypeDeriveAddressFromPublicKey, METH_FASTCALL,
     PyCoinTypeDeriveAddressFromPublicKey_doc},
    {}};

bool PyInit_CoinType(PyObject* module) {
  PyCoinTypeType.tp_new = PyCoinType_new;
  PyCoinTypeType.tp_init = (initproc)PyCoinType_init;
  PyCoinTypeType.tp_str = (reprfunc)PyCoinType_str;
  PyCoinTypeType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyCoinTypeType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyCoinTypeType) < 0)
    return false;

  Py_INCREF(&PyCoinTypeType);
  if (PyModule_AddObject(module, "CoinType", (PyObject*)&PyCoinTypeType) < 0) {
    Py_DECREF(&PyCoinTypeType);
    return false;
  }

  PyObject* dict = PyCoinTypeType.tp_dict;
  (void)dict;

  for (const Constant& constant : constants) {
    PyDict_SetItemString(dict, constant.name,
                         PyCoinType_FromTWCoinType(constant.value));
  }

  return true;
}