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

#include "generated/CoinTypeConfiguration.h"

#include "String.h"
#include "generated/CoinType.h"

struct PyCoinTypeConfigurationObject {
  PyObject_HEAD;
};

static PyTypeObject PyCoinTypeConfigurationType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.CoinTypeConfiguration",    /* tp_name */
    sizeof(PyCoinTypeConfigurationObject), /* tp_basicsize */
    0,                                     /* tp_itemsize */
    0,                                     /* tp_dealloc */
    0,                                     /* tp_print */
    0,                                     /* tp_getattr */
    0,                                     /* tp_setattr */
    0,                                     /* tp_reserved */
    0,                                     /* tp_repr */
    0,                                     /* tp_as_number */
    0,                                     /* tp_as_sequence */
    0,                                     /* tp_as_mapping */
    0,                                     /* tp_hash  */
    0,                                     /* tp_call */
    0,                                     /* tp_str */
    0,                                     /* tp_getattro */
    0,                                     /* tp_setattro */
    0,                                     /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                    /* tp_flags */
    nullptr,                               /* tp_doc */
};

// static method function for GetSymbol
static const char PyCoinTypeConfigurationGetSymbol_doc[] =
    "TWString* TWCoinTypeConfigurationGetSymbol(enum TWCoinType type)";
static PyObject* PyCoinTypeConfigurationGetSymbol(
    PyCoinTypeConfigurationObject* self,
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

  TWStringPtr result(TWCoinTypeConfigurationGetSymbol(arg0));
  return PyUnicode_FromTWString(result);
}

// static method function for GetDecimals
static const char PyCoinTypeConfigurationGetDecimals_doc[] =
    "int32_t TWCoinTypeConfigurationGetDecimals(enum TWCoinType type)";
static PyObject* PyCoinTypeConfigurationGetDecimals(
    PyCoinTypeConfigurationObject* self,
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

  int32_t result = TWCoinTypeConfigurationGetDecimals(arg0);
  return PyLong_FromLong(result);
}

// static method function for GetTransactionURL
static const char PyCoinTypeConfigurationGetTransactionURL_doc[] =
    "TWString* TWCoinTypeConfigurationGetTransactionURL(enum TWCoinType type, "
    "TWString* transactionID)";
static PyObject* PyCoinTypeConfigurationGetTransactionURL(
    PyCoinTypeConfigurationObject* self,
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

  TWStringPtr result(
      TWCoinTypeConfigurationGetTransactionURL(arg0, arg1.get()));
  return PyUnicode_FromTWString(result);
}

// static method function for GetAccountURL
static const char PyCoinTypeConfigurationGetAccountURL_doc[] =
    "TWString* TWCoinTypeConfigurationGetAccountURL(enum TWCoinType type, "
    "TWString* accountID)";
static PyObject* PyCoinTypeConfigurationGetAccountURL(
    PyCoinTypeConfigurationObject* self,
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

  TWStringPtr result(TWCoinTypeConfigurationGetAccountURL(arg0, arg1.get()));
  return PyUnicode_FromTWString(result);
}

// static method function for GetID
static const char PyCoinTypeConfigurationGetID_doc[] =
    "TWString* TWCoinTypeConfigurationGetID(enum TWCoinType type)";
static PyObject* PyCoinTypeConfigurationGetID(
    PyCoinTypeConfigurationObject* self,
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

  TWStringPtr result(TWCoinTypeConfigurationGetID(arg0));
  return PyUnicode_FromTWString(result);
}

// static method function for GetName
static const char PyCoinTypeConfigurationGetName_doc[] =
    "TWString* TWCoinTypeConfigurationGetName(enum TWCoinType type)";
static PyObject* PyCoinTypeConfigurationGetName(
    PyCoinTypeConfigurationObject* self,
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

  TWStringPtr result(TWCoinTypeConfigurationGetName(arg0));
  return PyUnicode_FromTWString(result);
}

// properties

static const PyGetSetDef get_set_defs[] = {{}};

static const PyMethodDef method_defs[] = {
    {"get_symbol", (PyCFunction)PyCoinTypeConfigurationGetSymbol,
     METH_FASTCALL | METH_STATIC, PyCoinTypeConfigurationGetSymbol_doc},
    {"get_decimals", (PyCFunction)PyCoinTypeConfigurationGetDecimals,
     METH_FASTCALL | METH_STATIC, PyCoinTypeConfigurationGetDecimals_doc},
    {"get_transaction_url",
     (PyCFunction)PyCoinTypeConfigurationGetTransactionURL,
     METH_FASTCALL | METH_STATIC, PyCoinTypeConfigurationGetTransactionURL_doc},
    {"get_account_url", (PyCFunction)PyCoinTypeConfigurationGetAccountURL,
     METH_FASTCALL | METH_STATIC, PyCoinTypeConfigurationGetAccountURL_doc},
    {"get_id", (PyCFunction)PyCoinTypeConfigurationGetID,
     METH_FASTCALL | METH_STATIC, PyCoinTypeConfigurationGetID_doc},
    {"get_name", (PyCFunction)PyCoinTypeConfigurationGetName,
     METH_FASTCALL | METH_STATIC, PyCoinTypeConfigurationGetName_doc},
    {}};

bool PyInit_CoinTypeConfiguration(PyObject* module) {
  PyCoinTypeConfigurationType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyCoinTypeConfigurationType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyCoinTypeConfigurationType) < 0)
    return false;

  Py_INCREF(&PyCoinTypeConfigurationType);
  if (PyModule_AddObject(module, "CoinTypeConfiguration",
                         (PyObject*)&PyCoinTypeConfigurationType) < 0) {
    Py_DECREF(&PyCoinTypeConfigurationType);
    return false;
  }

  return true;
}