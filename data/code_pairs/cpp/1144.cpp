#include <iostream>
#include <cmath> // For std::fabs

namespace modE {
    double square(double x) {
        return x * x;
    }
}

void testSquareFunction(double input, double expectedOutput) {
    double result = modE::square(input);

    if (std::fabs(result - expectedOutput) < 1e-6) { // Using a small tolerance for floating point comparison
        std::cout << "Test passed: Square of " << input << " is " << result << std::endl;
    } else {
        std::cout << "Test failed: Square of " << input << " is " << result << ", expected " << expectedOutput << std::endl;
    }
}

int main() {
    double value = 3.0;
    std::cout << "The square of " << value << " is " << modE::square(value) << std::endl;

    testSquareFunction(2.0, 4.0); // Example test

    return 0;
}