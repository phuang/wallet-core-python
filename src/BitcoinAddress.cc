// This is a GENERATED FILE, changes made here WILL BE LOST.

#include "BitcoinAddress.h"

#include "Data.h"
#include "String.h"

static PyTypeObject PyBitcoinAddressType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.BitcoinAddress",    /* tp_name */
    sizeof(PyBitcoinAddressObject), /* tp_basicsize */
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

bool PyBitcoinAddress_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyBitcoinAddressType) != 0;
}

// Create PyBitcoinAddress from enum TWBitcoinAddress.
PyObject* PyBitcoinAddress_FromTWBitcoinAddress(TWBitcoinAddress* value) {
  if (!value)
    return nullptr;

  PyBitcoinAddressObject* object =
      PyObject_New(PyBitcoinAddressObject, &PyBitcoinAddressType);
  if (!object)
    return nullptr;

  object->value = value;

  return (PyObject*)object;
}

TWBitcoinAddress* PyBitcoinAddress_GetTWBitcoinAddress(PyObject* object) {
  assert(PyBitcoinAddress_Check(object));
  return ((PyBitcoinAddressObject*)object)->value;
}

// static int PyBitcoinAddress_init(PyBitcoinAddressObject *self, PyObject
// *args, PyObject *kwds) {
//   return 0;
// }

// static PyObject* PyBitcoinAddress_new(PyTypeObject *subtype, PyObject *args,
// PyObject *kwds) {
//   int value = 0;
//   if (!PyArg_ParseTuple(args, "|i", &value)) {
//     return nullptr;
//   }
//   return PyBitcoinAddress_FromTWBitcoinAddress((TWBitcoinAddress)value);
// }

// static PyObject* PyBitcoinAddress_str(PyBitcoinAddressObject *self) {
//   const char* str = "Unknown";
//   return PyUnicode_FromString(str);
// }

// getter function for Prefix
// uint8_t TWBitcoinAddressPrefix(struct TWBitcoinAddress* address);
static PyObject* PyBitcoinAddressPrefix(PyBitcoinAddressObject* self, void*) {
  return PyLong_FromLong(TWBitcoinAddressPrefix(self->value));
}

// static method function for Equal
// bool TWBitcoinAddressEqual(struct TWBitcoinAddress* lhs, struct
// TWBitcoinAddress* rhs);
static PyObject* PyBitcoinAddressEqual(PyBitcoinAddressObject* self,
                                       PyObject* const* args,
                                       Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyBitcoinAddress_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type BitcoinAddress");
    return nullptr;
  }
  auto arg0 = PyBitcoinAddress_GetTWBitcoinAddress(args[0]);

  if (!PyBitcoinAddress_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type BitcoinAddress");
    return nullptr;
  }
  auto arg1 = PyBitcoinAddress_GetTWBitcoinAddress(args[1]);

  bool result = TWBitcoinAddressEqual(arg0, arg1);
  return PyBool_FromLong(result);
}

// static method function for IsValid
// bool TWBitcoinAddressIsValid(TWData* data);
static PyObject* PyBitcoinAddressIsValid(PyBitcoinAddressObject* self,
                                         PyObject* const* args,
                                         Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyByteArray_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type ByteArray");
    return nullptr;
  }
  auto arg0 = PyByteArray_GetTWData(args[0]);

  bool result = TWBitcoinAddressIsValid(arg0.get());
  return PyBool_FromLong(result);
}

// static method function for IsValidString
// bool TWBitcoinAddressIsValidString(TWString* string);
static PyObject* PyBitcoinAddressIsValidString(PyBitcoinAddressObject* self,
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

  bool result = TWBitcoinAddressIsValidString(arg0.get());
  return PyBool_FromLong(result);
}

static const PyGetSetDef get_set_defs[] = {
    {"Prefix", (getter)PyBitcoinAddressPrefix},
    {}};

static const PyMethodDef method_defs[] = {
    {"Equal", (PyCFunction)PyBitcoinAddressEqual, METH_FASTCALL | METH_STATIC},
    {"IsValid", (PyCFunction)PyBitcoinAddressIsValid,
     METH_FASTCALL | METH_STATIC},
    {"IsValidString", (PyCFunction)PyBitcoinAddressIsValidString,
     METH_FASTCALL | METH_STATIC},
    {}};

bool PyInit_BitcoinAddress(PyObject* module) {
  // PyBitcoinAddressType.tp_new = PyBitcoinAddress_new;
  // PyBitcoinAddressType.tp_init = (initproc)PyBitcoinAddress_init;
  // PyBitcoinAddressType.tp_str = (reprfunc)PyBitcoinAddress_str;
  PyBitcoinAddressType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyBitcoinAddressType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyBitcoinAddressType) < 0)
    return false;

  Py_INCREF(&PyBitcoinAddressType);
  if (PyModule_AddObject(module, "BitcoinAddress",
                         (PyObject*)&PyBitcoinAddressType) < 0) {
    Py_DECREF(&PyBitcoinAddressType);
    return false;
  }

  return true;
}