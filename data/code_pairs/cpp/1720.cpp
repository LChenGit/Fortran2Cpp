#include <iostream>
#include <vector>
#include <cstdlib> // For rand()
#include <ctime> // For seeding rand()

template <typename T>
void initializeRandom(std::vector<std::vector<T>>& matrix) {
    for (auto& row : matrix) {
        for (auto& elem : row) {
            elem = static_cast<T>(rand()) / static_cast<T>(RAND_MAX);
        }
    }
}

template <typename T>
void printMatrix(const std::vector<std::vector<T>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
}

template <typename T>
void gdmpgd(std::vector<std::vector<T>>& R, const std::vector<std::vector<T>>& A, const std::vector<std::vector<T>>& B, T CON, int NI, int NJ, int NB) {
    int IL = 1 + NB / 1000 - 1;  // Adjust for 0-based indexing
    int JB = 1 + (NB % 1000) / 100 - 1;
    int IR = NI - (NB % 100) / 10;
    int JT = NJ - (NB % 10);
    if (NB == 0) {
        JT = 1;
        IR = NI*NJ;
    }

    for (int j = JB; j < JT; ++j) {
        for (int i = IL; i < IR; ++i) {
            R[i][j] = CON * A[i][j] + B[i][j];  // Simplified operation for demonstration
        }
    }
}

int main() {
    srand(static_cast<unsigned>(time(0))); // Seed random number generator

    int NI = 4, NJ = 4, NB = 1234;
    float CON = 1.5f;
    std::vector<std::vector<float>> R(NI, std::vector<float>(NJ)),
                                    A(NI, std::vector<float>(NJ)),
                                    B(NI, std::vector<float>(NJ));

    initializeRandom(A);
    initializeRandom(B);

    gdmpgd(R, A, B, CON, NI, NJ, NB);

    std::cout << "Result R:" << std::endl;
    printMatrix(R);

    return 0;
}