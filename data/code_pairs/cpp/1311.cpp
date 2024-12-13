#ifndef TYPESIZES_H
#define TYPESIZES_H

#include <cstddef> // For size_t
#include <limits>  // For numeric_limits
#include <cstdint> // For fixed-width integer types
#include <type_traits> // For is_same

class TypeSizes {
public:
    using OneByteInt = std::int8_t;
    using TwoByteInt = std::int16_t;
    using FourByteInt = std::int32_t;
    using EightByteInt = std::int64_t;

    using FourByteReal = float;
    using EightByteReal = double;

    static bool byteSizesOK() {
        bool intSizesOK = (sizeof(OneByteInt) * 8 == 8) &&
                          (sizeof(TwoByteInt) * 8 == 16) &&
                          (sizeof(FourByteInt) * 8 == 32) &&
                          (sizeof(EightByteInt) * 8 == 64);

        bool realSizesOK = (sizeof(FourByteReal) * 8 == 32) &&
                           (sizeof(EightByteReal) * 8 == 64);

        bool realTypesDifferent = !std::is_same<FourByteReal, EightByteReal>::value;

        return intSizesOK && realSizesOK && realTypesDifferent;
    }
};

#endif // TYPESIZES_H