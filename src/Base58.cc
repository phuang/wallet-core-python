// This is a GENERATED FILE, changes made here WILL BE LOST.

#include "Base58.h"

#include "Data.h"
#include "String.h"

static PyTypeObject PyBase58Type = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.Base58",    /* tp_name */
    sizeof(PyBase58Object), /* tp_basicsize */
    0,                      /* tp_itemsize */
    0,                      /* tp_dealloc */
    0,                      /* tp_print */
    0,                      /* tp_getattr */
    0,                      /* tp_setattr */
    0,                      /* tp_reserved */
    0,                      /* tp_repr */
    0,                      /* tp_as_number */
    0,                      /* tp_as_sequence */
    0,                      /* tp_as_mapping */
    0,                      /* tp_hash  */
    0,                      /* tp_call */
    0,                      /* tp_str */
    0,                      /* tp_getattro */
    0,                      /* tp_setattro */
    0,                      /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,     /* tp_flags */
    nullptr,                /* tp_doc */
};

bool PyBase58_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyBase58Type) != 0;
}

// Create PyBase58 from enum TWBase58.
PyObject* PyBase58_FromTWBase58(TWBase58* value) {
  if (!value)
    return nullptr;

  PyBase58Object* object = PyObject_New(PyBase58Object, &PyBase58Type);
  if (!object)
    return nullptr;

  object->value = value;

  return (PyObject*)object;
}

TWBase58* PyBase58_GetTWBase58(PyObject* object) {
  assert(PyBase58_Check(object));
  return ((PyBase58Object*)object)->value;
}

// static int PyBase58_init(PyBase58Object *self, PyObject *args, PyObject
// *kwds) {
//   return 0;
// }

// static PyObject* PyBase58_new(PyTypeObject *subtype, PyObject *args, PyObject
// *kwds) {
//   int value = 0;
//   if (!PyArg_ParseTuple(args, "|i", &value)) {
//     return nullptr;
//   }
//   return PyBase58_FromTWBase58((TWBase58)value);
// }

// static PyObject* PyBase58_str(PyBase58Object *self) {
//   const char* str = "Unknown";
//   return PyUnicode_FromString(str);
// }

// static method function for Encode
// TWString* TWBase58Encode(TWData* data);
static PyObject* PyBase58Encode(PyBase58Object* self,
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

  TWStringPtr result = TWBase58Encode(arg0.get());
  return PyUnicode_FromTWString(result);
}

// static method function for EncodeNoCheck
// TWString* TWBase58EncodeNoCheck(TWData* data);
static PyObject* PyBase58EncodeNoCheck(PyBase58Object* self,
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

  TWStringPtr result = TWBase58EncodeNoCheck(arg0.get());
  return PyUnicode_FromTWString(result);
}

// static method function for Decode
// TWData* TWBase58Decode(TWString* string);
static PyObject* PyBase58Decode(PyBase58Object* self,
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

  TWDataPtr result = TWBase58Decode(arg0.get());
  return PyByteArray_FromTWData(result);
}

// static method function for DecodeNoCheck
// TWData* TWBase58DecodeNoCheck(TWString* string);
static PyObject* PyBase58DecodeNoCheck(PyBase58Object* self,
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

  TWDataPtr result = TWBase58DecodeNoCheck(arg0.get());
  return PyByteArray_FromTWData(result);
}

static const PyGetSetDef get_set_defs[] = {{}};

static const PyMethodDef method_defs[] = {
    {"Encode", (PyCFunction)PyBase58Encode, METH_FASTCALL | METH_STATIC},
    {"EncodeNoCheck", (PyCFunction)PyBase58EncodeNoCheck,
     METH_FASTCALL | METH_STATIC},
    {"Decode", (PyCFunction)PyBase58Decode, METH_FASTCALL | METH_STATIC},
    {"DecodeNoCheck", (PyCFunction)PyBase58DecodeNoCheck,
     METH_FASTCALL | METH_STATIC},
    {}};

bool PyInit_Base58(PyObject* module) {
  // PyBase58Type.tp_new = PyBase58_new;
  // PyBase58Type.tp_init = (initproc)PyBase58_init;
  // PyBase58Type.tp_str = (reprfunc)PyBase58_str;
  PyBase58Type.tp_getset = (PyGetSetDef*)get_set_defs;
  PyBase58Type.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyBase58Type) < 0)
    return false;

  Py_INCREF(&PyBase58Type);
  if (PyModule_AddObject(module, "Base58", (PyObject*)&PyBase58Type) < 0) {
    Py_DECREF(&PyBase58Type);
    return false;
  }

  return true;
}