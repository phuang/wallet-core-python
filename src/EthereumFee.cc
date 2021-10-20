// This is a GENERATED FILE, changes made here WILL BE LOST.

#include "EthereumFee.h"

#include "String.h"

static PyTypeObject PyEthereumFeeType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.EthereumFee",    /* tp_name */
    sizeof(PyEthereumFeeObject), /* tp_basicsize */
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

bool PyEthereumFee_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyEthereumFeeType) != 0;
}

// Create PyEthereumFee from enum TWEthereumFee.
PyObject* PyEthereumFee_FromTWEthereumFee(TWEthereumFee* value) {
  if (!value)
    return nullptr;

  PyEthereumFeeObject* object =
      PyObject_New(PyEthereumFeeObject, &PyEthereumFeeType);
  if (!object)
    return nullptr;

  object->value = value;

  return (PyObject*)object;
}

TWEthereumFee* PyEthereumFee_GetTWEthereumFee(PyObject* object) {
  assert(PyEthereumFee_Check(object));
  return ((PyEthereumFeeObject*)object)->value;
}

// static int PyEthereumFee_init(PyEthereumFeeObject *self, PyObject *args,
// PyObject *kwds) {
//   return 0;
// }

// static PyObject* PyEthereumFee_new(PyTypeObject *subtype, PyObject *args,
// PyObject *kwds) {
//   int value = 0;
//   if (!PyArg_ParseTuple(args, "|i", &value)) {
//     return nullptr;
//   }
//   return PyEthereumFee_FromTWEthereumFee((TWEthereumFee)value);
// }

// static PyObject* PyEthereumFee_str(PyEthereumFeeObject *self) {
//   const char* str = "Unknown";
//   return PyUnicode_FromString(str);
// }

// static method function for Suggest
// TWString* TWEthereumFeeSuggest(TWString* feeHistory);
static PyObject* PyEthereumFeeSuggest(PyEthereumFeeObject* self,
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

  TWStringPtr result = TWEthereumFeeSuggest(arg0.get());
  return PyUnicode_FromTWString(result);
}

static const PyGetSetDef get_set_defs[] = {{}};

static const PyMethodDef method_defs[] = {
    {"Suggest", (PyCFunction)PyEthereumFeeSuggest, METH_FASTCALL | METH_STATIC},
    {}};

bool PyInit_EthereumFee(PyObject* module) {
  // PyEthereumFeeType.tp_new = PyEthereumFee_new;
  // PyEthereumFeeType.tp_init = (initproc)PyEthereumFee_init;
  // PyEthereumFeeType.tp_str = (reprfunc)PyEthereumFee_str;
  PyEthereumFeeType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyEthereumFeeType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyEthereumFeeType) < 0)
    return false;

  Py_INCREF(&PyEthereumFeeType);
  if (PyModule_AddObject(module, "EthereumFee", (PyObject*)&PyEthereumFeeType) <
      0) {
    Py_DECREF(&PyEthereumFeeType);
    return false;
  }

  return true;
}