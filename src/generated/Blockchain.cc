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

#include "generated/Blockchain.h"

#include <algorithm>
#include <iterator>

static PyTypeObject PyBlockchainType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.Blockchain",    /* tp_name */
    sizeof(PyBlockchainObject), /* tp_basicsize */
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

bool PyBlockchain_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyBlockchainType) != 0;
}

struct Constant {
  const TWBlockchain value;
  const char* name;
  PyObject* pyvalue;
};

static Constant constants[] = {
    // clang-format off
    { TWBlockchainBitcoin, "Bitcoin", nullptr },
    { TWBlockchainEthereum, "Ethereum", nullptr },
    { TWBlockchainVechain, "Vechain", nullptr },
    { TWBlockchainTron, "Tron", nullptr },
    { TWBlockchainIcon, "Icon", nullptr },
    { TWBlockchainBinance, "Binance", nullptr },
    { TWBlockchainRipple, "Ripple", nullptr },
    { TWBlockchainTezos, "Tezos", nullptr },
    { TWBlockchainNimiq, "Nimiq", nullptr },
    { TWBlockchainStellar, "Stellar", nullptr },
    { TWBlockchainAion, "Aion", nullptr },
    { TWBlockchainCosmos, "Cosmos", nullptr },
    { TWBlockchainTheta, "Theta", nullptr },
    { TWBlockchainOntology, "Ontology", nullptr },
    { TWBlockchainZilliqa, "Zilliqa", nullptr },
    { TWBlockchainIoTeX, "IoTeX", nullptr },
    { TWBlockchainEOS, "EOS", nullptr },
    { TWBlockchainNano, "Nano", nullptr },
    { TWBlockchainNULS, "NULS", nullptr },
    { TWBlockchainWaves, "Waves", nullptr },
    { TWBlockchainAeternity, "Aeternity", nullptr },
    { TWBlockchainNebulas, "Nebulas", nullptr },
    { TWBlockchainFIO, "FIO", nullptr },
    { TWBlockchainSolana, "Solana", nullptr },
    { TWBlockchainHarmony, "Harmony", nullptr },
    { TWBlockchainNEAR, "NEAR", nullptr },
    { TWBlockchainAlgorand, "Algorand", nullptr },
    { TWBlockchainPolkadot, "Polkadot", nullptr },
    { TWBlockchainCardano, "Cardano", nullptr },
    { TWBlockchainNEO, "NEO", nullptr },
    { TWBlockchainFilecoin, "Filecoin", nullptr },
    { TWBlockchainElrondNetwork, "ElrondNetwork", nullptr },
    { TWBlockchainOasisNetwork, "OasisNetwork", nullptr },
    // clang-format on
};

// Create PyBlockchain from enum TWBlockchain. It returns the same PyBlockchain
// instance for the same enum TWBlockchain value.
PyObject* PyBlockchain_FromTWBlockchain(TWBlockchain value) {
  Constant* constant =
      std::find_if(std::begin(constants), std::end(constants),
                   [value](const Constant& v) { return v.value == value; });

  if (!constant) {
    PyErr_Format(PyExc_ValueError, "Invalid Blockchain value: %d", value);
    return nullptr;
  }

  if (!constant->pyvalue) {
    auto* pyvalue = PyObject_New(PyBlockchainObject, &PyBlockchainType);
    *const_cast<TWBlockchain*>(&pyvalue->value) = value;
    constant->pyvalue = (PyObject*)pyvalue;
  }

  Py_INCREF(constant->pyvalue);
  return constant->pyvalue;
}

TWBlockchain PyBlockchain_GetTWBlockchain(PyObject* object) {
  assert(PyBlockchain_Check(object));
  return ((PyBlockchainObject*)object)->value;
}

static int PyBlockchain_init(PyBlockchainObject* self,
                             PyObject* args,
                             PyObject* kwds) {
  return 0;
}

static PyObject* PyBlockchain_new(PyTypeObject* subtype,
                                  PyObject* args,
                                  PyObject* kwds) {
  int value = 0;
  if (!PyArg_ParseTuple(args, "|i", &value)) {
    return nullptr;
  }
  return PyBlockchain_FromTWBlockchain((TWBlockchain)value);
}

static PyObject* PyBlockchain_str(PyBlockchainObject* self) {
  Constant* constant = std::find_if(
      std::begin(constants), std::end(constants),
      [self](const Constant& v) { return v.value == self->value; });

  return PyUnicode_FromString(constant ? constant->name : "Unknown");
}

// properties

static const PyGetSetDef get_set_defs[] = {{}};

static const PyMethodDef method_defs[] = {{}};

bool PyInit_Blockchain(PyObject* module) {
  PyBlockchainType.tp_new = PyBlockchain_new;
  PyBlockchainType.tp_init = (initproc)PyBlockchain_init;
  PyBlockchainType.tp_str = (reprfunc)PyBlockchain_str;
  PyBlockchainType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyBlockchainType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyBlockchainType) < 0)
    return false;

  Py_INCREF(&PyBlockchainType);
  if (PyModule_AddObject(module, "Blockchain", (PyObject*)&PyBlockchainType) <
      0) {
    Py_DECREF(&PyBlockchainType);
    return false;
  }

  PyObject* dict = PyBlockchainType.tp_dict;
  (void)dict;

  for (const Constant& constant : constants) {
    PyDict_SetItemString(dict, constant.name,
                         PyBlockchain_FromTWBlockchain(constant.value));
  }

  return true;
}