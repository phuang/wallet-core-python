// This is a GENERATED FILE, changes made here WILL BE LOST.

#include "PublicKey.h"

#include "Data.h"
#include "PublicKey.h"
#include "PublicKeyType.h"
#include "String.h"

static PyTypeObject PyPublicKeyType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.PublicKey",    /* tp_name */
    sizeof(PyPublicKeyObject), /* tp_basicsize */
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

bool PyPublicKey_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyPublicKeyType) != 0;
}

// Create PyPublicKey from enum TWPublicKey.
PyObject* PyPublicKey_FromTWPublicKey(TWPublicKey* value) {
  if (!value)
    return nullptr;

  PyPublicKeyObject* object = PyObject_New(PyPublicKeyObject, &PyPublicKeyType);
  if (!object)
    return nullptr;

  object->value = value;

  return (PyObject*)object;
}

TWPublicKey* PyPublicKey_GetTWPublicKey(PyObject* object) {
  assert(PyPublicKey_Check(object));
  return ((PyPublicKeyObject*)object)->value;
}

static void PyPublicKey_dealloc(PyPublicKeyObject* self) {
  if (self->value) {
    TWPublicKeyDelete(self->value);
  }
  Py_TYPE(self)->tp_free(self);
}

// static int PyPublicKey_init(PyPublicKeyObject *self, PyObject *args, PyObject
// *kwds) {
//   return 0;
// }

// static PyObject* PyPublicKey_new(PyTypeObject *subtype, PyObject *args,
// PyObject *kwds) {
//   int value = 0;
//   if (!PyArg_ParseTuple(args, "|i", &value)) {
//     return nullptr;
//   }
//   return PyPublicKey_FromTWPublicKey((TWPublicKey)value);
// }

// static PyObject* PyPublicKey_str(PyPublicKeyObject *self) {
//   const char* str = "Unknown";
//   return PyUnicode_FromString(str);
// }

// getter function for IsCompressed
static const char PyPublicKeyIsCompressed_doc[] =
    "bool TWPublicKeyIsCompressed(struct TWPublicKey* pk)";
static PyObject* PyPublicKeyIsCompressed(PyPublicKeyObject* self, void*) {
  return PyBool_FromLong(TWPublicKeyIsCompressed(self->value));
}

// getter function for Compressed
static const char PyPublicKeyCompressed_doc[] =
    "struct TWPublicKey* TWPublicKeyCompressed(struct TWPublicKey* from)";
static PyObject* PyPublicKeyCompressed(PyPublicKeyObject* self, void*) {
  return PyPublicKey_FromTWPublicKey(TWPublicKeyCompressed(self->value));
}

// getter function for Uncompressed
static const char PyPublicKeyUncompressed_doc[] =
    "struct TWPublicKey* TWPublicKeyUncompressed(struct TWPublicKey* from)";
static PyObject* PyPublicKeyUncompressed(PyPublicKeyObject* self, void*) {
  return PyPublicKey_FromTWPublicKey(TWPublicKeyUncompressed(self->value));
}

// getter function for Data
static const char PyPublicKeyData_doc[] =
    "TWData* TWPublicKeyData(struct TWPublicKey* pk)";
static PyObject* PyPublicKeyData(PyPublicKeyObject* self, void*) {
  return PyByteArray_FromTWData(TWPublicKeyData(self->value));
}

// getter function for KeyType
static const char PyPublicKeyKeyType_doc[] =
    "enum TWPublicKeyType TWPublicKeyKeyType(struct TWPublicKey* publicKey)";
static PyObject* PyPublicKeyKeyType(PyPublicKeyObject* self, void*) {
  return PyPublicKeyType_FromTWPublicKeyType(TWPublicKeyKeyType(self->value));
}

// getter function for Description
static const char PyPublicKeyDescription_doc[] =
    "TWString* TWPublicKeyDescription(struct TWPublicKey* publicKey)";
static PyObject* PyPublicKeyDescription(PyPublicKeyObject* self, void*) {
  return PyUnicode_FromTWString(TWPublicKeyDescription(self->value));
}

// method function for Delete
static const char PyPublicKeyDelete_doc[] =
    "void TWPublicKeyDelete(struct TWPublicKey* pk)";
static PyObject* PyPublicKeyDelete(PyPublicKeyObject* self,
                                   PyObject* const* args,
                                   Py_ssize_t nargs) {
  if (nargs != 0) {
    PyErr_Format(PyExc_TypeError, "Expect 0 instead of %d.", nargs);
    return nullptr;
  }

  TWPublicKeyDelete(self->value);
  return nullptr;
}

// method function for Verify
static const char PyPublicKeyVerify_doc[] =
    "bool TWPublicKeyVerify(struct TWPublicKey* pk, TWData* signature, TWData* "
    "message)";
static PyObject* PyPublicKeyVerify(PyPublicKeyObject* self,
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

  if (!PyByteArray_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type ByteArray");
    return nullptr;
  }
  auto arg1 = PyByteArray_GetTWData(args[1]);

  bool result = TWPublicKeyVerify(self->value, arg0.get(), arg1.get());
  return PyBool_FromLong(result);
}

