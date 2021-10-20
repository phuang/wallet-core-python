// This is a GENERATED FILE, changes made here WILL BE LOST.

#include "FIOAccount.h"

static PyTypeObject PyFIOAccountType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.FIOAccount",    /* tp_name */
    sizeof(PyFIOAccountObject), /* tp_basicsize */
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

bool PyFIOAccount_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyFIOAccountType) != 0;
}

// Create PyFIOAccount from enum TWFIOAccount.
PyObject* PyFIOAccount_FromTWFIOAccount(TWFIOAccount* value) {
  if (!value)
    return nullptr;

  PyFIOAccountObject* object =
      PyObject_New(PyFIOAccountObject, &PyFIOAccountType);
  if (!object)
    return nullptr;

  object->value = value;

  return (PyObject*)object;
}

TWFIOAccount* PyFIOAccount_GetTWFIOAccount(PyObject* object) {
  assert(PyFIOAccount_Check(object));
  return ((PyFIOAccountObject*)object)->value;
}

// static int PyFIOAccount_init(PyFIOAccountObject *self, PyObject *args,
// PyObject *kwds) {
//   return 0;
// }

// static PyObject* PyFIOAccount_new(PyTypeObject *subtype, PyObject *args,
// PyObject *kwds) {
//   int value = 0;
//   if (!PyArg_ParseTuple(args, "|i", &value)) {
//     return nullptr;
//   }
//   return PyFIOAccount_FromTWFIOAccount((TWFIOAccount)value);
// }

// static PyObject* PyFIOAccount_str(PyFIOAccountObject *self) {
//   const char* str = "Unknown";
//   return PyUnicode_FromString(str);
// }

static const PyGetSetDef get_set_defs[] = {{}};

static const PyMethodDef method_defs[] = {{}};

bool PyInit_FIOAccount(PyObject* module) {
  // PyFIOAccountType.tp_new = PyFIOAccount_new;
  // PyFIOAccountType.tp_init = (initproc)PyFIOAccount_init;
  // PyFIOAccountType.tp_str = (reprfunc)PyFIOAccount_str;
  PyFIOAccountType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyFIOAccountType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyFIOAccountType) < 0)
    return false;

  Py_INCREF(&PyFIOAccountType);
  if (PyModule_AddObject(module, "FIOAccount", (PyObject*)&PyFIOAccountType) <
      0) {
    Py_DECREF(&PyFIOAccountType);
    return false;
  }

  return true;
}