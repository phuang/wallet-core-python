// This is a GENERATED FILE, changes made here WILL BE LOST.

#include "${name}.h"

${includes}

static PyTypeObject Py${name}Type = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
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


bool Py${name}_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &Py${name}Type) != 0;
}

// Create Py${name} from enum TW${name}.
PyObject* Py${name}_FromTW${name}(TW${name}* value) {
  if (!value)
    return nullptr;

  Py${name}Object* object = PyObject_New(Py${name}Object, &Py${name}Type);
  if (!object)
    return nullptr;

  object->value = value;

  return (PyObject*)object;
}

TW${name}* Py${name}_GetTW${name}(PyObject* object) {
  assert(Py${name}_Check(object));
  return ((Py${name}Object*)object)->value;
}

// static int Py${name}_init(Py${name}Object *self, PyObject *args, PyObject *kwds) {
//   return 0;
// }

// static PyObject* Py${name}_new(PyTypeObject *subtype, PyObject *args, PyObject *kwds) {
//   int value = 0;
//   if (!PyArg_ParseTuple(args, "|i", &value)) {
//     return nullptr;
//   }
//   return Py${name}_FromTW${name}((TW${name})value);
// }

// static PyObject* Py${name}_str(Py${name}Object *self) {
//   const char* str = "Unknown";
//   return PyUnicode_FromString(str);
// }

${functions}

static const PyGetSetDef get_set_defs[] = {
${getsetdefs}
};

static const PyMethodDef method_defs[] = {
${methoddefs}
};

bool PyInit_${name}(PyObject *module) {

  // Py${name}Type.tp_new = Py${name}_new;
  // Py${name}Type.tp_init = (initproc)Py${name}_init;
  // Py${name}Type.tp_str = (reprfunc)Py${name}_str;
  Py${name}Type.tp_getset = (PyGetSetDef*)get_set_defs;
  Py${name}Type.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&Py${name}Type) < 0)
    return false;

  Py_INCREF(&Py${name}Type);
  if (PyModule_AddObject(module, "${name}", (PyObject *) &Py${name}Type) < 0) {
    Py_DECREF(&Py${name}Type);
    return false;
  }

  return true;
}