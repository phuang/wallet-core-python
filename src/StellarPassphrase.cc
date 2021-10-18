#include "StellarPassphrase.h"

static PyTypeObject StellarPassphraseType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "walletcore.StellarPassphrase",      /* tp_name */
    sizeof(StellarPassphraseObject),     /* tp_basicsize */
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

int StellarPassphrase_init(StellarPassphraseObject *self, PyObject *args, PyObject *kwds) {
    return 0;
}

bool StellarPassphrase_enum_init(PyObject *module) {
    
    StellarPassphraseType.tp_init = (initproc)StellarPassphrase_init;
    StellarPassphraseType.tp_new = PyType_GenericNew;

    if (PyType_Ready(&StellarPassphraseType) < 0)
        return false;
    
    Py_INCREF(&StellarPassphraseType);
    if (PyModule_AddObject(module, "StellarPassphrase", (PyObject *) &StellarPassphraseType) < 0) {
        Py_DECREF(&StellarPassphraseType);
        return false;
    }

    // auto* o = PyObject_New(StellarPassphraseObject, &StellarPassphraseType);

    PyObject* dict = StellarPassphraseType.tp_dict;
    (void)dict;



    return true;
}