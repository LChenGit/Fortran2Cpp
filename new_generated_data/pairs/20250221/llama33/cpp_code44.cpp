#include <iostream>
#include <complex>
#include <cassert>
#include <cstdlib>
#include <ctime>

void clatsy(char uplo, int n, std::complex<double>* A) {
    if (uplo == 'U') {
        // Zero out the lower triangular part of A
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < j; ++i) {
                A[i * n + j] = std::complex<double>(0.0, 0.0);
            }
        }

        // Fill in the matrix with random values
        for (int i = 0; i < n; ++i) {
            double rand_val = static_cast<double>(rand()) / RAND_MAX;
            A[i * n + i] = std::complex<double>(rand_val, rand_val);
        }
    } else if (uplo == 'L') {
        // Zero out the upper triangular part of A
        for (int j = 0; j < n; ++j) {
            for (int i = j + 1; i < n; ++i) {
                A[i * n + j] = std::complex<double>(0.0, 0.0);
            }
        }

        // Fill in the matrix with random values
        for (int i = 0; i < n; ++i) {
            double rand_val = static_cast<double>(rand()) / RAND_MAX;
            A[i * n + i] = std::complex<double>(rand_val, rand_val);
        }
    }
}

bool isClose(const std::complex<double>& a, const std::complex<double>& b, double tol = 1e-6) {
    return (std::abs(a - b) < tol);
}

int main() {
    srand(time(0)); // Seed the random number generator

    int n = 10;
    std::complex<double> A[n * n], B[n * n];

    for (int i = 0; i < n * n; ++i) {
        double rand_val1 = static_cast<double>(rand()) / RAND_MAX;
        double rand_val2 = static_cast<double>(rand()) / RAND_MAX;
        A[i] = std::complex<double>(rand_val1, rand_val2);
    }

    for (int i = 0; i < n * n; ++i) {
        B[i] = A[i];
    }

    clatsy('U', n, A);
    clatsy('L', n, B);

    // Test case 1: Check if the diagonal elements are non-zero
    for (int i = 0; i < n; ++i) {
        assert(!isClose(A[i * n + i], std::complex<double>(0.0, 0.0)));
        assert(!isClose(B[i * n + i], std::complex<double>(0.0, 0.0)));
    }

    // Test case 2: Check if the upper triangular part of A is zero
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < j; ++i) {
            assert(isClose(A[i * n + j], std::complex<double>(0.0, 0.0)));
        }
    }

    // Test case 3: Check if the lower triangular part of B is zero
    for (int j = 0; j < n; ++j) {
        for (int i = j + 1; i < n; ++i) {
            assert(isClose(B[i * n + j], std::complex<double>(0.0, 0.0)));
        }
    }

    return 0;
}