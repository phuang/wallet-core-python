// Copyright © 2017-2021 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//
#include "PyEnum.h"

namespace TW {

PyTypeObject* PyEnum_Create(const char* name,
                            const PyEnumConstantNameValue* constants) {
    struct EnumObject {
        PyObject_HEAD;
    };

    static PyType_Slot slots[] = {
        {0, 0},
    };

    PyType_Spec spec = {
        name,
        sizeof(EnumObject),
        0,
        Py_TPFLAGS_DEFAULT,
        slots
    };

    PyTypeObject* type = (PyTypeObject*)PyType_FromSpec(&spec);
    if (!type) {
        return nullptr;
    }
    
    PyObject* dict = type->tp_dict;

    for (const PyEnumConstantNameValue* i = constants; i->name; ++i) {
        PyDict_SetItemString(dict, i->name, PyLong_FromLong(i->value));
    }

    return type;    
}

}  // namespace TW

PyMODINIT_FUNC
PyInit_enum(void)
{
    static struct PyModuleDef enum_module_def = {
        PyModuleDef_HEAD_INIT,
        "enum",   /* name of module */
        NULL, /* module documentation, may be NULL */
        -1,       /* size of per-interpreter state of the module,
                    or -1 if the module keeps state in global variables. */
        NULL
    };
    
    PyObject *module = PyModule_Create(&enum_module_def);
    if (module == NULL)
        return NULL;

    TW::PyEnumConstantNameValue constants[] {
        { "A", 1},
        { "B", 2},
        { "C", 3},
        { nullptr, 0},
    };

    PyTypeObject* type = TW::PyEnum_Create("DynamicEnum", constants);
    if (!type)
        return nullptr;

    if (PyModule_AddObject(module, "DynamicEnum", (PyObject *)type) < 0) {
        Py_DECREF(type);
        return NULL;
    }

    return module;
}