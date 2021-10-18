#include "AESPaddingMode.h"

static PyTypeObject PyAESPaddingModeType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "walletcore.AESPaddingMode",      /* tp_name */
    sizeof(PyAESPaddingModeObject),   /* tp_basicsize */
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

int PyAESPaddingMode_init(PyAESPaddingModeObject *self, PyObject *args, PyObject *kwds) {
    return 0;
}

bool PyInit_AESPaddingMode(PyObject *module) {
    PyAESPaddingModeType.tp_init = (initproc)PyAESPaddingMode_init;
    PyAESPaddingModeType.tp_new = PyType_GenericNew;

    if (PyType_Ready(&PyAESPaddingModeType) < 0)
        return false;

    Py_INCREF(&PyAESPaddingModeType);
    if (PyModule_AddObject(module, "AESPaddingMode", (PyObject *) &PyAESPaddingModeType) < 0) {
        Py_DECREF(&PyAESPaddingModeType);
        return false;
    }

    // auto* o = PyObject_New(PyAESPaddingModeObject, &PyAESPaddingModeType);

    PyObject* dict = PyAESPaddingModeType.tp_dict;
    (void)dict;

    PyDict_SetItemString(dict, "Zero", PyLong_FromLong(TWAESPaddingModeZero));
    PyDict_SetItemString(dict, "PKCS7", PyLong_FromLong(TWAESPaddingModePKCS7));

    return true;
}