#include <iostream>
#include <cmath>
#include <cassert>

void saxpy(int n, float sa, float* sx, int incx, float* sy, int incy) {
    if (n <= 0) return;
    if (sa == 0.0f) return;

    if (incx == 1 && incy == 1) {
        for (int i = 0; i < n; i += 4) {
            sy[i] += sa * sx[i];
            if (i + 1 < n) sy[i + 1] += sa * sx[i + 1];
            if (i + 2 < n) sy[i + 2] += sa * sx[i + 2];
            if (i + 3 < n) sy[i + 3] += sa * sx[i + 3];
        }
    } else {
        int ix = 0;
        int iy = 0;
        if (incx < 0) ix = (n - 1) * incx;
        if (incy < 0) iy = (n - 1) * incy;
        for (int i = 0; i < n; i++) {
            sy[iy] += sa * sx[ix];
            ix += incx;
            iy += incy;
        }
    }
}

void testSaxpy() {
    const int n = 5;
    float sa = 2.0f;
    float sx[n] = {1, 2, 3, 4, 5};
    float sy[n] = {5, 4, 3, 2, 1};
    int incx = 1, incy = 1;

    saxpy(n, sa, sx, incx, sy, incy);

    float expected[n] = {7, 8, 9, 10, 11};
    for (int i = 0; i < n; i++) {
        assert(std::abs(sy[i] - expected[i]) < 1e-5);
    }

    std::cout << "All tests passed." << std::endl;
}

int main() {
    testSaxpy();
    return 0;
}