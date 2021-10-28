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

template <typename Dst, typename Src>
inline std::optional<Dst> NumericCast(Src value) {
  typedef std::numeric_limits<Dst> DstLim;
  typedef std::numeric_limits<Src> SrcLim;

  const bool positive_overflow_possible = DstLim::max() < SrcLim::max();
  const bool negative_overflow_possible =
      SrcLim::is_signed or (DstLim::lowest() > SrcLim::lowest());

  // unsigned <-- unsigned
  if ((not DstLim::is_signed) and (not SrcLim::is_signed)) {
    if (positive_overflow_possible and (value > DstLim::max())) {
      return {};
    }
  }
  // unsigned <-- signed
  else if ((not DstLim::is_signed) and SrcLim::is_signed) {
    if (positive_overflow_possible and (value > DstLim::max())) {
      return {};
    } else if (negative_overflow_possible and (value < 0)) {
      return {};
    }

  }
  // signed <-- unsigned
  else if (DstLim::is_signed and (not SrcLim::is_signed)) {
    if (positive_overflow_possible and (value > DstLim::max())) {
      return {};
    }
  }
  // signed <-- signed
  else if (DstLim::is_signed and SrcLim::is_signed) {
    if (positive_overflow_possible and (value > DstLim::max())) {
      return {};
    } else if (negative_overflow_possible and (value < DstLim::lowest())) {
      return {};
    }
  }

  // limits have been checked, therefore safe to cast
  return static_cast<Dst>(value);
}