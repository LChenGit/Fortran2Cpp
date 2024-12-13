#include <iostream>
#include <cmath> // For std::abs
#include <cstdlib> // For std::abort()

void DAXPY(int N, double DA, double DX[], double DY[]);

int main() {
    int N = 5;
    double DA = 1.0;
    double DX[9] = {-2, -1, -3, -4, 1, 2, 10, 15, 14};
    double DY[9] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};

    DAXPY(N, DA, DX, DY);

    // Expected DY after DAXPY operation: {-2, -1, -3, -4, 1}
    for (int I = 0; I < N; ++I) {
        std::cout << "DY(" << I + 1 << ") = " << DY[I] << std::endl;
    }

    return 0;
}

void DAXPY(int N, double DA, double DX[], double DY[]) {
    for (int I = 0; I < N; ++I) {
        DY[I] = DY[I] + DA * DX[I];
    }
}