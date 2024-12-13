#include <cstdint>

std::int64_t specific__dim_i8(std::int64_t p1, std::int64_t p2) {
    return (p1 > p2) ? (p1 - p2) : 0;
}