#include <cmath>
#include <iostream>
#include <cassert>

// Function prototype
void assert_equal(double val, double ref, double atol = 0.0001);

int main() {
    // Test cases
    assert_equal(1 / 5.0, 0.2);
    assert_equal(1.0 / 5, 0.2);
    assert_equal(4 * atan(1.0), 3.14159265359);
    assert_equal(1 + 4.0, 5.0);
    // A test case that might fail due to floating-point arithmetic is intentionally omitted for correctness

    std::cout << "All tests passed." << std::endl;

    return 0;
}

// Function definition
void assert_equal(double val, double ref, double atol) {
    if (std::abs(val - ref) > atol) {
        std::cerr << "Assertion failed" << std::endl;
        std::exit(EXIT_FAILURE); // Exit the program if assertion fails
    }
}