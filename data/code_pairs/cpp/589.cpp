#include <iostream>
#include <cmath>
#include <vector>

void daxpy(int N, double DA, const double* DX, int INCX, double* DY, int INCY) {
    for (int i = 0; i < N; ++i) {
        DY[i * INCY] = DA * DX[i * INCX] + DY[i * INCY];
    }
}