#include "SS58AddressType.h"

#define CONSTANTS(I) \
    I(Polkadot) \
    I(Kusama) \

struct ValuePair {
    TWSS58AddressType value;
    PyObject* pyvalue;
};

#define I(name) { TWSS58AddressType##name, nullptr },
static ValuePair constants[] = {
    CONSTANTS(I)
};
#undef I

static PyTypeObject PySS58AddressTypeType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "walletcore.SS58AddressType",      /* tp_name */
    sizeof(PySS58AddressTypeObject),   /* tp_basicsize */
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

PyObject* PySS58AddressType_FromTWSS58AddressType(TWSS58AddressType value) {
    ValuePair* p = nullptr;
    for (auto& constant : constants) {
        if (constant.value == value) {
            p = &constant;
            break;
        }
    }

    if (!p) {
        PyErr_Format(PyExc_ValueError, "Invalid SS58AddressType value: %d", value);
        return nullptr;
    }

    if (!p->pyvalue) {
        auto* pyvalue = PyObject_New(PySS58AddressTypeObject, &PySS58AddressTypeType);
        *const_cast<TWSS58AddressType*>(&pyvalue->value) = value;
        p->pyvalue = (PyObject*)pyvalue;
    }

    Py_INCREF(p->pyvalue);
    return p->pyvalue;
}

static int PySS58AddressType_init(PySS58AddressTypeObject *self, PyObject *args, PyObject *kwds) {
    return 0;
}

static PyObject* PySS58AddressType_new(PyTypeObject *subtype, PyObject *args, PyObject *kwds) {
    int value = 0;
    if (!PyArg_ParseTuple(args, "|i", &value)) {
        return nullptr;
    }
    return PySS58AddressType_FromTWSS58AddressType((TWSS58AddressType)value);
}

static PyObject* PySS58AddressType_str(PySS58AddressTypeObject *self) {
    const char* str = nullptr;
    switch(self->value) {
#define I(name) \
        case TWSS58AddressType##name: \
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

bool PyInit_SS58AddressType(PyObject *module) {
    PySS58AddressTypeType.tp_new = PySS58AddressType_new;
    PySS58AddressTypeType.tp_init = (initproc)PySS58AddressType_init;
    PySS58AddressTypeType.tp_str = (reprfunc)PySS58AddressType_str;

    if (PyType_Ready(&PySS58AddressTypeType) < 0)
        return false;

    Py_INCREF(&PySS58AddressTypeType);
    if (PyModule_AddObject(module, "SS58AddressType", (PyObject *) &PySS58AddressTypeType) < 0) {
        Py_DECREF(&PySS58AddressTypeType);
        return false;
    }

    PyObject* dict = PySS58AddressTypeType.tp_dict;
    (void)dict;

#define I(name) \
    PyDict_SetItemString(dict, #name, PySS58AddressType_FromTWSS58AddressType(TWSS58AddressType##name));
    CONSTANTS(I)
#undef I

    return true;
}