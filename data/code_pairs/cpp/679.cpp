// ILASLR.cpp
#include <iostream>
#include <vector>
#include <algorithm> // for std::max

int ILASLR(int M, int N, std::vector<std::vector<float>>& A, int LDA) {
    float ZERO = 0.0f;
    if (M == 0) {
        return M;
    } else if (A[M-1][0] != ZERO || A[M-1][N-1] != ZERO) {
        return M;
    } else {
        int smallestRow = 0;
        for (int J = 0; J < N; ++J) {
            int I = M-1;
            while (A[I][J] != ZERO && I >= 0) {
                --I;
                if (I < 0) {
                    break;
                }
            }
            smallestRow = std::max(smallestRow, I + 1);
        }
        return smallestRow;
    }
}

int main() {
    // Test 1: All zeros matrix
    std::vector<std::vector<float>> A1 = {
        {0.0f, 0.0f, 0.0f}, 
        {0.0f, 0.0f, 0.0f}, 
        {0.0f, 0.0f, 0.0f}
    };
    std::cout << "Test 1: " << (ILASLR(3, 3, A1, 3) == 3 ? "Passed." : "Failed.") << std::endl;

    // Test 2: Last row has a non-zero element at the start
    std::vector<std::vector<float>> A2 = {
        {0.0f, 0.0f, 0.0f}, 
        {0.0f, 0.0f, 0.0f}, 
        {1.0f, 0.0f, 0.0f}
    };
    std::cout << "Test 2: " << (ILASLR(3, 3, A2, 3) == 3 ? "Passed." : "Failed.") << std::endl;

    return 0;
}