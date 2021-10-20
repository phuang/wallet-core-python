// This is a GENERATED FILE, changes made here WILL BE LOST.

#include "BitcoinScript.h"

#include "CoinType.h"
#include "Data.h"
#include "String.h"

static PyTypeObject PyBitcoinScriptType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.BitcoinScript",    /* tp_name */
    sizeof(PyBitcoinScriptObject), /* tp_basicsize */
    0,                             /* tp_itemsize */
    0,                             /* tp_dealloc */
    0,                             /* tp_print */
    0,                             /* tp_getattr */
    0,                             /* tp_setattr */
    0,                             /* tp_reserved */
    0,                             /* tp_repr */
    0,                             /* tp_as_number */
    0,                             /* tp_as_sequence */
    0,                             /* tp_as_mapping */
    0,                             /* tp_hash  */
    0,                             /* tp_call */
    0,                             /* tp_str */
    0,                             /* tp_getattro */
    0,                             /* tp_setattro */
    0,                             /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,            /* tp_flags */
    nullptr,                       /* tp_doc */
};

bool PyBitcoinScript_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyBitcoinScriptType) != 0;
}

// Create PyBitcoinScript from enum TWBitcoinScript.
PyObject* PyBitcoinScript_FromTWBitcoinScript(TWBitcoinScript* value) {
  if (!value)
    return nullptr;

  PyBitcoinScriptObject* object =
      PyObject_New(PyBitcoinScriptObject, &PyBitcoinScriptType);
  if (!object)
    return nullptr;

  object->value = value;

  return (PyObject*)object;
}

TWBitcoinScript* PyBitcoinScript_GetTWBitcoinScript(PyObject* object) {
  assert(PyBitcoinScript_Check(object));
  return ((PyBitcoinScriptObject*)object)->value;
}

// static int PyBitcoinScript_init(PyBitcoinScriptObject *self, PyObject *args,
// PyObject *kwds) {
//   return 0;
// }

// static PyObject* PyBitcoinScript_new(PyTypeObject *subtype, PyObject *args,
// PyObject *kwds) {
//   int value = 0;
//   if (!PyArg_ParseTuple(args, "|i", &value)) {
//     return nullptr;
//   }
//   return PyBitcoinScript_FromTWBitcoinScript((TWBitcoinScript)value);
// }

// static PyObject* PyBitcoinScript_str(PyBitcoinScriptObject *self) {
//   const char* str = "Unknown";
//   return PyUnicode_FromString(str);
// }

// getter function for IsPayToScriptHash
// bool TWBitcoinScriptIsPayToScriptHash(const struct TWBitcoinScript* script);
static PyObject* PyBitcoinScriptIsPayToScriptHash(PyBitcoinScriptObject* self,
                                                  void*) {
  return PyBool_FromLong(TWBitcoinScriptIsPayToScriptHash(self->value));
}

// getter function for IsPayToWitnessScriptHash
// bool TWBitcoinScriptIsPayToWitnessScriptHash(const struct TWBitcoinScript*
// script);
static PyObject* PyBitcoinScriptIsPayToWitnessScriptHash(
    PyBitcoinScriptObject* self,
    void*) {
  return PyBool_FromLong(TWBitcoinScriptIsPayToWitnessScriptHash(self->value));
}

// getter function for IsPayToWitnessPublicKeyHash
// bool TWBitcoinScriptIsPayToWitnessPublicKeyHash(const struct TWBitcoinScript*
// script);
static PyObject* PyBitcoinScriptIsPayToWitnessPublicKeyHash(
    PyBitcoinScriptObject* self,
    void*) {
  return PyBool_FromLong(
      TWBitcoinScriptIsPayToWitnessPublicKeyHash(self->value));
}

// getter function for IsWitnessProgram
// bool TWBitcoinScriptIsWitnessProgram(const struct TWBitcoinScript* script);
static PyObject* PyBitcoinScriptIsWitnessProgram(PyBitcoinScriptObject* self,
                                                 void*) {
  return PyBool_FromLong(TWBitcoinScriptIsWitnessProgram(self->value));
}

// method function for Delete
// void TWBitcoinScriptDelete(struct TWBitcoinScript* script);
static PyObject* PyBitcoinScriptDelete(PyBitcoinScriptObject* self,
                                       PyObject* const* args,
                                       Py_ssize_t nargs) {
  if (nargs != 0) {
    PyErr_Format(PyExc_TypeError, "Expect 0 instead of %d.", nargs);
    return nullptr;
  }

  TWBitcoinScriptDelete(self->value);
  return nullptr;
}

