#include <iostream>
#include <cmath>
#include <cstdlib>

// Global variables to replicate the Fortran common block
double a, b, c;

void initialize(double va, double vb, double vc) {
    a = va;
    b = vb;
    c = vc;
}

void check_values() {
    const double eps = 0.00001;

    if (std::abs(a - 3.0) < eps && std::abs(b - 4.0) < eps && std::abs(c - 5.0) < eps) {
        std::cout << "Test OK" << std::endl;
    } else {
        std::cout << "Test NG" << std::endl;
        // In a test, we generally don't want to exit the program early
    }
}

int main() {
    // Test 1: Expected OK
    initialize(3.0, 4.0, 5.0);
    check_values();

    // Test 2: Expected NG
    initialize(3.1, 4.0, 5.0);
    check_values();

    return 0;
}