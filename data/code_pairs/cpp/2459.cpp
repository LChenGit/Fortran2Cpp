#include <iostream>
#include <vector>
#include <complex>
#include <cassert>

float scasum(int n, const std::vector<std::complex<float>>& cx, int incx) {
    float stemp = 0.0f;

    if (n <= 0 || incx <= 0) {
        return 0.0f;
    }

    if (incx == 1) {
        for (int i = 0; i < n; ++i) {
            stemp += std::abs(cx[i].real()) + std::abs(cx[i].imag());
        }
    } else {
        for (int i = 0; i < n * incx; i += incx) {
            stemp += std::abs(cx[i].real()) + std::abs(cx[i].imag());
        }
    }

    return stemp;
}