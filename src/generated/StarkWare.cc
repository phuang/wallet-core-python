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

#include "generated/StarkWare.h"

#include "String.h"
#include "generated/DerivationPath.h"
#include "generated/PrivateKey.h"

struct PyStarkWareObject {
  PyObject_HEAD;
};

static PyTypeObject PyStarkWareType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.StarkWare",    /* tp_name */
    sizeof(PyStarkWareObject), /* tp_basicsize */
    0,                         /* tp_itemsize */
    0,                         /* tp_dealloc */
    0,                         /* tp_print */
    0,                         /* tp_getattr */
    0,                         /* tp_setattr */
    0,                         /* tp_reserved */
    0,                         /* tp_repr */
    0,                         /* tp_as_number */
    0,                         /* tp_as_sequence */
    0,                         /* tp_as_mapping */
    0,                         /* tp_hash  */
    0,                         /* tp_call */
    0,                         /* tp_str */
    0,                         /* tp_getattro */
    0,                         /* tp_setattro */
    0,                         /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,        /* tp_flags */
    nullptr,                   /* tp_doc */
};

// static method function for GetStarkKeyFromSignature
static const char PyStarkWareGetStarkKeyFromSignature_doc[] =
    "struct TWPrivateKey* TWStarkWareGetStarkKeyFromSignature(const struct "
    "TWDerivationPath* derivationPath, TWString* signature)";
static PyObject* PyStarkWareGetStarkKeyFromSignature(PyStarkWareObject* self,
                                                     PyObject* const* args,
                                                     Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  if (!PyDerivationPath_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type DerivationPath");
    return nullptr;
  }
  auto arg0 = PyDerivationPath_GetTWDerivationPath(args[0]);

  if (!PyUnicode_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Unicode");
    return nullptr;
  }
  auto arg1 = PyUnicode_GetTWString(args[1]);

  TWPrivateKey* result = TWStarkWareGetStarkKeyFromSignature(arg0, arg1.get());
  return PyPrivateKey_FromTWPrivateKey(result);
}

// properties

static const PyGetSetDef get_set_defs[] = {{}};

static const PyMethodDef method_defs[] = {
    {"get_stark_key_from_signature",
     (PyCFunction)PyStarkWareGetStarkKeyFromSignature,
     METH_FASTCALL | METH_STATIC, PyStarkWareGetStarkKeyFromSignature_doc},
    {}};

bool PyInit_StarkWare(PyObject* module) {
  PyStarkWareType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyStarkWareType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyStarkWareType) < 0)
    return false;

  Py_INCREF(&PyStarkWareType);
  if (PyModule_AddObject(module, "StarkWare", (PyObject*)&PyStarkWareType) <
      0) {
    Py_DECREF(&PyStarkWareType);
    return false;
  }

  return true;
}