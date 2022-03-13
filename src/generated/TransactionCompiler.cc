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

#include "generated/TransactionCompiler.h"

#include "Data.h"
#include "String.h"
#include "generated/CoinType.h"
#include "generated/DataVector.h"

struct PyTransactionCompilerObject {
  PyObject_HEAD;
};

static PyTypeObject PyTransactionCompilerType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.TransactionCompiler",    /* tp_name */
    sizeof(PyTransactionCompilerObject), /* tp_basicsize */
    0,                                   /* tp_itemsize */
    0,                                   /* tp_dealloc */
    0,                                   /* tp_print */
    0,                                   /* tp_getattr */
    0,                                   /* tp_setattr */
    0,                                   /* tp_reserved */
    0,                                   /* tp_repr */
    0,                                   /* tp_as_number */
    0,                                   /* tp_as_sequence */
    0,                                   /* tp_as_mapping */
    0,                                   /* tp_hash  */
    0,                                   /* tp_call */
    0,                                   /* tp_str */
    0,                                   /* tp_getattro */
    0,                                   /* tp_setattro */
    0,                                   /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                  /* tp_flags */
    nullptr,                             /* tp_doc */
};

// static method function for BuildInput
static const char PyTransactionCompilerBuildInput_doc[] =
    "TWData* TWTransactionCompilerBuildInput(enum TWCoinType coinType, "
    "TWString* from, TWString* to, TWString* amount, TWString* asset, "
    "TWString* memo, TWString* chainId)";
static PyObject* PyTransactionCompilerBuildInput(
    PyTransactionCompilerObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 7) {
    PyErr_Format(PyExc_TypeError, "Expect 7 args, but %d args are passed in.",
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

  if (!PyUnicode_Check(args[4])) {
    PyErr_SetString(PyExc_TypeError, "The arg 4 is not in type Unicode");
    return nullptr;
  }
  auto arg4 = PyUnicode_GetTWString(args[4]);

  if (!PyUnicode_Check(args[5])) {
    PyErr_SetString(PyExc_TypeError, "The arg 5 is not in type Unicode");
    return nullptr;
  }
  auto arg5 = PyUnicode_GetTWString(args[5]);

  if (!PyUnicode_Check(args[6])) {
    PyErr_SetString(PyExc_TypeError, "The arg 6 is not in type Unicode");
    return nullptr;
  }
  auto arg6 = PyUnicode_GetTWString(args[6]);

  TWDataPtr result(TWTransactionCompilerBuildInput(arg0, arg1.get(), arg2.get(),
                                                   arg3.get(), arg4.get(),
                                                   arg5.get(), arg6.get()));
  return PyBytes_FromTWData(result);
}

// static method function for PreImageHashes
static const char PyTransactionCompilerPreImageHashes_doc[] =
    "struct TWDataVector* TWTransactionCompilerPreImageHashes(enum TWCoinType "
    "coinType, TWData* txInputData)";
static PyObject* PyTransactionCompilerPreImageHashes(
    PyTransactionCompilerObject* self,
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

  TWDataVector* result = TWTransactionCompilerPreImageHashes(arg0, arg1.get());
  return PyDataVector_FromTWDataVector(result);
}

// static method function for CompileWithSignatures
static const char PyTransactionCompilerCompileWithSignatures_doc[] =
    "TWData* TWTransactionCompilerCompileWithSignatures(enum TWCoinType "
    "coinType, TWData* txInputData, const struct TWDataVector* signatures, "
    "const struct TWDataVector* publicKeys)";
static PyObject* PyTransactionCompilerCompileWithSignatures(
    PyTransactionCompilerObject* self,
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

  if (!PyBytes_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bytes");
    return nullptr;
  }
  auto arg1 = PyBytes_GetTWData(args[1]);

  if (!PyDataVector_Check(args[2])) {
    PyErr_SetString(PyExc_TypeError, "The arg 2 is not in type DataVector");
    return nullptr;
  }
  auto arg2 = PyDataVector_GetTWDataVector(args[2]);

  if (!PyDataVector_Check(args[3])) {
    PyErr_SetString(PyExc_TypeError, "The arg 3 is not in type DataVector");
    return nullptr;
  }
  auto arg3 = PyDataVector_GetTWDataVector(args[3]);

  TWDataPtr result(
      TWTransactionCompilerCompileWithSignatures(arg0, arg1.get(), arg2, arg3));
  return PyBytes_FromTWData(result);
}

// properties

static const PyGetSetDef get_set_defs[] = {{}};

static const PyMethodDef method_defs[] = {
    {"build_input", (PyCFunction)PyTransactionCompilerBuildInput,
     METH_FASTCALL | METH_STATIC, PyTransactionCompilerBuildInput_doc},
    {"pre_image_hashes", (PyCFunction)PyTransactionCompilerPreImageHashes,
     METH_FASTCALL | METH_STATIC, PyTransactionCompilerPreImageHashes_doc},
    {"compile_with_signatures",
     (PyCFunction)PyTransactionCompilerCompileWithSignatures,
     METH_FASTCALL | METH_STATIC,
     PyTransactionCompilerCompileWithSignatures_doc},
    {}};

bool PyInit_TransactionCompiler(PyObject* module) {
  PyTransactionCompilerType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyTransactionCompilerType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyTransactionCompilerType) < 0)
    return false;

  Py_INCREF(&PyTransactionCompilerType);
  if (PyModule_AddObject(module, "TransactionCompiler",
                         (PyObject*)&PyTransactionCompilerType) < 0) {
    Py_DECREF(&PyTransactionCompilerType);
    return false;
  }

  return true;
}