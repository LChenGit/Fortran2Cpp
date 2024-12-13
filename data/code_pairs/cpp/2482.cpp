#include <iostream>
#include <cmath>

// Function declaration
double iau_ANP(double A);

int main() {
    double test_cases[] = { -1.0, 0.0, 7.0 };
    double expected_results[] = { 5.283185307179586, 0.0, 0.7168146928204138 };
    bool all_passed = true;

    for (int i = 0; i < 3; ++i) {
        double result = iau_ANP(test_cases[i]);
        std::cout << "Test case: " << test_cases[i] << " Result: " << result << " Expected: " << expected_results[i] << std::endl;

        if (std::abs(result - expected_results[i]) > 1.0e-10) {
            std::cout << "Test failed!" << std::endl;
            all_passed = false;
        } else {
            std::cout << "Test passed!" << std::endl;
        }
    }

    if (all_passed) {
        std::cout << "All tests passed!" << std::endl;
    } else {
        std::cout << "Some tests failed!" << std::endl;
    }

    return 0;
}

// Function definition
double iau_ANP(double A) {
    const double D2PI = 6.283185307179586476925287;
    double W = fmod(A, D2PI);
    if (W < 0.0) W += D2PI;
    return W;
}