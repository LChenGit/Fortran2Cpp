#include <cmath>
#include <iostream>
#include <cassert>

double SINDD(double ALFA) {
    const double PI = 3.14159265358979323840;
    double ALFARAD = ALFA * PI / 180.0;
    return sin(ALFARAD);
}

int main() {
    // Test the SINDD function with a known value
    double result = SINDD(30.0);
    std::cout << "Sine of 30 degrees: " << result << std::endl;
    std::cout << "Expected value: " << 0.5 << std::endl;
    
    // Check if the result is close enough to 0.5, considering floating point arithmetic precision
    assert(std::abs(result - 0.5) < 1E-6);
    std::cout << "Test passed." << std::endl;
    
    return 0;
}