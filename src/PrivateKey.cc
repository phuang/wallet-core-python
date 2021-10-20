// This is a GENERATED FILE, changes made here WILL BE LOST.

#include "PrivateKey.h"

#include "Bool.h"
#include "Curve.h"
#include "Data.h"
#include "PublicKey.h"

static PyTypeObject PyPrivateKeyType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.PrivateKey",    /* tp_name */
    sizeof(PyPrivateKeyObject), /* tp_basicsize */
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

bool PyPrivateKey_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyPrivateKeyType) != 0;
}

// Create PyPrivateKey from enum TWPrivateKey.
PyObject* PyPrivateKey_FromTWPrivateKey(TWPrivateKey* value) {
  if (!value)
    return nullptr;

  PyPrivateKeyObject* object =
      PyObject_New(PyPrivateKeyObject, &PyPrivateKeyType);
  if (!object)
    return nullptr;

  object->value = value;

  return (PyObject*)object;
}

TWPrivateKey* PyPrivateKey_GetTWPrivateKey(PyObject* object) {
  assert(PyPrivateKey_Check(object));
  return ((PyPrivateKeyObject*)object)->value;
}

// static int PyPrivateKey_init(PyPrivateKeyObject *self, PyObject *args,
// PyObject *kwds) {
//   return 0;
// }

// static PyObject* PyPrivateKey_new(PyTypeObject *subtype, PyObject *args,
// PyObject *kwds) {
//   int value = 0;
//   if (!PyArg_ParseTuple(args, "|i", &value)) {
//     return nullptr;
//   }
//   return PyPrivateKey_FromTWPrivateKey((TWPrivateKey)value);
// }

// static PyObject* PyPrivateKey_str(PyPrivateKeyObject *self) {
//   const char* str = "Unknown";
//   return PyUnicode_FromString(str);
// }

// method function for Delete
// void TWPrivateKeyDelete(struct TWPrivateKey* pk);
static PyObject* PyPrivateKeyDelete(PyPrivateKeyObject* self,
                                    PyObject* const* args,
                                    Py_ssize_t nargs) {
  if (nargs != 0) {
    PyErr_Format(PyExc_TypeError, "Expect 0 instead of %d.", nargs);
    return nullptr;
  }

  TWPrivateKeyDelete(self->value);
  return nullptr;
}

// method function for GetPublicKeySecp256k1
// struct TWPublicKey* TWPrivateKeyGetPublicKeySecp256k1(struct TWPrivateKey*
// pk, bool compressed);
static PyObject* PyPrivateKeyGetPublicKeySecp256k1(PyPrivateKeyObject* self,
                                                   PyObject* const* args,
                                                   Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyBool_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Bool");
    return nullptr;
  }
  auto arg0 = PyBool_IsTrue(args[0]);

  TWPublicKey* result = TWPrivateKeyGetPublicKeySecp256k1(self->value, arg0);
  return PyPublicKey_FromTWPublicKey(result);
}

// method function for GetPublicKeyNist256p1
// struct TWPublicKey* TWPrivateKeyGetPublicKeyNist256p1(struct TWPrivateKey*
// pk);
static PyObject* PyPrivateKeyGetPublicKeyNist256p1(PyPrivateKeyObject* self,
                                                   PyObject* const* args,
                                                   Py_ssize_t nargs) {
  if (nargs != 0) {
    PyErr_Format(PyExc_TypeError, "Expect 0 instead of %d.", nargs);
    return nullptr;
  }

  TWPublicKey* result = TWPrivateKeyGetPublicKeyNist256p1(self->value);
  return PyPublicKey_FromTWPublicKey(result);
}

// method function for GetPublicKeyEd25519
// struct TWPublicKey* TWPrivateKeyGetPublicKeyEd25519(struct TWPrivateKey* pk);
static PyObject* PyPrivateKeyGetPublicKeyEd25519(PyPrivateKeyObject* self,
                                                 PyObject* const* args,
                                                 Py_ssize_t nargs) {
  if (nargs != 0) {
    PyErr_Format(PyExc_TypeError, "Expect 0 instead of %d.", nargs);
    return nullptr;
  }

  TWPublicKey* result = TWPrivateKeyGetPublicKeyEd25519(self->value);
  return PyPublicKey_FromTWPublicKey(result);
}

