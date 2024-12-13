#include <cassert>
#include <iostream>

// Function to be tested
int square(int x) {
    return x * x;
}

// A simple test function for `square`
void testSquare() {
    assert(square(5) == 25); // Test with a positive number
    assert(square(-4) == 16); // Test with a negative number
    assert(square(0) == 0); // Test with zero
    
    std::cout << "All C++ tests passed." << std::endl;
}

int main() {
    // Run the test
    testSquare();
    return 0;
}