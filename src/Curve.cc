#include "Curve.h"

static PyTypeObject CurveType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "walletcore.Curve",      /* tp_name */
    sizeof(CurveObject),     /* tp_basicsize */
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

int Curve_init(CurveObject *self, PyObject *args, PyObject *kwds) {
    return 0;
}

bool Curve_enum_init(PyObject *module) {
    
    CurveType.tp_init = (initproc)Curve_init;
    CurveType.tp_new = PyType_GenericNew;

    if (PyType_Ready(&CurveType) < 0)
        return false;
    
    Py_INCREF(&CurveType);
    if (PyModule_AddObject(module, "Curve", (PyObject *) &CurveType) < 0) {
        Py_DECREF(&CurveType);
        return false;
    }

    // auto* o = PyObject_New(CurveObject, &CurveType);

    PyObject* dict = CurveType.tp_dict;
    (void)dict;



    return true;
}