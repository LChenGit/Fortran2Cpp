#include <complex>

void CSCAL(int N, std::complex<float> CA, std::complex<float>* CX, int INCX) {
    if (N <= 0 || INCX <= 0) return;

    if (INCX == 1) {
        for (int I = 0; I < N; ++I) {
            CX[I] = CA * CX[I];
        }
    } else {
        for (int I = 0; I < N * INCX; I += INCX) {
            CX[I] = CA * CX[I];
        }
    }
}