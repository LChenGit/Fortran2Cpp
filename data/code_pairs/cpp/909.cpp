#include <iostream>
#include <vector>
#include <omp.h>
#include <cmath> // For std::abs

float compute_sum(int N) {
    std::vector<float> A(N), B(N);
    float sum = 0.0;

    for (int i = 0; i < N; ++i) {
        A[i] = (i + 1) * 1.0f; // Adjust for 0-based indexing
        B[i] = A[i];
    }

    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < N; ++i) {
        sum += A[i] * B[i];
    }

    return sum;
}

int main() {
    int N = 100;
    float sum = compute_sum(N);

    std::cout << "   Sum = " << sum << std::endl;

    if (std::abs(sum - 338350.0f) < 1.0f) {
        std::cout << "Test Passed." << std::endl;
    } else {
        std::cout << "Test Failed." << std::endl;
    }

    return 0;
}