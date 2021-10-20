// This is a GENERATED FILE, changes made here WILL BE LOST.

#include "Mnemonic.h"

#include "String.h"

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

TWMnemonic* PyMnemonic_GetTWMnemonic(PyObject* object) {
  assert(PyMnemonic_Check(object));
  return ((PyMnemonicObject*)object)->value;
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

// static method function for IsValid
// bool TWMnemonicIsValid(TWString* mnemonic);
static PyObject* PyMnemonicIsValid(PyMnemonicObject* self,
                                   PyObject* const* args,
                                   Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyUnicode_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Unicode");
    return nullptr;
  }
  auto arg0 = PyUnicode_GetTWString(args[0]);

  bool result = TWMnemonicIsValid(arg0.get());
  return PyBool_FromLong(result);
}

// static method function for IsValidWord
// bool TWMnemonicIsValidWord(TWString* word);
static PyObject* PyMnemonicIsValidWord(PyMnemonicObject* self,
                                       PyObject* const* args,
                                       Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyUnicode_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Unicode");
    return nullptr;
  }
  auto arg0 = PyUnicode_GetTWString(args[0]);

  bool result = TWMnemonicIsValidWord(arg0.get());
  return PyBool_FromLong(result);
}

// static method function for Suggest
// TWString* TWMnemonicSuggest(TWString* prefix);
static PyObject* PyMnemonicSuggest(PyMnemonicObject* self,
                                   PyObject* const* args,
                                   Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyUnicode_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Unicode");
    return nullptr;
  }
  auto arg0 = PyUnicode_GetTWString(args[0]);

  TWStringPtr result = TWMnemonicSuggest(arg0.get());
  return PyUnicode_FromTWString(result);
}

static const PyGetSetDef get_set_defs[] = {{}};

static const PyMethodDef method_defs[] = {
    {"IsValid", (PyCFunction)PyMnemonicIsValid, METH_FASTCALL | METH_STATIC},
    {"IsValidWord", (PyCFunction)PyMnemonicIsValidWord,
     METH_FASTCALL | METH_STATIC},
    {"Suggest", (PyCFunction)PyMnemonicSuggest, METH_FASTCALL | METH_STATIC},
    {}};

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