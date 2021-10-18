#include "Blockchain.h"

static PyTypeObject PyBlockchainType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "walletcore.Blockchain",      /* tp_name */
    sizeof(PyBlockchainObject),   /* tp_basicsize */
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

int PyBlockchain_init(PyBlockchainObject *self, PyObject *args, PyObject *kwds) {
    return 0;
}

bool PyInit_Blockchain(PyObject *module) {
    PyBlockchainType.tp_init = (initproc)PyBlockchain_init;
    PyBlockchainType.tp_new = PyType_GenericNew;

    if (PyType_Ready(&PyBlockchainType) < 0)
        return false;

    Py_INCREF(&PyBlockchainType);
    if (PyModule_AddObject(module, "Blockchain", (PyObject *) &PyBlockchainType) < 0) {
        Py_DECREF(&PyBlockchainType);
        return false;
    }

    // auto* o = PyObject_New(PyBlockchainObject, &PyBlockchainType);

    PyObject* dict = PyBlockchainType.tp_dict;
    (void)dict;

    PyDict_SetItemString(dict, "Bitcoin", PyLong_FromLong(TWBlockchainBitcoin));
    PyDict_SetItemString(dict, "Ethereum", PyLong_FromLong(TWBlockchainEthereum));
    PyDict_SetItemString(dict, "Vechain", PyLong_FromLong(TWBlockchainVechain));
    PyDict_SetItemString(dict, "Tron", PyLong_FromLong(TWBlockchainTron));
    PyDict_SetItemString(dict, "Icon", PyLong_FromLong(TWBlockchainIcon));
    PyDict_SetItemString(dict, "Binance", PyLong_FromLong(TWBlockchainBinance));
    PyDict_SetItemString(dict, "Ripple", PyLong_FromLong(TWBlockchainRipple));
    PyDict_SetItemString(dict, "Tezos", PyLong_FromLong(TWBlockchainTezos));
    PyDict_SetItemString(dict, "Nimiq", PyLong_FromLong(TWBlockchainNimiq));
    PyDict_SetItemString(dict, "Stellar", PyLong_FromLong(TWBlockchainStellar));
    PyDict_SetItemString(dict, "Aion", PyLong_FromLong(TWBlockchainAion));
    PyDict_SetItemString(dict, "Cosmos", PyLong_FromLong(TWBlockchainCosmos));
    PyDict_SetItemString(dict, "Theta", PyLong_FromLong(TWBlockchainTheta));
    PyDict_SetItemString(dict, "Ontology", PyLong_FromLong(TWBlockchainOntology));
    PyDict_SetItemString(dict, "Zilliqa", PyLong_FromLong(TWBlockchainZilliqa));
    PyDict_SetItemString(dict, "IoTeX", PyLong_FromLong(TWBlockchainIoTeX));
    PyDict_SetItemString(dict, "EOS", PyLong_FromLong(TWBlockchainEOS));
    PyDict_SetItemString(dict, "Nano", PyLong_FromLong(TWBlockchainNano));
    PyDict_SetItemString(dict, "NULS", PyLong_FromLong(TWBlockchainNULS));
    PyDict_SetItemString(dict, "Waves", PyLong_FromLong(TWBlockchainWaves));
    PyDict_SetItemString(dict, "Aeternity", PyLong_FromLong(TWBlockchainAeternity));
    PyDict_SetItemString(dict, "Nebulas", PyLong_FromLong(TWBlockchainNebulas));
    PyDict_SetItemString(dict, "FIO", PyLong_FromLong(TWBlockchainFIO));
    PyDict_SetItemString(dict, "Solana", PyLong_FromLong(TWBlockchainSolana));
    PyDict_SetItemString(dict, "Harmony", PyLong_FromLong(TWBlockchainHarmony));
    PyDict_SetItemString(dict, "NEAR", PyLong_FromLong(TWBlockchainNEAR));
    PyDict_SetItemString(dict, "Algorand", PyLong_FromLong(TWBlockchainAlgorand));
    PyDict_SetItemString(dict, "Polkadot", PyLong_FromLong(TWBlockchainPolkadot));
    PyDict_SetItemString(dict, "Cardano", PyLong_FromLong(TWBlockchainCardano));
    PyDict_SetItemString(dict, "NEO", PyLong_FromLong(TWBlockchainNEO));
    PyDict_SetItemString(dict, "Filecoin", PyLong_FromLong(TWBlockchainFilecoin));
    PyDict_SetItemString(dict, "ElrondNetwork", PyLong_FromLong(TWBlockchainElrondNetwork));
    PyDict_SetItemString(dict, "OasisNetwork", PyLong_FromLong(TWBlockchainOasisNetwork));

    return true;
}