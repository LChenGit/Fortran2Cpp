#include <iostream>
#include <cmath>
#include <iomanip> // For setting precision

// Function declarations
double exau(double x, double y, double t);
double exav(double x, double y, double t);
double exap(double x, double y, double t);

int main() {
    // Test values
    double x = 0.5, y = -0.4, t = 1.0;

    // Set precision for printing
    std::cout << std::fixed << std::setprecision(6);

    // Testing exau
    std::cout << "exau(" << x << ", " << y << ", " << t << ") = " << exau(x, y, t) << std::endl;

    // Testing exav
    std::cout << "exav(" << x << ", " << y << ", " << t << ") = " << exav(x, y, t) << std::endl;

    // Testing exap
    std::cout << "exap(" << x << ", " << y << ", " << t << ") = " << exap(x, y, t) << std::endl;

    return 0;
}

// Function definitions
double exau(double x, double y, double t) {
    return -exp(-2 * t) * cos(x) * sin(y);
}

double exav(double x, double y, double t) {
    return exp(-2 * t) * sin(x) * cos(y);
}

double exap(double x, double y, double t) {
    return -0.25 * exp(-4 * t) * (cos(2 * x) + cos(2 * y));
}