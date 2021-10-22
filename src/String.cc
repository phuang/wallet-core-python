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

#include "String.h"

PyObject* PyUnicode_FromTWString(const TWStringPtr& str) {
  if (!str)
    Py_RETURN_NONE;

  return PyUnicode_FromStringAndSize(TWStringUTF8Bytes(str.get()),
                                     TWStringSize(str.get()));
}

TWStringPtr PyUnicode_GetTWString(PyObject* object) {
  if (!PyUnicode_Check(object))
    return {};

  Py_ssize_t size = 0;
  const char* str = PyUnicode_AsUTF8AndSize(object, &size);
  TWString* result = TWStringCreateWithRawBytes((const uint8_t*)str, size);
  return TWStringPtr(result);
}