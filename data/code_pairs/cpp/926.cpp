#include <iostream>
#include <cmath>

float square(float x) {
    return x * x;
}

int main() {
    float x = 2.0f;
    float expected = 4.0f;
    float computed = square(x);

    if (std::abs(computed - expected) < 0.0001f) {
        std::cout << "C++ Stdout: Test Passed." << std::endl;
    } else {
        std::cout << "C++ Stderr: Test Failed." << std::endl;
    }

    return 0;
}