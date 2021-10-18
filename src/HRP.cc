#include "HRP.h"

static PyTypeObject HRPType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "walletcore.HRP",      /* tp_name */
    sizeof(HRPObject),     /* tp_basicsize */
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

int HRP_init(HRPObject *self, PyObject *args, PyObject *kwds) {
    return 0;
}

bool HRP_enum_init(PyObject *module) {
    
    HRPType.tp_init = (initproc)HRP_init;
    HRPType.tp_new = PyType_GenericNew;

    if (PyType_Ready(&HRPType) < 0)
        return false;
    
    Py_INCREF(&HRPType);
    if (PyModule_AddObject(module, "HRP", (PyObject *) &HRPType) < 0) {
        Py_DECREF(&HRPType);
        return false;
    }

    // auto* o = PyObject_New(HRPObject, &HRPType);

    PyObject* dict = HRPType.tp_dict;
    (void)dict;



    return true;
}