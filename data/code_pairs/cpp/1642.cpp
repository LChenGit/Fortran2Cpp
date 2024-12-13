#include <iostream>
#include <complex>
#include <cmath>

double DCABS1(const std::complex<double>& z) {
    return std::abs(z.real()) + std::abs(z.imag());
}

int main() {
    std::complex<double> z1(3.0, 4.0); // A complex number where real=3 and imag=4
    std::cout << "Test 1: DCABS1((3.0, 4.0)) = " << DCABS1(z1) << std::endl; // Expected: 7

    std::complex<double> z2(-1.5, 2.5); // Another complex number where real=-1.5 and imag=2.5
    std::cout << "Test 2: DCABS1((-1.5, 2.5)) = " << DCABS1(z2) << std::endl; // Expected: 4

    return 0;
}