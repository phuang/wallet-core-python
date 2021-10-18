#include "SS58AddressType.h"

static PyTypeObject PySS58AddressTypeType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "walletcore.SS58AddressType",      /* tp_name */
    sizeof(PySS58AddressTypeObject),   /* tp_basicsize */
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

int PySS58AddressType_init(PySS58AddressTypeObject *self, PyObject *args, PyObject *kwds) {
    return 0;
}

bool PyInit_SS58AddressType(PyObject *module) {
    PySS58AddressTypeType.tp_init = (initproc)PySS58AddressType_init;
    PySS58AddressTypeType.tp_new = PyType_GenericNew;

    if (PyType_Ready(&PySS58AddressTypeType) < 0)
        return false;

    Py_INCREF(&PySS58AddressTypeType);
    if (PyModule_AddObject(module, "SS58AddressType", (PyObject *) &PySS58AddressTypeType) < 0) {
        Py_DECREF(&PySS58AddressTypeType);
        return false;
    }

    // auto* o = PyObject_New(PySS58AddressTypeObject, &PySS58AddressTypeType);

    PyObject* dict = PySS58AddressTypeType.tp_dict;
    (void)dict;

    PyDict_SetItemString(dict, "Polkadot", PyLong_FromLong(TWSS58AddressTypePolkadot));
    PyDict_SetItemString(dict, "Kusama", PyLong_FromLong(TWSS58AddressTypeKusama));

    return true;
}