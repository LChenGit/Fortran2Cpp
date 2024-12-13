#ifndef NRTYPE_HPP
#define NRTYPE_HPP

#include <cstdint>
#include <complex>
#include <vector>
#include <cmath>

namespace nrtype {

using ikind = int32_t;
using lkind = int64_t;

using rkind = float;
using dkind = double;

constexpr rkind pi = 3.1415927f;
constexpr dkind dpi = 3.14159265358979323846;

} // namespace nrtype

#endif // NRTYPE_HPP