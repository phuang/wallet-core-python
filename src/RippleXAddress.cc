// This is a GENERATED FILE, changes made here WILL BE LOST.

#include "RippleXAddress.h"

#include "PublicKey.h"
#include "String.h"

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

TWRippleXAddress* PyRippleXAddress_GetTWRippleXAddress(PyObject* object) {
  assert(PyRippleXAddress_Check(object));
  return ((PyRippleXAddressObject*)object)->value;
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
// uint32_t TWRippleXAddressTag(struct TWRippleXAddress* address);
static PyObject* PyRippleXAddressTag(PyRippleXAddressObject* self, void*) {
  return PyLong_FromLong(TWRippleXAddressTag(self->value));
}

// method function for Delete
// void TWRippleXAddressDelete(struct TWRippleXAddress* address);
static PyObject* PyRippleXAddressDelete(PyRippleXAddressObject* self,
                                        PyObject* const* args,
                                        Py_ssize_t nargs) {
  if (nargs != 0) {
    PyErr_Format(PyExc_TypeError, "Expect 0 instead of %d.", nargs);
    return nullptr;
  }

  TWRippleXAddressDelete(self->value);
  return nullptr;
}

// static method function for Equal
// bool TWRippleXAddressEqual(struct TWRippleXAddress* lhs, struct
// TWRippleXAddress* rhs);
static PyObject* PyRippleXAddressEqual(PyRippleXAddressObject* self,
                                       PyObject* const* args,
                                       Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyRippleXAddress_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type RippleXAddress");
    return nullptr;
  }
  auto arg0 = PyRippleXAddress_GetTWRippleXAddress(args[0]);

  if (!PyRippleXAddress_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type RippleXAddress");
    return nullptr;
  }
  auto arg1 = PyRippleXAddress_GetTWRippleXAddress(args[1]);

  bool result = TWRippleXAddressEqual(arg0, arg1);
  return PyBool_FromLong(result);
}

// static method function for IsValidString
// bool TWRippleXAddressIsValidString(TWString* string);
static PyObject* PyRippleXAddressIsValidString(PyRippleXAddressObject* self,
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

  bool result = TWRippleXAddressIsValidString(arg0.get());
  return PyBool_FromLong(result);
}

// static method function for CreateWithString
// struct TWRippleXAddress* TWRippleXAddressCreateWithString(TWString* string);
static PyObject* PyRippleXAddressCreateWithString(PyRippleXAddressObject* self,
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

  TWRippleXAddress* result = TWRippleXAddressCreateWithString(arg0.get());
  return PyRippleXAddress_FromTWRippleXAddress(result);
}

// static method function for CreateWithPublicKey
// struct TWRippleXAddress* TWRippleXAddressCreateWithPublicKey(struct
// TWPublicKey* publicKey, uint32_t tag);
static PyObject* PyRippleXAddressCreateWithPublicKey(
    PyRippleXAddressObject* self,
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

  if (!PyLong_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Long");
    return nullptr;
  }
  auto arg1 = PyLong_AsLong(args[1]);

  TWRippleXAddress* result = TWRippleXAddressCreateWithPublicKey(arg0, arg1);
  return PyRippleXAddress_FromTWRippleXAddress(result);
}

static const PyGetSetDef get_set_defs[] = {{"Tag", (getter)PyRippleXAddressTag},
                                           {}};

static const PyMethodDef method_defs[] = {
    {"Delete", (PyCFunction)PyRippleXAddressDelete, METH_FASTCALL},
    {"Equal", (PyCFunction)PyRippleXAddressEqual, METH_FASTCALL | METH_STATIC},
    {"IsValidString", (PyCFunction)PyRippleXAddressIsValidString,
     METH_FASTCALL | METH_STATIC},
    {"CreateWithString", (PyCFunction)PyRippleXAddressCreateWithString,
     METH_FASTCALL | METH_STATIC},
    {"CreateWithPublicKey", (PyCFunction)PyRippleXAddressCreateWithPublicKey,
     METH_FASTCALL | METH_STATIC},
    {}};

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