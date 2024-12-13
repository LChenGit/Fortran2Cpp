#include <iostream>
#include <cmath> // for pow
#include <cassert> // for assert

int main() {
    double x;
    x = pow(2.0, -3) * 5;
    double expected = 0.625;

    // Assert that the absolute difference is small to account for floating-point arithmetic errors
    assert(std::abs(x - expected) < 1e-5);

    std::cout << "Test passed: x = " << x << std::endl;
    return 0;
}