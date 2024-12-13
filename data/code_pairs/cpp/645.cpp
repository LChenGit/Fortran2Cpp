#include <array>

void addArrays(const std::array<float, 5>& array1, const std::array<float, 5>& array2, std::array<float, 5>& sumArray) {
    for (size_t i = 0; i < 5; ++i) {
        sumArray[i] = array1[i] + array2[i];
    }
}