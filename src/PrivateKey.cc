// This is a GENERATED FILE, changes made here WILL BE LOST.

#include "PrivateKey.h"

#include "Curve.h"
#include "Data.h"

static PyTypeObject PyPrivateKeyType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.PrivateKey",    /* tp_name */
    sizeof(PyPrivateKeyObject), /* tp_basicsize */
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

bool PyPrivateKey_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyPrivateKeyType) != 0;
}

// Create PyPrivateKey from enum TWPrivateKey.
PyObject* PyPrivateKey_FromTWPrivateKey(TWPrivateKey* value) {
  if (!value)
    return nullptr;

  PyPrivateKeyObject* object =
      PyObject_New(PyPrivateKeyObject, &PyPrivateKeyType);
  if (!object)
    return nullptr;

  object->value = value;

  return (PyObject*)object;
}

TWPrivateKey* PyPrivateKey_GetTWPrivateKey(PyObject* object) {
  assert(PyPrivateKey_Check(object));
  return ((PyPrivateKeyObject*)object)->value;
}

// static int PyPrivateKey_init(PyPrivateKeyObject *self, PyObject *args,
// PyObject *kwds) {
//   return 0;
// }

// static PyObject* PyPrivateKey_new(PyTypeObject *subtype, PyObject *args,
// PyObject *kwds) {
//   int value = 0;
//   if (!PyArg_ParseTuple(args, "|i", &value)) {
//     return nullptr;
//   }
//   return PyPrivateKey_FromTWPrivateKey((TWPrivateKey)value);
// }

// static PyObject* PyPrivateKey_str(PyPrivateKeyObject *self) {
//   const char* str = "Unknown";
//   return PyUnicode_FromString(str);
// }

// static method function for IsValid
// bool TWPrivateKeyIsValid(TWData* data, enum TWCurve curve);
static PyObject* PyPrivateKeyIsValid(PyPrivateKeyObject* self,
                                     PyObject* const* args,
                                     Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyByteArray_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type ByteArray");
    return nullptr;
  }
  auto arg0 = PyByteArray_GetTWData(args[0]);

  if (!PyCurve_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Curve");
    return nullptr;
  }
  auto arg1 = PyCurve_GetTWCurve(args[1]);

  bool result = TWPrivateKeyIsValid(arg0.get(), arg1);
  return PyBool_FromLong(result);
}

static const PyGetSetDef get_set_defs[] = {{}};

static const PyMethodDef method_defs[] = {
    {"IsValid", (PyCFunction)PyPrivateKeyIsValid, METH_FASTCALL | METH_STATIC},
    {}};

bool PyInit_PrivateKey(PyObject* module) {
  // PyPrivateKeyType.tp_new = PyPrivateKey_new;
  // PyPrivateKeyType.tp_init = (initproc)PyPrivateKey_init;
  // PyPrivateKeyType.tp_str = (reprfunc)PyPrivateKey_str;
  PyPrivateKeyType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyPrivateKeyType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyPrivateKeyType) < 0)
    return false;

  Py_INCREF(&PyPrivateKeyType);
  if (PyModule_AddObject(module, "PrivateKey", (PyObject*)&PyPrivateKeyType) <
      0) {
    Py_DECREF(&PyPrivateKeyType);
    return false;
  }

  return true;
}