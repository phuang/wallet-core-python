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

#include "generated/DerivationPathIndex.h"

#include "Bool.h"
#include "Number.h"
#include "String.h"

struct PyDerivationPathIndexObject {
  PyObject_HEAD;
  TWDerivationPathIndex* value;
};

static PyTypeObject PyDerivationPathIndexType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.DerivationPathIndex",    /* tp_name */
    sizeof(PyDerivationPathIndexObject), /* tp_basicsize */
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

bool PyDerivationPathIndex_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyDerivationPathIndexType) != 0;
}

// Create PyDerivationPathIndex from enum TWDerivationPathIndex.
PyObject* PyDerivationPathIndex_FromTWDerivationPathIndex(
    TWDerivationPathIndex* value) {
  if (!value)
    Py_RETURN_NONE;

  PyDerivationPathIndexObject* object =
      PyObject_New(PyDerivationPathIndexObject, &PyDerivationPathIndexType);
  if (!object)
    return nullptr;

  object->value = value;

  return (PyObject*)object;
}

TWDerivationPathIndex* PyDerivationPathIndex_GetTWDerivationPathIndex(
    PyObject* object) {
  assert(PyDerivationPathIndex_Check(object));
  return ((PyDerivationPathIndexObject*)object)->value;
}

static void PyDerivationPathIndex_dealloc(PyDerivationPathIndexObject* self) {
  if (self->value) {
    TWDerivationPathIndexDelete(self->value);
  }
  Py_TYPE(self)->tp_free(self);
}

// getter function for Value
static const char PyDerivationPathIndexValue_doc[] =
    "uint32_t TWDerivationPathIndexValue(struct TWDerivationPathIndex* index)";
static PyObject* PyDerivationPathIndexValue(PyDerivationPathIndexObject* self,
                                            void*) {
  uint32_t prop = TWDerivationPathIndexValue(self->value);
  return PyLong_FromLong(prop);
}

// getter function for Hardened
static const char PyDerivationPathIndexHardened_doc[] =
    "bool TWDerivationPathIndexHardened(struct TWDerivationPathIndex* index)";
static PyObject* PyDerivationPathIndexHardened(
    PyDerivationPathIndexObject* self,
    void*) {
  bool prop = TWDerivationPathIndexHardened(self->value);
  return PyBool_FromLong(prop);
}

// getter function for Description
static const char PyDerivationPathIndexDescription_doc[] =
    "TWString* TWDerivationPathIndexDescription(struct TWDerivationPathIndex* "
    "index)";
static PyObject* PyDerivationPathIndexDescription(
    PyDerivationPathIndexObject* self,
    void*) {
  TWStringPtr prop(TWDerivationPathIndexDescription(self->value));
  return PyUnicode_FromTWString(prop);
}

// static method function for Create
static const char PyDerivationPathIndexCreate_doc[] =
    "struct TWDerivationPathIndex* TWDerivationPathIndexCreate(uint32_t value, "
    "bool hardened)";
static PyObject* PyDerivationPathIndexCreate(PyDerivationPathIndexObject* self,
                                             PyObject* const* args,
                                             Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  auto checked_arg0 = PyLongArg_ToNumber<uint32_t>(args[0], 0, "uint32_t");
  if (!checked_arg0)
    return nullptr;
  const auto& arg0 = checked_arg0.value();

  if (!PyBool_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bool");
    return nullptr;
  }
  auto arg1 = PyBool_IsTrue(args[1]);

  TWDerivationPathIndex* result = TWDerivationPathIndexCreate(arg0, arg1);
  return PyDerivationPathIndex_FromTWDerivationPathIndex(result);
}

// properties

static const PyGetSetDef get_set_defs[] = {
    {"value", (getter)PyDerivationPathIndexValue, nullptr,
     PyDerivationPathIndexValue_doc},
    {"hardened", (getter)PyDerivationPathIndexHardened, nullptr,
     PyDerivationPathIndexHardened_doc},
    {"description", (getter)PyDerivationPathIndexDescription, nullptr,
     PyDerivationPathIndexDescription_doc},
    {}};

static const PyMethodDef method_defs[] = {
    {"create", (PyCFunction)PyDerivationPathIndexCreate,
     METH_FASTCALL | METH_STATIC, PyDerivationPathIndexCreate_doc},
    {}};

bool PyInit_DerivationPathIndex(PyObject* module) {
  PyDerivationPathIndexType.tp_dealloc =
      (destructor)PyDerivationPathIndex_dealloc;
  PyDerivationPathIndexType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyDerivationPathIndexType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyDerivationPathIndexType) < 0)
    return false;

  Py_INCREF(&PyDerivationPathIndexType);
  if (PyModule_AddObject(module, "DerivationPathIndex",
                         (PyObject*)&PyDerivationPathIndexType) < 0) {
    Py_DECREF(&PyDerivationPathIndexType);
    return false;
  }

  return true;
}