#include <iostream>
#include <complex>
#include <vector>

int ILAZLC(int M, int N, std::complex<double>* A, int LDA);

int main() {
    // Test 1: 0x0 matrix
    std::cout << "Test 1 (0x0 matrix): " << ILAZLC(0, 0, nullptr, 0) << std::endl;

    // Test 2: Matrix with all elements being zero
    int M = 2, N = 3, LDA = 2;
    std::vector<std::complex<double>> A(LDA*N, {0, 0});
    std::cout << "Test 2 (All zeros): " << ILAZLC(M, N, A.data(), LDA) << std::endl;

    // Test 3: Matrix with non-zero elements only in the last column
    A.assign(LDA*N, {0, 0});
    A[1 + (N-1)*LDA] = {1, 1};
    A[0 + (N-1)*LDA] = {1, 1};
    std::cout << "Test 3 (Non-zeros in last column): " << ILAZLC(M, N, A.data(), LDA) << std::endl;

    // Additional tests can be defined similarly

    return 0;
}

int ILAZLC(int M, int N, std::complex<double>* A, int LDA) {
    if (N == 0) {
        return 0;
    }
    else {
        for (int j = N-1; j >= 0; --j) {
            for (int i = 0; i < M; ++i) {
                if (A[i + j*LDA] != std::complex<double>(0, 0)) {
                    return j + 1;
                }
            }
        }
    }
    return 0; // Default return in case the matrix is completely zeroed
}