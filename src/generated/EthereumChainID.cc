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

#include "generated/EthereumChainID.h"

#include <algorithm>
#include <iterator>

static PyTypeObject PyEthereumChainIDType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.EthereumChainID",    /* tp_name */
    sizeof(PyEthereumChainIDObject), /* tp_basicsize */
    0,                               /* tp_itemsize */
    0,                               /* tp_dealloc */
    0,                               /* tp_print */
    0,                               /* tp_getattr */
    0,                               /* tp_setattr */
    0,                               /* tp_reserved */
    0,                               /* tp_repr */
    0,                               /* tp_as_number */
    0,                               /* tp_as_sequence */
    0,                               /* tp_as_mapping */
    0,                               /* tp_hash  */
    0,                               /* tp_call */
    0,                               /* tp_str */
    0,                               /* tp_getattro */
    0,                               /* tp_setattro */
    0,                               /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,              /* tp_flags */
    nullptr,                         /* tp_doc */
};

bool PyEthereumChainID_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyEthereumChainIDType) != 0;
}

struct Constant {
  const TWEthereumChainID value;
  const char* name;
  PyObject* pyvalue;
};

static Constant constants[] = {
    // clang-format off
    { TWEthereumChainIDEthereum, "Ethereum", nullptr },
    { TWEthereumChainIDGo, "Go", nullptr },
    { TWEthereumChainIDPOA, "POA", nullptr },
    { TWEthereumChainIDCallisto, "Callisto", nullptr },
    { TWEthereumChainIDEthereumClassic, "EthereumClassic", nullptr },
    { TWEthereumChainIDVeChain, "VeChain", nullptr },
    { TWEthereumChainIDThunderToken, "ThunderToken", nullptr },
    { TWEthereumChainIDTomoChain, "TomoChain", nullptr },
    { TWEthereumChainIDBinanceSmartChain, "BinanceSmartChain", nullptr },
    { TWEthereumChainIDPolygon, "Polygon", nullptr },
    { TWEthereumChainIDWanchain, "Wanchain", nullptr },
    { TWEthereumChainIDOptimism, "Optimism", nullptr },
    { TWEthereumChainIDArbitrum, "Arbitrum", nullptr },
    { TWEthereumChainIDHeco, "Heco", nullptr },
    { TWEthereumChainIDAvalanche, "Avalanche", nullptr },
    { TWEthereumChainIDXDai, "XDai", nullptr },
    { TWEthereumChainIDFantom, "Fantom", nullptr },
    { TWEthereumChainIDCelo, "Celo", nullptr },
    { TWEthereumChainIDRonin, "Ronin", nullptr },
    // clang-format on
};

// Create PyEthereumChainID from enum TWEthereumChainID. It returns the same
// PyEthereumChainID instance for the same enum TWEthereumChainID value.
PyObject* PyEthereumChainID_FromTWEthereumChainID(TWEthereumChainID value) {
  Constant* constant =
      std::find_if(std::begin(constants), std::end(constants),
                   [value](const Constant& v) { return v.value == value; });

  if (!constant) {
    PyErr_Format(PyExc_ValueError, "Invalid EthereumChainID value: %d", value);
    return nullptr;
  }

  if (!constant->pyvalue) {
    auto* pyvalue =
        PyObject_New(PyEthereumChainIDObject, &PyEthereumChainIDType);
    *const_cast<TWEthereumChainID*>(&pyvalue->value) = value;
    constant->pyvalue = (PyObject*)pyvalue;
  }

  Py_INCREF(constant->pyvalue);
  return constant->pyvalue;
}

TWEthereumChainID PyEthereumChainID_GetTWEthereumChainID(PyObject* object) {
  assert(PyEthereumChainID_Check(object));
  return ((PyEthereumChainIDObject*)object)->value;
}

static int PyEthereumChainID_init(PyEthereumChainIDObject* self,
                                  PyObject* args,
                                  PyObject* kwds) {
  return 0;
}

static PyObject* PyEthereumChainID_new(PyTypeObject* subtype,
                                       PyObject* args,
                                       PyObject* kwds) {
  int value = 0;
  if (!PyArg_ParseTuple(args, "|i", &value)) {
    return nullptr;
  }
  return PyEthereumChainID_FromTWEthereumChainID((TWEthereumChainID)value);
}

static PyObject* PyEthereumChainID_str(PyEthereumChainIDObject* self) {
  Constant* constant = std::find_if(
      std::begin(constants), std::end(constants),
      [self](const Constant& v) { return v.value == self->value; });

  return PyUnicode_FromString(constant ? constant->name : "Unknown");
}

// properties

static const PyGetSetDef get_set_defs[] = {{}};

static const PyMethodDef method_defs[] = {{}};

bool PyInit_EthereumChainID(PyObject* module) {
  PyEthereumChainIDType.tp_new = PyEthereumChainID_new;
  PyEthereumChainIDType.tp_init = (initproc)PyEthereumChainID_init;
  PyEthereumChainIDType.tp_str = (reprfunc)PyEthereumChainID_str;
  PyEthereumChainIDType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyEthereumChainIDType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyEthereumChainIDType) < 0)
    return false;

  Py_INCREF(&PyEthereumChainIDType);
  if (PyModule_AddObject(module, "EthereumChainID",
                         (PyObject*)&PyEthereumChainIDType) < 0) {
    Py_DECREF(&PyEthereumChainIDType);
    return false;
  }

  PyObject* dict = PyEthereumChainIDType.tp_dict;
  (void)dict;

  for (const Constant& constant : constants) {
    PyDict_SetItemString(
        dict, constant.name,
        PyEthereumChainID_FromTWEthereumChainID(constant.value));
  }

  return true;
}