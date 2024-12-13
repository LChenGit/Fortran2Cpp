#include <iostream>
#include <cstdint>
#include <climits>

int testSetHighestBit() {
    int8_t i1 = -1;
    return (i1 == -1) ? 0 : 1;
}

int testClearHighestBit() {
    int8_t i1 = 0;
    return (i1 == 0) ? 0 : 1;
}

int testInvertBits() {
    int8_t i1 = ~int8_t(0);
    return (i1 == -1) ? 0 : 1;
}

int main() {
    if (testSetHighestBit() == 0) {
        std::cout << "Test for setting the highest bit Passed\n";
    } else {
        std::cout << "Test for setting the highest bit Failed\n";
    }

    if (testClearHighestBit() == 0) {
        std::cout << "Test for clearing the highest bit Passed\n";
    } else {
        std::cout << "Test for clearing the highest bit Failed\n";
    }

    if (testInvertBits() == 0) {
        std::cout << "Test for inverting bits Passed\n";
    } else {
        std::cout << "Test for inverting bits Failed\n";
    }

    return 0;
}