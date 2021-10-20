// This is a GENERATED FILE, changes made here WILL BE LOST.

#include "EthereumAbiValue.h"

static PyTypeObject PyEthereumAbiValueType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.EthereumAbiValue",    /* tp_name */
    sizeof(PyEthereumAbiValueObject), /* tp_basicsize */
    0,                                /* tp_itemsize */
    0,                                /* tp_dealloc */
    0,                                /* tp_print */
    0,                                /* tp_getattr */
    0,                                /* tp_setattr */
    0,                                /* tp_reserved */
    0,                                /* tp_repr */
    0,                                /* tp_as_number */
    0,                                /* tp_as_sequence */
    0,                                /* tp_as_mapping */
    0,                                /* tp_hash  */
    0,                                /* tp_call */
    0,                                /* tp_str */
    0,                                /* tp_getattro */
    0,                                /* tp_setattro */
    0,                                /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,               /* tp_flags */
    nullptr,                          /* tp_doc */
};

bool PyEthereumAbiValue_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyEthereumAbiValueType) != 0;
}

// Create PyEthereumAbiValue from enum TWEthereumAbiValue.
PyObject* PyEthereumAbiValue_FromTWEthereumAbiValue(TWEthereumAbiValue* value) {
  if (!value)
    return nullptr;

  PyEthereumAbiValueObject* object =
      PyObject_New(PyEthereumAbiValueObject, &PyEthereumAbiValueType);
  if (!object)
    return nullptr;

  object->value = value;

  return (PyObject*)object;
}

// static int PyEthereumAbiValue_init(PyEthereumAbiValueObject *self, PyObject
// *args, PyObject *kwds) {
//   return 0;
// }

// static PyObject* PyEthereumAbiValue_new(PyTypeObject *subtype, PyObject
// *args, PyObject *kwds) {
//   int value = 0;
//   if (!PyArg_ParseTuple(args, "|i", &value)) {
//     return nullptr;
//   }
//   return
//   PyEthereumAbiValue_FromTWEthereumAbiValue((TWEthereumAbiValue)value);
// }

// static PyObject* PyEthereumAbiValue_str(PyEthereumAbiValueObject *self) {
//   const char* str = "Unknown";
//   return PyUnicode_FromString(str);
// }

static const PyGetSetDef get_set_defs[] = {{}};

static const PyMethodDef method_defs[] = {{}};

bool PyInit_EthereumAbiValue(PyObject* module) {
  // PyEthereumAbiValueType.tp_new = PyEthereumAbiValue_new;
  // PyEthereumAbiValueType.tp_init = (initproc)PyEthereumAbiValue_init;
  // PyEthereumAbiValueType.tp_str = (reprfunc)PyEthereumAbiValue_str;
  PyEthereumAbiValueType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyEthereumAbiValueType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyEthereumAbiValueType) < 0)
    return false;

  Py_INCREF(&PyEthereumAbiValueType);
  if (PyModule_AddObject(module, "EthereumAbiValue",
                         (PyObject*)&PyEthereumAbiValueType) < 0) {
    Py_DECREF(&PyEthereumAbiValueType);
    return false;
  }

  return true;
}