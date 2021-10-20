// This is a GENERATED FILE, changes made here WILL BE LOST.

#include "BitcoinAddress.h"

static PyTypeObject PyBitcoinAddressType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.BitcoinAddress",    /* tp_name */
    sizeof(PyBitcoinAddressObject), /* tp_basicsize */
    0,                              /* tp_itemsize */
    0,                              /* tp_dealloc */
    0,                              /* tp_print */
    0,                              /* tp_getattr */
    0,                              /* tp_setattr */
    0,                              /* tp_reserved */
    0,                              /* tp_repr */
    0,                              /* tp_as_number */
    0,                              /* tp_as_sequence */
    0,                              /* tp_as_mapping */
    0,                              /* tp_hash  */
    0,                              /* tp_call */
    0,                              /* tp_str */
    0,                              /* tp_getattro */
    0,                              /* tp_setattro */
    0,                              /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,             /* tp_flags */
    nullptr,                        /* tp_doc */
};

bool PyBitcoinAddress_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyBitcoinAddressType) != 0;
}

// Create PyBitcoinAddress from enum TWBitcoinAddress.
PyObject* PyBitcoinAddress_FromTWBitcoinAddress(TWBitcoinAddress* value) {
  if (!value)
    return nullptr;

  PyBitcoinAddressObject* object =
      PyObject_New(PyBitcoinAddressObject, &PyBitcoinAddressType);
  if (!object)
    return nullptr;

  object->value = value;

  return (PyObject*)object;
}

// static int PyBitcoinAddress_init(PyBitcoinAddressObject *self, PyObject
// *args, PyObject *kwds) {
//   return 0;
// }

// static PyObject* PyBitcoinAddress_new(PyTypeObject *subtype, PyObject *args,
// PyObject *kwds) {
//   int value = 0;
//   if (!PyArg_ParseTuple(args, "|i", &value)) {
//     return nullptr;
//   }
//   return PyBitcoinAddress_FromTWBitcoinAddress((TWBitcoinAddress)value);
// }

// static PyObject* PyBitcoinAddress_str(PyBitcoinAddressObject *self) {
//   const char* str = "Unknown";
//   return PyUnicode_FromString(str);
// }

// getter function for Prefix
static PyObject* PyBitcoinAddressPrefix(PyBitcoinAddressObject* self, void*) {
  return PyLong_FromLong(TWBitcoinAddressPrefix(self->value));
}

static const PyGetSetDef get_set_defs[] = {
    {"Prefix", (getter)PyBitcoinAddressPrefix},
    {}};

static const PyMethodDef method_defs[] = {{}};

bool PyInit_BitcoinAddress(PyObject* module) {
  // PyBitcoinAddressType.tp_new = PyBitcoinAddress_new;
  // PyBitcoinAddressType.tp_init = (initproc)PyBitcoinAddress_init;
  // PyBitcoinAddressType.tp_str = (reprfunc)PyBitcoinAddress_str;
  PyBitcoinAddressType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyBitcoinAddressType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyBitcoinAddressType) < 0)
    return false;

  Py_INCREF(&PyBitcoinAddressType);
  if (PyModule_AddObject(module, "BitcoinAddress",
                         (PyObject*)&PyBitcoinAddressType) < 0) {
    Py_DECREF(&PyBitcoinAddressType);
    return false;
  }

  return true;
}