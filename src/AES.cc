// This is a GENERATED FILE, changes made here WILL BE LOST.

#include "AES.h"

#include "AESPaddingMode.h"
#include "Data.h"

static PyTypeObject PyAESType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.AES",    /* tp_name */
    sizeof(PyAESObject), /* tp_basicsize */
    0,                   /* tp_itemsize */
    0,                   /* tp_dealloc */
    0,                   /* tp_print */
    0,                   /* tp_getattr */
    0,                   /* tp_setattr */
    0,                   /* tp_reserved */
    0,                   /* tp_repr */
    0,                   /* tp_as_number */
    0,                   /* tp_as_sequence */
    0,                   /* tp_as_mapping */
    0,                   /* tp_hash  */
    0,                   /* tp_call */
    0,                   /* tp_str */
    0,                   /* tp_getattro */
    0,                   /* tp_setattro */
    0,                   /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,  /* tp_flags */
    nullptr,             /* tp_doc */
};

bool PyAES_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyAESType) != 0;
}

// Create PyAES from enum TWAES.
PyObject* PyAES_FromTWAES(TWAES* value) {
  if (!value)
    return nullptr;

  PyAESObject* object = PyObject_New(PyAESObject, &PyAESType);
  if (!object)
    return nullptr;

  object->value = value;

  return (PyObject*)object;
}

TWAES* PyAES_GetTWAES(PyObject* object) {
  assert(PyAES_Check(object));
  return ((PyAESObject*)object)->value;
}

// static int PyAES_init(PyAESObject *self, PyObject *args, PyObject *kwds) {
//   return 0;
// }

// static PyObject* PyAES_new(PyTypeObject *subtype, PyObject *args, PyObject
// *kwds) {
//   int value = 0;
//   if (!PyArg_ParseTuple(args, "|i", &value)) {
//     return nullptr;
//   }
//   return PyAES_FromTWAES((TWAES)value);
// }

// static PyObject* PyAES_str(PyAESObject *self) {
//   const char* str = "Unknown";
//   return PyUnicode_FromString(str);
// }

// static method function for EncryptCBC
// TWData* TWAESEncryptCBC(TWData* key, TWData* data, TWData* iv, enum
// TWAESPaddingMode mode);
static PyObject* PyAESEncryptCBC(PyAESObject* self,
                                 PyObject* const* args,
                                 Py_ssize_t nargs) {
  if (nargs != 4) {
    PyErr_Format(PyExc_TypeError, "Expect 4 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyByteArray_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type ByteArray");
    return nullptr;
  }
  auto arg0 = PyByteArray_GetTWData(args[0]);

  if (!PyByteArray_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type ByteArray");
    return nullptr;
  }
  auto arg1 = PyByteArray_GetTWData(args[1]);

  if (!PyByteArray_Check(args[2])) {
    PyErr_SetString(PyExc_TypeError, "The arg 2 is not in type ByteArray");
    return nullptr;
  }
  auto arg2 = PyByteArray_GetTWData(args[2]);

  if (!PyAESPaddingMode_Check(args[3])) {
    PyErr_SetString(PyExc_TypeError, "The arg 3 is not in type AESPaddingMode");
    return nullptr;
  }
  auto arg3 = PyAESPaddingMode_GetTWAESPaddingMode(args[3]);

  TWDataPtr result = TWAESEncryptCBC(arg0.get(), arg1.get(), arg2.get(), arg3);
  return PyByteArray_FromTWData(result);
}

