#include <cstdint>
#include <iostream>

void GET_LRBT_SLICES(
    std::int32_t ICHUNK,
    std::int32_t& ILEFT,
    std::int32_t& IRIGHT
) {
    // Simple demonstration logic
    ILEFT = ICHUNK - 1;
    IRIGHT = ICHUNK + 1;
}