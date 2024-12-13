#include <iostream>
#include <cassert>

int factorial(int n) {
    if (n == 0) return 1;
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

void test_factorial(int n, int expected) {
    int result = factorial(n);
    assert(result == expected);
    std::cout << "Test passed for n = " << n << std::endl;
}

int main() {
    // Test case 1: Factorial of 5
    test_factorial(5, 120);

    // Test case 2: Factorial of 0
    test_factorial(0, 1);

    // Test case 3: Factorial of 10
    test_factorial(10, 3628800);

    return 0;
}