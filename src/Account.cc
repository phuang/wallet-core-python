// This is a GENERATED FILE, changes made here WILL BE LOST.

#include "Account.h"

#include "CoinType.h"

static PyTypeObject PyAccountType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.Account",    /* tp_name */
    sizeof(PyAccountObject), /* tp_basicsize */
    0,                       /* tp_itemsize */
    0,                       /* tp_dealloc */
    0,                       /* tp_print */
    0,                       /* tp_getattr */
    0,                       /* tp_setattr */
    0,                       /* tp_reserved */
    0,                       /* tp_repr */
    0,                       /* tp_as_number */
    0,                       /* tp_as_sequence */
    0,                       /* tp_as_mapping */
    0,                       /* tp_hash  */
    0,                       /* tp_call */
    0,                       /* tp_str */
    0,                       /* tp_getattro */
    0,                       /* tp_setattro */
    0,                       /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,      /* tp_flags */
    nullptr,                 /* tp_doc */
};

bool PyAccount_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyAccountType) != 0;
}

// Create PyAccount from enum TWAccount.
PyObject* PyAccount_FromTWAccount(TWAccount* value) {
  if (!value)
    return nullptr;

  PyAccountObject* object = PyObject_New(PyAccountObject, &PyAccountType);
  if (!object)
    return nullptr;

  object->value = value;

  return (PyObject*)object;
}

TWAccount* PyAccount_GetTWAccount(PyObject* object) {
  assert(PyAccount_Check(object));
  return ((PyAccountObject*)object)->value;
}

// static int PyAccount_init(PyAccountObject *self, PyObject *args, PyObject
// *kwds) {
//   return 0;
// }

// static PyObject* PyAccount_new(PyTypeObject *subtype, PyObject *args,
// PyObject *kwds) {
//   int value = 0;
//   if (!PyArg_ParseTuple(args, "|i", &value)) {
//     return nullptr;
//   }
//   return PyAccount_FromTWAccount((TWAccount)value);
// }

// static PyObject* PyAccount_str(PyAccountObject *self) {
//   const char* str = "Unknown";
//   return PyUnicode_FromString(str);
// }

// getter function for Coin
// enum TWCoinType TWAccountCoin(struct TWAccount* account);
static PyObject* PyAccountCoin(PyAccountObject* self, void*) {
  return PyCoinType_FromTWCoinType(TWAccountCoin(self->value));
}

static const PyGetSetDef get_set_defs[] = {{"Coin", (getter)PyAccountCoin}, {}};

static const PyMethodDef method_defs[] = {{}};

bool PyInit_Account(PyObject* module) {
  // PyAccountType.tp_new = PyAccount_new;
  // PyAccountType.tp_init = (initproc)PyAccount_init;
  // PyAccountType.tp_str = (reprfunc)PyAccount_str;
  PyAccountType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyAccountType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyAccountType) < 0)
    return false;

  Py_INCREF(&PyAccountType);
  if (PyModule_AddObject(module, "Account", (PyObject*)&PyAccountType) < 0) {
    Py_DECREF(&PyAccountType);
    return false;
  }

  return true;
}