#include "${name}.h"

static PyTypeObject Py${name}Type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "walletcore.${name}",      /* tp_name */
    sizeof(Py${name}Object),   /* tp_basicsize */
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

int Py${name}_init(Py${name}Object *self, PyObject *args, PyObject *kwds) {
    return 0;
}

bool PyInit_${name}(PyObject *module) {
    Py${name}Type.tp_init = (initproc)Py${name}_init;
    Py${name}Type.tp_new = PyType_GenericNew;

    if (PyType_Ready(&Py${name}Type) < 0)
        return false;

    Py_INCREF(&Py${name}Type);
    if (PyModule_AddObject(module, "${name}", (PyObject *) &Py${name}Type) < 0) {
        Py_DECREF(&Py${name}Type);
        return false;
    }

    // auto* o = PyObject_New(Py${name}Object, &Py${name}Type);

    PyObject* dict = Py${name}Type.tp_dict;
    (void)dict;

${constants}

    return true;
}