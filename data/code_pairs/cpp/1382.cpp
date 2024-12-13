#include <iostream>

void loop3_F77(int N, double* x, double* y, double a) {
    for (int i = 0; i < N; ++i) {
        y[i] = y[i] + a * x[i];
    }
}

void loop3_F77Overhead(int N, double* x, double* y, double a) {
    // This function intentionally left empty, similar to the Fortran version.
}