// bad1.cpp
#include <iostream>
#include <cmath> // For std::fabs()

// Declaration of bad1
void bad1(double& d) {
    d = 5.0;
}

// A simple test function for bad1
void test_bad1() {
    double d = 0.0;
    bad1(d);

    // Simple floating point comparison
    if (std::fabs(d - 5.0) < 1e-6) {
        std::cout << "Test passed: d equals 5.0" << std::endl;
    } else {
        std::cout << "Test failed: d does not equal 5.0" << std::endl;
    }
}

int main() {
    test_bad1(); // Run the test
    return 0;
}