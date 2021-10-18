#include "HRP.h"

static PyTypeObject PyHRPType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "walletcore.HRP",      /* tp_name */
    sizeof(PyHRPObject),   /* tp_basicsize */
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

int PyHRP_init(PyHRPObject *self, PyObject *args, PyObject *kwds) {
    return 0;
}

bool PyInit_HRP(PyObject *module) {
    PyHRPType.tp_init = (initproc)PyHRP_init;
    PyHRPType.tp_new = PyType_GenericNew;

    if (PyType_Ready(&PyHRPType) < 0)
        return false;

    Py_INCREF(&PyHRPType);
    if (PyModule_AddObject(module, "HRP", (PyObject *) &PyHRPType) < 0) {
        Py_DECREF(&PyHRPType);
        return false;
    }

    // auto* o = PyObject_New(PyHRPObject, &PyHRPType);

    PyObject* dict = PyHRPType.tp_dict;
    (void)dict;



    return true;
}