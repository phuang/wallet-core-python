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

#include "generated/Hash.h"

#include "Data.h"
#include "Number.h"

struct PyHashObject {
  PyObject_HEAD;
};

static PyTypeObject PyHashType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.Hash",    /* tp_name */
    sizeof(PyHashObject), /* tp_basicsize */
    0,                    /* tp_itemsize */
    0,                    /* tp_dealloc */
    0,                    /* tp_print */
    0,                    /* tp_getattr */
    0,                    /* tp_setattr */
    0,                    /* tp_reserved */
    0,                    /* tp_repr */
    0,                    /* tp_as_number */
    0,                    /* tp_as_sequence */
    0,                    /* tp_as_mapping */
    0,                    /* tp_hash  */
    0,                    /* tp_call */
    0,                    /* tp_str */
    0,                    /* tp_getattro */
    0,                    /* tp_setattro */
    0,                    /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,   /* tp_flags */
    nullptr,              /* tp_doc */
};

// static method function for SHA1
static const char PyHashSHA1_doc[] = "TWData* TWHashSHA1(TWData* data)";
static PyObject* PyHashSHA1(PyHashObject* self,
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

  TWDataPtr result(TWHashSHA1(arg0.get()));
  return PyBytes_FromTWData(result);
}

// static method function for SHA256
static const char PyHashSHA256_doc[] = "TWData* TWHashSHA256(TWData* data)";
static PyObject* PyHashSHA256(PyHashObject* self,
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

  TWDataPtr result(TWHashSHA256(arg0.get()));
  return PyBytes_FromTWData(result);
}

// static method function for SHA512
static const char PyHashSHA512_doc[] = "TWData* TWHashSHA512(TWData* data)";
static PyObject* PyHashSHA512(PyHashObject* self,
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

  TWDataPtr result(TWHashSHA512(arg0.get()));
  return PyBytes_FromTWData(result);
}

// static method function for SHA512_256
static const char PyHashSHA512_256_doc[] =
    "TWData* TWHashSHA512_256(TWData* data)";
static PyObject* PyHashSHA512_256(PyHashObject* self,
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

  TWDataPtr result(TWHashSHA512_256(arg0.get()));
  return PyBytes_FromTWData(result);
}

// static method function for Keccak256
static const char PyHashKeccak256_doc[] =
    "TWData* TWHashKeccak256(TWData* data)";
static PyObject* PyHashKeccak256(PyHashObject* self,
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

  TWDataPtr result(TWHashKeccak256(arg0.get()));
  return PyBytes_FromTWData(result);
}

// static method function for Keccak512
static const char PyHashKeccak512_doc[] =
    "TWData* TWHashKeccak512(TWData* data)";
static PyObject* PyHashKeccak512(PyHashObject* self,
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

  TWDataPtr result(TWHashKeccak512(arg0.get()));
  return PyBytes_FromTWData(result);
}

// static method function for SHA3_256
static const char PyHashSHA3_256_doc[] = "TWData* TWHashSHA3_256(TWData* data)";
static PyObject* PyHashSHA3_256(PyHashObject* self,
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

  TWDataPtr result(TWHashSHA3_256(arg0.get()));
  return PyBytes_FromTWData(result);
}

// static method function for SHA3_512
static const char PyHashSHA3_512_doc[] = "TWData* TWHashSHA3_512(TWData* data)";
static PyObject* PyHashSHA3_512(PyHashObject* self,
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

  TWDataPtr result(TWHashSHA3_512(arg0.get()));
  return PyBytes_FromTWData(result);
}

// static method function for RIPEMD
static const char PyHashRIPEMD_doc[] = "TWData* TWHashRIPEMD(TWData* data)";
static PyObject* PyHashRIPEMD(PyHashObject* self,
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

  TWDataPtr result(TWHashRIPEMD(arg0.get()));
  return PyBytes_FromTWData(result);
}

// static method function for Blake256
static const char PyHashBlake256_doc[] = "TWData* TWHashBlake256(TWData* data)";
static PyObject* PyHashBlake256(PyHashObject* self,
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

  TWDataPtr result(TWHashBlake256(arg0.get()));
  return PyBytes_FromTWData(result);
}

