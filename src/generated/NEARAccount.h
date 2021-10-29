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

#include <TrustWalletCore/TWNEARAccount.h>

// Returns true if the object is a PyNEARAccount.
bool PyNEARAccount_Check(PyObject* object);

// Create PyNEARAccount from an TWNEARAccount.
PyObject* PyNEARAccount_FromTWNEARAccount(TWNEARAccount* value);

// Get enum TWNEARAccount value from a PyNEARAccount object.
TWNEARAccount* PyNEARAccount_GetTWNEARAccount(PyObject* object);

// Initialize for PyNEARAccount. It is called by python module init function.
bool PyInit_NEARAccount(PyObject* module);