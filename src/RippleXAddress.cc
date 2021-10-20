// This is a GENERATED FILE, changes made here WILL BE LOST.

#include "RippleXAddress.h"

static PyTypeObject PyRippleXAddressType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.RippleXAddress",    /* tp_name */
    sizeof(PyRippleXAddressObject), /* tp_basicsize */
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

bool PyRippleXAddress_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyRippleXAddressType) != 0;
}

// Create PyRippleXAddress from enum TWRippleXAddress.
PyObject* PyRippleXAddress_FromTWRippleXAddress(TWRippleXAddress* value) {
  if (!value)
    return nullptr;

  PyRippleXAddressObject* object =
      PyObject_New(PyRippleXAddressObject, &PyRippleXAddressType);
  if (!object)
    return nullptr;

  object->value = value;

  return (PyObject*)object;
}

// static int PyRippleXAddress_init(PyRippleXAddressObject *self, PyObject
// *args, PyObject *kwds) {
//   return 0;
// }

// static PyObject* PyRippleXAddress_new(PyTypeObject *subtype, PyObject *args,
// PyObject *kwds) {
//   int value = 0;
//   if (!PyArg_ParseTuple(args, "|i", &value)) {
//     return nullptr;
//   }
//   return PyRippleXAddress_FromTWRippleXAddress((TWRippleXAddress)value);
// }

// static PyObject* PyRippleXAddress_str(PyRippleXAddressObject *self) {
//   const char* str = "Unknown";
//   return PyUnicode_FromString(str);
// }

// getter function for Tag
static PyObject* PyRippleXAddressTag(PyRippleXAddressObject* self, void*) {
  return PyLong_FromLong(TWRippleXAddressTag(self->value));
}

static const PyGetSetDef get_set_defs[] = {{"Tag", (getter)PyRippleXAddressTag},
                                           {}};

static const PyMethodDef method_defs[] = {{}};

bool PyInit_RippleXAddress(PyObject* module) {
  // PyRippleXAddressType.tp_new = PyRippleXAddress_new;
  // PyRippleXAddressType.tp_init = (initproc)PyRippleXAddress_init;
  // PyRippleXAddressType.tp_str = (reprfunc)PyRippleXAddress_str;
  PyRippleXAddressType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyRippleXAddressType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyRippleXAddressType) < 0)
    return false;

  Py_INCREF(&PyRippleXAddressType);
  if (PyModule_AddObject(module, "RippleXAddress",
                         (PyObject*)&PyRippleXAddressType) < 0) {
    Py_DECREF(&PyRippleXAddressType);
    return false;
  }

  return true;
}