#include <iostream>
#include <cstdlib>  // For std::abort
#include <cstdint>  // For fixed-width integer types

void assert_equal(int64_t actual, int64_t expected, const char* name) {
    if (actual != expected) {
        std::cerr << "Test failed: " << name << " expected: " << expected << " but got: " << actual << std::endl;
        std::abort();
    } else {
        std::cout << "Test passed: " << name << std::endl;
    }
}

int main() {
    constexpr int8_t b1 = 0b000000000001111;
    constexpr int16_t b2 = 0b00000000000000000111000011110000;
    constexpr int32_t b4 = 0b0000000000000000000000000000000001110000111100001111000011110000;

    constexpr int8_t o1 = 012;  // Octal
    constexpr int16_t o2 = 04321;  // Octal
    constexpr int32_t o4 = 043210765;  // Octal

    constexpr int8_t z1 = 0x0a;  // Hexadecimal
    constexpr int16_t z2 = 0x00ab;  // Hexadecimal
    constexpr int32_t z4 = 0x0000dead;  // Hexadecimal

    assert_equal(b1, 15, "b1");
    assert_equal(b2, 28912, "b2");
    assert_equal(b4, 1894838512, "b4");

    assert_equal(o1, 10, "o1");
    assert_equal(o2, 2257, "o2");
    assert_equal(o4, 9245173, "o4");

    assert_equal(z1, 10, "z1");
    assert_equal(z2, 171, "z2");
    assert_equal(z4, 57005, "z4");

    return 0;
}