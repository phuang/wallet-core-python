// This is a GENERATED FILE, changes made here WILL BE LOST.

#include "Mnemonic.h"

static PyTypeObject PyMnemonicType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.Mnemonic",    /* tp_name */
    sizeof(PyMnemonicObject), /* tp_basicsize */
    0,                        /* tp_itemsize */
    0,                        /* tp_dealloc */
    0,                        /* tp_print */
    0,                        /* tp_getattr */
    0,                        /* tp_setattr */
    0,                        /* tp_reserved */
    0,                        /* tp_repr */
    0,                        /* tp_as_number */
    0,                        /* tp_as_sequence */
    0,                        /* tp_as_mapping */
    0,                        /* tp_hash  */
    0,                        /* tp_call */
    0,                        /* tp_str */
    0,                        /* tp_getattro */
    0,                        /* tp_setattro */
    0,                        /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,       /* tp_flags */
    nullptr,                  /* tp_doc */
};

bool PyMnemonic_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyMnemonicType) != 0;
}

// Create PyMnemonic from enum TWMnemonic.
PyObject* PyMnemonic_FromTWMnemonic(TWMnemonic* value) {
  if (!value)
    return nullptr;

  PyMnemonicObject* object = PyObject_New(PyMnemonicObject, &PyMnemonicType);
  if (!object)
    return nullptr;

  object->value = value;

  return (PyObject*)object;
}

// static int PyMnemonic_init(PyMnemonicObject *self, PyObject *args, PyObject
// *kwds) {
//   return 0;
// }

// static PyObject* PyMnemonic_new(PyTypeObject *subtype, PyObject *args,
// PyObject *kwds) {
//   int value = 0;
//   if (!PyArg_ParseTuple(args, "|i", &value)) {
//     return nullptr;
//   }
//   return PyMnemonic_FromTWMnemonic((TWMnemonic)value);
// }

// static PyObject* PyMnemonic_str(PyMnemonicObject *self) {
//   const char* str = "Unknown";
//   return PyUnicode_FromString(str);
// }

static const PyGetSetDef get_set_defs[] = {{}};

static const PyMethodDef method_defs[] = {{}};

bool PyInit_Mnemonic(PyObject* module) {
  // PyMnemonicType.tp_new = PyMnemonic_new;
  // PyMnemonicType.tp_init = (initproc)PyMnemonic_init;
  // PyMnemonicType.tp_str = (reprfunc)PyMnemonic_str;
  PyMnemonicType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyMnemonicType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyMnemonicType) < 0)
    return false;

  Py_INCREF(&PyMnemonicType);
  if (PyModule_AddObject(module, "Mnemonic", (PyObject*)&PyMnemonicType) < 0) {
    Py_DECREF(&PyMnemonicType);
    return false;
  }

  return true;
}