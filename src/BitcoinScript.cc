// This is a GENERATED FILE, changes made here WILL BE LOST.

#include "BitcoinScript.h"

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
static PyObject* PyBitcoinScriptIsPayToScriptHash(PyBitcoinScriptObject* self,
                                                  void*) {
  return PyBool_FromLong(TWBitcoinScriptIsPayToScriptHash(self->value));
}

// getter function for IsPayToWitnessScriptHash
static PyObject* PyBitcoinScriptIsPayToWitnessScriptHash(
    PyBitcoinScriptObject* self,
    void*) {
  return PyBool_FromLong(TWBitcoinScriptIsPayToWitnessScriptHash(self->value));
}

// getter function for IsPayToWitnessPublicKeyHash
static PyObject* PyBitcoinScriptIsPayToWitnessPublicKeyHash(
    PyBitcoinScriptObject* self,
    void*) {
  return PyBool_FromLong(
      TWBitcoinScriptIsPayToWitnessPublicKeyHash(self->value));
}

// getter function for IsWitnessProgram
static PyObject* PyBitcoinScriptIsWitnessProgram(PyBitcoinScriptObject* self,
                                                 void*) {
  return PyBool_FromLong(TWBitcoinScriptIsWitnessProgram(self->value));
}

static const PyGetSetDef get_set_defs[] = {
    {"IsPayToScriptHash", (getter)PyBitcoinScriptIsPayToScriptHash},
    {"IsPayToWitnessScriptHash",
     (getter)PyBitcoinScriptIsPayToWitnessScriptHash},
    {"IsPayToWitnessPublicKeyHash",
     (getter)PyBitcoinScriptIsPayToWitnessPublicKeyHash},
    {"IsWitnessProgram", (getter)PyBitcoinScriptIsWitnessProgram},
    {}};

static const PyMethodDef method_defs[] = {{}};

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