// This is a GENERATED FILE, changes made here WILL BE LOST.

#include "Curve.h"

#include <algorithm>
#include <iterator>

#define CONSTANTS(I)    \
  I(SECP256k1)          \
  I(ED25519)            \
  I(ED25519Blake2bNano) \
  I(Curve25519)         \
  I(NIST256p1)          \
  I(ED25519Extended)    \
  I(None)

static PyTypeObject PyCurveType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.Curve",    /* tp_name */
    sizeof(PyCurveObject), /* tp_basicsize */
    0,                     /* tp_itemsize */
    0,                     /* tp_dealloc */
    0,                     /* tp_print */
    0,                     /* tp_getattr */
    0,                     /* tp_setattr */
    0,                     /* tp_reserved */
    0,                     /* tp_repr */
    0,                     /* tp_as_number */
    0,                     /* tp_as_sequence */
    0,                     /* tp_as_mapping */
    0,                     /* tp_hash  */
    0,                     /* tp_call */
    0,                     /* tp_str */
    0,                     /* tp_getattro */
    0,                     /* tp_setattro */
    0,                     /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,    /* tp_flags */
    nullptr,               /* tp_doc */
};

bool PyCurve_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyCurveType) != 0;
}

// Create PyCurve from enum TWCurve. It returns the same PyCurve instance
// for the same enum TWCurve value.
PyObject* PyCurve_FromTWCurve(TWCurve value) {
  struct ValuePair {
    const TWCurve value;
    PyObject* pyvalue;
  };
#define I(name) {TWCurve##name, nullptr},
  static ValuePair constants[] = {CONSTANTS(I)};
#undef I

  ValuePair* value_pair =
      std::find_if(std::begin(constants), std::end(constants),
                   [&value](const ValuePair& v) { return v.value == value; });

  if (!value_pair) {
    PyErr_Format(PyExc_ValueError, "Invalid Curve value: %d", value);
    return nullptr;
  }

  if (!value_pair->pyvalue) {
    auto* pyvalue = PyObject_New(PyCurveObject, &PyCurveType);
    *const_cast<TWCurve*>(&pyvalue->value) = value;
    value_pair->pyvalue = (PyObject*)pyvalue;
  }

  Py_INCREF(value_pair->pyvalue);
  return value_pair->pyvalue;
}

TWCurve PyCurve_GetTWCurve(PyObject* object) {
  assert(PyCurve_Check(object));
  return ((PyCurveObject*)object)->value;
}

static int PyCurve_init(PyCurveObject* self, PyObject* args, PyObject* kwds) {
  return 0;
}

static PyObject* PyCurve_new(PyTypeObject* subtype,
                             PyObject* args,
                             PyObject* kwds) {
  int value = 0;
  if (!PyArg_ParseTuple(args, "|i", &value)) {
    return nullptr;
  }
  return PyCurve_FromTWCurve((TWCurve)value);
}

static PyObject* PyCurve_str(PyCurveObject* self) {
  const char* str = "Unknown";
  switch (self->value) {
#define I(name)       \
  case TWCurve##name: \
    str = #name;      \
    break;
    CONSTANTS(I)
#undef I
  }
  return PyUnicode_FromString(str);
}

static const PyGetSetDef get_set_defs[] = {{}};

static const PyMethodDef method_defs[] = {{}};

bool PyInit_Curve(PyObject* module) {
  PyCurveType.tp_new = PyCurve_new;
  PyCurveType.tp_init = (initproc)PyCurve_init;
  PyCurveType.tp_str = (reprfunc)PyCurve_str;
  PyCurveType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyCurveType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyCurveType) < 0)
    return false;

  Py_INCREF(&PyCurveType);
  if (PyModule_AddObject(module, "Curve", (PyObject*)&PyCurveType) < 0) {
    Py_DECREF(&PyCurveType);
    return false;
  }

  PyObject* dict = PyCurveType.tp_dict;
  (void)dict;

#define I(name) \
  PyDict_SetItemString(dict, #name, PyCurve_FromTWCurve(TWCurve##name));
  CONSTANTS(I)
#undef I

  return true;
}