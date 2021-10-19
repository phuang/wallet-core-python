// This is a GENERATED FILE, changes made here WILL BE LOST.

#include "Purpose.h"



#define CONSTANTS(I) \
    I(BIP44) \
    I(BIP49) \
    I(BIP84) \
    I(BIP1852) \

PyTypeObject PyPurposeType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "walletcore.Purpose",      /* tp_name */
    sizeof(PyPurposeObject),   /* tp_basicsize */
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

PyObject* PyPurpose_FromTWPurpose(TWPurpose value) {
    struct ValuePair {
        TWPurpose value;
        PyObject* pyvalue;
    };
#define I(name) { TWPurpose##name, nullptr },
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
        PyErr_Format(PyExc_ValueError, "Invalid Purpose value: %d", value);
        return nullptr;
    }

    if (!value_pair->pyvalue) {
        auto* pyvalue = PyObject_New(PyPurposeObject, &PyPurposeType);
        *const_cast<TWPurpose*>(&pyvalue->value) = value;
        value_pair->pyvalue = (PyObject*)pyvalue;
    }

    Py_INCREF(value_pair->pyvalue);
    return value_pair->pyvalue;
}

static int PyPurpose_init(PyPurposeObject *self, PyObject *args, PyObject *kwds) {
    return 0;
}

static PyObject* PyPurpose_new(PyTypeObject *subtype, PyObject *args, PyObject *kwds) {
    int value = 0;
    if (!PyArg_ParseTuple(args, "|i", &value)) {
        return nullptr;
    }
    return PyPurpose_FromTWPurpose((TWPurpose)value);
}

static PyObject* PyPurpose_str(PyPurposeObject *self) {
    const char* str = "Unknown";
    switch(self->value) {
#define I(name) \
        case TWPurpose##name: \
            str = #name; \
            break;
        CONSTANTS(I)
#undef I
    }
    return PyUnicode_FromString(str);
}



static PyGetSetDef get_set_def[] = {
    
    {},
};

bool PyInit_Purpose(PyObject *module) {

    PyPurposeType.tp_new = PyPurpose_new;
    PyPurposeType.tp_init = (initproc)PyPurpose_init;
    PyPurposeType.tp_str = (reprfunc)PyPurpose_str;
    PyPurposeType.tp_getset = (PyGetSetDef*)get_set_def;

    if (PyType_Ready(&PyPurposeType) < 0)
        return false;

    Py_INCREF(&PyPurposeType);
    if (PyModule_AddObject(module, "Purpose", (PyObject *) &PyPurposeType) < 0) {
        Py_DECREF(&PyPurposeType);
        return false;
    }

    PyObject* dict = PyPurposeType.tp_dict;
    (void)dict;

#define I(name) \
    PyDict_SetItemString(dict, #name, PyPurpose_FromTWPurpose(TWPurpose##name));
    CONSTANTS(I)
#undef I

    return true;
}