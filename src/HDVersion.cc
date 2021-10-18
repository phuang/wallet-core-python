#include "HDVersion.h"

static PyTypeObject PyHDVersionType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "walletcore.HDVersion",      /* tp_name */
    sizeof(PyHDVersionObject),   /* tp_basicsize */
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

int PyHDVersion_init(PyHDVersionObject *self, PyObject *args, PyObject *kwds) {
    return 0;
}

bool PyInit_HDVersion(PyObject *module) {
    PyHDVersionType.tp_init = (initproc)PyHDVersion_init;
    PyHDVersionType.tp_new = PyType_GenericNew;

    if (PyType_Ready(&PyHDVersionType) < 0)
        return false;

    Py_INCREF(&PyHDVersionType);
    if (PyModule_AddObject(module, "HDVersion", (PyObject *) &PyHDVersionType) < 0) {
        Py_DECREF(&PyHDVersionType);
        return false;
    }

    // auto* o = PyObject_New(PyHDVersionObject, &PyHDVersionType);

    PyObject* dict = PyHDVersionType.tp_dict;
    (void)dict;

    PyDict_SetItemString(dict, "None", PyLong_FromLong(TWHDVersionNone));
    PyDict_SetItemString(dict, "XPUB", PyLong_FromLong(TWHDVersionXPUB));
    PyDict_SetItemString(dict, "XPRV", PyLong_FromLong(TWHDVersionXPRV));
    PyDict_SetItemString(dict, "YPUB", PyLong_FromLong(TWHDVersionYPUB));
    PyDict_SetItemString(dict, "YPRV", PyLong_FromLong(TWHDVersionYPRV));
    PyDict_SetItemString(dict, "ZPUB", PyLong_FromLong(TWHDVersionZPUB));
    PyDict_SetItemString(dict, "ZPRV", PyLong_FromLong(TWHDVersionZPRV));
    PyDict_SetItemString(dict, "LTUB", PyLong_FromLong(TWHDVersionLTUB));
    PyDict_SetItemString(dict, "LTPV", PyLong_FromLong(TWHDVersionLTPV));
    PyDict_SetItemString(dict, "MTUB", PyLong_FromLong(TWHDVersionMTUB));
    PyDict_SetItemString(dict, "MTPV", PyLong_FromLong(TWHDVersionMTPV));
    PyDict_SetItemString(dict, "DPUB", PyLong_FromLong(TWHDVersionDPUB));
    PyDict_SetItemString(dict, "DPRV", PyLong_FromLong(TWHDVersionDPRV));
    PyDict_SetItemString(dict, "DGUB", PyLong_FromLong(TWHDVersionDGUB));
    PyDict_SetItemString(dict, "DGPV", PyLong_FromLong(TWHDVersionDGPV));

    return true;
}