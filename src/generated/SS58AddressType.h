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

#include <TrustWalletCore/TWSS58AddressType.h>

struct PySS58AddressTypeObject {
  PyObject_HEAD;
  const TWSS58AddressType value;
};

// Returns true if the object is a PySS58AddressType.
bool PySS58AddressType_Check(PyObject* object);

// Create PySS58AddressType from an enum TWSS58AddressType value.
// Note: it returns the same PySS58AddressType instance for the same enum
// TWSS58AddressType value. the caller should release the reference after using.
PyObject* PySS58AddressType_FromTWSS58AddressType(TWSS58AddressType value);

// Get enum TWSS58AddressType value from a PySS58AddressType object.
TWSS58AddressType PySS58AddressType_GetTWSS58AddressType(PyObject* object);

// Initialize for PySS58AddressType. It is called by python module init
// function.
bool PyInit_SS58AddressType(PyObject* module);