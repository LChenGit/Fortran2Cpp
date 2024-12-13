#include <iostream>
using namespace std;

void daxpy(int n, double da, double dx[], int incx, double dy[], int incy) {
    if (n <= 0 || da == 0.0) return;

    if (incx == incy) {
        if (incx == 1) {
            int m = n % 4;
            for (int i = 0; i < m; ++i) {
                dy[i] += da * dx[i];
            }
            if (n < 4) return;
            for (int i = m; i < n; i += 4) {
                dy[i] += da * dx[i];
                dy[i+1] += da * dx[i+1];
                dy[i+2] += da * dx[i+2];
                dy[i+3] += da * dx[i+3];
            }
        } else {
            int ix = 0;
            int iy = 0;
            if (incx < 0) ix = (n-1) * incx;
            if (incy < 0) iy = (n-1) * incy;
            for (int i = 0; i < n; ++i) {
                dy[iy] += da * dx[ix];
                ix += incx;
                iy += incy;
            }
        }
    } else {
        int ns = n * incx;
        for (int i = 0; i < ns; i += incx) {
            dy[i] = da * dx[i] + dy[i];
        }
    }
}

int main() {
    const int N = 5;
    double dx[N] = {1.0, 2.0, 3.0, 4.0, 5.0};
    double dy[N] = {2.0, 4.0, 6.0, 8.0, 10.0};
    double da = 2.0;
    int incx = 1, incy = 1;

    daxpy(N, da, dx, incx, dy, incy);

    cout << "Resulting DY:" << endl;
    for (int i = 0; i < N; ++i) {
        cout << dy[i] << endl;
    }

    return 0;
}