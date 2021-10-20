// This is a GENERATED FILE, changes made here WILL BE LOST.

#include "StellarPassphrase.h"

#include <algorithm>
#include <iterator>

#define CONSTANTS(I) \
  I(Stellar)         \
  I(Kin)

static PyTypeObject PyStellarPassphraseType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.StellarPassphrase",    /* tp_name */
    sizeof(PyStellarPassphraseObject), /* tp_basicsize */
    0,                                 /* tp_itemsize */
    0,                                 /* tp_dealloc */
    0,                                 /* tp_print */
    0,                                 /* tp_getattr */
    0,                                 /* tp_setattr */
    0,                                 /* tp_reserved */
    0,                                 /* tp_repr */
    0,                                 /* tp_as_number */
    0,                                 /* tp_as_sequence */
    0,                                 /* tp_as_mapping */
    0,                                 /* tp_hash  */
    0,                                 /* tp_call */
    0,                                 /* tp_str */
    0,                                 /* tp_getattro */
    0,                                 /* tp_setattro */
    0,                                 /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                /* tp_flags */
    nullptr,                           /* tp_doc */
};

bool PyStellarPassphrase_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyStellarPassphraseType) != 0;
}

// Create PyStellarPassphrase from enum TWStellarPassphrase. It returns the same
// PyStellarPassphrase instance for the same enum TWStellarPassphrase value.
PyObject* PyStellarPassphrase_FromTWStellarPassphrase(
    TWStellarPassphrase value) {
  struct ValuePair {
    const TWStellarPassphrase value;
    PyObject* pyvalue;
  };
#define I(name) {TWStellarPassphrase##name, nullptr},
  static ValuePair constants[] = {CONSTANTS(I)};
#undef I

  ValuePair* value_pair =
      std::find_if(std::begin(constants), std::end(constants),
                   [&value](const ValuePair& v) { return v.value == value; });

  if (!value_pair) {
    PyErr_Format(PyExc_ValueError, "Invalid StellarPassphrase value: %d",
                 value);
    return nullptr;
  }

  if (!value_pair->pyvalue) {
    auto* pyvalue =
        PyObject_New(PyStellarPassphraseObject, &PyStellarPassphraseType);
    *const_cast<TWStellarPassphrase*>(&pyvalue->value) = value;
    value_pair->pyvalue = (PyObject*)pyvalue;
  }

  Py_INCREF(value_pair->pyvalue);
  return value_pair->pyvalue;
}

TWStellarPassphrase PyStellarPassphrase_GetTWStellarPassphrase(
    PyObject* object) {
  assert(PyStellarPassphrase_Check(object));
  return ((PyStellarPassphraseObject*)object)->value;
}

static int PyStellarPassphrase_init(PyStellarPassphraseObject* self,
                                    PyObject* args,
                                    PyObject* kwds) {
  return 0;
}

static PyObject* PyStellarPassphrase_new(PyTypeObject* subtype,
                                         PyObject* args,
                                         PyObject* kwds) {
  int value = 0;
  if (!PyArg_ParseTuple(args, "|i", &value)) {
    return nullptr;
  }
  return PyStellarPassphrase_FromTWStellarPassphrase(
      (TWStellarPassphrase)value);
}

static PyObject* PyStellarPassphrase_str(PyStellarPassphraseObject* self) {
  const char* str = "Unknown";
  switch (self->value) {
#define I(name)                   \
  case TWStellarPassphrase##name: \
    str = #name;                  \
    break;
    CONSTANTS(I)
#undef I
  }
  return PyUnicode_FromString(str);
}

static const PyGetSetDef get_set_defs[] = {{}};

static const PyMethodDef method_defs[] = {{}};

bool PyInit_StellarPassphrase(PyObject* module) {
  PyStellarPassphraseType.tp_new = PyStellarPassphrase_new;
  PyStellarPassphraseType.tp_init = (initproc)PyStellarPassphrase_init;
  PyStellarPassphraseType.tp_str = (reprfunc)PyStellarPassphrase_str;
  PyStellarPassphraseType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyStellarPassphraseType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyStellarPassphraseType) < 0)
    return false;

  Py_INCREF(&PyStellarPassphraseType);
  if (PyModule_AddObject(module, "StellarPassphrase",
                         (PyObject*)&PyStellarPassphraseType) < 0) {
    Py_DECREF(&PyStellarPassphraseType);
    return false;
  }

  PyObject* dict = PyStellarPassphraseType.tp_dict;
  (void)dict;

#define I(name)         \
  PyDict_SetItemString( \
      dict, #name,      \
      PyStellarPassphrase_FromTWStellarPassphrase(TWStellarPassphrase##name));
  CONSTANTS(I)
#undef I

  return true;
}