// static method function for DecryptCBC
// TWData* TWAESDecryptCBC(TWData* key, TWData* data, TWData* iv, enum
// TWAESPaddingMode mode);
static PyObject* PyAESDecryptCBC(PyAESObject* self,
                                 PyObject* const* args,
                                 Py_ssize_t nargs) {
  if (nargs != 4) {
    PyErr_Format(PyExc_TypeError, "Expect 4 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyByteArray_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type ByteArray");
    return nullptr;
  }
  auto arg0 = PyByteArray_GetTWData(args[0]);

  if (!PyByteArray_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type ByteArray");
    return nullptr;
  }
  auto arg1 = PyByteArray_GetTWData(args[1]);

  if (!PyByteArray_Check(args[2])) {
    PyErr_SetString(PyExc_TypeError, "The arg 2 is not in type ByteArray");
    return nullptr;
  }
  auto arg2 = PyByteArray_GetTWData(args[2]);

  if (!PyAESPaddingMode_Check(args[3])) {
    PyErr_SetString(PyExc_TypeError, "The arg 3 is not in type AESPaddingMode");
    return nullptr;
  }
  auto arg3 = PyAESPaddingMode_GetTWAESPaddingMode(args[3]);

  TWDataPtr result = TWAESDecryptCBC(arg0.get(), arg1.get(), arg2.get(), arg3);
  return PyByteArray_FromTWData(result);
}

// static method function for EncryptCTR
// TWData* TWAESEncryptCTR(TWData* key, TWData* data, TWData* iv);
static PyObject* PyAESEncryptCTR(PyAESObject* self,
                                 PyObject* const* args,
                                 Py_ssize_t nargs) {
  if (nargs != 3) {
    PyErr_Format(PyExc_TypeError, "Expect 3 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyByteArray_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type ByteArray");
    return nullptr;
  }
  auto arg0 = PyByteArray_GetTWData(args[0]);

  if (!PyByteArray_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type ByteArray");
    return nullptr;
  }
  auto arg1 = PyByteArray_GetTWData(args[1]);

  if (!PyByteArray_Check(args[2])) {
    PyErr_SetString(PyExc_TypeError, "The arg 2 is not in type ByteArray");
    return nullptr;
  }
  auto arg2 = PyByteArray_GetTWData(args[2]);

  TWDataPtr result = TWAESEncryptCTR(arg0.get(), arg1.get(), arg2.get());
  return PyByteArray_FromTWData(result);
}

// static method function for DecryptCTR
// TWData* TWAESDecryptCTR(TWData* key, TWData* data, TWData* iv);
static PyObject* PyAESDecryptCTR(PyAESObject* self,
                                 PyObject* const* args,
                                 Py_ssize_t nargs) {
  if (nargs != 3) {
    PyErr_Format(PyExc_TypeError, "Expect 3 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyByteArray_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type ByteArray");
    return nullptr;
  }
  auto arg0 = PyByteArray_GetTWData(args[0]);

  if (!PyByteArray_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type ByteArray");
    return nullptr;
  }
  auto arg1 = PyByteArray_GetTWData(args[1]);

  if (!PyByteArray_Check(args[2])) {
    PyErr_SetString(PyExc_TypeError, "The arg 2 is not in type ByteArray");
    return nullptr;
  }
  auto arg2 = PyByteArray_GetTWData(args[2]);

  TWDataPtr result = TWAESDecryptCTR(arg0.get(), arg1.get(), arg2.get());
  return PyByteArray_FromTWData(result);
}

static const PyGetSetDef get_set_defs[] = {{}};

static const PyMethodDef method_defs[] = {
    {"EncryptCBC", (PyCFunction)PyAESEncryptCBC, METH_FASTCALL | METH_STATIC},
    {"DecryptCBC", (PyCFunction)PyAESDecryptCBC, METH_FASTCALL | METH_STATIC},
    {"EncryptCTR", (PyCFunction)PyAESEncryptCTR, METH_FASTCALL | METH_STATIC},
    {"DecryptCTR", (PyCFunction)PyAESDecryptCTR, METH_FASTCALL | METH_STATIC},
    {}};

bool PyInit_AES(PyObject* module) {
  // PyAESType.tp_new = PyAES_new;
  // PyAESType.tp_init = (initproc)PyAES_init;
  // PyAESType.tp_str = (reprfunc)PyAES_str;
  PyAESType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyAESType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyAESType) < 0)
    return false;

  Py_INCREF(&PyAESType);
  if (PyModule_AddObject(module, "AES", (PyObject*)&PyAESType) < 0) {
    Py_DECREF(&PyAESType);
    return false;
  }

  return true;
}