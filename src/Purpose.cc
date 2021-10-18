#include "Purpose.h"

static PyTypeObject PyPurposeType = {
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

int PyPurpose_init(PyPurposeObject *self, PyObject *args, PyObject *kwds) {
    return 0;
}

bool PyInit_Purpose(PyObject *module) {
    PyPurposeType.tp_init = (initproc)PyPurpose_init;
    PyPurposeType.tp_new = PyType_GenericNew;

    if (PyType_Ready(&PyPurposeType) < 0)
        return false;

    Py_INCREF(&PyPurposeType);
    if (PyModule_AddObject(module, "Purpose", (PyObject *) &PyPurposeType) < 0) {
        Py_DECREF(&PyPurposeType);
        return false;
    }

    // auto* o = PyObject_New(PyPurposeObject, &PyPurposeType);

    PyObject* dict = PyPurposeType.tp_dict;
    (void)dict;

    PyDict_SetItemString(dict, "BIP44", PyLong_FromLong(TWPurposeBIP44));
    PyDict_SetItemString(dict, "BIP49", PyLong_FromLong(TWPurposeBIP49));
    PyDict_SetItemString(dict, "BIP84", PyLong_FromLong(TWPurposeBIP84));
    PyDict_SetItemString(dict, "BIP1852", PyLong_FromLong(TWPurposeBIP1852));

    return true;
}