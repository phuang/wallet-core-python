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

#include <TrustWalletCore/TWDerivationPath.h>

// Returns true if the object is a PyDerivationPath.
bool PyDerivationPath_Check(PyObject* object);

// Create PyDerivationPath from an TWDerivationPath.
PyObject* PyDerivationPath_FromTWDerivationPath(TWDerivationPath* value);

// Get enum TWDerivationPath value from a PyDerivationPath object.
TWDerivationPath* PyDerivationPath_GetTWDerivationPath(PyObject* object);

// Initialize for PyDerivationPath. It is called by python module init function.
bool PyInit_DerivationPath(PyObject* module);