// static method function for Blake2b
static const char PyHashBlake2b_doc[] =
    "TWData* TWHashBlake2b(TWData* data, size_t size)";
static PyObject* PyHashBlake2b(PyHashObject* self,
                               PyObject* const* args,
                               Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  if (!PyBytes_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Bytes");
    return nullptr;
  }
  auto arg0 = PyBytes_GetTWData(args[0]);

  auto checked_arg1 = PyLongArg_ToNumber<size_t>(args[1], 1, "size_t");
  if (!checked_arg1)
    return nullptr;
  const auto& arg1 = checked_arg1.value();

  TWDataPtr result(TWHashBlake2b(arg0.get(), arg1));
  return PyBytes_FromTWData(result);
}

// static method function for Groestl512
static const char PyHashGroestl512_doc[] =
    "TWData* TWHashGroestl512(TWData* data)";
static PyObject* PyHashGroestl512(PyHashObject* self,
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

  TWDataPtr result(TWHashGroestl512(arg0.get()));
  return PyBytes_FromTWData(result);
}

// static method function for XXHash64
static const char PyHashXXHash64_doc[] =
    "TWData* TWHashXXHash64(TWData* data, uint64_t seed)";
static PyObject* PyHashXXHash64(PyHashObject* self,
                                PyObject* const* args,
                                Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 args, but %d args are passed in.",
                 nargs);
    return nullptr;
  }

  if (!PyBytes_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Bytes");
    return nullptr;
  }
  auto arg0 = PyBytes_GetTWData(args[0]);

  auto checked_arg1 = PyLongArg_ToNumber<uint64_t>(args[1], 1, "uint64_t");
  if (!checked_arg1)
    return nullptr;
  const auto& arg1 = checked_arg1.value();

  TWDataPtr result(TWHashXXHash64(arg0.get(), arg1));
  return PyBytes_FromTWData(result);
}

// static method function for TwoXXHash64Concat
static const char PyHashTwoXXHash64Concat_doc[] =
    "TWData* TWHashTwoXXHash64Concat(TWData* data)";
static PyObject* PyHashTwoXXHash64Concat(PyHashObject* self,
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

  TWDataPtr result(TWHashTwoXXHash64Concat(arg0.get()));
  return PyBytes_FromTWData(result);
}

// static method function for SHA256SHA256
static const char PyHashSHA256SHA256_doc[] =
    "TWData* TWHashSHA256SHA256(TWData* data)";
static PyObject* PyHashSHA256SHA256(PyHashObject* self,
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

  TWDataPtr result(TWHashSHA256SHA256(arg0.get()));
  return PyBytes_FromTWData(result);
}

// static method function for SHA256RIPEMD
static const char PyHashSHA256RIPEMD_doc[] =
    "TWData* TWHashSHA256RIPEMD(TWData* data)";
static PyObject* PyHashSHA256RIPEMD(PyHashObject* self,
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

  TWDataPtr result(TWHashSHA256RIPEMD(arg0.get()));
  return PyBytes_FromTWData(result);
}

// static method function for SHA3_256RIPEMD
static const char PyHashSHA3_256RIPEMD_doc[] =
    "TWData* TWHashSHA3_256RIPEMD(TWData* data)";
static PyObject* PyHashSHA3_256RIPEMD(PyHashObject* self,
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

  TWDataPtr result(TWHashSHA3_256RIPEMD(arg0.get()));
  return PyBytes_FromTWData(result);
}

// static method function for Blake256Blake256
static const char PyHashBlake256Blake256_doc[] =
    "TWData* TWHashBlake256Blake256(TWData* data)";
static PyObject* PyHashBlake256Blake256(PyHashObject* self,
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

  TWDataPtr result(TWHashBlake256Blake256(arg0.get()));
  return PyBytes_FromTWData(result);
}

// static method function for Blake256RIPEMD
static const char PyHashBlake256RIPEMD_doc[] =
    "TWData* TWHashBlake256RIPEMD(TWData* data)";
static PyObject* PyHashBlake256RIPEMD(PyHashObject* self,
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

  TWDataPtr result(TWHashBlake256RIPEMD(arg0.get()));
  return PyBytes_FromTWData(result);
}

