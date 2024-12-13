#include <cmath>
#include <iostream>
#include <cstdlib> // For std::abs in C++

// Global variables for pi and pi2
double pi, pi2;

// Function prototype
void mapc2m_latlong(int blockno, double xc, double yc, double& xp, double& yp, double& zp) {
    double deg2rad = pi / 180.0;

    double xc1 = deg2rad * xc;
    double yc1 = deg2rad * yc;

    xp = std::cos(yc1) * std::cos(xc1);
    yp = std::cos(yc1) * std::sin(xc1);
    zp = std::sin(yc1);
}

// Helper function for comparing floating-point numbers
bool check_close(double val1, double val2, double tolerance) {
    return std::abs(val1 - val2) < tolerance;
}

int main() {
    pi = 3.141592653589793;
    pi2 = 2.0 * pi;
    double tolerance = 1e-6;

    int blockno = 1;
    double xc = 0.0, yc = 0.0;
    double xp, yp, zp;
    double expected_xp = 1.0, expected_yp = 0.0, expected_zp = 0.0;

    mapc2m_latlong(blockno, xc, yc, xp, yp, zp);

    if (!check_close(xp, expected_xp, tolerance) ||
        !check_close(yp, expected_yp, tolerance) ||
        !check_close(zp, expected_zp, tolerance)) {
        std::cout << "Test Case 1 Failed" << std::endl;
    } else {
        std::cout << "Test Case 1 Passed" << std::endl;
    }

    return 0;
}