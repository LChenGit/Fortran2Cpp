#include <iostream>
#include <array>
#include <cmath>

bool test_arrays() {
    std::array<float, 3> y = {2.0f * 1, 2.0f * 2, 2.0f * 3}; // Initialize y array
    std::array<float, 4> z = {2.0f * 1, 2.0f * 2, 2.0f * 4, 2.0f * 3}; // Initialize z array
    bool test_passed = true;

    for (int i = 0; i < y.size(); ++i) {
        if (std::abs(y[i] - std::array<float, 3>{2.f, 4.f, 6.f}[i]) > 0.001f) { // Using a small threshold for float comparison
            std::cerr << "Test failed for y at index " << i << std::endl;
            test_passed = false;
        }
    }

    for (int i = 0; i < z.size(); ++i) {
        if (std::abs(z[i] - std::array<float, 4>{2.f, 4.f, 8.f, 6.f}[i]) > 0.001f) { // Using a small threshold for float comparison
            std::cerr << "Test failed for z at index " << i << std::endl;
            test_passed = false;
        }
    }

    return test_passed;
}

int main() {
    if (test_arrays()) {
        std::cout << "All tests passed." << std::endl;
        return 0;
    } else {
        std::cerr << "Some tests failed." << std::endl;
        return 1;
    }
}