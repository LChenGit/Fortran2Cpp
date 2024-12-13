#include <iostream>
#include <vector>
#include <complex>
#include <cmath>

// Function to be tested
void shiftz(const std::vector<std::complex<float>>& spec, int nsp, float dw, std::vector<std::complex<float>>& z) {
    // Ensure the output vector z has the correct size
    z.resize(nsp);

    std::complex<float> multiplier(std::cos(dw), std::sin(dw));

    for (int i = 0; i < nsp; ++i) {
        z[i] = spec[i] * multiplier;
    }
}

int main() {
    int nsp = 3;
    float dw = 0.5;

    std::vector<std::complex<float>> spec(nsp);
    std::vector<std::complex<float>> z;

    // Assign test values to spec vector
    spec[0] = std::complex<float>(1.0, 2.0);
    spec[1] = std::complex<float>(3.0, 4.0);
    spec[2] = std::complex<float>(5.0, 6.0);

    // Call the function
    shiftz(spec, nsp, dw, z);

    // Print results for verification
    std::cout << "spec: ";
    for (const auto& s : spec) {
        std::cout << "(" << s.real() << ", " << s.imag() << ") ";
    }
    std::cout << std::endl;

    std::cout << "z: ";
    for (const auto& zi : z) {
        std::cout << "(" << zi.real() << ", " << zi.imag() << ") ";
    }
    std::cout << std::endl;

    return 0;
}