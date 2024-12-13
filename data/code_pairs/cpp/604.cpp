#include <iostream>
#include <iomanip>
#include <cmath>

// Declaration of a function to compute value
double computeValue() {
    return 3.14;
}

// A very simple test function
void testComputeValue() {
    double expected = 3.14;
    double tolerance = 0.01;
    double result = computeValue();

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Computed Value: " << result << std::endl;

    std::cout << "Testing computeValue... ";

    if (std::fabs(result - expected) <= tolerance) {
        std::cout << "PASSED" << std::endl;
    } else {
        std::cout << "FAILED: Expected " << expected << ", got " << result << std::endl;
    }
}

// Main program: runs both the functionality and the tests
int main() {
    // Run the test
    testComputeValue();

    return 0;
}