// This is a GENERATED FILE, changes made here WILL BE LOST.

#include "GroestlcoinAddress.h"

#include "PublicKey.h"
#include "String.h"

static PyTypeObject PyGroestlcoinAddressType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.GroestlcoinAddress",    /* tp_name */
    sizeof(PyGroestlcoinAddressObject), /* tp_basicsize */
    0,                                  /* tp_itemsize */
    0,                                  /* tp_dealloc */
    0,                                  /* tp_print */
    0,                                  /* tp_getattr */
    0,                                  /* tp_setattr */
    0,                                  /* tp_reserved */
    0,                                  /* tp_repr */
    0,                                  /* tp_as_number */
    0,                                  /* tp_as_sequence */
    0,                                  /* tp_as_mapping */
    0,                                  /* tp_hash  */
    0,                                  /* tp_call */
    0,                                  /* tp_str */
    0,                                  /* tp_getattro */
    0,                                  /* tp_setattro */
    0,                                  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                 /* tp_flags */
    nullptr,                            /* tp_doc */
};

bool PyGroestlcoinAddress_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyGroestlcoinAddressType) != 0;
}

// Create PyGroestlcoinAddress from enum TWGroestlcoinAddress.
PyObject* PyGroestlcoinAddress_FromTWGroestlcoinAddress(
    TWGroestlcoinAddress* value) {
  if (!value)
    return nullptr;

  PyGroestlcoinAddressObject* object =
      PyObject_New(PyGroestlcoinAddressObject, &PyGroestlcoinAddressType);
  if (!object)
    return nullptr;

  object->value = value;

  return (PyObject*)object;
}

TWGroestlcoinAddress* PyGroestlcoinAddress_GetTWGroestlcoinAddress(
    PyObject* object) {
  assert(PyGroestlcoinAddress_Check(object));
  return ((PyGroestlcoinAddressObject*)object)->value;
}

static void PyGroestlcoinAddress_dealloc(PyGroestlcoinAddressObject* self) {
  if (self->value) {
    TWGroestlcoinAddressDelete(self->value);
  }
  Py_TYPE(self)->tp_free(self);
}

// static int PyGroestlcoinAddress_init(PyGroestlcoinAddressObject *self,
// PyObject *args, PyObject *kwds) {
//   return 0;
// }

// static PyObject* PyGroestlcoinAddress_new(PyTypeObject *subtype, PyObject
// *args, PyObject *kwds) {
//   int value = 0;
//   if (!PyArg_ParseTuple(args, "|i", &value)) {
//     return nullptr;
//   }
//   return
//   PyGroestlcoinAddress_FromTWGroestlcoinAddress((TWGroestlcoinAddress)value);
// }

// static PyObject* PyGroestlcoinAddress_str(PyGroestlcoinAddressObject *self) {
//   const char* str = "Unknown";
//   return PyUnicode_FromString(str);
// }

// getter function for Description
static const char PyGroestlcoinAddressDescription_doc[] =
    "TWString* TWGroestlcoinAddressDescription(struct TWGroestlcoinAddress* "
    "address)";
static PyObject* PyGroestlcoinAddressDescription(
    PyGroestlcoinAddressObject* self,
    void*) {
  return PyUnicode_FromTWString(TWGroestlcoinAddressDescription(self->value));
}

// method function for Delete
static const char PyGroestlcoinAddressDelete_doc[] =
    "void TWGroestlcoinAddressDelete(struct TWGroestlcoinAddress* address)";
static PyObject* PyGroestlcoinAddressDelete(PyGroestlcoinAddressObject* self,
                                            PyObject* const* args,
                                            Py_ssize_t nargs) {
  if (nargs != 0) {
    PyErr_Format(PyExc_TypeError, "Expect 0 instead of %d.", nargs);
    return nullptr;
  }

  TWGroestlcoinAddressDelete(self->value);
  return nullptr;
}

// static method function for Equal
static const char PyGroestlcoinAddressEqual_doc[] =
    "bool TWGroestlcoinAddressEqual(struct TWGroestlcoinAddress* lhs, struct "
    "TWGroestlcoinAddress* rhs)";
