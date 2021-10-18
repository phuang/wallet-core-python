// This is a GENERATED FILE, changes made here WILL BE LOST.

#include "EthereumChainID.h"

#define CONSTANTS(I) \
    I(Ethereum) \
    I(Go) \
    I(POA) \
    I(Callisto) \
    I(EthereumClassic) \
    I(VeChain) \
    I(ThunderToken) \
    I(TomoChain) \
    I(BinanceSmartChain) \
    I(Polygon) \
    I(Wanchain) \
    I(Optimism) \
    I(Arbitrum) \
    I(Heco) \
    I(Avalanche) \
    I(XDai) \
    I(Fantom) \
    I(Celo) \
    I(Ronin) \

struct ValuePair {
    TWEthereumChainID value;
    PyObject* pyvalue;
};

PyTypeObject PyEthereumChainIDType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "walletcore.EthereumChainID",      /* tp_name */
    sizeof(PyEthereumChainIDObject),   /* tp_basicsize */
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

PyObject* PyEthereumChainID_FromTWEthereumChainID(TWEthereumChainID value) {

#define I(name) { TWEthereumChainID##name, nullptr },
    static ValuePair constants[] = {
        CONSTANTS(I)
    };
#undef I

    ValuePair* value_pair = nullptr;
    for (auto& constant : constants) {
        if (constant.value == value) {
            value_pair = &constant;
            break;
        }
    }

    if (!value_pair) {
        PyErr_Format(PyExc_ValueError, "Invalid EthereumChainID value: %d", value);
        return nullptr;
    }

    if (!value_pair->pyvalue) {
        auto* pyvalue = PyObject_New(PyEthereumChainIDObject, &PyEthereumChainIDType);
        *const_cast<TWEthereumChainID*>(&pyvalue->value) = value;
        value_pair->pyvalue = (PyObject*)pyvalue;
    }

    Py_INCREF(value_pair->pyvalue);
    return value_pair->pyvalue;
}

static int PyEthereumChainID_init(PyEthereumChainIDObject *self, PyObject *args, PyObject *kwds) {
    return 0;
}

static PyObject* PyEthereumChainID_new(PyTypeObject *subtype, PyObject *args, PyObject *kwds) {
    int value = 0;
    if (!PyArg_ParseTuple(args, "|i", &value)) {
        return nullptr;
    }
    return PyEthereumChainID_FromTWEthereumChainID((TWEthereumChainID)value);
}

static PyObject* PyEthereumChainID_str(PyEthereumChainIDObject *self) {
    const char* str = nullptr;
    switch(self->value) {
#define I(name) \
        case TWEthereumChainID##name: \
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

bool PyInit_EthereumChainID(PyObject *module) {
    PyEthereumChainIDType.tp_new = PyEthereumChainID_new;
    PyEthereumChainIDType.tp_init = (initproc)PyEthereumChainID_init;
    PyEthereumChainIDType.tp_str = (reprfunc)PyEthereumChainID_str;

    if (PyType_Ready(&PyEthereumChainIDType) < 0)
        return false;

    Py_INCREF(&PyEthereumChainIDType);
    if (PyModule_AddObject(module, "EthereumChainID", (PyObject *) &PyEthereumChainIDType) < 0) {
        Py_DECREF(&PyEthereumChainIDType);
        return false;
    }

    PyObject* dict = PyEthereumChainIDType.tp_dict;
    (void)dict;

#define I(name) \
    PyDict_SetItemString(dict, #name, PyEthereumChainID_FromTWEthereumChainID(TWEthereumChainID##name));
    CONSTANTS(I)
#undef I

    return true;
}