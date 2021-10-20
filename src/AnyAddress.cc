// This is a GENERATED FILE, changes made here WILL BE LOST.

#include "AnyAddress.h"

#include "CoinType.h"

static PyTypeObject PyAnyAddressType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.AnyAddress",    /* tp_name */
    sizeof(PyAnyAddressObject), /* tp_basicsize */
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

bool PyAnyAddress_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyAnyAddressType) != 0;
}

// Create PyAnyAddress from enum TWAnyAddress.
PyObject* PyAnyAddress_FromTWAnyAddress(TWAnyAddress* value) {
  if (!value)
    return nullptr;

  PyAnyAddressObject* object =
      PyObject_New(PyAnyAddressObject, &PyAnyAddressType);
  if (!object)
    return nullptr;

  object->value = value;

  return (PyObject*)object;
}

// static int PyAnyAddress_init(PyAnyAddressObject *self, PyObject *args,
// PyObject *kwds) {
//   return 0;
// }

// static PyObject* PyAnyAddress_new(PyTypeObject *subtype, PyObject *args,
// PyObject *kwds) {
//   int value = 0;
//   if (!PyArg_ParseTuple(args, "|i", &value)) {
//     return nullptr;
//   }
//   return PyAnyAddress_FromTWAnyAddress((TWAnyAddress)value);
// }

// static PyObject* PyAnyAddress_str(PyAnyAddressObject *self) {
//   const char* str = "Unknown";
//   return PyUnicode_FromString(str);
// }

// getter function for Coin
static PyObject* PyAnyAddressCoin(PyAnyAddressObject* self, void*) {
  return PyCoinType_FromTWCoinType(TWAnyAddressCoin(self->value));
}

static const PyGetSetDef get_set_defs[] = {{"Coin", (getter)PyAnyAddressCoin},
                                           {}};

static const PyMethodDef method_defs[] = {{}};

bool PyInit_AnyAddress(PyObject* module) {
  // PyAnyAddressType.tp_new = PyAnyAddress_new;
  // PyAnyAddressType.tp_init = (initproc)PyAnyAddress_init;
  // PyAnyAddressType.tp_str = (reprfunc)PyAnyAddress_str;
  PyAnyAddressType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyAnyAddressType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyAnyAddressType) < 0)
    return false;

  Py_INCREF(&PyAnyAddressType);
  if (PyModule_AddObject(module, "AnyAddress", (PyObject*)&PyAnyAddressType) <
      0) {
    Py_DECREF(&PyAnyAddressType);
    return false;
  }

  return true;
}