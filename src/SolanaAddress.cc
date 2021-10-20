// This is a GENERATED FILE, changes made here WILL BE LOST.

#include "SolanaAddress.h"

static PyTypeObject PySolanaAddressType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.SolanaAddress",    /* tp_name */
    sizeof(PySolanaAddressObject), /* tp_basicsize */
    0,                             /* tp_itemsize */
    0,                             /* tp_dealloc */
    0,                             /* tp_print */
    0,                             /* tp_getattr */
    0,                             /* tp_setattr */
    0,                             /* tp_reserved */
    0,                             /* tp_repr */
    0,                             /* tp_as_number */
    0,                             /* tp_as_sequence */
    0,                             /* tp_as_mapping */
    0,                             /* tp_hash  */
    0,                             /* tp_call */
    0,                             /* tp_str */
    0,                             /* tp_getattro */
    0,                             /* tp_setattro */
    0,                             /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,            /* tp_flags */
    nullptr,                       /* tp_doc */
};

bool PySolanaAddress_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PySolanaAddressType) != 0;
}

// Create PySolanaAddress from enum TWSolanaAddress.
PyObject* PySolanaAddress_FromTWSolanaAddress(TWSolanaAddress* value) {
  if (!value)
    return nullptr;

  PySolanaAddressObject* object =
      PyObject_New(PySolanaAddressObject, &PySolanaAddressType);
  if (!object)
    return nullptr;

  object->value = value;

  return (PyObject*)object;
}

// static int PySolanaAddress_init(PySolanaAddressObject *self, PyObject *args,
// PyObject *kwds) {
//   return 0;
// }

// static PyObject* PySolanaAddress_new(PyTypeObject *subtype, PyObject *args,
// PyObject *kwds) {
//   int value = 0;
//   if (!PyArg_ParseTuple(args, "|i", &value)) {
//     return nullptr;
//   }
//   return PySolanaAddress_FromTWSolanaAddress((TWSolanaAddress)value);
// }

// static PyObject* PySolanaAddress_str(PySolanaAddressObject *self) {
//   const char* str = "Unknown";
//   return PyUnicode_FromString(str);
// }

static const PyGetSetDef get_set_defs[] = {{}};

static const PyMethodDef method_defs[] = {{}};

bool PyInit_SolanaAddress(PyObject* module) {
  // PySolanaAddressType.tp_new = PySolanaAddress_new;
  // PySolanaAddressType.tp_init = (initproc)PySolanaAddress_init;
  // PySolanaAddressType.tp_str = (reprfunc)PySolanaAddress_str;
  PySolanaAddressType.tp_getset = (PyGetSetDef*)get_set_defs;
  PySolanaAddressType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PySolanaAddressType) < 0)
    return false;

  Py_INCREF(&PySolanaAddressType);
  if (PyModule_AddObject(module, "SolanaAddress",
                         (PyObject*)&PySolanaAddressType) < 0) {
    Py_DECREF(&PySolanaAddressType);
    return false;
  }

  return true;
}