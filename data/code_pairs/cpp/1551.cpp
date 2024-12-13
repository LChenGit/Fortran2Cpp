#include <iostream>
#include <cmath>
#include <complex>

// Function declarations
void arcDAbs(double& r, double x);
void arcXDAbs(double& r, std::complex<double> x);

// Main function for basic testing
int main() {
    double rReal;
    std::complex<double> testValueComplex(3.0, 4.0);

    // Test arcDAbs
    arcDAbs(rReal, -4.0);
    std::cout << "arcDAbs(-4.0) = " << rReal << std::endl;

    // Test arcXDAbs
    arcXDAbs(rReal, testValueComplex);
    std::cout << "arcXDAbs((3.0, 4.0)) = " << rReal << std::endl;

    return 0;
}

// Function implementations
void arcDAbs(double& r, double x) {
    r = std::abs(x);
}

void arcXDAbs(double& r, std::complex<double> x) {
    r = std::abs(x);
}