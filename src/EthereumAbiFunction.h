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
//
// NOTE: this is a GENERATED FILE, changes made here WILL BE LOST.

#pragma once

#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <TrustWalletCore/TWEthereumAbiFunction.h>

struct PyEthereumAbiFunctionObject {
  PyObject_HEAD;
  TWEthereumAbiFunction* value;
};

// Returns true if the object is a PyEthereumAbiFunction.
bool PyEthereumAbiFunction_Check(PyObject* object);

// Create PyEthereumAbiFunction from an TWEthereumAbiFunction.
PyObject* PyEthereumAbiFunction_FromTWEthereumAbiFunction(
    TWEthereumAbiFunction* value);

// Get enum TWEthereumAbiFunction value from a PyEthereumAbiFunction object.
TWEthereumAbiFunction* PyEthereumAbiFunction_GetTWEthereumAbiFunction(
    PyObject* object);

// Initialize for PyEthereumAbiFunction. It is called by python module init
// function.
bool PyInit_EthereumAbiFunction(PyObject* module);