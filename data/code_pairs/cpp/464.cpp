#include <iostream>
#include <cassert>

// Define the equivalent function to the .FOO. operator
int F(int A, int B) {
    return A + B;  // Example operation
}

// Function to run tests
void runTests() {
    // Test 1
    assert(F(5, 3) == 8);
    std::cout << "Test 1 passed: F(5, 3) == 8" << std::endl;

    // Test 2
    assert(F(-1, 1) == 0);
    std::cout << "Test 2 passed: F(-1, 1) == 0" << std::endl;

    // Test 3
    assert(F(0, 0) == 0);
    std::cout << "Test 3 passed: F(0, 0) == 0" << std::endl;
}

int main() {
    runTests();
    return 0;
}