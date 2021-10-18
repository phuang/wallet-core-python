#include "CoinType.h"

static PyTypeObject PyCoinTypeType = {
    PyVarObject_HEAD_INIT(NULL, 0)
    "walletcore.CoinType",      /* tp_name */
    sizeof(PyCoinTypeObject),   /* tp_basicsize */
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

int PyCoinType_init(PyCoinTypeObject *self, PyObject *args, PyObject *kwds) {
    return 0;
}

bool PyInit_CoinType(PyObject *module) {
    PyCoinTypeType.tp_init = (initproc)PyCoinType_init;
    PyCoinTypeType.tp_new = PyType_GenericNew;

    if (PyType_Ready(&PyCoinTypeType) < 0)
        return false;

    Py_INCREF(&PyCoinTypeType);
    if (PyModule_AddObject(module, "CoinType", (PyObject *) &PyCoinTypeType) < 0) {
        Py_DECREF(&PyCoinTypeType);
        return false;
    }

    // auto* o = PyObject_New(PyCoinTypeObject, &PyCoinTypeType);

    PyObject* dict = PyCoinTypeType.tp_dict;
    (void)dict;

    PyDict_SetItemString(dict, "Aeternity", PyLong_FromLong(TWCoinTypeAeternity));
    PyDict_SetItemString(dict, "Aion", PyLong_FromLong(TWCoinTypeAion));
    PyDict_SetItemString(dict, "Binance", PyLong_FromLong(TWCoinTypeBinance));
    PyDict_SetItemString(dict, "Bitcoin", PyLong_FromLong(TWCoinTypeBitcoin));
    PyDict_SetItemString(dict, "BitcoinCash", PyLong_FromLong(TWCoinTypeBitcoinCash));
    PyDict_SetItemString(dict, "BitcoinGold", PyLong_FromLong(TWCoinTypeBitcoinGold));
    PyDict_SetItemString(dict, "Callisto", PyLong_FromLong(TWCoinTypeCallisto));
    PyDict_SetItemString(dict, "Cardano", PyLong_FromLong(TWCoinTypeCardano));
    PyDict_SetItemString(dict, "Cosmos", PyLong_FromLong(TWCoinTypeCosmos));
    PyDict_SetItemString(dict, "Dash", PyLong_FromLong(TWCoinTypeDash));
    PyDict_SetItemString(dict, "Decred", PyLong_FromLong(TWCoinTypeDecred));
    PyDict_SetItemString(dict, "DigiByte", PyLong_FromLong(TWCoinTypeDigiByte));
    PyDict_SetItemString(dict, "Dogecoin", PyLong_FromLong(TWCoinTypeDogecoin));
    PyDict_SetItemString(dict, "EOS", PyLong_FromLong(TWCoinTypeEOS));
    PyDict_SetItemString(dict, "Ethereum", PyLong_FromLong(TWCoinTypeEthereum));
    PyDict_SetItemString(dict, "EthereumClassic", PyLong_FromLong(TWCoinTypeEthereumClassic));
    PyDict_SetItemString(dict, "FIO", PyLong_FromLong(TWCoinTypeFIO));
    PyDict_SetItemString(dict, "GoChain", PyLong_FromLong(TWCoinTypeGoChain));
    PyDict_SetItemString(dict, "Groestlcoin", PyLong_FromLong(TWCoinTypeGroestlcoin));
    PyDict_SetItemString(dict, "ICON", PyLong_FromLong(TWCoinTypeICON));
    PyDict_SetItemString(dict, "IoTeX", PyLong_FromLong(TWCoinTypeIoTeX));
    PyDict_SetItemString(dict, "Kava", PyLong_FromLong(TWCoinTypeKava));
    PyDict_SetItemString(dict, "Kin", PyLong_FromLong(TWCoinTypeKin));
    PyDict_SetItemString(dict, "Litecoin", PyLong_FromLong(TWCoinTypeLitecoin));
    PyDict_SetItemString(dict, "Monacoin", PyLong_FromLong(TWCoinTypeMonacoin));
    PyDict_SetItemString(dict, "Nebulas", PyLong_FromLong(TWCoinTypeNebulas));
    PyDict_SetItemString(dict, "NULS", PyLong_FromLong(TWCoinTypeNULS));
    PyDict_SetItemString(dict, "Nano", PyLong_FromLong(TWCoinTypeNano));
    PyDict_SetItemString(dict, "NEAR", PyLong_FromLong(TWCoinTypeNEAR));
    PyDict_SetItemString(dict, "Nimiq", PyLong_FromLong(TWCoinTypeNimiq));
    PyDict_SetItemString(dict, "Ontology", PyLong_FromLong(TWCoinTypeOntology));
    PyDict_SetItemString(dict, "POANetwork", PyLong_FromLong(TWCoinTypePOANetwork));
    PyDict_SetItemString(dict, "Qtum", PyLong_FromLong(TWCoinTypeQtum));
    PyDict_SetItemString(dict, "XRP", PyLong_FromLong(TWCoinTypeXRP));
    PyDict_SetItemString(dict, "Solana", PyLong_FromLong(TWCoinTypeSolana));
    PyDict_SetItemString(dict, "Stellar", PyLong_FromLong(TWCoinTypeStellar));
    PyDict_SetItemString(dict, "Tezos", PyLong_FromLong(TWCoinTypeTezos));
    PyDict_SetItemString(dict, "Theta", PyLong_FromLong(TWCoinTypeTheta));
    PyDict_SetItemString(dict, "ThunderToken", PyLong_FromLong(TWCoinTypeThunderToken));
    PyDict_SetItemString(dict, "NEO", PyLong_FromLong(TWCoinTypeNEO));
    PyDict_SetItemString(dict, "TomoChain", PyLong_FromLong(TWCoinTypeTomoChain));
    PyDict_SetItemString(dict, "Tron", PyLong_FromLong(TWCoinTypeTron));
    PyDict_SetItemString(dict, "VeChain", PyLong_FromLong(TWCoinTypeVeChain));
    PyDict_SetItemString(dict, "Viacoin", PyLong_FromLong(TWCoinTypeViacoin));
    PyDict_SetItemString(dict, "Wanchain", PyLong_FromLong(TWCoinTypeWanchain));
    PyDict_SetItemString(dict, "Zcash", PyLong_FromLong(TWCoinTypeZcash));
    PyDict_SetItemString(dict, "Zcoin", PyLong_FromLong(TWCoinTypeZcoin));
    PyDict_SetItemString(dict, "Zilliqa", PyLong_FromLong(TWCoinTypeZilliqa));
    PyDict_SetItemString(dict, "Zelcash", PyLong_FromLong(TWCoinTypeZelcash));
    PyDict_SetItemString(dict, "Ravencoin", PyLong_FromLong(TWCoinTypeRavencoin));
    PyDict_SetItemString(dict, "Waves", PyLong_FromLong(TWCoinTypeWaves));
    PyDict_SetItemString(dict, "Terra", PyLong_FromLong(TWCoinTypeTerra));
    PyDict_SetItemString(dict, "Harmony", PyLong_FromLong(TWCoinTypeHarmony));
    PyDict_SetItemString(dict, "Algorand", PyLong_FromLong(TWCoinTypeAlgorand));
    PyDict_SetItemString(dict, "Kusama", PyLong_FromLong(TWCoinTypeKusama));
    PyDict_SetItemString(dict, "Polkadot", PyLong_FromLong(TWCoinTypePolkadot));
    PyDict_SetItemString(dict, "Filecoin", PyLong_FromLong(TWCoinTypeFilecoin));
    PyDict_SetItemString(dict, "Elrond", PyLong_FromLong(TWCoinTypeElrond));
    PyDict_SetItemString(dict, "BandChain", PyLong_FromLong(TWCoinTypeBandChain));
    PyDict_SetItemString(dict, "SmartChainLegacy", PyLong_FromLong(TWCoinTypeSmartChainLegacy));
    PyDict_SetItemString(dict, "SmartChain", PyLong_FromLong(TWCoinTypeSmartChain));
    PyDict_SetItemString(dict, "Oasis", PyLong_FromLong(TWCoinTypeOasis));
    PyDict_SetItemString(dict, "Polygon", PyLong_FromLong(TWCoinTypePolygon));
    PyDict_SetItemString(dict, "THORChain", PyLong_FromLong(TWCoinTypeTHORChain));
    PyDict_SetItemString(dict, "Bluzelle", PyLong_FromLong(TWCoinTypeBluzelle));
    PyDict_SetItemString(dict, "Optimism", PyLong_FromLong(TWCoinTypeOptimism));
    PyDict_SetItemString(dict, "Arbitrum", PyLong_FromLong(TWCoinTypeArbitrum));
    PyDict_SetItemString(dict, "ECOChain", PyLong_FromLong(TWCoinTypeECOChain));
    PyDict_SetItemString(dict, "AvalancheCChain", PyLong_FromLong(TWCoinTypeAvalancheCChain));
    PyDict_SetItemString(dict, "XDai", PyLong_FromLong(TWCoinTypeXDai));
    PyDict_SetItemString(dict, "Fantom", PyLong_FromLong(TWCoinTypeFantom));
    PyDict_SetItemString(dict, "CryptoOrg", PyLong_FromLong(TWCoinTypeCryptoOrg));
    PyDict_SetItemString(dict, "Celo", PyLong_FromLong(TWCoinTypeCelo));
    PyDict_SetItemString(dict, "Ronin", PyLong_FromLong(TWCoinTypeRonin));

    return true;
}