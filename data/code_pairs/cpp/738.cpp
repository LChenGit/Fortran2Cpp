#include <iostream>
#include <cmath>
#include <cstdint>
#include <limits>

// Function approximating Fortran's selected_int_kind
int selected_int_kind(int r) {
    if (r <= std::log10(std::numeric_limits<int8_t>::max())) return 1;
    if (r <= std::log10(std::numeric_limits<int16_t>::max())) return 2;
    if (r <= std::log10(std::numeric_limits<int32_t>::max())) return 4;
    if (r <= std::log10(std::numeric_limits<int64_t>::max())) return 8;
    return -1;
}

int main() {
    // Tests mimic the structure of the Fortran tests
    bool allTestsPassed = true;

    if (selected_int_kind(static_cast<int>(std::log10(std::numeric_limits<int8_t>::max()))) != 1) {
        std::cout << "Test for int8_t Failed\n";
        allTestsPassed = false;
    }

    if (selected_int_kind(static_cast<int>(std::log10(std::numeric_limits<int16_t>::max()))) != 2) {
        std::cout << "Test for int16_t Failed\n";
        allTestsPassed = false;
    }

    if (selected_int_kind(static_cast<int>(std::log10(std::numeric_limits<int32_t>::max()))) != 4) {
        std::cout << "Test for int32_t Failed\n";
        allTestsPassed = false;
    }

    if (selected_int_kind(static_cast<int>(std::log10(std::numeric_limits<int64_t>::max()))) != 8) {
        std::cout << "Test for int64_t Failed\n";
        allTestsPassed = false;
    }

    int i4 = std::numeric_limits<int32_t>::max();
    if (selected_int_kind(i4) != -1) {
        std::cout << "Special Case Test Failed\n";
        allTestsPassed = false;
    }

    if (allTestsPassed) {
        std::cout << "All tests passed!\n";
    }

    return 0;
}