// static method function for Groestl512Groestl512
static const char PyHashGroestl512Groestl512_doc[] =
    "TWData* TWHashGroestl512Groestl512(TWData* data)";
static PyObject* PyHashGroestl512Groestl512(PyHashObject* self,
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

  TWDataPtr result(TWHashGroestl512Groestl512(arg0.get()));
  return PyBytes_FromTWData(result);
}

// properties

static const PyGetSetDef get_set_defs[] = {{}};

static const PyMethodDef method_defs[] = {
    {"sha1", (PyCFunction)PyHashSHA1, METH_FASTCALL | METH_STATIC,
     PyHashSHA1_doc},
    {"sha256", (PyCFunction)PyHashSHA256, METH_FASTCALL | METH_STATIC,
     PyHashSHA256_doc},
    {"sha512", (PyCFunction)PyHashSHA512, METH_FASTCALL | METH_STATIC,
     PyHashSHA512_doc},
    {"sha512_256", (PyCFunction)PyHashSHA512_256, METH_FASTCALL | METH_STATIC,
     PyHashSHA512_256_doc},
    {"keccak256", (PyCFunction)PyHashKeccak256, METH_FASTCALL | METH_STATIC,
     PyHashKeccak256_doc},
    {"keccak512", (PyCFunction)PyHashKeccak512, METH_FASTCALL | METH_STATIC,
     PyHashKeccak512_doc},
    {"sha3_256", (PyCFunction)PyHashSHA3_256, METH_FASTCALL | METH_STATIC,
     PyHashSHA3_256_doc},
    {"sha3_512", (PyCFunction)PyHashSHA3_512, METH_FASTCALL | METH_STATIC,
     PyHashSHA3_512_doc},
    {"ripemd", (PyCFunction)PyHashRIPEMD, METH_FASTCALL | METH_STATIC,
     PyHashRIPEMD_doc},
    {"blake256", (PyCFunction)PyHashBlake256, METH_FASTCALL | METH_STATIC,
     PyHashBlake256_doc},
    {"blake2b", (PyCFunction)PyHashBlake2b, METH_FASTCALL | METH_STATIC,
     PyHashBlake2b_doc},
    {"groestl512", (PyCFunction)PyHashGroestl512, METH_FASTCALL | METH_STATIC,
     PyHashGroestl512_doc},
    {"xxhash64", (PyCFunction)PyHashXXHash64, METH_FASTCALL | METH_STATIC,
     PyHashXXHash64_doc},
    {"two_xxhash64_concat", (PyCFunction)PyHashTwoXXHash64Concat,
     METH_FASTCALL | METH_STATIC, PyHashTwoXXHash64Concat_doc},
    {"sha256_sha256", (PyCFunction)PyHashSHA256SHA256,
     METH_FASTCALL | METH_STATIC, PyHashSHA256SHA256_doc},
    {"sha256_ripemd", (PyCFunction)PyHashSHA256RIPEMD,
     METH_FASTCALL | METH_STATIC, PyHashSHA256RIPEMD_doc},
    {"sha3_256_ripemd", (PyCFunction)PyHashSHA3_256RIPEMD,
     METH_FASTCALL | METH_STATIC, PyHashSHA3_256RIPEMD_doc},
    {"blake256_blake256", (PyCFunction)PyHashBlake256Blake256,
     METH_FASTCALL | METH_STATIC, PyHashBlake256Blake256_doc},
    {"blake256_ripemd", (PyCFunction)PyHashBlake256RIPEMD,
     METH_FASTCALL | METH_STATIC, PyHashBlake256RIPEMD_doc},
    {"groestl512_groestl512", (PyCFunction)PyHashGroestl512Groestl512,
     METH_FASTCALL | METH_STATIC, PyHashGroestl512Groestl512_doc},
    {}};

bool PyInit_Hash(PyObject* module) {
  PyHashType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyHashType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyHashType) < 0)
    return false;

  Py_INCREF(&PyHashType);
  if (PyModule_AddObject(module, "Hash", (PyObject*)&PyHashType) < 0) {
    Py_DECREF(&PyHashType);
    return false;
  }

  return true;
}