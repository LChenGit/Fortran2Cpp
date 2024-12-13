#include <iostream>

int calculateFactorial(int n) {
    int result = 1;
    for(int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

void testFactorial(int n, int expected) {
    int result = calculateFactorial(n);
    if(result == expected) {
        std::cout << "Test passed for n = " << n << std::endl;
    } else {
        std::cout << "Test failed for n = " << n << ". Expected: " << expected << ", Got: " << result << std::endl;
    }
}

int main() {
    testFactorial(0, 1);
    testFactorial(1, 1);
    testFactorial(5, 120);
    return 0;
}