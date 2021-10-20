// This is a GENERATED FILE, changes made here WILL BE LOST.

#include "CoinTypeConfiguration.h"

#include "CoinType.h"
#include "String.h"

static PyTypeObject PyCoinTypeConfigurationType = {
    // clang-format off
    PyVarObject_HEAD_INIT(NULL, 0)
    // clang-format on
    "walletcore.CoinTypeConfiguration",    /* tp_name */
    sizeof(PyCoinTypeConfigurationObject), /* tp_basicsize */
    0,                                     /* tp_itemsize */
    0,                                     /* tp_dealloc */
    0,                                     /* tp_print */
    0,                                     /* tp_getattr */
    0,                                     /* tp_setattr */
    0,                                     /* tp_reserved */
    0,                                     /* tp_repr */
    0,                                     /* tp_as_number */
    0,                                     /* tp_as_sequence */
    0,                                     /* tp_as_mapping */
    0,                                     /* tp_hash  */
    0,                                     /* tp_call */
    0,                                     /* tp_str */
    0,                                     /* tp_getattro */
    0,                                     /* tp_setattro */
    0,                                     /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT,                    /* tp_flags */
    nullptr,                               /* tp_doc */
};

bool PyCoinTypeConfiguration_Check(PyObject* object) {
  return PyObject_TypeCheck(object, &PyCoinTypeConfigurationType) != 0;
}

// Create PyCoinTypeConfiguration from enum TWCoinTypeConfiguration.
PyObject* PyCoinTypeConfiguration_FromTWCoinTypeConfiguration(
    TWCoinTypeConfiguration* value) {
  if (!value)
    return nullptr;

  PyCoinTypeConfigurationObject* object =
      PyObject_New(PyCoinTypeConfigurationObject, &PyCoinTypeConfigurationType);
  if (!object)
    return nullptr;

  object->value = value;

  return (PyObject*)object;
}

TWCoinTypeConfiguration* PyCoinTypeConfiguration_GetTWCoinTypeConfiguration(
    PyObject* object) {
  assert(PyCoinTypeConfiguration_Check(object));
  return ((PyCoinTypeConfigurationObject*)object)->value;
}

// static int PyCoinTypeConfiguration_init(PyCoinTypeConfigurationObject *self,
// PyObject *args, PyObject *kwds) {
//   return 0;
// }

// static PyObject* PyCoinTypeConfiguration_new(PyTypeObject *subtype, PyObject
// *args, PyObject *kwds) {
//   int value = 0;
//   if (!PyArg_ParseTuple(args, "|i", &value)) {
//     return nullptr;
//   }
//   return
//   PyCoinTypeConfiguration_FromTWCoinTypeConfiguration((TWCoinTypeConfiguration)value);
// }

// static PyObject* PyCoinTypeConfiguration_str(PyCoinTypeConfigurationObject
// *self) {
//   const char* str = "Unknown";
//   return PyUnicode_FromString(str);
// }

// static method function for GetSymbol
static const char PyCoinTypeConfigurationGetSymbol_doc[] =
    "TWString* TWCoinTypeConfigurationGetSymbol(enum TWCoinType type)";
static PyObject* PyCoinTypeConfigurationGetSymbol(
    PyCoinTypeConfigurationObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyCoinType_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type CoinType");
    return nullptr;
  }
  auto arg0 = PyCoinType_GetTWCoinType(args[0]);

  TWStringPtr result = TWCoinTypeConfigurationGetSymbol(arg0);
  return PyUnicode_FromTWString(result);
}

// static method function for GetDecimals
static const char PyCoinTypeConfigurationGetDecimals_doc[] =
    "int TWCoinTypeConfigurationGetDecimals(enum TWCoinType type)";
static PyObject* PyCoinTypeConfigurationGetDecimals(
    PyCoinTypeConfigurationObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyCoinType_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type CoinType");
    return nullptr;
  }
  auto arg0 = PyCoinType_GetTWCoinType(args[0]);

  int result = TWCoinTypeConfigurationGetDecimals(arg0);
  return PyLong_FromLong(result);
}

// static method function for GetTransactionURL
static const char PyCoinTypeConfigurationGetTransactionURL_doc[] =
    "TWString* TWCoinTypeConfigurationGetTransactionURL(enum TWCoinType type, "
    "TWString* transactionID)";
static PyObject* PyCoinTypeConfigurationGetTransactionURL(
    PyCoinTypeConfigurationObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyCoinType_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type CoinType");
    return nullptr;
  }
  auto arg0 = PyCoinType_GetTWCoinType(args[0]);

  if (!PyUnicode_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Unicode");
    return nullptr;
  }
  auto arg1 = PyUnicode_GetTWString(args[1]);

  TWStringPtr result =
      TWCoinTypeConfigurationGetTransactionURL(arg0, arg1.get());
  return PyUnicode_FromTWString(result);
}

