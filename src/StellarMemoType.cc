#include "StellarMemoType.h"

static PyTypeObject PyStellarMemoTypeType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "walletcore.StellarMemoType",      /* tp_name */
    sizeof(PyStellarMemoTypeObject),   /* tp_basicsize */
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

int PyStellarMemoType_init(PyStellarMemoTypeObject *self, PyObject *args, PyObject *kwds) {
    return 0;
}

bool PyInit_StellarMemoType(PyObject *module) {
    PyStellarMemoTypeType.tp_init = (initproc)PyStellarMemoType_init;
    PyStellarMemoTypeType.tp_new = PyType_GenericNew;

    if (PyType_Ready(&PyStellarMemoTypeType) < 0)
        return false;

    Py_INCREF(&PyStellarMemoTypeType);
    if (PyModule_AddObject(module, "StellarMemoType", (PyObject *) &PyStellarMemoTypeType) < 0) {
        Py_DECREF(&PyStellarMemoTypeType);
        return false;
    }

    // auto* o = PyObject_New(PyStellarMemoTypeObject, &PyStellarMemoTypeType);

    PyObject* dict = PyStellarMemoTypeType.tp_dict;
    (void)dict;

    PyDict_SetItemString(dict, "None", PyLong_FromLong(TWStellarMemoTypeNone));
    PyDict_SetItemString(dict, "Text", PyLong_FromLong(TWStellarMemoTypeText));
    PyDict_SetItemString(dict, "Id", PyLong_FromLong(TWStellarMemoTypeId));
    PyDict_SetItemString(dict, "Hash", PyLong_FromLong(TWStellarMemoTypeHash));
    PyDict_SetItemString(dict, "Return", PyLong_FromLong(TWStellarMemoTypeReturn));

    return true;
}