// This is a GENERATED FILE, changes made here WILL BE LOST.

#include "Hash.h"

#include "Data.h"

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

bool PyHash_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyHashType) != 0;
}

// Create PyHash from enum TWHash.
PyObject* PyHash_FromTWHash(TWHash* value) {
  if (!value)
    return nullptr;

  PyHashObject* object = PyObject_New(PyHashObject, &PyHashType);
  if (!object)
    return nullptr;

  object->value = value;

  return (PyObject*)object;
}

TWHash* PyHash_GetTWHash(PyObject* object) {
  assert(PyHash_Check(object));
  return ((PyHashObject*)object)->value;
}

// static int PyHash_init(PyHashObject *self, PyObject *args, PyObject *kwds) {
//   return 0;
// }

// static PyObject* PyHash_new(PyTypeObject *subtype, PyObject *args, PyObject
// *kwds) {
//   int value = 0;
//   if (!PyArg_ParseTuple(args, "|i", &value)) {
//     return nullptr;
//   }
//   return PyHash_FromTWHash((TWHash)value);
// }

// static PyObject* PyHash_str(PyHashObject *self) {
//   const char* str = "Unknown";
//   return PyUnicode_FromString(str);
// }

// static method function for SHA1
// TWData* TWHashSHA1(TWData* data);
static PyObject* PyHashSHA1(PyHashObject* self,
                            PyObject* const* args,
                            Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyByteArray_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type ByteArray");
    return nullptr;
  }
  auto arg0 = PyByteArray_GetTWData(args[0]);

  TWDataPtr result = TWHashSHA1(arg0.get());
  return PyByteArray_FromTWData(result);
}

// static method function for SHA256
// TWData* TWHashSHA256(TWData* data);
static PyObject* PyHashSHA256(PyHashObject* self,
                              PyObject* const* args,
                              Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyByteArray_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type ByteArray");
    return nullptr;
  }
  auto arg0 = PyByteArray_GetTWData(args[0]);

  TWDataPtr result = TWHashSHA256(arg0.get());
  return PyByteArray_FromTWData(result);
}

// static method function for SHA512
// TWData* TWHashSHA512(TWData* data);
static PyObject* PyHashSHA512(PyHashObject* self,
                              PyObject* const* args,
                              Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyByteArray_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type ByteArray");
    return nullptr;
  }
  auto arg0 = PyByteArray_GetTWData(args[0]);

  TWDataPtr result = TWHashSHA512(arg0.get());
  return PyByteArray_FromTWData(result);
}

// static method function for SHA512_256
// TWData* TWHashSHA512_256(TWData* data);
static PyObject* PyHashSHA512_256(PyHashObject* self,
                                  PyObject* const* args,
                                  Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyByteArray_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type ByteArray");
    return nullptr;
  }
  auto arg0 = PyByteArray_GetTWData(args[0]);

  TWDataPtr result = TWHashSHA512_256(arg0.get());
  return PyByteArray_FromTWData(result);
}

// static method function for Keccak256
// TWData* TWHashKeccak256(TWData* data);
static PyObject* PyHashKeccak256(PyHashObject* self,
                                 PyObject* const* args,
                                 Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyByteArray_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type ByteArray");
    return nullptr;
  }
  auto arg0 = PyByteArray_GetTWData(args[0]);

  TWDataPtr result = TWHashKeccak256(arg0.get());
  return PyByteArray_FromTWData(result);
}

// static method function for Keccak512
// TWData* TWHashKeccak512(TWData* data);
static PyObject* PyHashKeccak512(PyHashObject* self,
                                 PyObject* const* args,
                                 Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyByteArray_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type ByteArray");
    return nullptr;
  }
  auto arg0 = PyByteArray_GetTWData(args[0]);

  TWDataPtr result = TWHashKeccak512(arg0.get());
  return PyByteArray_FromTWData(result);
}

// static method function for SHA3_256
// TWData* TWHashSHA3_256(TWData* data);
static PyObject* PyHashSHA3_256(PyHashObject* self,
                                PyObject* const* args,
                                Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyByteArray_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type ByteArray");
    return nullptr;
  }
  auto arg0 = PyByteArray_GetTWData(args[0]);

  TWDataPtr result = TWHashSHA3_256(arg0.get());
  return PyByteArray_FromTWData(result);
}

// static method function for SHA3_512
// TWData* TWHashSHA3_512(TWData* data);
static PyObject* PyHashSHA3_512(PyHashObject* self,
                                PyObject* const* args,
                                Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyByteArray_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type ByteArray");
    return nullptr;
  }
  auto arg0 = PyByteArray_GetTWData(args[0]);

  TWDataPtr result = TWHashSHA3_512(arg0.get());
  return PyByteArray_FromTWData(result);
}

