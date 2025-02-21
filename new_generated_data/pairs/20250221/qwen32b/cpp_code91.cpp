#include <iostream>
#include <cassert>

#define SPACE_2D
#define SPACEDIM 3

void BoundaryMassForceMatrix2D(double FiS, double FiN, const double TT[SPACEDIM][SPACEDIM], double RN[SPACEDIM][SPACEDIM]) {
    RN[0][0] = FiS * TT[0][0] * TT[0][0] + FiN * TT[2][2] * TT[2][2];
    RN[0][2] = (FiS - FiN) * TT[0][0] * TT[2][2];
    RN[2][0] = RN[0][2];
    RN[2][2] = FiS * TT[2][2] * TT[2][2] + FiN * TT[0][0] * TT[0][0];
}

int main() {
    // Test case 1
    double FiS = 2.0;
    double FiN = 1.0;
    double TT[3][3] = {{1.0, 0.0, 0.0}, {0.0, 1.0, 0.0}, {0.0, 0.0, 1.0}};
    double RN[3][3] = {{0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}, {0.0, 0.0, 0.0}};

    BoundaryMassForceMatrix2D(FiS, FiN, TT, RN);

    double expected_RN[3][3] = {
        {3.0, 0.0, 1.0},
        {0.0, 0.0, 0.0},
        {1.0, 0.0, 3.0}
    };

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            assert(abs(RN[i][j] - expected_RN[i][j]) < 1e-6);
        }
    }

    // Print the result for test case 1
    std::cout << "RN matrix after test case 1:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << RN[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Test case 2
    FiS = 3.0;
    FiN = 2.0;
    TT[0][0] = 2.0;
    TT[1][1] = 2.0;
    TT[2][2] = 2.0;
    RN[0][0] = 0.0;
    RN[0][1] = 0.0;
    RN[0][2] = 0.0;
    RN[1][0] = 0.0;
    RN[1][1] = 0.0;
    RN[1][2] = 0.0;
    RN[2][0] = 0.0;
    RN[2][1] = 0.0;
    RN[2][2] = 0.0;

    BoundaryMassForceMatrix2D(FiS, FiN, TT, RN);

    double expected_RN2[3][3] = {
        {20.0, 0.0, 4.0},
        {0.0, 0.0, 0.0},
        {4.0, 0.0, 20.0}
    };

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            assert(abs(RN[i][j] - expected_RN2[i][j]) < 1e-6);
        }
    }

    // Print the result for test case 2
    std::cout << "RN matrix after test case 2:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << RN[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "All tests passed!" << std::endl;
    return 0;
}