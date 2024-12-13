#include <cassert>
#include <cstdint>
#include <cmath>
#include <iostream>

int main() {
    int64_t t = -123456;
    double x = 1.7;
    long double y = 1.9;

    // Test the values
    std::cout << "Testing t..." << std::endl;
    assert(t == -123456);
    std::cout << "PASS: t has the expected value." << std::endl;

    std::cout << "Testing x..." << std::endl;
    assert(std::abs(x - 1.7) < 1e-9); // Using a small epsilon for floating point comparison
    std::cout << "PASS: x has the expected value." << std::endl;

    std::cout << "Testing y..." << std::endl;
    assert(std::abs(y - 1.9) < 1e-9); // Using a small epsilon for floating point comparison
    std::cout << "PASS: y has the expected value." << std::endl;

    return 0;
}