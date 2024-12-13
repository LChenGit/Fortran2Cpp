#include <cstdint>
#include <iostream>

template<typename T>
void mvbits(uint16_t source, int from, int len, T& dest, int topos) {
    dest = (source >> from) & ((1 << len) - 1);
}

int main() {
    int64_t i8 = 0;
    int32_t i4 = 0;
    int16_t i2 = 0;
    int8_t i1 = 0;

    mvbits(1, 0, 8, i1, 0);
    std::cout << "Test for i1: " << +i1 << std::endl; // Using unary + to correctly print int8_t as number

    mvbits(1, 0, 16, i2, 0);
    std::cout << "Test for i2: " << i2 << std::endl;

    mvbits(1, 0, 16, i4, 0);
    std::cout << "Test for i4: " << i4 << std::endl;

    mvbits(1, 0, 16, i8, 0);
    std::cout << "Test for i8: " << i8 << std::endl;

    return 0;
}