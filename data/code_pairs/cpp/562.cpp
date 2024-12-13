#include <iostream>
#include <cmath> // For fabs function

void test(int n, float* a, const float* b, const float* c) {
    for (int i = 0; i < n; ++i) {
        a[i] = b[i] + c[i];
    }
}

// Simple function to check arrays for equality
bool check_arrays(float* a, float* expected, int n) {
    for (int i = 0; i < n; ++i) {
        if (std::fabs(a[i] - expected[i]) > 1e-5) { // Using a small tolerance for floating point comparison
            return false;
        }
    }
    return true;
}

int main() {
    const int size = 5;
    float a[size], b[size], c[size], expected[size];

    // Test 1: Positive numbers
    float test1_b[size] = {1.0, 2.0, 3.0, 4.0, 5.0}, test1_c[size] = {5.0, 4.0, 3.0, 2.0, 1.0};
    float test1_expected[size] = {6.0, 6.0, 6.0, 6.0, 6.0};
    test(size, a, test1_b, test1_c);
    std::cout << "Test 1: " << (check_arrays(a, test1_expected, size) ? "Passed" : "Failed") << std::endl;

    // Test 2: Negative numbers
    float test2_b[size] = {-1.0, -2.0, -3.0, -4.0, -5.0}, test2_c[size] = {-5.0, -4.0, -3.0, -2.0, -1.0};
    float test2_expected[size] = {-6.0, -6.0, -6.0, -6.0, -6.0};
    test(size, a, test2_b, test2_c);
    std::cout << "Test 2: " << (check_arrays(a, test2_expected, size) ? "Passed" : "Failed") << std::endl;

    // Test 3: Zeros and positive numbers
    float test3_b[size] = {0.0, 0.0, 0.0, 0.0, 0.0}, test3_c[size] = {1.0, 2.0, 3.0, 4.0, 5.0};
    float test3_expected[size] = {1.0, 2.0, 3.0, 4.0, 5.0};
    test(size, a, test3_b, test3_c);
    std::cout << "Test 3: " << (check_arrays(a, test3_expected, size) ? "Passed" : "Failed") << std::endl;

    return 0;
}