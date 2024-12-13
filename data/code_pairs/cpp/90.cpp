#include <iostream>
#include <cstdint>  // For std::int16_t

std::int16_t sumSelectedIntegers(const std::int16_t* array, size_t size, const bool* mask) {
    std::int16_t sum = 0;
    for (size_t i = 0; i < size; ++i) {
        if (mask[i]) {
            sum += array[i];
        }
    }
    return sum;
}