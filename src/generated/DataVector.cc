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

#include "generated/DataVector.h"

#include "Data.h"
#include "Number.h"

struct PyDataVectorObject {
  PyObject_HEAD;
  TWDataVector* value;
};

static PyTypeObject PyDataVectorType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.DataVector",    /* tp_name */
    sizeof(PyDataVectorObject), /* tp_basicsize */
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

bool PyDataVector_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyDataVectorType) != 0;
}

// Create PyDataVector from enum TWDataVector.
PyObject* PyDataVector_FromTWDataVector(TWDataVector* value) {
  if (!value)
    Py_RETURN_NONE;

  PyDataVectorObject* object =
      PyObject_New(PyDataVectorObject, &PyDataVectorType);
  if (!object)
    return nullptr;

  object->value = value;

  return (PyObject*)object;
}

TWDataVector* PyDataVector_GetTWDataVector(PyObject* object) {
  assert(PyDataVector_Check(object));
  return ((PyDataVectorObject*)object)->value;
}

static void PyDataVector_dealloc(PyDataVectorObject* self) {
  if (self->value) {
    TWDataVectorDelete(self->value);
  }
  Py_TYPE(self)->tp_free(self);
}

// getter function for Size
static const char PyDataVectorSize_doc[] =
    "size_t TWDataVectorSize(const struct TWDataVector* dataVector)";
static PyObject* PyDataVectorSize(PyDataVectorObject* self, void*) {
  size_t prop = TWDataVectorSize(self->value);
  return PyLong_FromLong(prop);
}

// method function for Add
static const char PyDataVectorAdd_doc[] =
    "void TWDataVectorAdd(struct TWDataVector* dataVector, TWData* data)";
static PyObject* PyDataVectorAdd(PyDataVectorObject* self,
                                 PyObject* const* args,
                                 Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  if (!PyBytes_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Bytes");
    return nullptr;
  }
  auto arg0 = PyBytes_GetTWData(args[0]);

  TWDataVectorAdd(self->value, arg0.get());
  return nullptr;
}

// method function for Get
static const char PyDataVectorGet_doc[] =
    "TWData* TWDataVectorGet(const struct TWDataVector* dataVector, size_t "
    "index)";
static PyObject* PyDataVectorGet(PyDataVectorObject* self,
                                 PyObject* const* args,
                                 Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  auto checked_arg0 = PyLongArg_ToNumber<size_t>(args[0], 0, "size_t");
  if (!checked_arg0)
    return nullptr;
  const auto& arg0 = checked_arg0.value();

  TWDataPtr result(TWDataVectorGet(self->value, arg0));
  return PyBytes_FromTWData(result);
}

// static method function for Create
static const char PyDataVectorCreate_doc[] =
    "struct TWDataVector* TWDataVectorCreate()";
static PyObject* PyDataVectorCreate(PyDataVectorObject* self,
                                    PyObject* const* args,
                                    Py_ssize_t nargs) {
  if (nargs != 0) {
    PyErr_Format(PyExc_TypeError, "Expect 0 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  TWDataVector* result = TWDataVectorCreate();
  return PyDataVector_FromTWDataVector(result);
}

// static method function for CreateWithData
static const char PyDataVectorCreateWithData_doc[] =
    "struct TWDataVector* TWDataVectorCreateWithData(TWData* data)";
static PyObject* PyDataVectorCreateWithData(PyDataVectorObject* self,
                                            PyObject* const* args,
                                            Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  if (!PyBytes_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Bytes");
    return nullptr;
  }
  auto arg0 = PyBytes_GetTWData(args[0]);

  TWDataVector* result = TWDataVectorCreateWithData(arg0.get());
  return PyDataVector_FromTWDataVector(result);
}

// properties

static const PyGetSetDef get_set_defs[] = {
    {"size", (getter)PyDataVectorSize, nullptr, PyDataVectorSize_doc},
    {}};

static const PyMethodDef method_defs[] = {
    {"add", (PyCFunction)PyDataVectorAdd, METH_FASTCALL, PyDataVectorAdd_doc},
    {"get", (PyCFunction)PyDataVectorGet, METH_FASTCALL, PyDataVectorGet_doc},
    {"create", (PyCFunction)PyDataVectorCreate, METH_FASTCALL | METH_STATIC,
     PyDataVectorCreate_doc},
    {"create_with_data", (PyCFunction)PyDataVectorCreateWithData,
     METH_FASTCALL | METH_STATIC, PyDataVectorCreateWithData_doc},
    {}};

bool PyInit_DataVector(PyObject* module) {
  PyDataVectorType.tp_dealloc = (destructor)PyDataVector_dealloc;
  PyDataVectorType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyDataVectorType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyDataVectorType) < 0)
    return false;

  Py_INCREF(&PyDataVectorType);
  if (PyModule_AddObject(module, "DataVector", (PyObject*)&PyDataVectorType) <
      0) {
    Py_DECREF(&PyDataVectorType);
    return false;
  }

  return true;
}