// method function for GetPublicKeyEd25519Blake2b
// struct TWPublicKey* TWPrivateKeyGetPublicKeyEd25519Blake2b(struct
// TWPrivateKey* pk);
static PyObject* PyPrivateKeyGetPublicKeyEd25519Blake2b(
    PyPrivateKeyObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 0) {
    PyErr_Format(PyExc_TypeError, "Expect 0 instead of %d.", nargs);
    return nullptr;
  }

  TWPublicKey* result = TWPrivateKeyGetPublicKeyEd25519Blake2b(self->value);
  return PyPublicKey_FromTWPublicKey(result);
}

// method function for GetPublicKeyEd25519Extended
// struct TWPublicKey* TWPrivateKeyGetPublicKeyEd25519Extended(struct
// TWPrivateKey* pk);
static PyObject* PyPrivateKeyGetPublicKeyEd25519Extended(
    PyPrivateKeyObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 0) {
    PyErr_Format(PyExc_TypeError, "Expect 0 instead of %d.", nargs);
    return nullptr;
  }

  TWPublicKey* result = TWPrivateKeyGetPublicKeyEd25519Extended(self->value);
  return PyPublicKey_FromTWPublicKey(result);
}

// method function for GetPublicKeyCurve25519
// struct TWPublicKey* TWPrivateKeyGetPublicKeyCurve25519(struct TWPrivateKey*
// pk);
static PyObject* PyPrivateKeyGetPublicKeyCurve25519(PyPrivateKeyObject* self,
                                                    PyObject* const* args,
                                                    Py_ssize_t nargs) {
  if (nargs != 0) {
    PyErr_Format(PyExc_TypeError, "Expect 0 instead of %d.", nargs);
    return nullptr;
  }

  TWPublicKey* result = TWPrivateKeyGetPublicKeyCurve25519(self->value);
  return PyPublicKey_FromTWPublicKey(result);
}

// method function for GetSharedKey
// TWData* TWPrivateKeyGetSharedKey(const struct TWPrivateKey* pk, const struct
// TWPublicKey* publicKey, enum TWCurve curve);
static PyObject* PyPrivateKeyGetSharedKey(PyPrivateKeyObject* self,
                                          PyObject* const* args,
                                          Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyPublicKey_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type PublicKey");
    return nullptr;
  }
  auto arg0 = PyPublicKey_GetTWPublicKey(args[0]);

  if (!PyCurve_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Curve");
    return nullptr;
  }
  auto arg1 = PyCurve_GetTWCurve(args[1]);

  TWDataPtr result = TWPrivateKeyGetSharedKey(self->value, arg0, arg1);
  return PyByteArray_FromTWData(result);
}

// method function for Sign
// TWData* TWPrivateKeySign(struct TWPrivateKey* pk, TWData* digest, enum
// TWCurve curve);
static PyObject* PyPrivateKeySign(PyPrivateKeyObject* self,
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

  if (!PyCurve_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Curve");
    return nullptr;
  }
  auto arg1 = PyCurve_GetTWCurve(args[1]);

  TWDataPtr result = TWPrivateKeySign(self->value, arg0.get(), arg1);
  return PyByteArray_FromTWData(result);
}

// method function for SignAsDER
// TWData* TWPrivateKeySignAsDER(struct TWPrivateKey* pk, TWData* digest, enum
// TWCurve curve);
static PyObject* PyPrivateKeySignAsDER(PyPrivateKeyObject* self,
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

  if (!PyCurve_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Curve");
    return nullptr;
  }
  auto arg1 = PyCurve_GetTWCurve(args[1]);

  TWDataPtr result = TWPrivateKeySignAsDER(self->value, arg0.get(), arg1);
  return PyByteArray_FromTWData(result);
}

// method function for SignSchnorr
// TWData* TWPrivateKeySignSchnorr(struct TWPrivateKey* pk, TWData* message,
// enum TWCurve curve);
static PyObject* PyPrivateKeySignSchnorr(PyPrivateKeyObject* self,
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

  if (!PyCurve_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Curve");
    return nullptr;
  }
  auto arg1 = PyCurve_GetTWCurve(args[1]);

  TWDataPtr result = TWPrivateKeySignSchnorr(self->value, arg0.get(), arg1);
  return PyByteArray_FromTWData(result);
}

// static method function for Create
// struct TWPrivateKey* TWPrivateKeyCreate();
static PyObject* PyPrivateKeyCreate(PyPrivateKeyObject* self,
                                    PyObject* const* args,
                                    Py_ssize_t nargs) {
  if (nargs != 0) {
    PyErr_Format(PyExc_TypeError, "Expect 0 instead of %d.", nargs);
    return nullptr;
  }

  TWPrivateKey* result = TWPrivateKeyCreate();
  return PyPrivateKey_FromTWPrivateKey(result);
}