// method function for VerifySchnorr
static const char PyPublicKeyVerifySchnorr_doc[] =
    "bool TWPublicKeyVerifySchnorr(struct TWPublicKey* pk, TWData* signature, "
    "TWData* message)";
static PyObject* PyPublicKeyVerifySchnorr(PyPublicKeyObject* self,
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

  if (!PyByteArray_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type ByteArray");
    return nullptr;
  }
  auto arg1 = PyByteArray_GetTWData(args[1]);

  bool result = TWPublicKeyVerifySchnorr(self->value, arg0.get(), arg1.get());
  return PyBool_FromLong(result);
}

// static method function for CreateWithData
static const char PyPublicKeyCreateWithData_doc[] =
    "struct TWPublicKey* TWPublicKeyCreateWithData(TWData* data, enum "
    "TWPublicKeyType type)";
static PyObject* PyPublicKeyCreateWithData(PyPublicKeyObject* self,
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

  if (!PyPublicKeyType_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type PublicKeyType");
    return nullptr;
  }
  auto arg1 = PyPublicKeyType_GetTWPublicKeyType(args[1]);

  TWPublicKey* result = TWPublicKeyCreateWithData(arg0.get(), arg1);
  return PyPublicKey_FromTWPublicKey(result);
}

// static method function for IsValid
static const char PyPublicKeyIsValid_doc[] =
    "bool TWPublicKeyIsValid(TWData* data, enum TWPublicKeyType type)";
static PyObject* PyPublicKeyIsValid(PyPublicKeyObject* self,
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

  if (!PyPublicKeyType_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type PublicKeyType");
    return nullptr;
  }
  auto arg1 = PyPublicKeyType_GetTWPublicKeyType(args[1]);

  bool result = TWPublicKeyIsValid(arg0.get(), arg1);
  return PyBool_FromLong(result);
}

// static method function for Recover
static const char PyPublicKeyRecover_doc[] =
    "struct TWPublicKey* TWPublicKeyRecover(TWData* signature, TWData* "
    "message)";
static PyObject* PyPublicKeyRecover(PyPublicKeyObject* self,
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

  if (!PyByteArray_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type ByteArray");
    return nullptr;
  }
  auto arg1 = PyByteArray_GetTWData(args[1]);

  TWPublicKey* result = TWPublicKeyRecover(arg0.get(), arg1.get());
  return PyPublicKey_FromTWPublicKey(result);
}

static const PyGetSetDef get_set_defs[] = {
    {"IsCompressed", (getter)PyPublicKeyIsCompressed, nullptr,
     PyPublicKeyIsCompressed_doc},
    {"Compressed", (getter)PyPublicKeyCompressed, nullptr,
     PyPublicKeyCompressed_doc},
    {"Uncompressed", (getter)PyPublicKeyUncompressed, nullptr,
     PyPublicKeyUncompressed_doc},
    {"Data", (getter)PyPublicKeyData, nullptr, PyPublicKeyData_doc},
    {"KeyType", (getter)PyPublicKeyKeyType, nullptr, PyPublicKeyKeyType_doc},
    {"Description", (getter)PyPublicKeyDescription, nullptr,
     PyPublicKeyDescription_doc},
    {}};

static const PyMethodDef method_defs[] = {
    {"Delete", (PyCFunction)PyPublicKeyDelete, METH_FASTCALL,
     PyPublicKeyDelete_doc},
    {"Verify", (PyCFunction)PyPublicKeyVerify, METH_FASTCALL,
     PyPublicKeyVerify_doc},
    {"VerifySchnorr", (PyCFunction)PyPublicKeyVerifySchnorr, METH_FASTCALL,
     PyPublicKeyVerifySchnorr_doc},
    {"CreateWithData", (PyCFunction)PyPublicKeyCreateWithData,
     METH_FASTCALL | METH_STATIC, PyPublicKeyCreateWithData_doc},
    {"IsValid", (PyCFunction)PyPublicKeyIsValid, METH_FASTCALL | METH_STATIC,
     PyPublicKeyIsValid_doc},
    {"Recover", (PyCFunction)PyPublicKeyRecover, METH_FASTCALL | METH_STATIC,
     PyPublicKeyRecover_doc},
    {}};

bool PyInit_PublicKey(PyObject* module) {
  // PyPublicKeyType.tp_new = PyPublicKey_new;
  // PyPublicKeyType.tp_init = (initproc)PyPublicKey_init;
  PyPublicKeyType.tp_dealloc = (destructor)PyPublicKey_dealloc;
  // PyPublicKeyType.tp_str = (reprfunc)PyPublicKey_str;
  PyPublicKeyType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyPublicKeyType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyPublicKeyType) < 0)
    return false;

  Py_INCREF(&PyPublicKeyType);
  if (PyModule_AddObject(module, "PublicKey", (PyObject*)&PyPublicKeyType) <
      0) {
    Py_DECREF(&PyPublicKeyType);
    return false;
  }

  return true;
}