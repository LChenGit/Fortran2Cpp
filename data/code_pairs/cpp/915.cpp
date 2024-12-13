#include <cmath>

void sedivm(int n, float* dx, int incx, float* dy, int incy) {
    if (n <= 0) return;

    int ix = (incx > 0) ? 0 : (-n + 1) * incx;
    int iy = (incy > 0) ? 0 : (-n + 1) * incy;

    for (int i = 0; i < n; ++i) {
        dy[iy] /= dx[ix];
        ix += incx;
        iy += incy;
    }
}