#ifndef DATA_PRECISION_GLOBALS_H
#define DATA_PRECISION_GLOBALS_H

#include <cstdint>

namespace DataPrecisionGlobals {

    using int32 = int32_t;
    using int64 = int64_t;

    using real32 = float;
    using real64 = double;
    using default_prec = real64;

    constexpr real64 constant_zero = 0.0;
    constexpr real64 constant_one = 1.0;
    constexpr real64 constant_minusone = -1.0;
    constexpr real64 constant_twenty = 20.0;
    constexpr real64 constant_pointfive = 0.5;
    constexpr real64 EXP_LowerLimit = -20.0;
    constexpr real64 EXP_UpperLimit = 40.0;

}

#endif // DATA_PRECISION_GLOBALS_H