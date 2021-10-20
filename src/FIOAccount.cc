// This is a GENERATED FILE, changes made here WILL BE LOST.

#include "FIOAccount.h"

#include "String.h"

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

static void PyFIOAccount_dealloc(PyFIOAccountObject* self) {
  if (self->value) {
    TWFIOAccountDelete(self->value);
  }
  Py_TYPE(self)->tp_free(self);
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

// getter function for Description
static const char PyFIOAccountDescription_doc[] =
    "TWString* TWFIOAccountDescription(struct TWFIOAccount* account)";
static PyObject* PyFIOAccountDescription(PyFIOAccountObject* self, void*) {
  return PyUnicode_FromTWString(TWFIOAccountDescription(self->value));
}

// method function for Delete
static const char PyFIOAccountDelete_doc[] =
    "void TWFIOAccountDelete(struct TWFIOAccount* account)";
static PyObject* PyFIOAccountDelete(PyFIOAccountObject* self,
                                    PyObject* const* args,
                                    Py_ssize_t nargs) {
  if (nargs != 0) {
    PyErr_Format(PyExc_TypeError, "Expect 0 instead of %d.", nargs);
    return nullptr;
  }

  TWFIOAccountDelete(self->value);
  return nullptr;
}

// static method function for CreateWithString
static const char PyFIOAccountCreateWithString_doc[] =
    "struct TWFIOAccount* TWFIOAccountCreateWithString(TWString* string)";
static PyObject* PyFIOAccountCreateWithString(PyFIOAccountObject* self,
                                              PyObject* const* args,
                                              Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyUnicode_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Unicode");
    return nullptr;
  }
  auto arg0 = PyUnicode_GetTWString(args[0]);

  TWFIOAccount* result = TWFIOAccountCreateWithString(arg0.get());
  return PyFIOAccount_FromTWFIOAccount(result);
}

static const PyGetSetDef get_set_defs[] = {
    {"Description", (getter)PyFIOAccountDescription, nullptr,
     PyFIOAccountDescription_doc},
    {}};

static const PyMethodDef method_defs[] = {
    {"Delete", (PyCFunction)PyFIOAccountDelete, METH_FASTCALL,
     PyFIOAccountDelete_doc},
    {"CreateWithString", (PyCFunction)PyFIOAccountCreateWithString,
     METH_FASTCALL | METH_STATIC, PyFIOAccountCreateWithString_doc},
    {}};

bool PyInit_FIOAccount(PyObject* module) {
  // PyFIOAccountType.tp_new = PyFIOAccount_new;
  // PyFIOAccountType.tp_init = (initproc)PyFIOAccount_init;
  PyFIOAccountType.tp_dealloc = (destructor)PyFIOAccount_dealloc;
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