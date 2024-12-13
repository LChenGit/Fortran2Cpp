// poly_test.cpp
#include <iostream>
#include <cmath>
#include <cassert> // For assert()

long double timestwo(long double a);

int main() {
    constexpr long double pi = 4.0L * atan(1.0L);
    const long double expected = 2.0L * pi;
    const long double result = timestwo(pi);

    // Simple unit test comparison
    assert(std::abs(result - expected) < 1.0E-8L && "Test failed: Result does not match expected value.");

    std::cout << "Test passed: Result is " << result << std::endl;

    return 0;
}

long double timestwo(long double a) {
    return 2 * a;
}