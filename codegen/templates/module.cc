// This is a GENERATED FILE, changes made here WILL BE LOST.

#define PY_SSIZE_T_CLEAN
#include <Python.h>

${includes}

typedef bool (*InitProc)(PyObject* module);
const InitProc init_functions[]= {
${functions}
};

PyMODINIT_FUNC
PyInit_walletcore(void) {
  static struct PyModuleDef enum_module_def = {
    PyModuleDef_HEAD_INIT,
    "walletcore",   /* m_name */
    nullptr,        /* m_doc */
    -1,             /* m_size */
    nullptr         /* m_methods */
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