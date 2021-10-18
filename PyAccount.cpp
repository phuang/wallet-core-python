#include <memory>

#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <structmember.h>

#include <TrustWalletCore/TWAccount.h>
#include <TrustWalletCore/TWString.h>

#define WRAPS(x) std::unique_ptr<TWString, decltype(&TWStringDelete)>(x, &TWStringDelete)

typedef struct {
    PyObject_HEAD
    TWAccount* account;
} PyAccountObject;

static PyObject *
PyAccount_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    PyAccountObject *self;
    self = (PyAccountObject *) type->tp_alloc(type, 0);
    self->account = nullptr;
    return (PyObject *) self;
}

// struct TWAccount *_Nonnull TWAccountCreate(TWString *_Nonnull address, enum TWCoinType coin, TWString *_Nonnull derivationPath, TWString *_Nonnull extendedPublicKey);
int PyAccount_init(PyAccountObject *self, PyObject *args, PyObject *kwds) {
    const char* address;
    long coin;
    const char* derivationPath;
    const char* extendedPublicKey;
    if (!PyArg_ParseTuple(args, "slss", &address, &coin, &derivationPath, &extendedPublicKey)) {
        return -1;
    }

    auto tw_address = WRAPS(TWStringCreateWithUTF8Bytes(address));
    auto tw_derivationPath = WRAPS(TWStringCreateWithUTF8Bytes(derivationPath));
    auto tw_extendedPublicKey = WRAPS(TWStringCreateWithUTF8Bytes(extendedPublicKey));

    TWAccount* account = TWAccountCreate(tw_address.get(), (TWCoinType)coin, tw_derivationPath.get(), tw_extendedPublicKey.get());
    if (!account) {
        return -1;
    }

    self->account = account;
    return 0;
}

// void TWAccountDelete(struct TWAccount *_Nonnull account);
void PyAccount_dealloc(PyAccountObject *self) {
    if (self->account) {
        TWAccountDelete(self->account);
        self->account = nullptr;
    }
    Py_TYPE(self)->tp_free((PyObject *) self);
}

// TWString *_Nonnull TWAccountAddress(struct TWAccount *_Nonnull account);
PyObject* PyAccount_address(PyAccountObject *self) {
    auto address = WRAPS(TWAccountAddress(self->account));
    PyObject* result = PyUnicode_FromString(TWStringUTF8Bytes(address.get()));
    return result;
}

// TWString *_Nonnull TWAccountDerivationPath(struct TWAccount *_Nonnull account);
PyObject* PyAccount_derivation_path(PyAccountObject *self) {
    auto path = WRAPS(TWAccountDerivationPath(self->account));
    PyObject* result = PyUnicode_FromString(TWStringUTF8Bytes(path.get()));
    return result;
}

// TWString *_Nonnull TWAccountExtendedPublicKey(struct TWAccount *_Nonnull account);
PyObject* PyAccount_extended_public_key(PyAccountObject *self) {
    auto key = WRAPS(TWAccountExtendedPublicKey(self->account));
    PyObject* result = PyUnicode_FromString(TWStringUTF8Bytes(key.get()));
    return result;
}

// enum TWCoinType TWAccountCoin(struct TWAccount *_Nonnull account);
PyObject* PyAccount_coin(PyAccountObject *self) {
    TWCoinType coin = TWAccountCoin(self->account);
    return PyLong_FromLong((long)coin);
}

static PyMemberDef py_account_members[] = {
    {nullptr}
};

static PyMethodDef py_account_methods[] = {
    {"address", (PyCFunction) PyAccount_address, METH_NOARGS,
     "Return the address"
    },
    {"derivation_path", (PyCFunction) PyAccount_derivation_path, METH_NOARGS,
     "Return the derivation path"
    },
    {"extended_public_key", (PyCFunction) PyAccount_extended_public_key, METH_NOARGS,
     "Return the extended public key"
    },
    {"coin", (PyCFunction) PyAccount_coin, METH_NOARGS,
     "Return the coin type"
    },
    {NULL}  /* Sentinel */
};

static PyTypeObject py_account_type = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "account.Account",
    .tp_basicsize = sizeof(PyAccountObject),
    .tp_itemsize = 0,
    .tp_dealloc = (destructor) PyAccount_dealloc,
    .tp_flags = Py_TPFLAGS_DEFAULT,
    .tp_doc = "Account",
    .tp_methods = py_account_methods,
    .tp_members = py_account_members,
    .tp_init = (initproc) PyAccount_init,
    .tp_new = PyAccount_new,
};

static struct PyModuleDef demomodule = {
    PyModuleDef_HEAD_INIT,
    "account",   /* name of module */
    NULL, /* module documentation, may be NULL */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
};

PyMODINIT_FUNC
PyInit_account(void)
{
    PyObject *m;
    m = PyModule_Create(&demomodule);
    if (m == NULL)
        return NULL;

    if (PyType_Ready(&py_account_type) < 0)
        return NULL;
    
    if (PyModule_AddObject(m, "Account", (PyObject *) &py_account_type) < 0) {
        Py_DECREF(&py_account_type);
        Py_DECREF(m);
        return NULL;
    }

    return m;
}