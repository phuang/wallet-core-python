// This is a GENERATED FILE, changes made here WILL BE LOST.

#include "GroestlcoinAddress.h"

static PyTypeObject PyGroestlcoinAddressType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.GroestlcoinAddress",    /* tp_name */
    sizeof(PyGroestlcoinAddressObject), /* tp_basicsize */
    0,                                  /* tp_itemsize */
    0,                                  /* tp_dealloc */
    0,                                  /* tp_print */
    0,                                  /* tp_getattr */
    0,                                  /* tp_setattr */
    0,                                  /* tp_reserved */
    0,                                  /* tp_repr */
    0,                                  /* tp_as_number */
    0,                                  /* tp_as_sequence */
    0,                                  /* tp_as_mapping */
    0,                                  /* tp_hash  */
    0,                                  /* tp_call */
    0,                                  /* tp_str */
    0,                                  /* tp_getattro */
    0,                                  /* tp_setattro */
    0,                                  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                 /* tp_flags */
    nullptr,                            /* tp_doc */
};

bool PyGroestlcoinAddress_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyGroestlcoinAddressType) != 0;
}

// Create PyGroestlcoinAddress from enum TWGroestlcoinAddress.
PyObject* PyGroestlcoinAddress_FromTWGroestlcoinAddress(
    TWGroestlcoinAddress* value) {
  if (!value)
    return nullptr;

  PyGroestlcoinAddressObject* object =
      PyObject_New(PyGroestlcoinAddressObject, &PyGroestlcoinAddressType);
  if (!object)
    return nullptr;

  object->value = value;

  return (PyObject*)object;
}

// static int PyGroestlcoinAddress_init(PyGroestlcoinAddressObject *self,
// PyObject *args, PyObject *kwds) {
//   return 0;
// }

// static PyObject* PyGroestlcoinAddress_new(PyTypeObject *subtype, PyObject
// *args, PyObject *kwds) {
//   int value = 0;
//   if (!PyArg_ParseTuple(args, "|i", &value)) {
//     return nullptr;
//   }
//   return
//   PyGroestlcoinAddress_FromTWGroestlcoinAddress((TWGroestlcoinAddress)value);
// }

// static PyObject* PyGroestlcoinAddress_str(PyGroestlcoinAddressObject *self) {
//   const char* str = "Unknown";
//   return PyUnicode_FromString(str);
// }

static const PyGetSetDef get_set_defs[] = {{}};

static const PyMethodDef method_defs[] = {{}};

bool PyInit_GroestlcoinAddress(PyObject* module) {
  // PyGroestlcoinAddressType.tp_new = PyGroestlcoinAddress_new;
  // PyGroestlcoinAddressType.tp_init = (initproc)PyGroestlcoinAddress_init;
  // PyGroestlcoinAddressType.tp_str = (reprfunc)PyGroestlcoinAddress_str;
  PyGroestlcoinAddressType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyGroestlcoinAddressType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyGroestlcoinAddressType) < 0)
    return false;

  Py_INCREF(&PyGroestlcoinAddressType);
  if (PyModule_AddObject(module, "GroestlcoinAddress",
                         (PyObject*)&PyGroestlcoinAddressType) < 0) {
    Py_DECREF(&PyGroestlcoinAddressType);
    return false;
  }

  return true;
}