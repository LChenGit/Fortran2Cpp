#ifndef NRTYPE_H
#define NRTYPE_H

#include <cstdint>
#include <complex>

namespace nrtype {

using i1  = int8_t;
using i2  = int16_t;
using i4  = int32_t;
using i8  = int64_t;
// i16 omitted due to C++ standard limitations

using sp  = float;
using dp  = double;

constexpr dp pi    = 3.141592653589793238462643383279502884197;
constexpr dp pi2   = 1.57079632679489661923132169163975144209858;
constexpr dp tau   = 6.283185307179586476925286766559005768394;
constexpr dp sqrt2 = 1.41421356237309504880168872420969807856967;
constexpr dp euler = 2.71828182845904523536028747135266249775725;

} // namespace nrtype

#endif // NRTYPE_H