static PyObject* PyGroestlcoinAddressEqual(PyGroestlcoinAddressObject* self,
                                           PyObject* const* args,
                                           Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyGroestlcoinAddress_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError,
                    "The arg 0 is not in type GroestlcoinAddress");
    return nullptr;
  }
  auto arg0 = PyGroestlcoinAddress_GetTWGroestlcoinAddress(args[0]);

  if (!PyGroestlcoinAddress_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError,
                    "The arg 1 is not in type GroestlcoinAddress");
    return nullptr;
  }
  auto arg1 = PyGroestlcoinAddress_GetTWGroestlcoinAddress(args[1]);

  bool result = TWGroestlcoinAddressEqual(arg0, arg1);
  return PyBool_FromLong(result);
}

// static method function for IsValidString
static const char PyGroestlcoinAddressIsValidString_doc[] =
    "bool TWGroestlcoinAddressIsValidString(TWString* string)";
static PyObject* PyGroestlcoinAddressIsValidString(
    PyGroestlcoinAddressObject* self,
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

  bool result = TWGroestlcoinAddressIsValidString(arg0.get());
  return PyBool_FromLong(result);
}

// static method function for CreateWithString
static const char PyGroestlcoinAddressCreateWithString_doc[] =
    "struct TWGroestlcoinAddress* "
    "TWGroestlcoinAddressCreateWithString(TWString* string)";
static PyObject* PyGroestlcoinAddressCreateWithString(
    PyGroestlcoinAddressObject* self,
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

  TWGroestlcoinAddress* result =
      TWGroestlcoinAddressCreateWithString(arg0.get());
  return PyGroestlcoinAddress_FromTWGroestlcoinAddress(result);
}

// static method function for CreateWithPublicKey
static const char PyGroestlcoinAddressCreateWithPublicKey_doc[] =
    "struct TWGroestlcoinAddress* "
    "TWGroestlcoinAddressCreateWithPublicKey(struct TWPublicKey* publicKey, "
    "uint8_t prefix)";
static PyObject* PyGroestlcoinAddressCreateWithPublicKey(
    PyGroestlcoinAddressObject* self,
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

  TWGroestlcoinAddress* result =
      TWGroestlcoinAddressCreateWithPublicKey(arg0, arg1);
  return PyGroestlcoinAddress_FromTWGroestlcoinAddress(result);
}

static const PyGetSetDef get_set_defs[] = {
    {"Description", (getter)PyGroestlcoinAddressDescription, nullptr,
     PyGroestlcoinAddressDescription_doc},
    {}};

static const PyMethodDef method_defs[] = {
    {"Delete", (PyCFunction)PyGroestlcoinAddressDelete, METH_FASTCALL,
     PyGroestlcoinAddressDelete_doc},
    {"Equal", (PyCFunction)PyGroestlcoinAddressEqual,
     METH_FASTCALL | METH_STATIC, PyGroestlcoinAddressEqual_doc},
    {"IsValidString", (PyCFunction)PyGroestlcoinAddressIsValidString,
     METH_FASTCALL | METH_STATIC, PyGroestlcoinAddressIsValidString_doc},
    {"CreateWithString", (PyCFunction)PyGroestlcoinAddressCreateWithString,
     METH_FASTCALL | METH_STATIC, PyGroestlcoinAddressCreateWithString_doc},
    {"CreateWithPublicKey",
     (PyCFunction)PyGroestlcoinAddressCreateWithPublicKey,
     METH_FASTCALL | METH_STATIC, PyGroestlcoinAddressCreateWithPublicKey_doc},
    {}};

bool PyInit_GroestlcoinAddress(PyObject* module) {
  // PyGroestlcoinAddressType.tp_new = PyGroestlcoinAddress_new;
  // PyGroestlcoinAddressType.tp_init = (initproc)PyGroestlcoinAddress_init;
  PyGroestlcoinAddressType.tp_dealloc =
      (destructor)PyGroestlcoinAddress_dealloc;
  // PyGroestlcoinAddressType.tp_str = (reprfunc)PyGroestlcoinAddress_str;
  PyGroestlcoinAddressType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyGroestlcoinAddressType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyGroestlcoinAddressType) < 0)
    return false;

  Py_INCREF(&PyGroestlcoinAddressType);
  if (PyModule_AddObject(module, "GroestlcoinAddress",
                         (PyObject*)&PyGroestlcoinAddressType) < 0) {
    Py_DECREF(&PyGroestlcoinAddressType);
    return false;
  }

  return true;
}