#define PY_SSIZE_T_CLEAN
#include <Python.h>

${declares}

typedef bool (*InitProc)(PyObject* module);
const InitProc init_functions[]= {
${functions}
};

PyMODINIT_FUNC
PyInit_walletcore(void) {
    static struct PyModuleDef enum_module_def = {
        PyModuleDef_HEAD_INIT,
        "walletcore",   /* name of module */
        nullptr,        /* module documentation, may be NULL */
        -1,             /* size of per-interpreter state of the module,
                           or -1 if the module keeps state in global variables. */
        nullptr
    };
    
    PyObject *module = PyModule_Create(&enum_module_def);
    if (module == nullptr) {
        return nullptr;
    }

    for (const auto func : init_functions) {
        if (!func(module)) {
            Py_DECREF(module);
            return nullptr;
        }
    }
    
    return module;
}