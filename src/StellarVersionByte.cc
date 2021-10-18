#include "StellarVersionByte.h"

static PyTypeObject PyStellarVersionByteType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "walletcore.StellarVersionByte",      /* tp_name */
    sizeof(PyStellarVersionByteObject),   /* tp_basicsize */
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

int PyStellarVersionByte_init(PyStellarVersionByteObject *self, PyObject *args, PyObject *kwds) {
    return 0;
}

bool PyInit_StellarVersionByte(PyObject *module) {
    PyStellarVersionByteType.tp_init = (initproc)PyStellarVersionByte_init;
    PyStellarVersionByteType.tp_new = PyType_GenericNew;

    if (PyType_Ready(&PyStellarVersionByteType) < 0)
        return false;

    Py_INCREF(&PyStellarVersionByteType);
    if (PyModule_AddObject(module, "StellarVersionByte", (PyObject *) &PyStellarVersionByteType) < 0) {
        Py_DECREF(&PyStellarVersionByteType);
        return false;
    }

    // auto* o = PyObject_New(PyStellarVersionByteObject, &PyStellarVersionByteType);

    PyObject* dict = PyStellarVersionByteType.tp_dict;
    (void)dict;

    PyDict_SetItemString(dict, "AccountID", PyLong_FromLong(TWStellarVersionByteAccountID));
    PyDict_SetItemString(dict, "Seed", PyLong_FromLong(TWStellarVersionByteSeed));
    PyDict_SetItemString(dict, "PreAuthTX", PyLong_FromLong(TWStellarVersionBytePreAuthTX));
    PyDict_SetItemString(dict, "SHA256Hash", PyLong_FromLong(TWStellarVersionByteSHA256Hash));

    return true;
}