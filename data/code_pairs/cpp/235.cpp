#include <cmath>  // Include for math functions
#include <iostream>
#include <cassert> // For assert

double datanh(double x) {
    return tanh(x);
}

void xdatanh(double x, double& result) {
    result = datanh(x);
}

int main() {
    double x = 0.5;  // Example input
    double result;
    double expected = std::tanh(x); // The expected result using the standard library

    xdatanh(x, result);
    
    // Test
    assert(std::abs(result - expected) < 1.0e-7);
    std::cout << "Test passed for x=" << x << std::endl;
    
    return 0;
}