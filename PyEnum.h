// Copyright © 2017-2021 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//

#define PY_SSIZE_T_CLEAN
#include <Python.h>

namespace TW {

struct PyEnumConstantNameValue {
    const char* name;
    const long value;
};

PyTypeObject* PyEnum_Create(const char* name,
                            const PyEnumConstantNameValue* constants);

}  // namespace TW