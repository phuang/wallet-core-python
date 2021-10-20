// This is a GENERATED FILE, changes made here WILL BE LOST.

#include "AnyAddress.h"

#include "CoinType.h"
#include "PublicKey.h"
#include "String.h"

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

TWAnyAddress* PyAnyAddress_GetTWAnyAddress(PyObject* object) {
  assert(PyAnyAddress_Check(object));
  return ((PyAnyAddressObject*)object)->value;
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
// enum TWCoinType TWAnyAddressCoin(struct TWAnyAddress* address);
static PyObject* PyAnyAddressCoin(PyAnyAddressObject* self, void*) {
  return PyCoinType_FromTWCoinType(TWAnyAddressCoin(self->value));
}

// method function for Delete
// void TWAnyAddressDelete(struct TWAnyAddress* address);
static PyObject* PyAnyAddressDelete(PyAnyAddressObject* self,
                                    PyObject* const* args,
                                    Py_ssize_t nargs) {
  if (nargs != 0) {
    PyErr_Format(PyExc_TypeError, "Expect 0 instead of %d.", nargs);
    return nullptr;
  }

  TWAnyAddressDelete(self->value);
  return nullptr;
}

// static method function for Equal
// bool TWAnyAddressEqual(struct TWAnyAddress* lhs, struct TWAnyAddress* rhs);
static PyObject* PyAnyAddressEqual(PyAnyAddressObject* self,
                                   PyObject* const* args,
                                   Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyAnyAddress_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type AnyAddress");
    return nullptr;
  }
  auto arg0 = PyAnyAddress_GetTWAnyAddress(args[0]);

  if (!PyAnyAddress_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type AnyAddress");
    return nullptr;
  }
  auto arg1 = PyAnyAddress_GetTWAnyAddress(args[1]);

  bool result = TWAnyAddressEqual(arg0, arg1);
  return PyBool_FromLong(result);
}

// static method function for IsValid
// bool TWAnyAddressIsValid(TWString* string, enum TWCoinType coin);
static PyObject* PyAnyAddressIsValid(PyAnyAddressObject* self,
                                     PyObject* const* args,
                                     Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyUnicode_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Unicode");
    return nullptr;
  }
  auto arg0 = PyUnicode_GetTWString(args[0]);

  if (!PyCoinType_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type CoinType");
    return nullptr;
  }
  auto arg1 = PyCoinType_GetTWCoinType(args[1]);

  bool result = TWAnyAddressIsValid(arg0.get(), arg1);
  return PyBool_FromLong(result);
}

// static method function for CreateWithString
// struct TWAnyAddress* TWAnyAddressCreateWithString(TWString* string, enum
// TWCoinType coin);
static PyObject* PyAnyAddressCreateWithString(PyAnyAddressObject* self,
                                              PyObject* const* args,
                                              Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyUnicode_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Unicode");
    return nullptr;
  }
  auto arg0 = PyUnicode_GetTWString(args[0]);

  if (!PyCoinType_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type CoinType");
    return nullptr;
  }
  auto arg1 = PyCoinType_GetTWCoinType(args[1]);

  TWAnyAddress* result = TWAnyAddressCreateWithString(arg0.get(), arg1);
  return PyAnyAddress_FromTWAnyAddress(result);
}

// static method function for CreateWithPublicKey
// struct TWAnyAddress* TWAnyAddressCreateWithPublicKey(struct TWPublicKey*
// publicKey, enum TWCoinType coin);
static PyObject* PyAnyAddressCreateWithPublicKey(PyAnyAddressObject* self,
                                                 PyObject* const* args,
                                                 Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyPublicKey_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type PublicKey");
    return nullptr;
  }
  auto arg0 = PyPublicKey_GetTWPublicKey(args[0]);

  if (!PyCoinType_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type CoinType");
    return nullptr;
  }
  auto arg1 = PyCoinType_GetTWCoinType(args[1]);

  TWAnyAddress* result = TWAnyAddressCreateWithPublicKey(arg0, arg1);
  return PyAnyAddress_FromTWAnyAddress(result);
}

static const PyGetSetDef get_set_defs[] = {{"Coin", (getter)PyAnyAddressCoin},
                                           {}};

static const PyMethodDef method_defs[] = {
    {"Delete", (PyCFunction)PyAnyAddressDelete, METH_FASTCALL},
    {"Equal", (PyCFunction)PyAnyAddressEqual, METH_FASTCALL | METH_STATIC},
    {"IsValid", (PyCFunction)PyAnyAddressIsValid, METH_FASTCALL | METH_STATIC},
    {"CreateWithString", (PyCFunction)PyAnyAddressCreateWithString,
     METH_FASTCALL | METH_STATIC},
    {"CreateWithPublicKey", (PyCFunction)PyAnyAddressCreateWithPublicKey,
     METH_FASTCALL | METH_STATIC},
    {}};

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