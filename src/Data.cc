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

#include "Data.h"

PyObject* PyBytes_FromTWData(const TWDataPtr& data) {
  if (!data)
    Py_RETURN_NONE;

  return PyBytes_FromStringAndSize((const char*)TWDataBytes(data.get()),
                                   TWDataSize(data.get()));
}

TWDataPtr PyBytes_GetTWData(PyObject* object) {
  if (!PyBytes_Check(object))
    return {};

  TWData* result = TWDataCreateWithBytes(
      (const uint8_t*)PyBytes_AS_STRING(object), PyBytes_GET_SIZE(object));
  return TWDataPtr(result);
}