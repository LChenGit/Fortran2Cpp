#include <iostream>
#include <complex>

// Declaration of IZMAX1 function
int IZMAX1(int N, std::complex<double>* CX, int INCX);

int main() {
    // Test 1: Single-element array
    std::complex<double> cx1[] = {std::complex<double>(1.0, 2.0)};
    std::cout << "Test 1 (Single-element array): Expected 0, got " << IZMAX1(1, cx1, 1) << std::endl;

    // Test 2: Multi-element array, INCX = 1
    std::complex<double> cx2[] = {std::complex<double>(2.0, 2.0), std::complex<double>(3.0, 4.0), std::complex<double>(1.0, 1.0)};
    std::cout << "Test 2 (Multi-element, INCX=1): Expected 1, got " << IZMAX1(3, cx2, 1) << std::endl;

    // Test 3: Multi-element array, INCX > 1
    std::cout << "Test 3 (Multi-element, INCX>1): Expected 0, got " << IZMAX1(3, cx2, 2) << std::endl;

    return 0;
}

// The IZMAX1 function goes here, as defined in the initial C++ code you provided.