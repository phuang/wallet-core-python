// This is a GENERATED FILE, changes made here WILL BE LOST.

#include "EthereumAbi.h"

static PyTypeObject PyEthereumAbiType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.EthereumAbi",    /* tp_name */
    sizeof(PyEthereumAbiObject), /* tp_basicsize */
    0,                           /* tp_itemsize */
    0,                           /* tp_dealloc */
    0,                           /* tp_print */
    0,                           /* tp_getattr */
    0,                           /* tp_setattr */
    0,                           /* tp_reserved */
    0,                           /* tp_repr */
    0,                           /* tp_as_number */
    0,                           /* tp_as_sequence */
    0,                           /* tp_as_mapping */
    0,                           /* tp_hash  */
    0,                           /* tp_call */
    0,                           /* tp_str */
    0,                           /* tp_getattro */
    0,                           /* tp_setattro */
    0,                           /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,          /* tp_flags */
    nullptr,                     /* tp_doc */
};

bool PyEthereumAbi_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyEthereumAbiType) != 0;
}

// Create PyEthereumAbi from enum TWEthereumAbi.
PyObject* PyEthereumAbi_FromTWEthereumAbi(TWEthereumAbi* value) {
  if (!value)
    return nullptr;

  PyEthereumAbiObject* object =
      PyObject_New(PyEthereumAbiObject, &PyEthereumAbiType);
  if (!object)
    return nullptr;

  object->value = value;

  return (PyObject*)object;
}

// static int PyEthereumAbi_init(PyEthereumAbiObject *self, PyObject *args,
// PyObject *kwds) {
//   return 0;
// }

// static PyObject* PyEthereumAbi_new(PyTypeObject *subtype, PyObject *args,
// PyObject *kwds) {
//   int value = 0;
//   if (!PyArg_ParseTuple(args, "|i", &value)) {
//     return nullptr;
//   }
//   return PyEthereumAbi_FromTWEthereumAbi((TWEthereumAbi)value);
// }

// static PyObject* PyEthereumAbi_str(PyEthereumAbiObject *self) {
//   const char* str = "Unknown";
//   return PyUnicode_FromString(str);
// }

static const PyGetSetDef get_set_defs[] = {{}};

static const PyMethodDef method_defs[] = {{}};

bool PyInit_EthereumAbi(PyObject* module) {
  // PyEthereumAbiType.tp_new = PyEthereumAbi_new;
  // PyEthereumAbiType.tp_init = (initproc)PyEthereumAbi_init;
  // PyEthereumAbiType.tp_str = (reprfunc)PyEthereumAbi_str;
  PyEthereumAbiType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyEthereumAbiType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyEthereumAbiType) < 0)
    return false;

  Py_INCREF(&PyEthereumAbiType);
  if (PyModule_AddObject(module, "EthereumAbi", (PyObject*)&PyEthereumAbiType) <
      0) {
    Py_DECREF(&PyEthereumAbiType);
    return false;
  }

  return true;
}