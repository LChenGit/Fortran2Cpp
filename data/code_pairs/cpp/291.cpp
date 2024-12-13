#include <iostream>
#include <cassert>

float square(float x) {
    return x * x;
}

int main() {
    float number = 4.0;
    float result = square(number);
    assert(result == 16.0); // Simple assertion for unit testing
    std::cout << "C++ Stdout: The square of " << number << " is " << result << std::endl;
    return 0;
}