#include "Purpose.h"

static PyTypeObject PurposeType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "walletcore.Purpose",      /* tp_name */
    sizeof(PurposeObject),     /* tp_basicsize */
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

int Purpose_init(PurposeObject *self, PyObject *args, PyObject *kwds) {
    return 0;
}

bool Purpose_enum_init(PyObject *module) {
    
    PurposeType.tp_init = (initproc)Purpose_init;
    PurposeType.tp_new = PyType_GenericNew;

    if (PyType_Ready(&PurposeType) < 0)
        return false;
    
    Py_INCREF(&PurposeType);
    if (PyModule_AddObject(module, "Purpose", (PyObject *) &PurposeType) < 0) {
        Py_DECREF(&PurposeType);
        return false;
    }

    // auto* o = PyObject_New(PurposeObject, &PurposeType);

    PyObject* dict = PurposeType.tp_dict;
    (void)dict;

    PyDict_SetItemString(dict, "BIP44", PyLong_FromLong(TWPurposeBIP44));
    PyDict_SetItemString(dict, "BIP49", PyLong_FromLong(TWPurposeBIP49));
    PyDict_SetItemString(dict, "BIP84", PyLong_FromLong(TWPurposeBIP84));
    PyDict_SetItemString(dict, "BIP1852", PyLong_FromLong(TWPurposeBIP1852));

    return true;
}