// This is a GENERATED FILE, changes made here WILL BE LOST.

#include "StoredKey.h"

#include "Data.h"
#include "String.h"

static PyTypeObject PyStoredKeyType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.StoredKey",    /* tp_name */
    sizeof(PyStoredKeyObject), /* tp_basicsize */
    0,                         /* tp_itemsize */
    0,                         /* tp_dealloc */
    0,                         /* tp_print */
    0,                         /* tp_getattr */
    0,                         /* tp_setattr */
    0,                         /* tp_reserved */
    0,                         /* tp_repr */
    0,                         /* tp_as_number */
    0,                         /* tp_as_sequence */
    0,                         /* tp_as_mapping */
    0,                         /* tp_hash  */
    0,                         /* tp_call */
    0,                         /* tp_str */
    0,                         /* tp_getattro */
    0,                         /* tp_setattro */
    0,                         /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,        /* tp_flags */
    nullptr,                   /* tp_doc */
};

bool PyStoredKey_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyStoredKeyType) != 0;
}

// Create PyStoredKey from enum TWStoredKey.
PyObject* PyStoredKey_FromTWStoredKey(TWStoredKey* value) {
  if (!value)
    return nullptr;

  PyStoredKeyObject* object = PyObject_New(PyStoredKeyObject, &PyStoredKeyType);
  if (!object)
    return nullptr;

  object->value = value;

  return (PyObject*)object;
}

// static int PyStoredKey_init(PyStoredKeyObject *self, PyObject *args, PyObject
// *kwds) {
//   return 0;
// }

// static PyObject* PyStoredKey_new(PyTypeObject *subtype, PyObject *args,
// PyObject *kwds) {
//   int value = 0;
//   if (!PyArg_ParseTuple(args, "|i", &value)) {
//     return nullptr;
//   }
//   return PyStoredKey_FromTWStoredKey((TWStoredKey)value);
// }

// static PyObject* PyStoredKey_str(PyStoredKeyObject *self) {
//   const char* str = "Unknown";
//   return PyUnicode_FromString(str);
// }

// getter function for IsMnemonic
static PyObject* PyStoredKeyIsMnemonic(PyStoredKeyObject* self, void*) {
  return PyBool_FromLong(TWStoredKeyIsMnemonic(self->value));
}

// method function for Store
// bool TWStoredKeyStore(struct TWStoredKey * key, TWString * path)
static PyObject* PyStoredKeyStore(PyStoredKeyObject* self,
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

  bool result = TWStoredKeyStore(self->value, arg0.get());
  return PyBool_FromLong(result);
}

// method function for FixAddresses
// bool TWStoredKeyFixAddresses(struct TWStoredKey * key, TWData * password)
static PyObject* PyStoredKeyFixAddresses(PyStoredKeyObject* self,
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

  bool result = TWStoredKeyFixAddresses(self->value, arg0.get());
  return PyBool_FromLong(result);
}

static const PyGetSetDef get_set_defs[] = {
    {"IsMnemonic", (getter)PyStoredKeyIsMnemonic},
    {}};

static const PyMethodDef method_defs[] = {
    {"Store", (PyCFunction)PyStoredKeyStore, METH_FASTCALL},
    {"FixAddresses", (PyCFunction)PyStoredKeyFixAddresses, METH_FASTCALL},
    {}};

bool PyInit_StoredKey(PyObject* module) {
  // PyStoredKeyType.tp_new = PyStoredKey_new;
  // PyStoredKeyType.tp_init = (initproc)PyStoredKey_init;
  // PyStoredKeyType.tp_str = (reprfunc)PyStoredKey_str;
  PyStoredKeyType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyStoredKeyType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyStoredKeyType) < 0)
    return false;

  Py_INCREF(&PyStoredKeyType);
  if (PyModule_AddObject(module, "StoredKey", (PyObject*)&PyStoredKeyType) <
      0) {
    Py_DECREF(&PyStoredKeyType);
    return false;
  }

  return true;
}