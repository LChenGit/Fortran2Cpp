#include <vector>
#include <iostream>

int main() {
    const int N = 4000;
    std::vector<std::vector<double>> A(N, std::vector<double>(N));
    std::vector<std::vector<double>> B(N, std::vector<double>(N));
    bool test_passed = true;

    for (int j = 0; j < N; ++j) {
        for (int i = 0; i < N; ++i) {
            A[i][j] = 1.0;
            B[i][j] = 1.0;
        }
    }

    for (int j = 0; j < N; ++j) {
        for (int i = 0; i < N; ++i) {
            A[i][j] += B[j][i];
        }
    }

    // Unit Test
    for (int j = 0; j < N && test_passed; ++j) {
        for (int i = 0; i < N; ++i) {
            if (A[i][j] != 2.0 || B[i][j] != 1.0) {
                test_passed = false;
                break;
            }
        }
    }

    if (test_passed) {
        std::cout << "Test Passed." << std::endl;
    } else {
        std::cout << "Test Failed." << std::endl;
    }

    return 0;
}