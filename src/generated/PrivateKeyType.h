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
//
// NOTE: this is a GENERATED FILE, changes made here WILL BE LOST.

#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWPrivateKeyType.h>

struct PyPrivateKeyTypeObject {
  PyObject_HEAD;
  const TWPrivateKeyType value;
};

// Returns true if the object is a PyPrivateKeyType.
bool PyPrivateKeyType_Check(PyObject* object);

// Create PyPrivateKeyType from an enum TWPrivateKeyType value.
// Note: it returns the same PyPrivateKeyType instance for the same enum
// TWPrivateKeyType value. the caller should release the reference after using.
PyObject* PyPrivateKeyType_FromTWPrivateKeyType(TWPrivateKeyType value);

// Get enum TWPrivateKeyType value from a PyPrivateKeyType object.
TWPrivateKeyType PyPrivateKeyType_GetTWPrivateKeyType(PyObject* object);

// Initialize for PyPrivateKeyType. It is called by python module init function.
bool PyInit_PrivateKeyType(PyObject* module);