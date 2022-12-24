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

#include "generated/DerivationPath.h"

#include "Number.h"
#include "String.h"
#include "generated/DerivationPathIndex.h"
#include "generated/Purpose.h"

struct PyDerivationPathObject {
  PyObject_HEAD;
  TWDerivationPath* value;
};

static PyTypeObject PyDerivationPathType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.DerivationPath",    /* tp_name */
    sizeof(PyDerivationPathObject), /* tp_basicsize */
    0,                              /* tp_itemsize */
    0,                              /* tp_dealloc */
    0,                              /* tp_print */
    0,                              /* tp_getattr */
    0,                              /* tp_setattr */
    0,                              /* tp_reserved */
    0,                              /* tp_repr */
    0,                              /* tp_as_number */
    0,                              /* tp_as_sequence */
    0,                              /* tp_as_mapping */
    0,                              /* tp_hash  */
    0,                              /* tp_call */
    0,                              /* tp_str */
    0,                              /* tp_getattro */
    0,                              /* tp_setattro */
    0,                              /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,             /* tp_flags */
    nullptr,                        /* tp_doc */
};

bool PyDerivationPath_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyDerivationPathType) != 0;
}

// Create PyDerivationPath from enum TWDerivationPath.
PyObject* PyDerivationPath_FromTWDerivationPath(TWDerivationPath* value) {
  if (!value)
    Py_RETURN_NONE;

  PyDerivationPathObject* object =
      PyObject_New(PyDerivationPathObject, &PyDerivationPathType);
  if (!object)
    return nullptr;

  object->value = value;

  return (PyObject*)object;
}

TWDerivationPath* PyDerivationPath_GetTWDerivationPath(PyObject* object) {
  assert(PyDerivationPath_Check(object));
  return ((PyDerivationPathObject*)object)->value;
}

static void PyDerivationPath_dealloc(PyDerivationPathObject* self) {
  if (self->value) {
    TWDerivationPathDelete(self->value);
  }
  Py_TYPE(self)->tp_free(self);
}

// getter function for Purpose
static const char PyDerivationPathPurpose_doc[] =
    "enum TWPurpose TWDerivationPathPurpose(struct TWDerivationPath* path)";
static PyObject* PyDerivationPathPurpose(PyDerivationPathObject* self, void*) {
  TWPurpose prop = TWDerivationPathPurpose(self->value);
  return PyPurpose_FromTWPurpose(prop);
}

// getter function for Coin
static const char PyDerivationPathCoin_doc[] =
    "uint32_t TWDerivationPathCoin(struct TWDerivationPath* path)";
static PyObject* PyDerivationPathCoin(PyDerivationPathObject* self, void*) {
  uint32_t prop = TWDerivationPathCoin(self->value);
  return PyLong_FromLong(prop);
}

// getter function for Account
static const char PyDerivationPathAccount_doc[] =
    "uint32_t TWDerivationPathAccount(struct TWDerivationPath* path)";
static PyObject* PyDerivationPathAccount(PyDerivationPathObject* self, void*) {
  uint32_t prop = TWDerivationPathAccount(self->value);
  return PyLong_FromLong(prop);
}

// getter function for Change
static const char PyDerivationPathChange_doc[] =
    "uint32_t TWDerivationPathChange(struct TWDerivationPath* path)";
static PyObject* PyDerivationPathChange(PyDerivationPathObject* self, void*) {
  uint32_t prop = TWDerivationPathChange(self->value);
  return PyLong_FromLong(prop);
}

// getter function for Address
static const char PyDerivationPathAddress_doc[] =
    "uint32_t TWDerivationPathAddress(struct TWDerivationPath* path)";
static PyObject* PyDerivationPathAddress(PyDerivationPathObject* self, void*) {
  uint32_t prop = TWDerivationPathAddress(self->value);
  return PyLong_FromLong(prop);
}

// getter function for Description
static const char PyDerivationPathDescription_doc[] =
    "TWString* TWDerivationPathDescription(struct TWDerivationPath* path)";
static PyObject* PyDerivationPathDescription(PyDerivationPathObject* self,
                                             void*) {
  TWStringPtr prop(TWDerivationPathDescription(self->value));
  return PyUnicode_FromTWString(prop);
}

// method function for IndexAt
static const char PyDerivationPathIndexAt_doc[] =
    "struct TWDerivationPathIndex* TWDerivationPathIndexAt(struct "
    "TWDerivationPath* path, uint32_t index)";
