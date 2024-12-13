#include <iostream>
#include <vector>
#include <memory>
#include <cassert>

// Function definition
void tq_tvgh(float& t, const float& p) {
    t = p;
}

int main() {
    int jplev = 42;
    int k_lev = 1;

    std::vector<float> p(jplev);
    std::unique_ptr<float[]> q(new float[jplev]);

    // Initialize test data
    for (int i = 0; i < jplev; ++i) {
        p[i] = static_cast<float>(i + 1); // Initialize p with 1.0, 2.0, ..., 42.0
    }

    // Call the function
    for (int i = k_lev - 1; i < jplev; ++i) {
        tq_tvgh(q[i], p[i]);
    }

    // Test the result
    bool test_passed = true;
    for (int i = k_lev - 1; i < jplev; ++i) {
        if (q[i] != p[i]) {
            test_passed = false;
            break;
        }
    }

    // Print test result
    if (test_passed) {
        std::cout << "Test Passed" << std::endl;
    } else {
        std::cout << "Test Failed" << std::endl;
    }

    return 0;
}