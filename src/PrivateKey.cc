// This is a GENERATED FILE, changes made here WILL BE LOST.

#include "PrivateKey.h"

static PyTypeObject PyPrivateKeyType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.PrivateKey",    /* tp_name */
    sizeof(PyPrivateKeyObject), /* tp_basicsize */
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

bool PyPrivateKey_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyPrivateKeyType) != 0;
}

// Create PyPrivateKey from enum TWPrivateKey.
PyObject* PyPrivateKey_FromTWPrivateKey(TWPrivateKey* value) {
  if (!value)
    return nullptr;

  PyPrivateKeyObject* object =
      PyObject_New(PyPrivateKeyObject, &PyPrivateKeyType);
  if (!object)
    return nullptr;

  object->value = value;

  return (PyObject*)object;
}

// static int PyPrivateKey_init(PyPrivateKeyObject *self, PyObject *args,
// PyObject *kwds) {
//   return 0;
// }

// static PyObject* PyPrivateKey_new(PyTypeObject *subtype, PyObject *args,
// PyObject *kwds) {
//   int value = 0;
//   if (!PyArg_ParseTuple(args, "|i", &value)) {
//     return nullptr;
//   }
//   return PyPrivateKey_FromTWPrivateKey((TWPrivateKey)value);
// }

// static PyObject* PyPrivateKey_str(PyPrivateKeyObject *self) {
//   const char* str = "Unknown";
//   return PyUnicode_FromString(str);
// }

static const PyGetSetDef get_set_defs[] = {{}};

static const PyMethodDef method_defs[] = {{}};

bool PyInit_PrivateKey(PyObject* module) {
  // PyPrivateKeyType.tp_new = PyPrivateKey_new;
  // PyPrivateKeyType.tp_init = (initproc)PyPrivateKey_init;
  // PyPrivateKeyType.tp_str = (reprfunc)PyPrivateKey_str;
  PyPrivateKeyType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyPrivateKeyType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyPrivateKeyType) < 0)
    return false;

  Py_INCREF(&PyPrivateKeyType);
  if (PyModule_AddObject(module, "PrivateKey", (PyObject*)&PyPrivateKeyType) <
      0) {
    Py_DECREF(&PyPrivateKeyType);
    return false;
  }

  return true;
}