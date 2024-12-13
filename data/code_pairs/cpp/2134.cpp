#include <iostream>
#include <complex>
#include <cassert>

void zlacgv(int n, std::complex<double>* x, int incx) {
    if (incx == 1) {
        for (int i = 0; i < n; ++i) {
            x[i] = std::conj(x[i]);
        }
    } else {
        int ioff = 0;
        if (incx < 0) {
            ioff = (1 - (n - 1) * incx) - 1; // Adjust for zero-based indexing
        }
        for (int i = 0; i < n; ++i) {
            x[ioff] = std::conj(x[ioff]);
            ioff += incx;
        }
    }
}

void test_zlacgv() {
    int n = 5;
    int incx = 1;
    std::complex<double> x[] = { {1.0, 2.0}, {3.0, 4.0}, {5.0, 6.0}, {7.0, 8.0}, {9.0, 10.0} };
    std::complex<double> expected[] = { {1.0, -2.0}, {3.0, -4.0}, {5.0, -6.0}, {7.0, -8.0}, {9.0, -10.0} };

    zlacgv(n, x, incx);

    for (int i = 0; i < n; ++i) {
        assert(x[i] == expected[i]);
    }

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    test_zlacgv();
    return 0;
}