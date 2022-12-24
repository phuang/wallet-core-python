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

#include "generated/StarkExMessageSigner.h"

#include "String.h"
#include "generated/PrivateKey.h"
#include "generated/PublicKey.h"

struct PyStarkExMessageSignerObject {
  PyObject_HEAD;
};

static PyTypeObject PyStarkExMessageSignerType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.StarkExMessageSigner",    /* tp_name */
    sizeof(PyStarkExMessageSignerObject), /* tp_basicsize */
    0,                                    /* tp_itemsize */
    0,                                    /* tp_dealloc */
    0,                                    /* tp_print */
    0,                                    /* tp_getattr */
    0,                                    /* tp_setattr */
    0,                                    /* tp_reserved */
    0,                                    /* tp_repr */
    0,                                    /* tp_as_number */
    0,                                    /* tp_as_sequence */
    0,                                    /* tp_as_mapping */
    0,                                    /* tp_hash  */
    0,                                    /* tp_call */
    0,                                    /* tp_str */
    0,                                    /* tp_getattro */
    0,                                    /* tp_setattro */
    0,                                    /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                   /* tp_flags */
    nullptr,                              /* tp_doc */
};

// static method function for SignMessage
static const char PyStarkExMessageSignerSignMessage_doc[] =
    "TWString* TWStarkExMessageSignerSignMessage(const struct TWPrivateKey* "
    "privateKey, TWString* message)";
static PyObject* PyStarkExMessageSignerSignMessage(
    PyStarkExMessageSignerObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  if (!PyPrivateKey_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type PrivateKey");
    return nullptr;
  }
  auto arg0 = PyPrivateKey_GetTWPrivateKey(args[0]);

  if (!PyUnicode_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Unicode");
    return nullptr;
  }
  auto arg1 = PyUnicode_GetTWString(args[1]);

  TWStringPtr result(TWStarkExMessageSignerSignMessage(arg0, arg1.get()));
  return PyUnicode_FromTWString(result);
}

// static method function for VerifyMessage
static const char PyStarkExMessageSignerVerifyMessage_doc[] =
    "bool TWStarkExMessageSignerVerifyMessage(const struct TWPublicKey* "
    "pubKey, TWString* message, TWString* signature)";
static PyObject* PyStarkExMessageSignerVerifyMessage(
    PyStarkExMessageSignerObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 3) {
    PyErr_Format(PyExc_TypeError, "Expect 3 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  if (!PyPublicKey_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type PublicKey");
    return nullptr;
  }
  auto arg0 = PyPublicKey_GetTWPublicKey(args[0]);

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

  bool result =
      TWStarkExMessageSignerVerifyMessage(arg0, arg1.get(), arg2.get());
  return PyBool_FromLong(result);
}

// properties

static const PyGetSetDef get_set_defs[] = {{}};

static const PyMethodDef method_defs[] = {
    {"sign_message", (PyCFunction)PyStarkExMessageSignerSignMessage,
     METH_FASTCALL | METH_STATIC, PyStarkExMessageSignerSignMessage_doc},
    {"verify_message", (PyCFunction)PyStarkExMessageSignerVerifyMessage,
     METH_FASTCALL | METH_STATIC, PyStarkExMessageSignerVerifyMessage_doc},
    {}};

bool PyInit_StarkExMessageSigner(PyObject* module) {
  PyStarkExMessageSignerType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyStarkExMessageSignerType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyStarkExMessageSignerType) < 0)
    return false;

  Py_INCREF(&PyStarkExMessageSignerType);
  if (PyModule_AddObject(module, "StarkExMessageSigner",
                         (PyObject*)&PyStarkExMessageSignerType) < 0) {
    Py_DECREF(&PyStarkExMessageSignerType);
    return false;
  }

  return true;
}