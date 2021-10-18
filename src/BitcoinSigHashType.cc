// This is a GENERATED FILE, changes made here WILL BE LOST.

#include "BitcoinSigHashType.h"

#define CONSTANTS(I) \
    I(All) \
    I(None) \
    I(Single) \
    I(Fork) \
    I(ForkBTG) \

struct ValuePair {
    TWBitcoinSigHashType value;
    PyObject* pyvalue;
};

#define I(name) { TWBitcoinSigHashType##name, nullptr },
static ValuePair constants[] = {
    CONSTANTS(I)
};
#undef I

static PyTypeObject PyBitcoinSigHashTypeType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "walletcore.BitcoinSigHashType",      /* tp_name */
    sizeof(PyBitcoinSigHashTypeObject),   /* tp_basicsize */
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

PyObject* PyBitcoinSigHashType_FromTWBitcoinSigHashType(TWBitcoinSigHashType value) {
    ValuePair* value_pair = nullptr;
    for (auto& constant : constants) {
        if (constant.value == value) {
            value_pair = &constant;
            break;
        }
    }

    if (!value_pair) {
        PyErr_Format(PyExc_ValueError, "Invalid BitcoinSigHashType value: %d", value);
        return nullptr;
    }

    if (!value_pair->pyvalue) {
        auto* pyvalue = PyObject_New(PyBitcoinSigHashTypeObject, &PyBitcoinSigHashTypeType);
        *const_cast<TWBitcoinSigHashType*>(&pyvalue->value) = value;
        value_pair->pyvalue = (PyObject*)pyvalue;
    }

    Py_INCREF(value_pair->pyvalue);
    return value_pair->pyvalue;
}

static int PyBitcoinSigHashType_init(PyBitcoinSigHashTypeObject *self, PyObject *args, PyObject *kwds) {
    return 0;
}

static PyObject* PyBitcoinSigHashType_new(PyTypeObject *subtype, PyObject *args, PyObject *kwds) {
    int value = 0;
    if (!PyArg_ParseTuple(args, "|i", &value)) {
        return nullptr;
    }
    return PyBitcoinSigHashType_FromTWBitcoinSigHashType((TWBitcoinSigHashType)value);
}

static PyObject* PyBitcoinSigHashType_str(PyBitcoinSigHashTypeObject *self) {
    const char* str = nullptr;
    switch(self->value) {
#define I(name) \
        case TWBitcoinSigHashType##name: \
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

bool PyInit_BitcoinSigHashType(PyObject *module) {
    PyBitcoinSigHashTypeType.tp_new = PyBitcoinSigHashType_new;
    PyBitcoinSigHashTypeType.tp_init = (initproc)PyBitcoinSigHashType_init;
    PyBitcoinSigHashTypeType.tp_str = (reprfunc)PyBitcoinSigHashType_str;

    if (PyType_Ready(&PyBitcoinSigHashTypeType) < 0)
        return false;

    Py_INCREF(&PyBitcoinSigHashTypeType);
    if (PyModule_AddObject(module, "BitcoinSigHashType", (PyObject *) &PyBitcoinSigHashTypeType) < 0) {
        Py_DECREF(&PyBitcoinSigHashTypeType);
        return false;
    }

    PyObject* dict = PyBitcoinSigHashTypeType.tp_dict;
    (void)dict;

#define I(name) \
    PyDict_SetItemString(dict, #name, PyBitcoinSigHashType_FromTWBitcoinSigHashType(TWBitcoinSigHashType##name));
    CONSTANTS(I)
#undef I

    return true;
}