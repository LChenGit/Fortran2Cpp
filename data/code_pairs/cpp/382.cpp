#include <iostream>
#include <cassert>

int calculate_factorial(int n) {
    int result = 1;
    for(int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    // Test 1: Factorial of 5
    assert(calculate_factorial(5) == 120);
    std::cout << "Test 1 passed: 5! = 120" << std::endl;

    // Test 2: Factorial of 0
    assert(calculate_factorial(0) == 1);
    std::cout << "Test 2 passed: 0! = 1" << std::endl;

    // Additional tests for completeness
    assert(calculate_factorial(1) == 1);
    assert(calculate_factorial(2) == 2);
    assert(calculate_factorial(3) == 6);
    assert(calculate_factorial(4) == 24);

    std::cout << "All tests passed." << std::endl;

    return 0;
}