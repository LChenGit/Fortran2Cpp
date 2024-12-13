#include <iostream>
#include <cmath>
#include <cassert>

double PTOPA(double P) {
    return 44331.0 * (1.0 - pow(P / 1013.25, 0.190263));
}

int main() {
    // Test cases
    assert(std::abs(PTOPA(1013.25) - 0.0) < 1e-5); // Expecting a value close to 0
    assert(std::abs(PTOPA(800) - 1948.99573) < 1e-5); // Close to the Fortran output

    std::cout << "PTOPA(1013.25) = " << PTOPA(1013.25) << std::endl;
    std::cout << "PTOPA(800) = " << PTOPA(800) << std::endl;

    return 0;
}