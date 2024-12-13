#include <iostream>
#include <cmath>
#include <algorithm>
#include <limits>

float z[3] = {1.0, 1.0, 1.0};

void sub(const float* x, float* res, int size) {
    std::copy(x, x + size, res);
}

void doubleArray(float* x, int size) {
    std::transform(x, x + size, x, [](float v) { return 2 * v; });
}

float* get_var() {
    return z;
}

// Simplified test framework for demonstration
void test_sub() {
    float testRes[3];
    const float inputArr[3] = {1.0, 1.0, 1.0};
    const float expectedRes[3] = {1.0, 1.0, 1.0};
    sub(inputArr, testRes, 3);
    bool passed = true;
    for (int i = 0; i < 3; ++i) {
        if (std::abs(testRes[i] - expectedRes[i]) >= std::numeric_limits<float>::epsilon()) {
            passed = false;
            break;
        }
    }
    std::cout << "test_sub: " << (passed ? "PASSED" : "FAILED") << std::endl;
}

void test_double() {
    float testArr[3] = {1.0, 2.0, 3.0};
    doubleArray(testArr, 3);
    const float expectedArr[3] = {2.0, 4.0, 6.0};
    bool passed = true;
    for (int i = 0; i < 3; ++i) {
        if (std::abs(testArr[i] - expectedArr[i]) >= std::numeric_limits<float>::epsilon()) {
            passed = false;
            break;
        }
    }
    std::cout << "test_double: " << (passed ? "PASSED" : "FAILED") << std::endl;
}

void test_get_var() {
    float* ptr = get_var();
    bool passed = (ptr == z);
    std::cout << "test_get_var: " << (passed ? "PASSED" : "FAILED") << std::endl;
}

int main() {
    // Call your program's main functions here

    // Call test functions
    test_sub();
    test_double();
    test_get_var();

    return 0;
}