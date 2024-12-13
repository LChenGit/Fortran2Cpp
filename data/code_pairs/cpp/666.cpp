#include <vector>
#include <algorithm> // For std::min

bool DGENND(int M, int N, const std::vector<std::vector<double>>& A) {
    const double ZERO = 0.0;
    int K = std::min(M, N);

    for (int I = 0; I < K; ++I) {
        if (A[I][I] < ZERO) {
            return false;
        }
    }
    return true;
}