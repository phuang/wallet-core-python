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

#include <TrustWalletCore/TWSegwitAddress.h>

// Returns true if the object is a PySegwitAddress.
bool PySegwitAddress_Check(PyObject* object);

// Create PySegwitAddress from an TWSegwitAddress.
PyObject* PySegwitAddress_FromTWSegwitAddress(TWSegwitAddress* value);

// Get enum TWSegwitAddress value from a PySegwitAddress object.
TWSegwitAddress* PySegwitAddress_GetTWSegwitAddress(PyObject* object);

// Initialize for PySegwitAddress. It is called by python module init function.
bool PyInit_SegwitAddress(PyObject* module);