// static method function for RIPEMD
// TWData* TWHashRIPEMD(TWData* data);
static PyObject* PyHashRIPEMD(PyHashObject* self,
                              PyObject* const* args,
                              Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyByteArray_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type ByteArray");
    return nullptr;
  }
  auto arg0 = PyByteArray_GetTWData(args[0]);

  TWDataPtr result = TWHashRIPEMD(arg0.get());
  return PyByteArray_FromTWData(result);
}

// static method function for Blake256
// TWData* TWHashBlake256(TWData* data);
static PyObject* PyHashBlake256(PyHashObject* self,
                                PyObject* const* args,
                                Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyByteArray_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type ByteArray");
    return nullptr;
  }
  auto arg0 = PyByteArray_GetTWData(args[0]);

  TWDataPtr result = TWHashBlake256(arg0.get());
  return PyByteArray_FromTWData(result);
}

// static method function for Blake2b
// TWData* TWHashBlake2b(TWData* data, size_t size);
static PyObject* PyHashBlake2b(PyHashObject* self,
                               PyObject* const* args,
                               Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyByteArray_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type ByteArray");
    return nullptr;
  }
  auto arg0 = PyByteArray_GetTWData(args[0]);

  if (!PyLong_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Long");
    return nullptr;
  }
  auto arg1 = PyLong_AsLong(args[1]);

  TWDataPtr result = TWHashBlake2b(arg0.get(), arg1);
  return PyByteArray_FromTWData(result);
}

// static method function for Groestl512
// TWData* TWHashGroestl512(TWData* data);
static PyObject* PyHashGroestl512(PyHashObject* self,
                                  PyObject* const* args,
                                  Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyByteArray_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type ByteArray");
    return nullptr;
  }
  auto arg0 = PyByteArray_GetTWData(args[0]);

  TWDataPtr result = TWHashGroestl512(arg0.get());
  return PyByteArray_FromTWData(result);
}

// static method function for XXHash64
// TWData* TWHashXXHash64(TWData* data, uint64_t seed);
static PyObject* PyHashXXHash64(PyHashObject* self,
                                PyObject* const* args,
                                Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyByteArray_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type ByteArray");
    return nullptr;
  }
  auto arg0 = PyByteArray_GetTWData(args[0]);

  if (!PyLong_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Long");
    return nullptr;
  }
  auto arg1 = PyLong_AsLongLong(args[1]);

  TWDataPtr result = TWHashXXHash64(arg0.get(), arg1);
  return PyByteArray_FromTWData(result);
}

// static method function for TwoXXHash64Concat
// TWData* TWHashTwoXXHash64Concat(TWData* data);
static PyObject* PyHashTwoXXHash64Concat(PyHashObject* self,
                                         PyObject* const* args,
                                         Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyByteArray_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type ByteArray");
    return nullptr;
  }
  auto arg0 = PyByteArray_GetTWData(args[0]);

  TWDataPtr result = TWHashTwoXXHash64Concat(arg0.get());
  return PyByteArray_FromTWData(result);
}

// static method function for SHA256SHA256
// TWData* TWHashSHA256SHA256(TWData* data);
static PyObject* PyHashSHA256SHA256(PyHashObject* self,
                                    PyObject* const* args,
                                    Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyByteArray_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type ByteArray");
    return nullptr;
  }
  auto arg0 = PyByteArray_GetTWData(args[0]);

  TWDataPtr result = TWHashSHA256SHA256(arg0.get());
  return PyByteArray_FromTWData(result);
}

// static method function for SHA256RIPEMD
// TWData* TWHashSHA256RIPEMD(TWData* data);
static PyObject* PyHashSHA256RIPEMD(PyHashObject* self,
                                    PyObject* const* args,
                                    Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyByteArray_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type ByteArray");
    return nullptr;
  }
  auto arg0 = PyByteArray_GetTWData(args[0]);

  TWDataPtr result = TWHashSHA256RIPEMD(arg0.get());
  return PyByteArray_FromTWData(result);
}

// static method function for SHA3_256RIPEMD
// TWData* TWHashSHA3_256RIPEMD(TWData* data);
static PyObject* PyHashSHA3_256RIPEMD(PyHashObject* self,
                                      PyObject* const* args,
                                      Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyByteArray_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type ByteArray");
    return nullptr;
  }
  auto arg0 = PyByteArray_GetTWData(args[0]);

  TWDataPtr result = TWHashSHA3_256RIPEMD(arg0.get());
  return PyByteArray_FromTWData(result);
}