// method function for MatchPayToPubkey
// TWData* TWBitcoinScriptMatchPayToPubkey(const struct TWBitcoinScript*
// script);
static PyObject* PyBitcoinScriptMatchPayToPubkey(PyBitcoinScriptObject* self,
                                                 PyObject* const* args,
                                                 Py_ssize_t nargs) {
  if (nargs != 0) {
    PyErr_Format(PyExc_TypeError, "Expect 0 instead of %d.", nargs);
    return nullptr;
  }

  TWDataPtr result = TWBitcoinScriptMatchPayToPubkey(self->value);
  return PyByteArray_FromTWData(result);
}

// method function for MatchPayToPubkeyHash
// TWData* TWBitcoinScriptMatchPayToPubkeyHash(const struct TWBitcoinScript*
// script);
static PyObject* PyBitcoinScriptMatchPayToPubkeyHash(
    PyBitcoinScriptObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 0) {
    PyErr_Format(PyExc_TypeError, "Expect 0 instead of %d.", nargs);
    return nullptr;
  }

  TWDataPtr result = TWBitcoinScriptMatchPayToPubkeyHash(self->value);
  return PyByteArray_FromTWData(result);
}

// method function for MatchPayToScriptHash
// TWData* TWBitcoinScriptMatchPayToScriptHash(const struct TWBitcoinScript*
// script);
static PyObject* PyBitcoinScriptMatchPayToScriptHash(
    PyBitcoinScriptObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 0) {
    PyErr_Format(PyExc_TypeError, "Expect 0 instead of %d.", nargs);
    return nullptr;
  }

  TWDataPtr result = TWBitcoinScriptMatchPayToScriptHash(self->value);
  return PyByteArray_FromTWData(result);
}

// method function for MatchPayToWitnessPublicKeyHash
// TWData* TWBitcoinScriptMatchPayToWitnessPublicKeyHash(const struct
// TWBitcoinScript* script);
static PyObject* PyBitcoinScriptMatchPayToWitnessPublicKeyHash(
    PyBitcoinScriptObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 0) {
    PyErr_Format(PyExc_TypeError, "Expect 0 instead of %d.", nargs);
    return nullptr;
  }

  TWDataPtr result = TWBitcoinScriptMatchPayToWitnessPublicKeyHash(self->value);
  return PyByteArray_FromTWData(result);
}

// method function for MatchPayToWitnessScriptHash
// TWData* TWBitcoinScriptMatchPayToWitnessScriptHash(const struct
// TWBitcoinScript* script);
static PyObject* PyBitcoinScriptMatchPayToWitnessScriptHash(
    PyBitcoinScriptObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 0) {
    PyErr_Format(PyExc_TypeError, "Expect 0 instead of %d.", nargs);
    return nullptr;
  }

  TWDataPtr result = TWBitcoinScriptMatchPayToWitnessScriptHash(self->value);
  return PyByteArray_FromTWData(result);
}

// method function for Encode
// TWData* TWBitcoinScriptEncode(const struct TWBitcoinScript* script);
static PyObject* PyBitcoinScriptEncode(PyBitcoinScriptObject* self,
                                       PyObject* const* args,
                                       Py_ssize_t nargs) {
  if (nargs != 0) {
    PyErr_Format(PyExc_TypeError, "Expect 0 instead of %d.", nargs);
    return nullptr;
  }

  TWDataPtr result = TWBitcoinScriptEncode(self->value);
  return PyByteArray_FromTWData(result);
}

// static method function for Create
// struct TWBitcoinScript* TWBitcoinScriptCreate();
static PyObject* PyBitcoinScriptCreate(PyBitcoinScriptObject* self,
                                       PyObject* const* args,
                                       Py_ssize_t nargs) {
  if (nargs != 0) {
    PyErr_Format(PyExc_TypeError, "Expect 0 instead of %d.", nargs);
    return nullptr;
  }

  TWBitcoinScript* result = TWBitcoinScriptCreate();
  return PyBitcoinScript_FromTWBitcoinScript(result);
}

// static method function for CreateWithData
// struct TWBitcoinScript* TWBitcoinScriptCreateWithData(TWData* data);
static PyObject* PyBitcoinScriptCreateWithData(PyBitcoinScriptObject* self,
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

  TWBitcoinScript* result = TWBitcoinScriptCreateWithData(arg0.get());
  return PyBitcoinScript_FromTWBitcoinScript(result);
}

