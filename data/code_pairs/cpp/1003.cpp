#include <iostream>
#include <complex>

void zdscale(int n, double da, std::complex<double>* zx, int incx) {
    if (n <= 0 || incx <= 0) return;

    if (incx == 1) {
        for (int i = 0; i < n; ++i) {
            zx[i] = std::complex<double>(da, 0.0) * zx[i];
        }
    } else {
        int nincx = n * incx;
        for (int i = 0; i < nincx; i += incx) {
            zx[i] = std::complex<double>(da, 0.0) * zx[i];
        }
    }
}