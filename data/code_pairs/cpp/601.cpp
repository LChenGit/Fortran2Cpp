#include <iostream>
#include <cmath>
#include <algorithm>

double DLAPY3(double X, double Y, double Z) {
    const double ZERO = 0.0;
    double XABS = std::abs(X);
    double YABS = std::abs(Y);
    double ZABS = std::abs(Z);
    double W = std::max({XABS, YABS, ZABS});

    if (W == ZERO) {
        return ZERO;
    } else {
        return W * std::sqrt((XABS / W) * (XABS / W) + (YABS / W) * (YABS / W) + (ZABS / W) * (ZABS / W));
    }
}

int main() {
    const double error = 1e-10;

    // Test 1
    if (std::abs(DLAPY3(1.0, 2.0, 2.0) - 3.0) > error) {
        std::cout << "Test 1 Failed" << std::endl;
    } else {
        std::cout << "Test 1 Passed" << std::endl;
    }

    // Test 2
    if (std::abs(DLAPY3(0.0, 0.0, 0.0) - 0.0) > error) {
        std::cout << "Test 2 Failed" << std::endl;
    } else {
        std::cout << "Test 2 Passed" << std::endl;
    }

    // Test 3
    if (std::abs(DLAPY3(-3.0, 4.0, 0.0) - 5.0) > error) {
        std::cout << "Test 3 Failed" << std::endl;
    } else {
        std::cout << "Test 3 Passed" << std::endl;
    }

    return 0;
}