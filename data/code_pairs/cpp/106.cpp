#include <iostream>
#include <cmath> // for std::abs
#include <cassert> // for assert

int main() {
    float a[2] = {-5.0f, 3.0f}; // Test inputs directly assigned
    float b[2]; // Outputs
    float x;
    
    for (int i = 0; i < 2; ++i) {
        x = std::abs(a[i]);
        b[i] = x;
    }

    // Assertions for automatic verification
    assert(b[0] == 5.0f && "Test 1 Failed: b[0] incorrect.");
    assert(b[1] == 3.0f && "Test 1 Failed: b[1] incorrect.");

    std::cout << "All tests passed!" << std::endl;

    return 0;
}