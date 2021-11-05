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

#include "generated/HRP.h"

#include <algorithm>
#include <iterator>

static PyTypeObject PyHRPType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.HRP",    /* tp_name */
    sizeof(PyHRPObject), /* tp_basicsize */
    0,                   /* tp_itemsize */
    0,                   /* tp_dealloc */
    0,                   /* tp_print */
    0,                   /* tp_getattr */
    0,                   /* tp_setattr */
    0,                   /* tp_reserved */
    0,                   /* tp_repr */
    0,                   /* tp_as_number */
    0,                   /* tp_as_sequence */
    0,                   /* tp_as_mapping */
    0,                   /* tp_hash  */
    0,                   /* tp_call */
    0,                   /* tp_str */
    0,                   /* tp_getattro */
    0,                   /* tp_setattro */
    0,                   /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,  /* tp_flags */
    nullptr,             /* tp_doc */
};

bool PyHRP_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyHRPType) != 0;
}

struct Constant {
  const TWHRP value;
  const char* name;
  PyObject* pyvalue;
};

static Constant constants[] = {
    // clang-format off
    { TWHRPUnknown, "Unknown", nullptr },
    { TWHRPBitcoin, "Bitcoin", nullptr },
    { TWHRPLitecoin, "Litecoin", nullptr },
    { TWHRPViacoin, "Viacoin", nullptr },
    { TWHRPGroestlcoin, "Groestlcoin", nullptr },
    { TWHRPDigiByte, "DigiByte", nullptr },
    { TWHRPMonacoin, "Monacoin", nullptr },
    { TWHRPCosmos, "Cosmos", nullptr },
    { TWHRPBitcoinCash, "BitcoinCash", nullptr },
    { TWHRPBitcoinGold, "BitcoinGold", nullptr },
    { TWHRPIoTeX, "IoTeX", nullptr },
    { TWHRPZilliqa, "Zilliqa", nullptr },
    { TWHRPTerra, "Terra", nullptr },
    { TWHRPCryptoOrg, "CryptoOrg", nullptr },
    { TWHRPKava, "Kava", nullptr },
    { TWHRPOasis, "Oasis", nullptr },
    { TWHRPBluzelle, "Bluzelle", nullptr },
    { TWHRPBandChain, "BandChain", nullptr },
    { TWHRPElrond, "Elrond", nullptr },
    { TWHRPBinance, "Binance", nullptr },
    { TWHRPTHORChain, "THORChain", nullptr },
    { TWHRPHarmony, "Harmony", nullptr },
    { TWHRPCardano, "Cardano", nullptr },
    { TWHRPQtum, "Qtum", nullptr },
    // clang-format on
};

// Create PyHRP from enum TWHRP. It returns the same PyHRP instance
// for the same enum TWHRP value.
PyObject* PyHRP_FromTWHRP(TWHRP value) {
  Constant* constant =
      std::find_if(std::begin(constants), std::end(constants),
                   [value](const Constant& v) { return v.value == value; });

  if (!constant) {
    PyErr_Format(PyExc_ValueError, "Invalid HRP value: %d", value);
    return nullptr;
  }

  if (!constant->pyvalue) {
    auto* pyvalue = PyObject_New(PyHRPObject, &PyHRPType);
    *const_cast<TWHRP*>(&pyvalue->value) = value;
    constant->pyvalue = (PyObject*)pyvalue;
  }

  Py_INCREF(constant->pyvalue);
  return constant->pyvalue;
}

TWHRP PyHRP_GetTWHRP(PyObject* object) {
  assert(PyHRP_Check(object));
  return ((PyHRPObject*)object)->value;
}

static int PyHRP_init(PyHRPObject* self, PyObject* args, PyObject* kwds) {
  return 0;
}

static PyObject* PyHRP_new(PyTypeObject* subtype,
                           PyObject* args,
                           PyObject* kwds) {
  int value = 0;
  if (!PyArg_ParseTuple(args, "|i", &value)) {
    return nullptr;
  }
  return PyHRP_FromTWHRP((TWHRP)value);
}

static PyObject* PyHRP_str(PyHRPObject* self) {
  Constant* constant = std::find_if(
      std::begin(constants), std::end(constants),
      [self](const Constant& v) { return v.value == self->value; });

  return PyUnicode_FromString(constant ? constant->name : "Unknown");
}

// properties

static const PyGetSetDef get_set_defs[] = {{}};

static const PyMethodDef method_defs[] = {{}};

bool PyInit_HRP(PyObject* module) {
  PyHRPType.tp_new = PyHRP_new;
  PyHRPType.tp_init = (initproc)PyHRP_init;
  PyHRPType.tp_str = (reprfunc)PyHRP_str;
  PyHRPType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyHRPType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyHRPType) < 0)
    return false;

  Py_INCREF(&PyHRPType);
  if (PyModule_AddObject(module, "HRP", (PyObject*)&PyHRPType) < 0) {
    Py_DECREF(&PyHRPType);
    return false;
  }

  PyObject* dict = PyHRPType.tp_dict;
  (void)dict;

  for (const Constant& constant : constants) {
    PyDict_SetItemString(dict, constant.name, PyHRP_FromTWHRP(constant.value));
  }

  return true;
}