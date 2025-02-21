#include <iostream>
#include <cmath>

bool has_close_elements(double* a, double* b, int n, double tol) {
    for (int i = 0; i < n; ++i) {
        if (std::fabs(a[i] - b[i]) > tol) return false;
    }
    return true;
}

int main() {
    double a[] = {1.000001, 2.000001};
    double b[] = {1.0, 2.0};
    int n = sizeof(a)/sizeof(a[0]);
    double tol = 1e-6;

    if (has_close_elements(a, b, n, tol)) {
        std::cout << "Test passed: arrays have close elements" << std::endl;
    } else {
        std::cout << "Test failed: arrays do not have close elements" << std::endl;
    }

    double f[] = {-3.0, -4.0};
    double expected_f[] = {-3.0, -4.0};

    if (has_close_elements(f, expected_f, n, tol)) {
        std::cout << "Test passed: function values match expected values" << std::endl;
    } else {
        std::cout << "Test failed: function values do not match expected values" << std::endl;
    }

    return 0;
}