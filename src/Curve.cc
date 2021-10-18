#include "Curve.h"

static PyTypeObject PyCurveType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "walletcore.Curve",      /* tp_name */
    sizeof(PyCurveObject),   /* tp_basicsize */
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

int PyCurve_init(PyCurveObject *self, PyObject *args, PyObject *kwds) {
    return 0;
}

bool PyInit_Curve(PyObject *module) {
    PyCurveType.tp_init = (initproc)PyCurve_init;
    PyCurveType.tp_new = PyType_GenericNew;

    if (PyType_Ready(&PyCurveType) < 0)
        return false;

    Py_INCREF(&PyCurveType);
    if (PyModule_AddObject(module, "Curve", (PyObject *) &PyCurveType) < 0) {
        Py_DECREF(&PyCurveType);
        return false;
    }

    // auto* o = PyObject_New(PyCurveObject, &PyCurveType);

    PyObject* dict = PyCurveType.tp_dict;
    (void)dict;



    return true;
}