// static method function for CreateCopy
// struct TWBitcoinScript* TWBitcoinScriptCreateCopy(const struct
// TWBitcoinScript* script);
static PyObject* PyBitcoinScriptCreateCopy(PyBitcoinScriptObject* self,
                                           PyObject* const* args,
                                           Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyBitcoinScript_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type BitcoinScript");
    return nullptr;
  }
  auto arg0 = PyBitcoinScript_GetTWBitcoinScript(args[0]);

  TWBitcoinScript* result = TWBitcoinScriptCreateCopy(arg0);
  return PyBitcoinScript_FromTWBitcoinScript(result);
}

// static method function for Equal
// bool TWBitcoinScriptEqual(const struct TWBitcoinScript* lhs, const struct
// TWBitcoinScript* rhs);
static PyObject* PyBitcoinScriptEqual(PyBitcoinScriptObject* self,
                                      PyObject* const* args,
                                      Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyBitcoinScript_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type BitcoinScript");
    return nullptr;
  }
  auto arg0 = PyBitcoinScript_GetTWBitcoinScript(args[0]);

  if (!PyBitcoinScript_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type BitcoinScript");
    return nullptr;
  }
  auto arg1 = PyBitcoinScript_GetTWBitcoinScript(args[1]);

  bool result = TWBitcoinScriptEqual(arg0, arg1);
  return PyBool_FromLong(result);
}

// static method function for BuildPayToPublicKey
// struct TWBitcoinScript* TWBitcoinScriptBuildPayToPublicKey(TWData* pubkey);
static PyObject* PyBitcoinScriptBuildPayToPublicKey(PyBitcoinScriptObject* self,
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

  TWBitcoinScript* result = TWBitcoinScriptBuildPayToPublicKey(arg0.get());
  return PyBitcoinScript_FromTWBitcoinScript(result);
}

// static method function for BuildPayToPublicKeyHash
// struct TWBitcoinScript* TWBitcoinScriptBuildPayToPublicKeyHash(TWData* hash);
static PyObject* PyBitcoinScriptBuildPayToPublicKeyHash(
    PyBitcoinScriptObject* self,
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

  TWBitcoinScript* result = TWBitcoinScriptBuildPayToPublicKeyHash(arg0.get());
  return PyBitcoinScript_FromTWBitcoinScript(result);
}

// static method function for BuildPayToScriptHash
// struct TWBitcoinScript* TWBitcoinScriptBuildPayToScriptHash(TWData*
// scriptHash);
static PyObject* PyBitcoinScriptBuildPayToScriptHash(
    PyBitcoinScriptObject* self,
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

  TWBitcoinScript* result = TWBitcoinScriptBuildPayToScriptHash(arg0.get());
  return PyBitcoinScript_FromTWBitcoinScript(result);
}

// static method function for BuildPayToWitnessPubkeyHash
// struct TWBitcoinScript* TWBitcoinScriptBuildPayToWitnessPubkeyHash(TWData*
// hash);
static PyObject* PyBitcoinScriptBuildPayToWitnessPubkeyHash(
    PyBitcoinScriptObject* self,
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

  TWBitcoinScript* result =
      TWBitcoinScriptBuildPayToWitnessPubkeyHash(arg0.get());
  return PyBitcoinScript_FromTWBitcoinScript(result);
}

// static method function for BuildPayToWitnessScriptHash
// struct TWBitcoinScript* TWBitcoinScriptBuildPayToWitnessScriptHash(TWData*
// scriptHash);
static PyObject* PyBitcoinScriptBuildPayToWitnessScriptHash(
    PyBitcoinScriptObject* self,
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

  TWBitcoinScript* result =
      TWBitcoinScriptBuildPayToWitnessScriptHash(arg0.get());
  return PyBitcoinScript_FromTWBitcoinScript(result);
}

// static method function for LockScriptForAddress
// struct TWBitcoinScript* TWBitcoinScriptLockScriptForAddress(TWString*
// address, enum TWCoinType coin);
static PyObject* PyBitcoinScriptLockScriptForAddress(
    PyBitcoinScriptObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyUnicode_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Unicode");
    return nullptr;
  }
  auto arg0 = PyUnicode_GetTWString(args[0]);

  if (!PyCoinType_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type CoinType");
    return nullptr;
  }
  auto arg1 = PyCoinType_GetTWCoinType(args[1]);

  TWBitcoinScript* result =
      TWBitcoinScriptLockScriptForAddress(arg0.get(), arg1);
  return PyBitcoinScript_FromTWBitcoinScript(result);
}

