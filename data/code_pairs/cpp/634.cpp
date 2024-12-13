#include <cstddef> // for size_t

void dscal(int n, double da, double* dx, int incx) {
    int i, m, mp1, nincx;

    if (n <= 0 || incx <= 0) return;

    if (incx == 1) {
        // Optimized loop for unit increment
        m = n % 5;
        for (i = 0; i < m; i++) {
            dx[i] = da * dx[i];
        }
        if (n < 5) return;
        for (i = m; i < n; i += 5) {
            dx[i] = da * dx[i];
            dx[i + 1] = da * dx[i + 1];
            dx[i + 2] = da * dx[i + 2];
            dx[i + 3] = da * dx[i + 3];
            dx[i + 4] = da * dx[i + 4];
        }
    } else {
        // General loop for arbitrary increment
        nincx = n * incx;
        for (i = 0; i < nincx; i += incx) {
            dx[i] = da * dx[i];
        }
    }
}