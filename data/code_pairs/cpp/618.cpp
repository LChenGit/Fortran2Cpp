#include <cstdint>
#include <climits>
#include <limits>

class TypeSizes {
public:
    static bool byteSizesOK() {
        // Using fixed-width integers to check sizes
        int8_t One;
        int16_t Two;
        int32_t Four;

        // Check sizes and floating-point properties
        if (sizeof(One) * CHAR_BIT == 8 &&
            sizeof(Two) * CHAR_BIT == 16 &&
            sizeof(Four) * CHAR_BIT == 32 &&
            std::numeric_limits<float>::is_iec559 && // IEEE 754 check for float
            std::numeric_limits<double>::is_iec559 && // IEEE 754 check for double
            std::numeric_limits<float>::radix == 2 &&
            std::numeric_limits<double>::radix == 2) { // Checking radix for binary FP representation
            return true;
        } else {
            return false;
        }
    }
};