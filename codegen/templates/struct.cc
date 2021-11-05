{% include "header.template" %}

{% include "includes.template" %}


struct Py{{ name }}Object {
  PyObject_HEAD;
};

static PyTypeObject Py{{ name }}Type = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.{{ name }}",      /* tp_name */
    sizeof(Py{{ name }}Object),   /* tp_basicsize */
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

{% for function in functions %}
{{ function }}
{%- endfor %}

{% include "properties.template" %}

static const PyGetSetDef get_set_defs[] = {
{%- for def in getsetdefs -%}
  {{ def }},
{%- endfor -%}
  {}
};

static const PyMethodDef method_defs[] = {
{%- for def in methoddefs -%}
  {{ def }},
{%- endfor -%}
  {}
};

bool PyInit_{{ name }}(PyObject *module) {
  Py{{ name }}Type.tp_getset = (PyGetSetDef*)get_set_defs;
  Py{{ name }}Type.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&Py{{ name }}Type) < 0)
    return false;

  Py_INCREF(&Py{{ name }}Type);
  if (PyModule_AddObject(module, "{{ name }}", (PyObject *) &Py{{ name }}Type) < 0) {
    Py_DECREF(&Py{{ name }}Type);
    return false;
  }

  return true;
}