// static method function for GetAccountURL
static const char PyCoinTypeConfigurationGetAccountURL_doc[] =
    "TWString* TWCoinTypeConfigurationGetAccountURL(enum TWCoinType type, "
    "TWString* accountID)";
static PyObject* PyCoinTypeConfigurationGetAccountURL(
    PyCoinTypeConfigurationObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 2) {
    PyErr_Format(PyExc_TypeError, "Expect 2 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyCoinType_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type CoinType");
    return nullptr;
  }
  auto arg0 = PyCoinType_GetTWCoinType(args[0]);

  if (!PyUnicode_Check(args[1])) {
    PyErr_SetString(PyExc_TypeError, "The arg 1 is not in type Unicode");
    return nullptr;
  }
  auto arg1 = PyUnicode_GetTWString(args[1]);

  TWStringPtr result = TWCoinTypeConfigurationGetAccountURL(arg0, arg1.get());
  return PyUnicode_FromTWString(result);
}

// static method function for GetID
static const char PyCoinTypeConfigurationGetID_doc[] =
    "TWString* TWCoinTypeConfigurationGetID(enum TWCoinType type)";
static PyObject* PyCoinTypeConfigurationGetID(
    PyCoinTypeConfigurationObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyCoinType_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type CoinType");
    return nullptr;
  }
  auto arg0 = PyCoinType_GetTWCoinType(args[0]);

  TWStringPtr result = TWCoinTypeConfigurationGetID(arg0);
  return PyUnicode_FromTWString(result);
}

// static method function for GetName
static const char PyCoinTypeConfigurationGetName_doc[] =
    "TWString* TWCoinTypeConfigurationGetName(enum TWCoinType type)";
static PyObject* PyCoinTypeConfigurationGetName(
    PyCoinTypeConfigurationObject* self,
    PyObject* const* args,
    Py_ssize_t nargs) {
  if (nargs != 1) {
    PyErr_Format(PyExc_TypeError, "Expect 1 instead of %d.", nargs);
    return nullptr;
  }

  if (!PyCoinType_Check(args[0])) {
    PyErr_SetString(PyExc_TypeError, "The arg 0 is not in type CoinType");
    return nullptr;
  }
  auto arg0 = PyCoinType_GetTWCoinType(args[0]);

  TWStringPtr result = TWCoinTypeConfigurationGetName(arg0);
  return PyUnicode_FromTWString(result);
}

static const PyGetSetDef get_set_defs[] = {{}};

static const PyMethodDef method_defs[] = {
    {"GetSymbol", (PyCFunction)PyCoinTypeConfigurationGetSymbol,
     METH_FASTCALL | METH_STATIC, PyCoinTypeConfigurationGetSymbol_doc},
    {"GetDecimals", (PyCFunction)PyCoinTypeConfigurationGetDecimals,
     METH_FASTCALL | METH_STATIC, PyCoinTypeConfigurationGetDecimals_doc},
    {"GetTransactionURL", (PyCFunction)PyCoinTypeConfigurationGetTransactionURL,
     METH_FASTCALL | METH_STATIC, PyCoinTypeConfigurationGetTransactionURL_doc},
    {"GetAccountURL", (PyCFunction)PyCoinTypeConfigurationGetAccountURL,
     METH_FASTCALL | METH_STATIC, PyCoinTypeConfigurationGetAccountURL_doc},
    {"GetID", (PyCFunction)PyCoinTypeConfigurationGetID,
     METH_FASTCALL | METH_STATIC, PyCoinTypeConfigurationGetID_doc},
    {"GetName", (PyCFunction)PyCoinTypeConfigurationGetName,
     METH_FASTCALL | METH_STATIC, PyCoinTypeConfigurationGetName_doc},
    {}};

bool PyInit_CoinTypeConfiguration(PyObject* module) {
  // PyCoinTypeConfigurationType.tp_new = PyCoinTypeConfiguration_new;
  // PyCoinTypeConfigurationType.tp_init =
  // (initproc)PyCoinTypeConfiguration_init; PyCoinTypeConfigurationType.tp_str
  // = (reprfunc)PyCoinTypeConfiguration_str;
  PyCoinTypeConfigurationType.tp_getset = (PyGetSetDef*)get_set_defs;
  PyCoinTypeConfigurationType.tp_methods = (PyMethodDef*)method_defs;

  if (PyType_Ready(&PyCoinTypeConfigurationType) < 0)
    return false;

  Py_INCREF(&PyCoinTypeConfigurationType);
  if (PyModule_AddObject(module, "CoinTypeConfiguration",
                         (PyObject*)&PyCoinTypeConfigurationType) < 0) {
    Py_DECREF(&PyCoinTypeConfigurationType);
    return false;
  }

  return true;
}