// This is a GENERATED FILE, changes made here WILL BE LOST.

#include "HRP.h"

#include <algorithm>
#include <iterator>

#define CONSTANTS(I)                                                           \
  I(Unknown)                                                                   \
  I(Bitcoin)                                                                   \
  I(Litecoin)                                                                  \
  I(Viacoin)                                                                   \
  I(Groestlcoin)                                                               \
  I(DigiByte)                                                                  \
  I(Monacoin)                                                                  \
  I(Cosmos)                                                                    \
  I(BitcoinCash)                                                               \
  I(BitcoinGold)                                                               \
  I(IoTeX)                                                                     \
  I(Zilliqa)                                                                   \
  I(Terra)                                                                     \
  I(CryptoOrg)                                                                 \
  I(Kava)                                                                      \
  I(Oasis)                                                                     \
  I(Bluzelle)                                                                  \
  I(BandChain)                                                                 \
  I(Elrond)                                                                    \
  I(Binance)                                                                   \
  I(THORChain)                                                                 \
  I(Harmony)                                                                   \
  I(Cardano)                                                                   \
  I(Qtum)

static PyTypeObject PyHRPType = {
    PyVarObject_HEAD_INIT(NULL, 0) "walletcore.HRP", /* tp_name */
    sizeof(PyHRPObject),                             /* tp_basicsize */
    0,                                               /* tp_itemsize */
    0,                                               /* tp_dealloc */
    0,                                               /* tp_print */
    0,                                               /* tp_getattr */
    0,                                               /* tp_setattr */
    0,                                               /* tp_reserved */
    0,                                               /* tp_repr */
    0,                                               /* tp_as_number */
    0,                                               /* tp_as_sequence */
    0,                                               /* tp_as_mapping */
    0,                                               /* tp_hash  */
    0,                                               /* tp_call */
    0,                                               /* tp_str */
    0,                                               /* tp_getattro */
    0,                                               /* tp_setattro */
    0,                                               /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                              /* tp_flags */
    nullptr,                                         /* tp_doc */
};

bool PyHRP_Check(PyObject *object) {
  return PyObject_TypeCheck(object, &PyHRPType) != 0;
}

// Create PyHRP from enum TWHRP. It returns the same PyHRP instance
// for the same enum TWHRP value.
PyObject *PyHRP_FromTWHRP(TWHRP value) {
  struct ValuePair {
    const TWHRP value;
    PyObject *pyvalue;
  };
#define I(name) {TWHRP##name, nullptr},
  static ValuePair constants[] = {CONSTANTS(I)};
#undef I

  ValuePair *value_pair =
      std::find_if(std::begin(constants), std::end(constants),
                   [&value](const ValuePair &v) { return v.value == value; });

  if (!value_pair) {
    PyErr_Format(PyExc_ValueError, "Invalid HRP value: %d", value);
    return nullptr;
  }

  if (!value_pair->pyvalue) {
    auto *pyvalue = PyObject_New(PyHRPObject, &PyHRPType);
    *const_cast<TWHRP *>(&pyvalue->value) = value;
    value_pair->pyvalue = (PyObject *)pyvalue;
  }

  Py_INCREF(value_pair->pyvalue);
  return value_pair->pyvalue;
}

static int PyHRP_init(PyHRPObject *self, PyObject *args, PyObject *kwds) {
  return 0;
}

static PyObject *PyHRP_new(PyTypeObject *subtype, PyObject *args,
                           PyObject *kwds) {
  int value = 0;
  if (!PyArg_ParseTuple(args, "|i", &value)) {
    return nullptr;
  }
  return PyHRP_FromTWHRP((TWHRP)value);
}

static PyObject *PyHRP_str(PyHRPObject *self) {
  const char *str = "Unknown";
  switch (self->value) {
#define I(name)                                                                \
  case TWHRP##name:                                                            \
    str = #name;                                                               \
    break;
    CONSTANTS(I)
#undef I
  }
  return PyUnicode_FromString(str);
}

static const PyGetSetDef get_set_def[] = {{}};

static const PyMethodDef method_def[] = {{}};

bool PyInit_HRP(PyObject *module) {

  PyHRPType.tp_new = PyHRP_new;
  PyHRPType.tp_init = (initproc)PyHRP_init;
  PyHRPType.tp_str = (reprfunc)PyHRP_str;
  PyHRPType.tp_getset = (PyGetSetDef *)get_set_def;
  PyHRPType.tp_methods = (PyMethodDef *)method_def;

  if (PyType_Ready(&PyHRPType) < 0)
    return false;

  Py_INCREF(&PyHRPType);
  if (PyModule_AddObject(module, "HRP", (PyObject *)&PyHRPType) < 0) {
    Py_DECREF(&PyHRPType);
    return false;
  }

  PyObject *dict = PyHRPType.tp_dict;
  (void)dict;

#define I(name) PyDict_SetItemString(dict, #name, PyHRP_FromTWHRP(TWHRP##name));
  CONSTANTS(I)
#undef I

  return true;
}