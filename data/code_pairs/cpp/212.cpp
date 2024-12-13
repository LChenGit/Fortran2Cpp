#include <vector>

void mamult(const std::vector<double>& A, const std::vector<double>& B, std::vector<double>& C, int N, double ONE) {
    for (int i = 0; i < N; ++i) {
        C[i] = A[i] * B[i] + ONE;
    }
}