// Filename: test_cuconmut.cpp
#include <iostream>
#include <complex>

// Function declarations
void cuconmut(double* data, int size) {
    for (int i = 0; i < size; ++i) {
        data[i] *= 2.0;
    }
}

void cuconmut(std::complex<double>* data, int size) {
    for (int i = 0; i < size; ++i) {
        data[i] *= std::complex<double>(2.0, 0.0);
    }
}

int main() {
    const int size = 5;
    double real_data[size] = {1.0, 2.0, 3.0, 4.0, 5.0};
    std::complex<double> complex_data[size] = {
        {1.0, 1.0}, {2.0, 2.0}, {3.0, 3.0}, {4.0, 4.0}, {5.0, 5.0}
    };

    // Test cuconmut with real data
    cuconmut(real_data, size);
    std::cout << "Real data after cuconmut: ";
    for (int i = 0; i < size; ++i) {
        std::cout << real_data[i] << " ";
    }
    std::cout << std::endl;

    // Test cuconmut with complex data
    cuconmut(complex_data, size);
    std::cout << "Complex data after cuconmut: ";
    for (int i = 0; i < size; ++i) {
        std::cout << "(" << complex_data[i].real() << ", " << complex_data[i].imag() << ") ";
    }
    std::cout << std::endl;

    return 0;
}