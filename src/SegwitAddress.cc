// This is a GENERATED FILE, changes made here WILL BE LOST.

#include "SegwitAddress.h"

#include "HRP.h"

static PyTypeObject PySegwitAddressType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.SegwitAddress",    /* tp_name */
    sizeof(PySegwitAddressObject), /* tp_basicsize */
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

bool PySegwitAddress_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PySegwitAddressType) != 0;
}

// Create PySegwitAddress from enum TWSegwitAddress.
PyObject* PySegwitAddress_FromTWSegwitAddress(TWSegwitAddress* value) {
  if (!value)
    return nullptr;

  PySegwitAddressObject* object =
      PyObject_New(PySegwitAddressObject, &PySegwitAddressType);
  if (!object)
    return nullptr;

  object->value = value;

  return (PyObject*)object;
}

// static int PySegwitAddress_init(PySegwitAddressObject *self, PyObject *args,
// PyObject *kwds) {
//   return 0;
// }

// static PyObject* PySegwitAddress_new(PyTypeObject *subtype, PyObject *args,
// PyObject *kwds) {
//   int value = 0;
//   if (!PyArg_ParseTuple(args, "|i", &value)) {
//     return nullptr;
//   }
//   return PySegwitAddress_FromTWSegwitAddress((TWSegwitAddress)value);
// }

// static PyObject* PySegwitAddress_str(PySegwitAddressObject *self) {
//   const char* str = "Unknown";
//   return PyUnicode_FromString(str);
// }

// getter function for HRP
static PyObject* PySegwitAddressHRP(PySegwitAddressObject* self, void*) {
  return PyHRP_FromTWHRP(TWSegwitAddressHRP(self->value));
}

static const PyGetSetDef get_set_defs[] = {{"HRP", (getter)PySegwitAddressHRP},
                                           {}};

static const PyMethodDef method_defs[] = {{}};

bool PyInit_SegwitAddress(PyObject* module) {
  // PySegwitAddressType.tp_new = PySegwitAddress_new;
  // PySegwitAddressType.tp_init = (initproc)PySegwitAddress_init;
  // PySegwitAddressType.tp_str = (reprfunc)PySegwitAddress_str;
  PySegwitAddressType.tp_getset = (PyGetSetDef*)get_set_defs;
  PySegwitAddressType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PySegwitAddressType) < 0)
    return false;

  Py_INCREF(&PySegwitAddressType);
  if (PyModule_AddObject(module, "SegwitAddress",
                         (PyObject*)&PySegwitAddressType) < 0) {
    Py_DECREF(&PySegwitAddressType);
    return false;
  }

  return true;
}