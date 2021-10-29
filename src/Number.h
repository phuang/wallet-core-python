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

#pragma once

#include <limits>
#include <optional>

#define PY_SSIZE_T_CLEAN
#include <Python.h>

template <typename Dst, typename Src>
inline std::optional<Dst> NumericCast(Src value) {
  typedef std::numeric_limits<Dst> DstLim;
  typedef std::numeric_limits<Src> SrcLim;

  constexpr bool positive_overflow_possible = DstLim::max() < SrcLim::max();
  constexpr bool negative_overflow_possible =
      SrcLim::is_signed || (DstLim::lowest() > SrcLim::lowest());

  // unsigned <-- unsigned
  if ((!DstLim::is_signed) && (!SrcLim::is_signed)) {
    if (positive_overflow_possible && (value > DstLim::max())) {
      return std::nullopt;
    }
  }
  // unsigned <-- signed
  else if ((!DstLim::is_signed) && SrcLim::is_signed) {
    if (positive_overflow_possible && (value > DstLim::max())) {
      return std::nullopt;
    } else if (negative_overflow_possible && (value < 0)) {
      return std::nullopt;
    }

  }
  // signed <-- unsigned
  else if (DstLim::is_signed && (!SrcLim::is_signed)) {
    if (positive_overflow_possible && (value > DstLim::max())) {
      return std::nullopt;
    }
  }
  // signed <-- signed
  else if (DstLim::is_signed && SrcLim::is_signed) {
    if (positive_overflow_possible && (value > DstLim::max())) {
      return std::nullopt;
    } else if (negative_overflow_possible && (value < DstLim::lowest())) {
      return std::nullopt;
    }
  }

  // limits have been checked, therefore safe to cast
  return std::make_optional(static_cast<Dst>(value));
}

template <typename T>
inline std::optional<T> PyLongArg_ToNumber(PyObject* arg,
                                           int i,
                                           const char* type) {
  if (!PyLong_Check(arg)) {
    PyErr_Format(PyExc_TypeError, "The arg %d is not in a number", i);
    return std::nullopt;
  }

  auto longlong = PyLong_AsLongLong(arg);
  if (PyErr_Occurred()) {
    return std::nullopt;
  }

  auto result = NumericCast<T>(longlong);
  if (!result) {
    PyErr_Format(PyExc_ValueError, "The arg %d value %lld doesn't fit in %s", i,
                 longlong, type);
    return std::nullopt;
  }

  return result;
}