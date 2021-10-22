// Copyright 2021 Peng Huang <shawn.p.huang@gmail.com>
// This file is part of wallet-core-python.
//
// Foobar is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Foobar is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Foobar.  If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include <memory>

#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <TrustWalletCore/TWData.h>

class TWDataPtr : public std::unique_ptr<TWData, decltype(&TWDataDelete)> {
 public:
  TWDataPtr(TWData* p)
      : std::unique_ptr<TWData, decltype(&TWDataDelete)>(p, &TWDataDelete) {}
};

PyObject* PyBytes_FromTWData(const TWDataPtr& data);

TWDataPtr PyBytes_GetTWData(PyObject* object);