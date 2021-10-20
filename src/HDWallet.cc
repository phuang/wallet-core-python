// This is a GENERATED FILE, changes made here WILL BE LOST.

#include "HDWallet.h"

static PyTypeObject PyHDWalletType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.HDWallet",    /* tp_name */
    sizeof(PyHDWalletObject), /* tp_basicsize */
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

bool PyHDWallet_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyHDWalletType) != 0;
}

// Create PyHDWallet from enum TWHDWallet.
PyObject* PyHDWallet_FromTWHDWallet(TWHDWallet* value) {
  if (!value)
    return nullptr;

  PyHDWalletObject* object = PyObject_New(PyHDWalletObject, &PyHDWalletType);
  if (!object)
    return nullptr;

  object->value = value;

  return (PyObject*)object;
}

// static int PyHDWallet_init(PyHDWalletObject *self, PyObject *args, PyObject
// *kwds) {
//   return 0;
// }

// static PyObject* PyHDWallet_new(PyTypeObject *subtype, PyObject *args,
// PyObject *kwds) {
//   int value = 0;
//   if (!PyArg_ParseTuple(args, "|i", &value)) {
//     return nullptr;
//   }
//   return PyHDWallet_FromTWHDWallet((TWHDWallet)value);
// }

// static PyObject* PyHDWallet_str(PyHDWalletObject *self) {
//   const char* str = "Unknown";
//   return PyUnicode_FromString(str);
// }

static const PyGetSetDef get_set_defs[] = {{}};

static const PyMethodDef method_defs[] = {{}};

bool PyInit_HDWallet(PyObject* module) {
  // PyHDWalletType.tp_new = PyHDWallet_new;
  // PyHDWalletType.tp_init = (initproc)PyHDWallet_init;
  // PyHDWalletType.tp_str = (reprfunc)PyHDWallet_str;
  PyHDWalletType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyHDWalletType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyHDWalletType) < 0)
    return false;

  Py_INCREF(&PyHDWalletType);
  if (PyModule_AddObject(module, "HDWallet", (PyObject*)&PyHDWalletType) < 0) {
    Py_DECREF(&PyHDWalletType);
    return false;
  }

  return true;
}