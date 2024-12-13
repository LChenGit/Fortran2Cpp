#include <iostream>
#include <cassert>

// Function declaration
int factorial(int n);

// Simple test function declaration
void testFactorial();

int main() {
    testFactorial(); // Run tests

    // Main program logic
    int number;
    std::cout << "Enter a number to calculate factorial: ";
    std::cin >> number;
    std::cout << "The factorial of " << number << " is " << factorial(number) << std::endl;

    return 0;
}

// Function definition
int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; ++i) {
        fact *= i;
    }
    return fact;
}

// Simple test function definition
void testFactorial() {
    assert(factorial(0) == 1); // Test case for factorial of 0
    assert(factorial(1) == 1); // Test case for factorial of 1
    assert(factorial(5) == 120); // Test case for factorial of 5

    std::cout << "All tests passed." << std::endl;
}