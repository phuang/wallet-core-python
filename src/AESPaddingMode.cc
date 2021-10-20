// This is a GENERATED FILE, changes made here WILL BE LOST.

#include "AESPaddingMode.h"

#include <algorithm>
#include <iterator>

#define CONSTANTS(I) \
  I(Zero)            \
  I(PKCS7)

static PyTypeObject PyAESPaddingModeType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.AESPaddingMode",    /* tp_name */
    sizeof(PyAESPaddingModeObject), /* tp_basicsize */
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

bool PyAESPaddingMode_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyAESPaddingModeType) != 0;
}

// Create PyAESPaddingMode from enum TWAESPaddingMode. It returns the same
// PyAESPaddingMode instance for the same enum TWAESPaddingMode value.
PyObject* PyAESPaddingMode_FromTWAESPaddingMode(TWAESPaddingMode value) {
  struct ValuePair {
    const TWAESPaddingMode value;
    PyObject* pyvalue;
  };
#define I(name) {TWAESPaddingMode##name, nullptr},
  static ValuePair constants[] = {CONSTANTS(I)};
#undef I

  ValuePair* value_pair =
      std::find_if(std::begin(constants), std::end(constants),
                   [&value](const ValuePair& v) { return v.value == value; });

  if (!value_pair) {
    PyErr_Format(PyExc_ValueError, "Invalid AESPaddingMode value: %d", value);
    return nullptr;
  }

  if (!value_pair->pyvalue) {
    auto* pyvalue = PyObject_New(PyAESPaddingModeObject, &PyAESPaddingModeType);
    *const_cast<TWAESPaddingMode*>(&pyvalue->value) = value;
    value_pair->pyvalue = (PyObject*)pyvalue;
  }

  Py_INCREF(value_pair->pyvalue);
  return value_pair->pyvalue;
}

static int PyAESPaddingMode_init(PyAESPaddingModeObject* self,
                                 PyObject* args,
                                 PyObject* kwds) {
  return 0;
}

static PyObject* PyAESPaddingMode_new(PyTypeObject* subtype,
                                      PyObject* args,
                                      PyObject* kwds) {
  int value = 0;
  if (!PyArg_ParseTuple(args, "|i", &value)) {
    return nullptr;
  }
  return PyAESPaddingMode_FromTWAESPaddingMode((TWAESPaddingMode)value);
}

static PyObject* PyAESPaddingMode_str(PyAESPaddingModeObject* self) {
  const char* str = "Unknown";
  switch (self->value) {
#define I(name)                \
  case TWAESPaddingMode##name: \
    str = #name;               \
    break;
    CONSTANTS(I)
#undef I
  }
  return PyUnicode_FromString(str);
}

static const PyGetSetDef get_set_defs[] = {{}};

static const PyMethodDef method_defs[] = {{}};

bool PyInit_AESPaddingMode(PyObject* module) {
  PyAESPaddingModeType.tp_new = PyAESPaddingMode_new;
  PyAESPaddingModeType.tp_init = (initproc)PyAESPaddingMode_init;
  PyAESPaddingModeType.tp_str = (reprfunc)PyAESPaddingMode_str;
  PyAESPaddingModeType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyAESPaddingModeType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyAESPaddingModeType) < 0)
    return false;

  Py_INCREF(&PyAESPaddingModeType);
  if (PyModule_AddObject(module, "AESPaddingMode",
                         (PyObject*)&PyAESPaddingModeType) < 0) {
    Py_DECREF(&PyAESPaddingModeType);
    return false;
  }

  PyObject* dict = PyAESPaddingModeType.tp_dict;
  (void)dict;

#define I(name)         \
  PyDict_SetItemString( \
      dict, #name,      \
      PyAESPaddingMode_FromTWAESPaddingMode(TWAESPaddingMode##name));
  CONSTANTS(I)
#undef I

  return true;
}