#include <iostream>
#include <cmath>
#include <complex>

int main() {
    std::complex<double> complexBase(2.0, -4.3);
    std::complex<double> result = std::pow(complexBase, 2);
    std::complex<double> expected(-14.49, -17.2); // Assuming this is the expected calculation result
    
    const double epsilon = 0.0001;
    if (std::abs(result.real() - expected.real()) < epsilon && std::abs(result.imag() - expected.imag()) < epsilon) {
        std::cout << "Test passed for complex power." << std::endl;
    } else {
        std::cout << "Test failed for complex power." << std::endl;
    }
    
    return 0;
}