// static method function for HashTypeForCoin
// uint32_t TWBitcoinScriptHashTypeForCoin(enum TWCoinType coinType);
static PyObject* PyBitcoinScriptHashTypeForCoin(PyBitcoinScriptObject* self,
                                                PyObject* const* args,
                                                Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyCoinType_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type CoinType");
    return nullptr;
  }
  auto arg0 = PyCoinType_GetTWCoinType(args[0]);

  uint32_t result = TWBitcoinScriptHashTypeForCoin(arg0);
  return PyLong_FromLong(result);
}

static const PyGetSetDef get_set_defs[] = {
    {"IsPayToScriptHash", (getter)PyBitcoinScriptIsPayToScriptHash},
    {"IsPayToWitnessScriptHash",
     (getter)PyBitcoinScriptIsPayToWitnessScriptHash},
    {"IsPayToWitnessPublicKeyHash",
     (getter)PyBitcoinScriptIsPayToWitnessPublicKeyHash},
    {"IsWitnessProgram", (getter)PyBitcoinScriptIsWitnessProgram},
    {}};

static const PyMethodDef method_defs[] = {
    {"Delete", (PyCFunction)PyBitcoinScriptDelete, METH_FASTCALL},
    {"MatchPayToPubkey", (PyCFunction)PyBitcoinScriptMatchPayToPubkey,
     METH_FASTCALL},
    {"MatchPayToPubkeyHash", (PyCFunction)PyBitcoinScriptMatchPayToPubkeyHash,
     METH_FASTCALL},
    {"MatchPayToScriptHash", (PyCFunction)PyBitcoinScriptMatchPayToScriptHash,
     METH_FASTCALL},
    {"MatchPayToWitnessPublicKeyHash",
     (PyCFunction)PyBitcoinScriptMatchPayToWitnessPublicKeyHash, METH_FASTCALL},
    {"MatchPayToWitnessScriptHash",
     (PyCFunction)PyBitcoinScriptMatchPayToWitnessScriptHash, METH_FASTCALL},
    {"Encode", (PyCFunction)PyBitcoinScriptEncode, METH_FASTCALL},
    {"Create", (PyCFunction)PyBitcoinScriptCreate, METH_FASTCALL | METH_STATIC},
    {"CreateWithData", (PyCFunction)PyBitcoinScriptCreateWithData,
     METH_FASTCALL | METH_STATIC},
    {"CreateCopy", (PyCFunction)PyBitcoinScriptCreateCopy,
     METH_FASTCALL | METH_STATIC},
    {"Equal", (PyCFunction)PyBitcoinScriptEqual, METH_FASTCALL | METH_STATIC},
    {"BuildPayToPublicKey", (PyCFunction)PyBitcoinScriptBuildPayToPublicKey,
     METH_FASTCALL | METH_STATIC},
    {"BuildPayToPublicKeyHash",
     (PyCFunction)PyBitcoinScriptBuildPayToPublicKeyHash,
     METH_FASTCALL | METH_STATIC},
    {"BuildPayToScriptHash", (PyCFunction)PyBitcoinScriptBuildPayToScriptHash,
     METH_FASTCALL | METH_STATIC},
    {"BuildPayToWitnessPubkeyHash",
     (PyCFunction)PyBitcoinScriptBuildPayToWitnessPubkeyHash,
     METH_FASTCALL | METH_STATIC},
    {"BuildPayToWitnessScriptHash",
     (PyCFunction)PyBitcoinScriptBuildPayToWitnessScriptHash,
     METH_FASTCALL | METH_STATIC},
    {"LockScriptForAddress", (PyCFunction)PyBitcoinScriptLockScriptForAddress,
     METH_FASTCALL | METH_STATIC},
    {"HashTypeForCoin", (PyCFunction)PyBitcoinScriptHashTypeForCoin,
     METH_FASTCALL | METH_STATIC},
    {}};

bool PyInit_BitcoinScript(PyObject* module) {
  // PyBitcoinScriptType.tp_new = PyBitcoinScript_new;
  // PyBitcoinScriptType.tp_init = (initproc)PyBitcoinScript_init;
  // PyBitcoinScriptType.tp_str = (reprfunc)PyBitcoinScript_str;
  PyBitcoinScriptType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyBitcoinScriptType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyBitcoinScriptType) < 0)
    return false;

  Py_INCREF(&PyBitcoinScriptType);
  if (PyModule_AddObject(module, "BitcoinScript",
                         (PyObject*)&PyBitcoinScriptType) < 0) {
    Py_DECREF(&PyBitcoinScriptType);
    return false;
  }

  return true;
}