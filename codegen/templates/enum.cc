
#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TW${name}.h>

struct ${name}Object {
    PyObject_HEAD
};

static PyTypeObject ${name}Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "walletcore.${name}",
    .tp_basicsize = sizeof(${name}Object),
    .tp_itemsize = 0,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_doc = "${name} enum object",
    .tp_new = PyType_GenericNew,
};

bool ${name}_init(PyObject *module) {
    if (PyType_Ready(&${name}Type) < 0)
        return false;
    
    Py_INCREF(&${name}Type);
    if (PyModule_AddObject(module, "${name}", (PyObject *) &${name}Type) < 0) {
        Py_DECREF(&${name}Type);
        return false;
    }

    PyObject* dict = ${name}Type.tp_dict;

${constants}

    return true;
}
