// This is a GENERATED FILE, changes made here WILL BE LOST.

#include "Blockchain.h"

#include <algorithm>
#include <iterator>

#define CONSTANTS(I) \
  I(Bitcoin)         \
  I(Ethereum)        \
  I(Vechain)         \
  I(Tron)            \
  I(Icon)            \
  I(Binance)         \
  I(Ripple)          \
  I(Tezos)           \
  I(Nimiq)           \
  I(Stellar)         \
  I(Aion)            \
  I(Cosmos)          \
  I(Theta)           \
  I(Ontology)        \
  I(Zilliqa)         \
  I(IoTeX)           \
  I(EOS)             \
  I(Nano)            \
  I(NULS)            \
  I(Waves)           \
  I(Aeternity)       \
  I(Nebulas)         \
  I(FIO)             \
  I(Solana)          \
  I(Harmony)         \
  I(NEAR)            \
  I(Algorand)        \
  I(Polkadot)        \
  I(Cardano)         \
  I(NEO)             \
  I(Filecoin)        \
  I(ElrondNetwork)   \
  I(OasisNetwork)

static PyTypeObject PyBlockchainType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.Blockchain",    /* tp_name */
    sizeof(PyBlockchainObject), /* tp_basicsize */
    0,                          /* tp_itemsize */
    0,                          /* tp_dealloc */
    0,                          /* tp_print */
    0,                          /* tp_getattr */
    0,                          /* tp_setattr */
    0,                          /* tp_reserved */
    0,                          /* tp_repr */
    0,                          /* tp_as_number */
    0,                          /* tp_as_sequence */
    0,                          /* tp_as_mapping */
    0,                          /* tp_hash  */
    0,                          /* tp_call */
    0,                          /* tp_str */
    0,                          /* tp_getattro */
    0,                          /* tp_setattro */
    0,                          /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,         /* tp_flags */
    nullptr,                    /* tp_doc */
};

bool PyBlockchain_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyBlockchainType) != 0;
}

// Create PyBlockchain from enum TWBlockchain. It returns the same PyBlockchain
// instance for the same enum TWBlockchain value.
PyObject* PyBlockchain_FromTWBlockchain(TWBlockchain value) {
  struct ValuePair {
    const TWBlockchain value;
    PyObject* pyvalue;
  };
#define I(name) {TWBlockchain##name, nullptr},
  static ValuePair constants[] = {CONSTANTS(I)};
#undef I

  ValuePair* value_pair =
      std::find_if(std::begin(constants), std::end(constants),
                   [&value](const ValuePair& v) { return v.value == value; });

  if (!value_pair) {
    PyErr_Format(PyExc_ValueError, "Invalid Blockchain value: %d", value);
    return nullptr;
  }

  if (!value_pair->pyvalue) {
    auto* pyvalue = PyObject_New(PyBlockchainObject, &PyBlockchainType);
    *const_cast<TWBlockchain*>(&pyvalue->value) = value;
    value_pair->pyvalue = (PyObject*)pyvalue;
  }

  Py_INCREF(value_pair->pyvalue);
  return value_pair->pyvalue;
}

TWBlockchain PyBlockchain_GetTWBlockchain(PyObject* object) {
  assert(PyBlockchain_Check(object));
  return ((PyBlockchainObject*)object)->value;
}

static int PyBlockchain_init(PyBlockchainObject* self,
                             PyObject* args,
                             PyObject* kwds) {
  return 0;
}

static PyObject* PyBlockchain_new(PyTypeObject* subtype,
                                  PyObject* args,
                                  PyObject* kwds) {
  int value = 0;
  if (!PyArg_ParseTuple(args, "|i", &value)) {
    return nullptr;
  }
  return PyBlockchain_FromTWBlockchain((TWBlockchain)value);
}

static PyObject* PyBlockchain_str(PyBlockchainObject* self) {
  const char* str = "Unknown";
  switch (self->value) {
#define I(name)            \
  case TWBlockchain##name: \
    str = #name;           \
    break;
    CONSTANTS(I)
#undef I
  }
  return PyUnicode_FromString(str);
}

static const PyGetSetDef get_set_defs[] = {{}};

static const PyMethodDef method_defs[] = {{}};

bool PyInit_Blockchain(PyObject* module) {
  PyBlockchainType.tp_new = PyBlockchain_new;
  PyBlockchainType.tp_init = (initproc)PyBlockchain_init;
  PyBlockchainType.tp_str = (reprfunc)PyBlockchain_str;
  PyBlockchainType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyBlockchainType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyBlockchainType) < 0)
    return false;

  Py_INCREF(&PyBlockchainType);
  if (PyModule_AddObject(module, "Blockchain", (PyObject*)&PyBlockchainType) <
      0) {
    Py_DECREF(&PyBlockchainType);
    return false;
  }

  PyObject* dict = PyBlockchainType.tp_dict;
  (void)dict;

#define I(name)                     \
  PyDict_SetItemString(dict, #name, \
                       PyBlockchain_FromTWBlockchain(TWBlockchain##name));
  CONSTANTS(I)
#undef I

  return true;
}