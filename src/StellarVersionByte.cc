// This is a GENERATED FILE, changes made here WILL BE LOST.

#include "StellarVersionByte.h"

#include <algorithm>
#include <iterator>

#define CONSTANTS(I) \
  I(AccountID)       \
  I(Seed)            \
  I(PreAuthTX)       \
  I(SHA256Hash)

static PyTypeObject PyStellarVersionByteType = {
    PyVarObject_HEAD_INIT(NULL,
                          0) "walletcore.StellarVersionByte", /* tp_name */
    sizeof(PyStellarVersionByteObject),                       /* tp_basicsize */
    0,                                                        /* tp_itemsize */
    0,                                                        /* tp_dealloc */
    0,                                                        /* tp_print */
    0,                                                        /* tp_getattr */
    0,                                                        /* tp_setattr */
    0,                                                        /* tp_reserved */
    0,                                                        /* tp_repr */
    0,                                                        /* tp_as_number */
    0,                  /* tp_as_sequence */
    0,                  /* tp_as_mapping */
    0,                  /* tp_hash  */
    0,                  /* tp_call */
    0,                  /* tp_str */
    0,                  /* tp_getattro */
    0,                  /* tp_setattro */
    0,                  /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT, /* tp_flags */
    nullptr,            /* tp_doc */
};

bool PyStellarVersionByte_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyStellarVersionByteType) != 0;
}

// Create PyStellarVersionByte from enum TWStellarVersionByte. It returns the
// same PyStellarVersionByte instance for the same enum TWStellarVersionByte
// value.
PyObject* PyStellarVersionByte_FromTWStellarVersionByte(
    TWStellarVersionByte value) {
  struct ValuePair {
    const TWStellarVersionByte value;
    PyObject* pyvalue;
  };
#define I(name) {TWStellarVersionByte##name, nullptr},
  static ValuePair constants[] = {CONSTANTS(I)};
#undef I

  ValuePair* value_pair =
      std::find_if(std::begin(constants), std::end(constants),
                   [&value](const ValuePair& v) { return v.value == value; });

  if (!value_pair) {
    PyErr_Format(PyExc_ValueError, "Invalid StellarVersionByte value: %d",
                 value);
    return nullptr;
  }

  if (!value_pair->pyvalue) {
    auto* pyvalue =
        PyObject_New(PyStellarVersionByteObject, &PyStellarVersionByteType);
    *const_cast<TWStellarVersionByte*>(&pyvalue->value) = value;
    value_pair->pyvalue = (PyObject*)pyvalue;
  }

  Py_INCREF(value_pair->pyvalue);
  return value_pair->pyvalue;
}

static int PyStellarVersionByte_init(PyStellarVersionByteObject* self,
                                     PyObject* args,
                                     PyObject* kwds) {
  return 0;
}

static PyObject* PyStellarVersionByte_new(PyTypeObject* subtype,
                                          PyObject* args,
                                          PyObject* kwds) {
  int value = 0;
  if (!PyArg_ParseTuple(args, "|i", &value)) {
    return nullptr;
  }
  return PyStellarVersionByte_FromTWStellarVersionByte(
      (TWStellarVersionByte)value);
}

static PyObject* PyStellarVersionByte_str(PyStellarVersionByteObject* self) {
  const char* str = "Unknown";
  switch (self->value) {
#define I(name)                    \
  case TWStellarVersionByte##name: \
    str = #name;                   \
    break;
    CONSTANTS(I)
#undef I
  }
  return PyUnicode_FromString(str);
}

static const PyGetSetDef get_set_defs[] = {{}};

static const PyMethodDef method_defs[] = {{}};

bool PyInit_StellarVersionByte(PyObject* module) {
  PyStellarVersionByteType.tp_new = PyStellarVersionByte_new;
  PyStellarVersionByteType.tp_init = (initproc)PyStellarVersionByte_init;
  PyStellarVersionByteType.tp_str = (reprfunc)PyStellarVersionByte_str;
  PyStellarVersionByteType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyStellarVersionByteType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyStellarVersionByteType) < 0)
    return false;

  Py_INCREF(&PyStellarVersionByteType);
  if (PyModule_AddObject(module, "StellarVersionByte",
                         (PyObject*)&PyStellarVersionByteType) < 0) {
    Py_DECREF(&PyStellarVersionByteType);
    return false;
  }

  PyObject* dict = PyStellarVersionByteType.tp_dict;
  (void)dict;

#define I(name)                                                       \
  PyDict_SetItemString(dict, #name,                                   \
                       PyStellarVersionByte_FromTWStellarVersionByte( \
                           TWStellarVersionByte##name));
  CONSTANTS(I)
#undef I

  return true;
}