// static method function for CreateWithData
// struct TWPrivateKey* TWPrivateKeyCreateWithData(TWData* data);
static PyObject* PyPrivateKeyCreateWithData(PyPrivateKeyObject* self,
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

  TWPrivateKey* result = TWPrivateKeyCreateWithData(arg0.get());
  return PyPrivateKey_FromTWPrivateKey(result);
}

// static method function for CreateCopy
// struct TWPrivateKey* TWPrivateKeyCreateCopy(struct TWPrivateKey* key);
static PyObject* PyPrivateKeyCreateCopy(PyPrivateKeyObject* self,
                                        PyObject* const* args,
                                        Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyPrivateKey_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type PrivateKey");
    return nullptr;
  }
  auto arg0 = PyPrivateKey_GetTWPrivateKey(args[0]);

  TWPrivateKey* result = TWPrivateKeyCreateCopy(arg0);
  return PyPrivateKey_FromTWPrivateKey(result);
}

// static method function for IsValid
// bool TWPrivateKeyIsValid(TWData* data, enum TWCurve curve);
static PyObject* PyPrivateKeyIsValid(PyPrivateKeyObject* self,
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

  if (!PyCurve_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Curve");
    return nullptr;
  }
  auto arg1 = PyCurve_GetTWCurve(args[1]);

  bool result = TWPrivateKeyIsValid(arg0.get(), arg1);
  return PyBool_FromLong(result);
}

static const PyGetSetDef get_set_defs[] = {{}};

static const PyMethodDef method_defs[] = {
    {"Delete", (PyCFunction)PyPrivateKeyDelete, METH_FASTCALL},
    {"GetPublicKeySecp256k1", (PyCFunction)PyPrivateKeyGetPublicKeySecp256k1,
     METH_FASTCALL},
    {"GetPublicKeyNist256p1", (PyCFunction)PyPrivateKeyGetPublicKeyNist256p1,
     METH_FASTCALL},
    {"GetPublicKeyEd25519", (PyCFunction)PyPrivateKeyGetPublicKeyEd25519,
     METH_FASTCALL},
    {"GetPublicKeyEd25519Blake2b",
     (PyCFunction)PyPrivateKeyGetPublicKeyEd25519Blake2b, METH_FASTCALL},
    {"GetPublicKeyEd25519Extended",
     (PyCFunction)PyPrivateKeyGetPublicKeyEd25519Extended, METH_FASTCALL},
    {"GetPublicKeyCurve25519", (PyCFunction)PyPrivateKeyGetPublicKeyCurve25519,
     METH_FASTCALL},
    {"GetSharedKey", (PyCFunction)PyPrivateKeyGetSharedKey, METH_FASTCALL},
    {"Sign", (PyCFunction)PyPrivateKeySign, METH_FASTCALL},
    {"SignAsDER", (PyCFunction)PyPrivateKeySignAsDER, METH_FASTCALL},
    {"SignSchnorr", (PyCFunction)PyPrivateKeySignSchnorr, METH_FASTCALL},
    {"Create", (PyCFunction)PyPrivateKeyCreate, METH_FASTCALL | METH_STATIC},
    {"CreateWithData", (PyCFunction)PyPrivateKeyCreateWithData,
     METH_FASTCALL | METH_STATIC},
    {"CreateCopy", (PyCFunction)PyPrivateKeyCreateCopy,
     METH_FASTCALL | METH_STATIC},
    {"IsValid", (PyCFunction)PyPrivateKeyIsValid, METH_FASTCALL | METH_STATIC},
    {}};

bool PyInit_PrivateKey(PyObject* module) {
  // PyPrivateKeyType.tp_new = PyPrivateKey_new;
  // PyPrivateKeyType.tp_init = (initproc)PyPrivateKey_init;
  // PyPrivateKeyType.tp_str = (reprfunc)PyPrivateKey_str;
  PyPrivateKeyType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyPrivateKeyType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyPrivateKeyType) < 0)
    return false;

  Py_INCREF(&PyPrivateKeyType);
  if (PyModule_AddObject(module, "PrivateKey", (PyObject*)&PyPrivateKeyType) <
      0) {
    Py_DECREF(&PyPrivateKeyType);
    return false;
  }

  return true;
}