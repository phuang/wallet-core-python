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

#include <TrustWalletCore/TWNervosAddress.h>

// Returns true if the object is a PyNervosAddress.
bool PyNervosAddress_Check(PyObject* object);

// Create PyNervosAddress from an TWNervosAddress.
PyObject* PyNervosAddress_FromTWNervosAddress(TWNervosAddress* value);

// Get enum TWNervosAddress value from a PyNervosAddress object.
TWNervosAddress* PyNervosAddress_GetTWNervosAddress(PyObject* object);

// Initialize for PyNervosAddress. It is called by python module init function.
bool PyInit_NervosAddress(PyObject* module);