// static method function for Blake256Blake256
// TWData* TWHashBlake256Blake256(TWData* data);
static PyObject* PyHashBlake256Blake256(PyHashObject* self,
                                        PyObject* const* args,
                                        Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyByteArray_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type ByteArray");
    return nullptr;
  }
  auto arg0 = PyByteArray_GetTWData(args[0]);

  TWDataPtr result = TWHashBlake256Blake256(arg0.get());
  return PyByteArray_FromTWData(result);
}

// static method function for Blake256RIPEMD
// TWData* TWHashBlake256RIPEMD(TWData* data);
static PyObject* PyHashBlake256RIPEMD(PyHashObject* self,
                                      PyObject* const* args,
                                      Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyByteArray_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type ByteArray");
    return nullptr;
  }
  auto arg0 = PyByteArray_GetTWData(args[0]);

  TWDataPtr result = TWHashBlake256RIPEMD(arg0.get());
  return PyByteArray_FromTWData(result);
}

// static method function for Groestl512Groestl512
// TWData* TWHashGroestl512Groestl512(TWData* data);
static PyObject* PyHashGroestl512Groestl512(PyHashObject* self,
                                            PyObject* const* args,
                                            Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyByteArray_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type ByteArray");
    return nullptr;
  }
  auto arg0 = PyByteArray_GetTWData(args[0]);

  TWDataPtr result = TWHashGroestl512Groestl512(arg0.get());
  return PyByteArray_FromTWData(result);
}

static const PyGetSetDef get_set_defs[] = {{}};

static const PyMethodDef method_defs[] = {
    {"SHA1", (PyCFunction)PyHashSHA1, METH_FASTCALL | METH_STATIC},
    {"SHA256", (PyCFunction)PyHashSHA256, METH_FASTCALL | METH_STATIC},
    {"SHA512", (PyCFunction)PyHashSHA512, METH_FASTCALL | METH_STATIC},
    {"SHA512_256", (PyCFunction)PyHashSHA512_256, METH_FASTCALL | METH_STATIC},
    {"Keccak256", (PyCFunction)PyHashKeccak256, METH_FASTCALL | METH_STATIC},
    {"Keccak512", (PyCFunction)PyHashKeccak512, METH_FASTCALL | METH_STATIC},
    {"SHA3_256", (PyCFunction)PyHashSHA3_256, METH_FASTCALL | METH_STATIC},
    {"SHA3_512", (PyCFunction)PyHashSHA3_512, METH_FASTCALL | METH_STATIC},
    {"RIPEMD", (PyCFunction)PyHashRIPEMD, METH_FASTCALL | METH_STATIC},
    {"Blake256", (PyCFunction)PyHashBlake256, METH_FASTCALL | METH_STATIC},
    {"Blake2b", (PyCFunction)PyHashBlake2b, METH_FASTCALL | METH_STATIC},
    {"Groestl512", (PyCFunction)PyHashGroestl512, METH_FASTCALL | METH_STATIC},
    {"XXHash64", (PyCFunction)PyHashXXHash64, METH_FASTCALL | METH_STATIC},
    {"TwoXXHash64Concat", (PyCFunction)PyHashTwoXXHash64Concat,
     METH_FASTCALL | METH_STATIC},
    {"SHA256SHA256", (PyCFunction)PyHashSHA256SHA256,
     METH_FASTCALL | METH_STATIC},
    {"SHA256RIPEMD", (PyCFunction)PyHashSHA256RIPEMD,
     METH_FASTCALL | METH_STATIC},
    {"SHA3_256RIPEMD", (PyCFunction)PyHashSHA3_256RIPEMD,
     METH_FASTCALL | METH_STATIC},
    {"Blake256Blake256", (PyCFunction)PyHashBlake256Blake256,
     METH_FASTCALL | METH_STATIC},
    {"Blake256RIPEMD", (PyCFunction)PyHashBlake256RIPEMD,
     METH_FASTCALL | METH_STATIC},
    {"Groestl512Groestl512", (PyCFunction)PyHashGroestl512Groestl512,
     METH_FASTCALL | METH_STATIC},
    {}};

bool PyInit_Hash(PyObject* module) {
  // PyHashType.tp_new = PyHash_new;
  // PyHashType.tp_init = (initproc)PyHash_init;
  // PyHashType.tp_str = (reprfunc)PyHash_str;
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