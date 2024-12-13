#include <algorithm> // For std::min

bool DGENND(int M, int N, double* A, int LDA) {
    const double ZERO = 0.0;
    int K = std::min(M, N);

    for (int I = 0; I < K; ++I) {
        if (*(A + I * LDA + I) < ZERO) { // Accessing A(I,I) considering Fortran's column-major vs. C++'s row-major
            return false;
        }
    }

    return true;
}