#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <structmember.h>

static PyObject *DemoError = NULL;

static PyObject *
demo_system(PyObject *self, PyObject *args)
{
    const char *command;
    int sts;

    if (!PyArg_ParseTuple(args, "s", &command))
        return NULL;
    sts = system(command);
    if (sts < 0) {
        PyErr_SetString(DemoError, "System command failed");
        return NULL;
    }
    return PyLong_FromLong(sts);
}

static PyMethodDef DemoModuleMethods[] = {
    {"system",  demo_system, METH_VARARGS,
     "Execute a shell command."},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

typedef struct {
    PyObject_HEAD
    /* Type-specific fields go here. */
    PyObject *first; /* first name */
    PyObject *last;  /* last name */
    int number;    
} DemoObject;

static void
Demo_dealloc(DemoObject *self)
{
    Py_XDECREF(self->first);
    Py_XDECREF(self->last);
    Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyObject *
Demo_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    DemoObject *self;
    self = (DemoObject *) type->tp_alloc(type, 0);
    if (self != NULL) {
        self->first = PyUnicode_FromString("");
        if (self->first == NULL) {
            Py_DECREF(self);
            return NULL;
        }
        self->last = PyUnicode_FromString("");
        if (self->last == NULL) {
            Py_DECREF(self);
            return NULL;
        }
        self->number = 0;
    }
    return (PyObject *) self;
}

static int
Demo_init(DemoObject *self, PyObject *args, PyObject *kwds)
{
    static const char *kwlist[] = {"first", "last", "number", NULL};
    PyObject *first = NULL, *last = NULL, *tmp;

    if (!PyArg_ParseTupleAndKeywords(args, kwds, "|OOi", const_cast<char**>(kwlist),
                                     &first, &last,
                                     &self->number))
        return -1;

    if (first) {
        tmp = self->first;
        Py_INCREF(first);
        self->first = first;
        Py_XDECREF(tmp);
    }
    if (last) {
        tmp = self->last;
        Py_INCREF(last);
        self->last = last;
        Py_XDECREF(tmp);
    }
    return 0;
}

static PyMemberDef Demo_members[] = {
    {"first", T_OBJECT_EX, offsetof(DemoObject, first), 0,
     "first name"},
    {"last", T_OBJECT_EX, offsetof(DemoObject, last), 0,
     "last name"},
    {"number", T_INT, offsetof(DemoObject, number), 0,
     "custom number"},
    {NULL}  /* Sentinel */
};

static PyObject *
Demo_name(DemoObject *self, PyObject *Py_UNUSED(ignored))
{
    if (self->first == NULL) {
        PyErr_SetString(PyExc_AttributeError, "first");
        return NULL;
    }
    if (self->last == NULL) {
        PyErr_SetString(PyExc_AttributeError, "last");
        return NULL;
    }
    return PyUnicode_FromFormat("%S %S", self->first, self->last);
}

static PyMethodDef Demo_methods[] = {
    {"name", (PyCFunction) Demo_name, METH_NOARGS,
     "Return the name, combining the first and last name"
    },
    {NULL}  /* Sentinel */
};


static PyTypeObject DemoType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "demo.Demo",
    .tp_basicsize = sizeof(DemoObject),
    .tp_itemsize = 0,
    .tp_dealloc = (destructor) Demo_dealloc,
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
    .tp_doc = "Demo objects",
    .tp_methods = Demo_methods,
    .tp_members = Demo_members,
    .tp_init = (initproc) Demo_init,
    .tp_new = Demo_new,
};

static struct PyModuleDef demomodule = {
    PyModuleDef_HEAD_INIT,
    "demo",   /* name of module */
    NULL, /* module documentation, may be NULL */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    DemoModuleMethods
};

PyMODINIT_FUNC
PyInit_demo(void)
{
    PyObject *m;

    m = PyModule_Create(&demomodule);
    if (m == NULL)
        return NULL;

    DemoError = PyErr_NewException("demo.error", NULL, NULL);
    Py_XINCREF(DemoError);
    
    if (PyModule_AddObject(m, "error", DemoError) < 0) {
        Py_XDECREF(DemoError);
        Py_CLEAR(DemoError);
        Py_DECREF(m);
        return NULL;
    }
    
    if (PyType_Ready(&DemoType) < 0)
        return NULL;
    
    if (PyModule_AddObject(m, "Demo", (PyObject *) &DemoType) < 0) {
        Py_DECREF(&DemoType);
        Py_DECREF(m);
        return NULL;
    }

    PyObject* dict = DemoType.tp_dict;
    PyDict_SetItemString(dict,"AAABBBCCC", PyLong_FromLong(99));

    return m;
}

