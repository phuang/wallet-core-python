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

#pragma once

#include <memory>

#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <TrustWalletCore/TWData.h>

struct TWDataDeleter {
  void operator()(TWData* data) {
    TWDataDelete(data);
  }
};

// std::unique_ptr for holding TWData*
using TWDataPtr = std::unique_ptr<TWData, TWDataDeleter>;

// Create PyBytes object from TWData.
PyObject* PyBytes_FromTWData(const TWDataPtr& data);

// Get content of PyBytes in a new allocated TWData.
TWDataPtr PyBytes_GetTWData(PyObject* object);