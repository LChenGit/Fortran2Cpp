#ifndef NRTYPE_H
#define NRTYPE_H

#include <cstdint>

namespace nrtype {
    using I4B = int32_t;
    using I2B = int16_t;
    using I1B = int8_t;

    using SP = float;
    using DP = double;
    using QP = long double;

    constexpr SP PI = 3.141592653589793238462643383279502884197f;
    constexpr SP PIO2 = 1.57079632679489661923132169163975144209858f;
    constexpr SP TWOPI = 6.283185307179586476925286766559005768394f;
    constexpr SP SQRT2 = 1.41421356237309504880168872420969807856967f;
    constexpr SP EULER = 0.5772156649015328606065120900824024310422f;

    constexpr DP PI_D = 3.141592653589793238462643383279502884197;
    constexpr DP PIO2_D = 1.57079632679489661923132169163975144209858;
    constexpr DP TWOPI_D = 6.283185307179586476925286766559005768394;
}

#endif // NRTYPE_H