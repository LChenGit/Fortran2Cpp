// iau_EPJ2JD.cpp
#include <iostream>
#include <cassert>
#include <cmath> // For std::abs

void iau_EPJ2JD(double EPJ, double& DJM0, double& DJM) {
    DJM0 = 2400000.5;
    DJM = 51544.5 + (EPJ - 2000.0) * 365.25;
}

void test_iau_EPJ2JD() {
    double EPJ = 2000.0; // Known epoch year
    double expected_DJM0 = 2400000.5;
    double expected_DJM = 51544.5;
    double DJM0, DJM;

    iau_EPJ2JD(EPJ, DJM0, DJM);

    // Asserting the results with a tolerance for floating-point comparison
    assert(std::abs(DJM0 - expected_DJM0) < 1e-12);
    assert(std::abs(DJM - expected_DJM) < 1e-12);

    std::cout << "Test passed: iau_EPJ2JD with EPJ = " << EPJ << std::endl;
}

int main() {
    test_iau_EPJ2JD();
    return 0;
}