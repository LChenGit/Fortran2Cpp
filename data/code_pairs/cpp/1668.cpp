#include <iostream>
#include <complex>
#include <cmath>

float SCABS1(std::complex<float> z) {
    return std::abs(z.real()) + std::abs(z.imag());
}

int main() {
    // Test cases
    std::complex<float> z1(3.0, 4.0);
    std::cout << "SCABS1(3+4i) = " << SCABS1(z1) << std::endl;

    std::complex<float> z2(-5.0, -12.0);
    std::cout << "SCABS1(-5-12i) = " << SCABS1(z2) << std::endl;

    return 0;
}