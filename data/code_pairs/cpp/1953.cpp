#include <iostream>
#include <algorithm>

class WFN1_AD1 {
public:
    static int WFN1_AD_ILADLR(int M, int N, double** A, int LDA) {
        const double ZERO = 0.0;
        if (M == 0) {
            return M;
        } else if (A[M-1][0] != ZERO || A[M-1][N-1] != ZERO) { // Adjusting for 0-based indexing
            return M;
        } else {
            int result = 0;
            for (int j = 0; j < N; ++j) {
                int i = M;
                while (i >= 1 && A[std::max(i-1, 0)][j] == ZERO) { // Adjust for 0-based indexing
                    --i;
                }
                result = std::max(result, i);
            }
            return result;
        }
    }
};

int main() {
    // Example usage
    int M = 3;
    int N = 2;
    int LDA = 3;

    // Dynamic allocation of the 2D array A
    double** A = new double*[LDA];
    for (int i = 0; i < LDA; ++i) {
        A[i] = new double[N];
    }

    // Initialize A with zeros for testing
    for (int i = 0; i < LDA; ++i) {
        for (int j = 0; j < N; ++j) {
            A[i][j] = 0.0; // Fill with zeros
        }
    }

    int result = WFN1_AD1::WFN1_AD_ILADLR(M, N, A, LDA);
    std::cout << "Result = " << result << std::endl;

    // Clean up memory
    for (int i = 0; i < LDA; ++i) {
        delete[] A[i];
    }
    delete[] A;

    return 0;
}