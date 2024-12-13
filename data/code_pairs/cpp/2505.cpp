#include <iostream>
#include <complex>
#include <cstdlib>

int main() {
    std::complex<double> z0, z1, z2;

    z0 = std::complex<double>(0.0, 0.5);
    z1 = 1.0 / z0;
    if (z1 != std::complex<double>(0.0, -2.0)) {
        std::cerr << "STOP 1" << std::endl;
        std::exit(1);
    }

    z0 = 10.0 * z0;
    if (z0 != std::complex<double>(0.0, 5.0)) {
        std::cerr << "STOP 2" << std::endl;
        std::exit(2);
    }

    z2 = std::complex<double>(1.0, 2.0);
    z1 = z0 / z2;
    if (z1 != std::complex<double>(2.0, 1.0)) {
        std::cerr << "STOP 3" << std::endl;
        std::exit(3);
    }

    z1 = z0 * z2;
    if (z1 != std::complex<double>(-10.0, 5.0)) {
        std::cerr << "STOP 4" << std::endl;
        std::exit(4);
    }

    return 0;
}