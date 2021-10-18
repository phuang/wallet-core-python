#include "StellarVersionByte.h"

static PyTypeObject StellarVersionByteType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "walletcore.StellarVersionByte",      /* tp_name */
    sizeof(StellarVersionByteObject),     /* tp_basicsize */
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

int StellarVersionByte_init(StellarVersionByteObject *self, PyObject *args, PyObject *kwds) {
    return 0;
}

bool StellarVersionByte_enum_init(PyObject *module) {
    
    StellarVersionByteType.tp_init = (initproc)StellarVersionByte_init;
    StellarVersionByteType.tp_new = PyType_GenericNew;

    if (PyType_Ready(&StellarVersionByteType) < 0)
        return false;
    
    Py_INCREF(&StellarVersionByteType);
    if (PyModule_AddObject(module, "StellarVersionByte", (PyObject *) &StellarVersionByteType) < 0) {
        Py_DECREF(&StellarVersionByteType);
        return false;
    }

    // auto* o = PyObject_New(StellarVersionByteObject, &StellarVersionByteType);

    PyObject* dict = StellarVersionByteType.tp_dict;
    (void)dict;

    PyDict_SetItemString(dict, "AccountID", PyLong_FromLong(TWStellarVersionByteAccountID));
    PyDict_SetItemString(dict, "Seed", PyLong_FromLong(TWStellarVersionByteSeed));
    PyDict_SetItemString(dict, "PreAuthTX", PyLong_FromLong(TWStellarVersionBytePreAuthTX));
    PyDict_SetItemString(dict, "SHA256Hash", PyLong_FromLong(TWStellarVersionByteSHA256Hash));

    return true;
}