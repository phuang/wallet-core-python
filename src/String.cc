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

#include "String.h"

PyObject* PyUnicode_FromTWString(const TWStringPtr& str) {
  if (!str)
    return nullptr;

  return PyUnicode_FromStringAndSize(TWStringUTF8Bytes(str.get()),
                                     TWStringSize(str.get()));
}

TWStringPtr PyUnicode_GetTWString(PyObject* object) {
  if (!PyUnicode_Check(object))
    return nullptr;

  Py_ssize_t size = 0;
  const char* str = PyUnicode_AsUTF8AndSize(object, &size);
  return TWStringPtr(TWStringCreateWithRawBytes((const uint8_t*)str, size));
}