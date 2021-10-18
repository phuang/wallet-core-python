// This is a GENERATED FILE, changes made here WILL BE LOST.

#include "Blockchain.h"

#define CONSTANTS(I) \
    I(Bitcoin) \
    I(Ethereum) \
    I(Vechain) \
    I(Tron) \
    I(Icon) \
    I(Binance) \
    I(Ripple) \
    I(Tezos) \
    I(Nimiq) \
    I(Stellar) \
    I(Aion) \
    I(Cosmos) \
    I(Theta) \
    I(Ontology) \
    I(Zilliqa) \
    I(IoTeX) \
    I(EOS) \
    I(Nano) \
    I(NULS) \
    I(Waves) \
    I(Aeternity) \
    I(Nebulas) \
    I(FIO) \
    I(Solana) \
    I(Harmony) \
    I(NEAR) \
    I(Algorand) \
    I(Polkadot) \
    I(Cardano) \
    I(NEO) \
    I(Filecoin) \
    I(ElrondNetwork) \
    I(OasisNetwork) \

struct ValuePair {
    TWBlockchain value;
    PyObject* pyvalue;
};

#define I(name) { TWBlockchain##name, nullptr },
static ValuePair constants[] = {
    CONSTANTS(I)
};
#undef I

static PyTypeObject PyBlockchainType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "walletcore.Blockchain",      /* tp_name */
    sizeof(PyBlockchainObject),   /* tp_basicsize */
    0,                         /* tp_itemsize */
    0,                         /* tp_dealloc */
    0,                         /* tp_print */
    0,                         /* tp_getattr */
    0,                         /* tp_setattr */
    0,                         /* tp_reserved */
    0,                         /* tp_repr */
    0,                         /* tp_as_number */
    0,                         /* tp_as_sequence */
    0,                         /* tp_as_mapping */
    0,                         /* tp_hash  */
    0,                         /* tp_call */
    0,                         /* tp_str */
    0,                         /* tp_getattro */
    0,                         /* tp_setattro */
    0,                         /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,        /* tp_flags */
    nullptr,                   /* tp_doc */
};

PyObject* PyBlockchain_FromTWBlockchain(TWBlockchain value) {
    ValuePair* value_pair = nullptr;
    for (auto& constant : constants) {
        if (constant.value == value) {
            value_pair = &constant;
            break;
        }
    }

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

static int PyBlockchain_init(PyBlockchainObject *self, PyObject *args, PyObject *kwds) {
    return 0;
}

static PyObject* PyBlockchain_new(PyTypeObject *subtype, PyObject *args, PyObject *kwds) {
    int value = 0;
    if (!PyArg_ParseTuple(args, "|i", &value)) {
        return nullptr;
    }
    return PyBlockchain_FromTWBlockchain((TWBlockchain)value);
}

static PyObject* PyBlockchain_str(PyBlockchainObject *self) {
    const char* str = nullptr;
    switch(self->value) {
#define I(name) \
        case TWBlockchain##name: \
            str = #name; \
            break;
        CONSTANTS(I)
#undef I
      default:
        str = "Unknown";
        break;
    }
    return PyUnicode_FromString(str);
}

bool PyInit_Blockchain(PyObject *module) {
    PyBlockchainType.tp_new = PyBlockchain_new;
    PyBlockchainType.tp_init = (initproc)PyBlockchain_init;
    PyBlockchainType.tp_str = (reprfunc)PyBlockchain_str;

    if (PyType_Ready(&PyBlockchainType) < 0)
        return false;

    Py_INCREF(&PyBlockchainType);
    if (PyModule_AddObject(module, "Blockchain", (PyObject *) &PyBlockchainType) < 0) {
        Py_DECREF(&PyBlockchainType);
        return false;
    }

    PyObject* dict = PyBlockchainType.tp_dict;
    (void)dict;

#define I(name) \
    PyDict_SetItemString(dict, #name, PyBlockchain_FromTWBlockchain(TWBlockchain##name));
    CONSTANTS(I)
#undef I

    return true;
}