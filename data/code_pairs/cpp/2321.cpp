#include <iostream>
#include <vector>
#include <cassert>

int ILADLC(int M, int N, const std::vector<std::vector<double>>& A);

int main() {
    testILADLC();
    std::cout << "Test passed successfully!" << std::endl;
    return 0;
}

void testILADLC() {
    std::vector<std::vector<double>> A = {
        {0.0, 0.0, 0.0, 0.0},
        {0.0, 1.0, 0.0, 0.0},
        {0.0, 0.0, 0.0, 0.0}
    };

    int M = 3;
    int N = 4;

    int result = ILADLC(M, N, A);

    std::cout << "Result of ILADLC: " << result << std::endl;

    // Check the result
    assert(result == 2);
}

int ILADLC(int M, int N, const std::vector<std::vector<double>>& A) {
    const double ZERO = 0.0;

    if (N == 0 || A[0][N - 1] != ZERO || A[M - 1][N - 1] != ZERO) {
        return N;
    } else {
        for (int ILADLC = N; ILADLC >= 1; --ILADLC) {
            for (int I = 0; I < M; ++I) {
                if (A[I][ILADLC - 1] != ZERO) {
                    return ILADLC;
                }
            }
        }
    }

    return 0;
}