static PyObject* PyDerivationPathIndexAt(PyDerivationPathObject* self,
                                         PyObject* const* args,
                                         Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  auto checked_arg0 = PyLongArg_ToNumber<uint32_t>(args[0], 0, "uint32_t");
  if (!checked_arg0)
    return nullptr;
  const auto& arg0 = checked_arg0.value();

  TWDerivationPathIndex* result = TWDerivationPathIndexAt(self->value, arg0);
  return PyDerivationPathIndex_FromTWDerivationPathIndex(result);
}

// method function for IndicesCount
static const char PyDerivationPathIndicesCount_doc[] =
    "uint32_t TWDerivationPathIndicesCount(struct TWDerivationPath* path)";
static PyObject* PyDerivationPathIndicesCount(PyDerivationPathObject* self,
                                              PyObject* const* args,
                                              Py_ssize_t nargs) {
  if (nargs != 0) {
    PyErr_Format(PyExc_TypeError, "Expect 0 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  uint32_t result = TWDerivationPathIndicesCount(self->value);
  return PyLong_FromLong(result);
}

// static method function for Create
static const char PyDerivationPathCreate_doc[] =
    "struct TWDerivationPath* TWDerivationPathCreate(enum TWPurpose purpose, "
    "uint32_t coin, uint32_t account, uint32_t change, uint32_t address)";
static PyObject* PyDerivationPathCreate(PyDerivationPathObject* self,
                                        PyObject* const* args,
                                        Py_ssize_t nargs) {
  if (nargs != 5) {
    PyErr_Format(PyExc_TypeError, "Expect 5 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  if (!PyPurpose_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Purpose");
    return nullptr;
  }
  auto arg0 = PyPurpose_GetTWPurpose(args[0]);

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

  auto checked_arg4 = PyLongArg_ToNumber<uint32_t>(args[4], 4, "uint32_t");
  if (!checked_arg4)
    return nullptr;
  const auto& arg4 = checked_arg4.value();

  TWDerivationPath* result =
      TWDerivationPathCreate(arg0, arg1, arg2, arg3, arg4);
  return PyDerivationPath_FromTWDerivationPath(result);
}

// static method function for CreateWithString
static const char PyDerivationPathCreateWithString_doc[] =
    "struct TWDerivationPath* TWDerivationPathCreateWithString(TWString* "
    "string)";
static PyObject* PyDerivationPathCreateWithString(PyDerivationPathObject* self,
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

  TWDerivationPath* result = TWDerivationPathCreateWithString(arg0.get());
  return PyDerivationPath_FromTWDerivationPath(result);
}

// properties

static const PyGetSetDef get_set_defs[] = {
    {"purpose", (getter)PyDerivationPathPurpose, nullptr,
     PyDerivationPathPurpose_doc},
    {"coin", (getter)PyDerivationPathCoin, nullptr, PyDerivationPathCoin_doc},
    {"account", (getter)PyDerivationPathAccount, nullptr,
     PyDerivationPathAccount_doc},
    {"change", (getter)PyDerivationPathChange, nullptr,
     PyDerivationPathChange_doc},
    {"address", (getter)PyDerivationPathAddress, nullptr,
     PyDerivationPathAddress_doc},
    {"description", (getter)PyDerivationPathDescription, nullptr,
     PyDerivationPathDescription_doc},
    {}};

static const PyMethodDef method_defs[] = {
    {"index_at", (PyCFunction)PyDerivationPathIndexAt, METH_FASTCALL,
     PyDerivationPathIndexAt_doc},
    {"indices_count", (PyCFunction)PyDerivationPathIndicesCount, METH_FASTCALL,
     PyDerivationPathIndicesCount_doc},
    {"create", (PyCFunction)PyDerivationPathCreate, METH_FASTCALL | METH_STATIC,
     PyDerivationPathCreate_doc},
    {"create_with_string", (PyCFunction)PyDerivationPathCreateWithString,
     METH_FASTCALL | METH_STATIC, PyDerivationPathCreateWithString_doc},
    {}};

bool PyInit_DerivationPath(PyObject* module) {
  PyDerivationPathType.tp_dealloc = (destructor)PyDerivationPath_dealloc;
  PyDerivationPathType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyDerivationPathType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyDerivationPathType) < 0)
    return false;

  Py_INCREF(&PyDerivationPathType);
  if (PyModule_AddObject(module, "DerivationPath",
                         (PyObject*)&PyDerivationPathType) < 0) {
    Py_DECREF(&PyDerivationPathType);
    return false;
  }

  return true;
}