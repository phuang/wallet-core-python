// This is a GENERATED FILE, changes made here WILL BE LOST.

#include "NEARAccount.h"

static PyTypeObject PyNEARAccountType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.NEARAccount",    /* tp_name */
    sizeof(PyNEARAccountObject), /* tp_basicsize */
    0,                           /* tp_itemsize */
    0,                           /* tp_dealloc */
    0,                           /* tp_print */
    0,                           /* tp_getattr */
    0,                           /* tp_setattr */
    0,                           /* tp_reserved */
    0,                           /* tp_repr */
    0,                           /* tp_as_number */
    0,                           /* tp_as_sequence */
    0,                           /* tp_as_mapping */
    0,                           /* tp_hash  */
    0,                           /* tp_call */
    0,                           /* tp_str */
    0,                           /* tp_getattro */
    0,                           /* tp_setattro */
    0,                           /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,          /* tp_flags */
    nullptr,                     /* tp_doc */
};

bool PyNEARAccount_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyNEARAccountType) != 0;
}

// Create PyNEARAccount from enum TWNEARAccount.
PyObject* PyNEARAccount_FromTWNEARAccount(TWNEARAccount* value) {
  if (!value)
    return nullptr;

  PyNEARAccountObject* object =
      PyObject_New(PyNEARAccountObject, &PyNEARAccountType);
  if (!object)
    return nullptr;

  object->value = value;

  return (PyObject*)object;
}

// static int PyNEARAccount_init(PyNEARAccountObject *self, PyObject *args,
// PyObject *kwds) {
//   return 0;
// }

// static PyObject* PyNEARAccount_new(PyTypeObject *subtype, PyObject *args,
// PyObject *kwds) {
//   int value = 0;
//   if (!PyArg_ParseTuple(args, "|i", &value)) {
//     return nullptr;
//   }
//   return PyNEARAccount_FromTWNEARAccount((TWNEARAccount)value);
// }

// static PyObject* PyNEARAccount_str(PyNEARAccountObject *self) {
//   const char* str = "Unknown";
//   return PyUnicode_FromString(str);
// }

static const PyGetSetDef get_set_defs[] = {{}};

static const PyMethodDef method_defs[] = {{}};

bool PyInit_NEARAccount(PyObject* module) {
  // PyNEARAccountType.tp_new = PyNEARAccount_new;
  // PyNEARAccountType.tp_init = (initproc)PyNEARAccount_init;
  // PyNEARAccountType.tp_str = (reprfunc)PyNEARAccount_str;
  PyNEARAccountType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyNEARAccountType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyNEARAccountType) < 0)
    return false;

  Py_INCREF(&PyNEARAccountType);
  if (PyModule_AddObject(module, "NEARAccount", (PyObject*)&PyNEARAccountType) <
      0) {
    Py_DECREF(&PyNEARAccountType);
    return false;
  }

  return true;
}