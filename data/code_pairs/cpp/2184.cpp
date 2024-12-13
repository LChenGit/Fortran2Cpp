#include <vector>
#include <iostream>

void SSMV(int N, const std::vector<float>& X, std::vector<float>& Y, int NELT, 
          const std::vector<int>& IA, const std::vector<int>& JA, 
          const std::vector<float>& A, int ISYM) {
    Y.assign(N, 0.0f); // Initialize Y

    for (int i = 0; i < NELT; ++i) {
        Y[IA[i] - 1] += A[i] * X[JA[i] - 1];
        if (ISYM == 1) {
            Y[JA[i] - 1] += A[i] * X[IA[i] - 1];
        }
    }
}