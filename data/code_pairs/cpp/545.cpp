#include <iostream>
#include <cassert>

float square(float x) {
    return x * x;
}

int main() {
    float x = 4.0f;
    float expected = 16.0f;
    float computed = square(x);

    assert(computed == expected); // Simple assertion as a unit test.
    std::cout << "Test passed." << std::endl;

    // In a real scenario, you might use a proper unit testing framework
    // and have more comprehensive tests with different inputs and expected outputs.

    return 0;
}