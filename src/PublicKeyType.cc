#include "PublicKeyType.h"

#define CONSTANTS(I) \
    I(SECP256k1) \
    I(SECP256k1Extended) \
    I(NIST256p1) \
    I(NIST256p1Extended) \
    I(ED25519) \
    I(ED25519Blake2b) \
    I(CURVE25519) \
    I(ED25519Extended) \

struct ValuePair {
    TWPublicKeyType value;
    PyObject* pyvalue;
};

#define I(name) { TWPublicKeyType##name, nullptr },
static ValuePair constants[] = {
    CONSTANTS(I)
};
#undef I

static PyTypeObject PyPublicKeyTypeType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "walletcore.PublicKeyType",      /* tp_name */
    sizeof(PyPublicKeyTypeObject),   /* tp_basicsize */
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

PyObject* PyPublicKeyType_FromTWPublicKeyType(TWPublicKeyType value) {
    ValuePair* p = nullptr;
    for (auto& constant : constants) {
        if (constant.value == value) {
            p = &constant;
            break;
        }
    }

    if (!p) {
        PyErr_Format(PyExc_ValueError, "Invalid PublicKeyType value: %d", value);
        return nullptr;
    }

    if (!p->pyvalue) {
        auto* pyvalue = PyObject_New(PyPublicKeyTypeObject, &PyPublicKeyTypeType);
        *const_cast<TWPublicKeyType*>(&pyvalue->value) = value;
        p->pyvalue = (PyObject*)pyvalue;
    }

    Py_INCREF(p->pyvalue);
    return p->pyvalue;
}

static int PyPublicKeyType_init(PyPublicKeyTypeObject *self, PyObject *args, PyObject *kwds) {
    return 0;
}

static PyObject* PyPublicKeyType_new(PyTypeObject *subtype, PyObject *args, PyObject *kwds) {
    int value = 0;
    if (!PyArg_ParseTuple(args, "|i", &value)) {
        return nullptr;
    }
    return PyPublicKeyType_FromTWPublicKeyType((TWPublicKeyType)value);
}

static PyObject* PyPublicKeyType_str(PyPublicKeyTypeObject *self) {
    const char* str = nullptr;
    switch(self->value) {
#define I(name) \
        case TWPublicKeyType##name: \
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

bool PyInit_PublicKeyType(PyObject *module) {
    PyPublicKeyTypeType.tp_new = PyPublicKeyType_new;
    PyPublicKeyTypeType.tp_init = (initproc)PyPublicKeyType_init;
    PyPublicKeyTypeType.tp_str = (reprfunc)PyPublicKeyType_str;

    if (PyType_Ready(&PyPublicKeyTypeType) < 0)
        return false;

    Py_INCREF(&PyPublicKeyTypeType);
    if (PyModule_AddObject(module, "PublicKeyType", (PyObject *) &PyPublicKeyTypeType) < 0) {
        Py_DECREF(&PyPublicKeyTypeType);
        return false;
    }

    PyObject* dict = PyPublicKeyTypeType.tp_dict;
    (void)dict;

#define I(name) \
    PyDict_SetItemString(dict, #name, PyPublicKeyType_FromTWPublicKeyType(TWPublicKeyType##name));
    CONSTANTS(I)
#undef I

    return true;
}