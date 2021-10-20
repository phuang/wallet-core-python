// This is a GENERATED FILE, changes made here WILL BE LOST.

#include "EthereumAbiFunction.h"

#include "Bool.h"

static PyTypeObject PyEthereumAbiFunctionType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.EthereumAbiFunction",    /* tp_name */
    sizeof(PyEthereumAbiFunctionObject), /* tp_basicsize */
    0,                                   /* tp_itemsize */
    0,                                   /* tp_dealloc */
    0,                                   /* tp_print */
    0,                                   /* tp_getattr */
    0,                                   /* tp_setattr */
    0,                                   /* tp_reserved */
    0,                                   /* tp_repr */
    0,                                   /* tp_as_number */
    0,                                   /* tp_as_sequence */
    0,                                   /* tp_as_mapping */
    0,                                   /* tp_hash  */
    0,                                   /* tp_call */
    0,                                   /* tp_str */
    0,                                   /* tp_getattro */
    0,                                   /* tp_setattro */
    0,                                   /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                  /* tp_flags */
    nullptr,                             /* tp_doc */
};

bool PyEthereumAbiFunction_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyEthereumAbiFunctionType) != 0;
}

// Create PyEthereumAbiFunction from enum TWEthereumAbiFunction.
PyObject* PyEthereumAbiFunction_FromTWEthereumAbiFunction(
    TWEthereumAbiFunction* value) {
  if (!value)
    return nullptr;

  PyEthereumAbiFunctionObject* object =
      PyObject_New(PyEthereumAbiFunctionObject, &PyEthereumAbiFunctionType);
  if (!object)
    return nullptr;

  object->value = value;

  return (PyObject*)object;
}

TWEthereumAbiFunction* PyEthereumAbiFunction_GetTWEthereumAbiFunction(
    PyObject* object) {
  assert(PyEthereumAbiFunction_Check(object));
  return ((PyEthereumAbiFunctionObject*)object)->value;
}

// static int PyEthereumAbiFunction_init(PyEthereumAbiFunctionObject *self,
// PyObject *args, PyObject *kwds) {
//   return 0;
// }

// static PyObject* PyEthereumAbiFunction_new(PyTypeObject *subtype, PyObject
// *args, PyObject *kwds) {
//   int value = 0;
//   if (!PyArg_ParseTuple(args, "|i", &value)) {
//     return nullptr;
//   }
//   return
//   PyEthereumAbiFunction_FromTWEthereumAbiFunction((TWEthereumAbiFunction)value);
// }

// static PyObject* PyEthereumAbiFunction_str(PyEthereumAbiFunctionObject *self)
// {
//   const char* str = "Unknown";
//   return PyUnicode_FromString(str);
// }

// method function for GetParamUInt8
// uint8_t TWEthereumAbiFunctionGetParamUInt8(struct TWEthereumAbiFunction* fn,
// int idx, bool isOutput);
static PyObject* PyEthereumAbiFunctionGetParamUInt8(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyLong_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Long");
    return nullptr;
  }
  auto arg0 = PyLong_AsLong(args[0]);

  if (!PyBool_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bool");
    return nullptr;
  }
  auto arg1 = PyBool_IsTrue(args[1]);

  uint8_t result = TWEthereumAbiFunctionGetParamUInt8(self->value, arg0, arg1);
  return PyLong_FromLong(result);
}

// method function for GetParamBool
// bool TWEthereumAbiFunctionGetParamBool(struct TWEthereumAbiFunction* fn, int
// idx, bool isOutput);
static PyObject* PyEthereumAbiFunctionGetParamBool(
    PyEthereumAbiFunctionObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyLong_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type Long");
    return nullptr;
  }
  auto arg0 = PyLong_AsLong(args[0]);

  if (!PyBool_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Bool");
    return nullptr;
  }
  auto arg1 = PyBool_IsTrue(args[1]);

  bool result = TWEthereumAbiFunctionGetParamBool(self->value, arg0, arg1);
  return PyBool_FromLong(result);
}

static const PyGetSetDef get_set_defs[] = {{}};

static const PyMethodDef method_defs[] = {
    {"GetParamUInt8", (PyCFunction)PyEthereumAbiFunctionGetParamUInt8,
     METH_FASTCALL},
    {"GetParamBool", (PyCFunction)PyEthereumAbiFunctionGetParamBool,
     METH_FASTCALL},
    {}};

bool PyInit_EthereumAbiFunction(PyObject* module) {
  // PyEthereumAbiFunctionType.tp_new = PyEthereumAbiFunction_new;
  // PyEthereumAbiFunctionType.tp_init = (initproc)PyEthereumAbiFunction_init;
  // PyEthereumAbiFunctionType.tp_str = (reprfunc)PyEthereumAbiFunction_str;
  PyEthereumAbiFunctionType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyEthereumAbiFunctionType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyEthereumAbiFunctionType) < 0)
    return false;

  Py_INCREF(&PyEthereumAbiFunctionType);
  if (PyModule_AddObject(module, "EthereumAbiFunction",
                         (PyObject*)&PyEthereumAbiFunctionType) < 0) {
    Py_DECREF(&PyEthereumAbiFunctionType);
    return false;
  }

  return true;
}