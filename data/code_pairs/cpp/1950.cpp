#include <iostream>
#include <vector>
#include <cmath>

// Function prototype
void SUBV(int N, const std::vector<double>& A, const std::vector<double>& B, std::vector<double>& C);

int main() {
    // Test case setup
    int N = 5;
    std::vector<double> A = {1.0, 2.0, 3.0, 4.0, 5.0};
    std::vector<double> B = {5.0, 4.0, 3.0, 2.0, 1.0};
    std::vector<double> C(N); // Initialize vector C with N elements

    // Expected result
    std::vector<double> expected = {-4.0, -2.0, 0.0, 2.0, 4.0};

    // Function call
    SUBV(N, A, B, C);

    // Result check
    bool correct = true;
    for (int i = 0; i < N; i++) {
        if (std::abs(C[i] - expected[i]) > 1e-6) { // Using a small tolerance for floating-point comparison
            correct = false;
            std::cout << "Mismatch at index " << i << ": got " << C[i] << ", expected " << expected[i] << std::endl;
            break;
        }
    }

    // Test result output
    if (correct) {
        std::cout << "Test Passed!" << std::endl;
    } else {
        std::cout << "Test Failed!" << std::endl;
    }

    return 0;
}

// Function definition
void SUBV(int N, const std::vector<double>& A, const std::vector<double>& B, std::vector<double>& C) {
    for (int i = 0; i < N; i++) {
        C[i] = A[i] - B[i];
    }
}