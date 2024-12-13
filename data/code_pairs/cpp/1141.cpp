// Interpolate.h
#ifndef INTERPOLATE_H
#define INTERPOLATE_H

class Interpolate {
public:
    // Linear interpolation function
    static double linearInterpolation(double x1, double y1, double x2, double y2, double xi) {
        return y1 + (xi - x1) * (y2 - y1) / (x2 - x1);
    }
};

#endif // INTERPOLATE_H

// test_interpolate.cpp
#include <iostream>
#include <cmath> // For std::abs
#include "Interpolate.h"

// A simple test function for linear interpolation
void testLinearInterpolation(double x1, double y1, double x2, double y2, double xi, double expectedYi, const std::string& testName) {
    double yi = Interpolate::linearInterpolation(x1, y1, x2, y2, xi);
    if (std::abs(yi - expectedYi) < 1e-6) {
        std::cout << "PASS: " << testName << std::endl;
    } else {
        std::cout << "FAIL: " << testName << " - Expected " << expectedYi << ", got " << yi << std::endl;
    }
}

int main() {
    // Test cases for linear interpolation
    testLinearInterpolation(0.0, 0.0, 10.0, 10.0, 5.0, 5.0, "Test 1: Simple linear interpolation");
    testLinearInterpolation(1.0, 2.0, 3.0, 4.0, 2.0, 3.0, "Test 2: Off-origin linear interpolation");

    return 0;
}