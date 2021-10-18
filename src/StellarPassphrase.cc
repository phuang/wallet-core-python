#include "StellarPassphrase.h"

static PyTypeObject PyStellarPassphraseType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "walletcore.StellarPassphrase",      /* tp_name */
    sizeof(PyStellarPassphraseObject),   /* tp_basicsize */
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

int PyStellarPassphrase_init(PyStellarPassphraseObject *self, PyObject *args, PyObject *kwds) {
    return 0;
}

bool PyInit_StellarPassphrase(PyObject *module) {
    PyStellarPassphraseType.tp_init = (initproc)PyStellarPassphrase_init;
    PyStellarPassphraseType.tp_new = PyType_GenericNew;

    if (PyType_Ready(&PyStellarPassphraseType) < 0)
        return false;

    Py_INCREF(&PyStellarPassphraseType);
    if (PyModule_AddObject(module, "StellarPassphrase", (PyObject *) &PyStellarPassphraseType) < 0) {
        Py_DECREF(&PyStellarPassphraseType);
        return false;
    }

    // auto* o = PyObject_New(PyStellarPassphraseObject, &PyStellarPassphraseType);

    PyObject* dict = PyStellarPassphraseType.tp_dict;
    (void)dict;



    return true;
}