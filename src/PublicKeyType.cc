#include "PublicKeyType.h"

static PyTypeObject PyPublicKeyTypeType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "walletcore.PublicKeyType",      /* tp_name */
    sizeof(PyPublicKeyTypeObject),   /* tp_basicsize */
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

int PyPublicKeyType_init(PyPublicKeyTypeObject *self, PyObject *args, PyObject *kwds) {
    return 0;
}

bool PyInit_PublicKeyType(PyObject *module) {
    PyPublicKeyTypeType.tp_init = (initproc)PyPublicKeyType_init;
    PyPublicKeyTypeType.tp_new = PyType_GenericNew;

    if (PyType_Ready(&PyPublicKeyTypeType) < 0)
        return false;

    Py_INCREF(&PyPublicKeyTypeType);
    if (PyModule_AddObject(module, "PublicKeyType", (PyObject *) &PyPublicKeyTypeType) < 0) {
        Py_DECREF(&PyPublicKeyTypeType);
        return false;
    }

    // auto* o = PyObject_New(PyPublicKeyTypeObject, &PyPublicKeyTypeType);

    PyObject* dict = PyPublicKeyTypeType.tp_dict;
    (void)dict;

    PyDict_SetItemString(dict, "SECP256k1", PyLong_FromLong(TWPublicKeyTypeSECP256k1));
    PyDict_SetItemString(dict, "SECP256k1Extended", PyLong_FromLong(TWPublicKeyTypeSECP256k1Extended));
    PyDict_SetItemString(dict, "NIST256p1", PyLong_FromLong(TWPublicKeyTypeNIST256p1));
    PyDict_SetItemString(dict, "NIST256p1Extended", PyLong_FromLong(TWPublicKeyTypeNIST256p1Extended));
    PyDict_SetItemString(dict, "ED25519", PyLong_FromLong(TWPublicKeyTypeED25519));
    PyDict_SetItemString(dict, "ED25519Blake2b", PyLong_FromLong(TWPublicKeyTypeED25519Blake2b));
    PyDict_SetItemString(dict, "CURVE25519", PyLong_FromLong(TWPublicKeyTypeCURVE25519));
    PyDict_SetItemString(dict, "ED25519Extended", PyLong_FromLong(TWPublicKeyTypeED25519Extended));

    return true;
}