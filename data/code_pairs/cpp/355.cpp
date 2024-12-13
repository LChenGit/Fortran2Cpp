#include <iostream>
#include <cmath>

void testDoublePrecision() {
    double value = 1.0;
    std::cout << "Testing double precision representation of 1.0..." << std::endl;
    if (std::abs(value - 1.0) < 1e-9) { // Check if value is close enough to 1.0
        std::cout << "Test passed." << std::endl;
    } else {
        std::cout << "Test failed. Expected: 1.0, Got: " << value << std::endl;
    }
}

int main() {
    testDoublePrecision();
    return 0;
}