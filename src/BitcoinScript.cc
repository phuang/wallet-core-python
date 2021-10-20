// This is a GENERATED FILE, changes made here WILL BE LOST.

#include "BitcoinScript.h"

#include "CoinType.h"

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
    {"Equal", (PyCFunction)PyBitcoinScriptEqual, METH_FASTCALL | METH_STATIC},
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