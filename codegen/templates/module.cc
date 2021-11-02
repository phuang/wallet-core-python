// Copyright 2021 Peng Huang <shawn.p.huang@gmail.com>
// This file is part of Wallet-core-python.
//
// Wallet-core-python is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Wallet-core-python is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Wallet-core-python.  If not, see <https://www.gnu.org/licenses/>.
//
// NOTE: this is a GENERATED FILE, changes made here WILL BE LOST.

#define PY_SSIZE_T_CLEAN
#include <Python.h>

{% for include in includes -%}
{{ include }}
{% endfor %}

typedef bool (*InitProc)(PyObject* module);
const InitProc init_functions[]= {
    // clang-format off
{%- for function in functions %}
    {{ function }},
{%- endfor %}
    // clang-format on
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