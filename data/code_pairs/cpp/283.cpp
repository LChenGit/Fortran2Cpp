#include <iostream>
#include <cmath> // For std::abs

// Function prototype declaration
double REF(double A);

// Test function prototype
void testREF(double input, double expected);

int main() {
    testREF(2.0, 4.0); // Test 1
    testREF(-1.0, -2.0); // Test 2
    return 0;
}

// Function definition
double REF(double A) {
    double B;
    B = A + A;
    return B;
}

// Test function definition
void testREF(double input, double expected) {
    double result = REF(input);
    if (std::abs(result - expected) < 1e-6) { // Floating-point comparison
        std::cout << "Test Passed: REF(" << input << ") = " << expected << std::endl;
    } else {
        std::cout << "Test Failed: REF(" << input << ") = " << result << ", expected " << expected << std::endl;
    }
}