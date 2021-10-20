// This is a GENERATED FILE, changes made here WILL BE LOST.

#include "BitcoinSigHashType.h"

#include <algorithm>
#include <iterator>

#define CONSTANTS(I) \
  I(All)             \
  I(None)            \
  I(Single)          \
  I(Fork)            \
  I(ForkBTG)         \
  I(AnyoneCanPay)

static PyTypeObject PyBitcoinSigHashTypeType = {
    PyVarObject_HEAD_INIT(NULL,
                          0) "walletcore.BitcoinSigHashType", /* tp_name */
    sizeof(PyBitcoinSigHashTypeObject),                       /* tp_basicsize */
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

bool PyBitcoinSigHashType_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyBitcoinSigHashTypeType) != 0;
}

// Create PyBitcoinSigHashType from enum TWBitcoinSigHashType. It returns the
// same PyBitcoinSigHashType instance for the same enum TWBitcoinSigHashType
// value.
PyObject* PyBitcoinSigHashType_FromTWBitcoinSigHashType(
    TWBitcoinSigHashType value) {
  struct ValuePair {
    const TWBitcoinSigHashType value;
    PyObject* pyvalue;
  };
#define I(name) {TWBitcoinSigHashType##name, nullptr},
  static ValuePair constants[] = {CONSTANTS(I)};
#undef I

  ValuePair* value_pair =
      std::find_if(std::begin(constants), std::end(constants),
                   [&value](const ValuePair& v) { return v.value == value; });

  if (!value_pair) {
    PyErr_Format(PyExc_ValueError, "Invalid BitcoinSigHashType value: %d",
                 value);
    return nullptr;
  }

  if (!value_pair->pyvalue) {
    auto* pyvalue =
        PyObject_New(PyBitcoinSigHashTypeObject, &PyBitcoinSigHashTypeType);
    *const_cast<TWBitcoinSigHashType*>(&pyvalue->value) = value;
    value_pair->pyvalue = (PyObject*)pyvalue;
  }

  Py_INCREF(value_pair->pyvalue);
  return value_pair->pyvalue;
}

static int PyBitcoinSigHashType_init(PyBitcoinSigHashTypeObject* self,
                                     PyObject* args,
                                     PyObject* kwds) {
  return 0;
}

static PyObject* PyBitcoinSigHashType_new(PyTypeObject* subtype,
                                          PyObject* args,
                                          PyObject* kwds) {
  int value = 0;
  if (!PyArg_ParseTuple(args, "|i", &value)) {
    return nullptr;
  }
  return PyBitcoinSigHashType_FromTWBitcoinSigHashType(
      (TWBitcoinSigHashType)value);
}

static PyObject* PyBitcoinSigHashType_str(PyBitcoinSigHashTypeObject* self) {
  const char* str = "Unknown";
  switch (self->value) {
#define I(name)                    \
  case TWBitcoinSigHashType##name: \
    str = #name;                   \
    break;
    CONSTANTS(I)
#undef I
  }
  return PyUnicode_FromString(str);
}

// method function for IsSingle
static PyObject* PyBitcoinSigHashTypeIsSingle(PyBitcoinSigHashTypeObject* self,
                                              PyObject* const* args,
                                              Py_ssize_t nargs) {
  if (nargs != 0) {
    PyErr_Format(PyExc_TypeError, "Expect 0 instead of %d.", nargs);
    return nullptr;
  }

  bool result = TWBitcoinSigHashTypeIsSingle(self->value);
  return PyBool_FromLong(result);
}

// method function for IsNone
static PyObject* PyBitcoinSigHashTypeIsNone(PyBitcoinSigHashTypeObject* self,
                                            PyObject* const* args,
                                            Py_ssize_t nargs) {
  if (nargs != 0) {
    PyErr_Format(PyExc_TypeError, "Expect 0 instead of %d.", nargs);
    return nullptr;
  }

  bool result = TWBitcoinSigHashTypeIsNone(self->value);
  return PyBool_FromLong(result);
}

static const PyGetSetDef get_set_defs[] = {{}};

static const PyMethodDef method_defs[] = {
    {"IsSingle", (PyCFunction)PyBitcoinSigHashTypeIsSingle, METH_FASTCALL},
    {"IsNone", (PyCFunction)PyBitcoinSigHashTypeIsNone, METH_FASTCALL},
    {}};

bool PyInit_BitcoinSigHashType(PyObject* module) {
  PyBitcoinSigHashTypeType.tp_new = PyBitcoinSigHashType_new;
  PyBitcoinSigHashTypeType.tp_init = (initproc)PyBitcoinSigHashType_init;
  PyBitcoinSigHashTypeType.tp_str = (reprfunc)PyBitcoinSigHashType_str;
  PyBitcoinSigHashTypeType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyBitcoinSigHashTypeType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyBitcoinSigHashTypeType) < 0)
    return false;

  Py_INCREF(&PyBitcoinSigHashTypeType);
  if (PyModule_AddObject(module, "BitcoinSigHashType",
                         (PyObject*)&PyBitcoinSigHashTypeType) < 0) {
    Py_DECREF(&PyBitcoinSigHashTypeType);
    return false;
  }

  PyObject* dict = PyBitcoinSigHashTypeType.tp_dict;
  (void)dict;

#define I(name)                                                       \
  PyDict_SetItemString(dict, #name,                                   \
                       PyBitcoinSigHashType_FromTWBitcoinSigHashType( \
                           TWBitcoinSigHashType##name));
  CONSTANTS(I)
#undef I

  return true;
}