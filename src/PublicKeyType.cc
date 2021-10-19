// This is a GENERATED FILE, changes made here WILL BE LOST.

#include "PublicKeyType.h"

#include <algorithm>
#include <iterator>

#define CONSTANTS(I)   \
  I(SECP256k1)         \
  I(SECP256k1Extended) \
  I(NIST256p1)         \
  I(NIST256p1Extended) \
  I(ED25519)           \
  I(ED25519Blake2b)    \
  I(CURVE25519)        \
  I(ED25519Extended)

static PyTypeObject PyPublicKeyTypeType = {
    PyVarObject_HEAD_INIT(NULL, 0) "walletcore.PublicKeyType", /* tp_name */
    sizeof(PyPublicKeyTypeObject), /* tp_basicsize */
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

bool PyPublicKeyType_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyPublicKeyTypeType) != 0;
}

// Create PyPublicKeyType from enum TWPublicKeyType. It returns the same
// PyPublicKeyType instance for the same enum TWPublicKeyType value.
PyObject* PyPublicKeyType_FromTWPublicKeyType(TWPublicKeyType value) {
  struct ValuePair {
    const TWPublicKeyType value;
    PyObject* pyvalue;
  };
#define I(name) {TWPublicKeyType##name, nullptr},
  static ValuePair constants[] = {CONSTANTS(I)};
#undef I

  ValuePair* value_pair =
      std::find_if(std::begin(constants), std::end(constants),
                   [&value](const ValuePair& v) { return v.value == value; });

  if (!value_pair) {
    PyErr_Format(PyExc_ValueError, "Invalid PublicKeyType value: %d", value);
    return nullptr;
  }

  if (!value_pair->pyvalue) {
    auto* pyvalue = PyObject_New(PyPublicKeyTypeObject, &PyPublicKeyTypeType);
    *const_cast<TWPublicKeyType*>(&pyvalue->value) = value;
    value_pair->pyvalue = (PyObject*)pyvalue;
  }

  Py_INCREF(value_pair->pyvalue);
  return value_pair->pyvalue;
}

static int PyPublicKeyType_init(PyPublicKeyTypeObject* self,
                                PyObject* args,
                                PyObject* kwds) {
  return 0;
}

static PyObject* PyPublicKeyType_new(PyTypeObject* subtype,
                                     PyObject* args,
                                     PyObject* kwds) {
  int value = 0;
  if (!PyArg_ParseTuple(args, "|i", &value)) {
    return nullptr;
  }
  return PyPublicKeyType_FromTWPublicKeyType((TWPublicKeyType)value);
}

static PyObject* PyPublicKeyType_str(PyPublicKeyTypeObject* self) {
  const char* str = "Unknown";
  switch (self->value) {
#define I(name)               \
  case TWPublicKeyType##name: \
    str = #name;              \
    break;
    CONSTANTS(I)
#undef I
  }
  return PyUnicode_FromString(str);
}

static const PyGetSetDef get_set_defs[] = {{}};

static const PyMethodDef method_defs[] = {{}};

bool PyInit_PublicKeyType(PyObject* module) {
  PyPublicKeyTypeType.tp_new = PyPublicKeyType_new;
  PyPublicKeyTypeType.tp_init = (initproc)PyPublicKeyType_init;
  PyPublicKeyTypeType.tp_str = (reprfunc)PyPublicKeyType_str;
  PyPublicKeyTypeType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyPublicKeyTypeType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyPublicKeyTypeType) < 0)
    return false;

  Py_INCREF(&PyPublicKeyTypeType);
  if (PyModule_AddObject(module, "PublicKeyType",
                         (PyObject*)&PyPublicKeyTypeType) < 0) {
    Py_DECREF(&PyPublicKeyTypeType);
    return false;
  }

  PyObject* dict = PyPublicKeyTypeType.tp_dict;
  (void)dict;

#define I(name)         \
  PyDict_SetItemString( \
      dict, #name,      \
      PyPublicKeyType_FromTWPublicKeyType(TWPublicKeyType##name));
  CONSTANTS(I)
#undef I

  return true;
}