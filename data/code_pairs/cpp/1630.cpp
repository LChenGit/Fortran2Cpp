#include <iostream>
#include <cmath> // For std::fabs

void floop19_F77(int N, float* y, float* x, float* a, float* b, float u, float v) {
    for(int i = 0; i < N; ++i) {
        x[i] = u * a[i];
        y[i] = v * b[i];
    }
}