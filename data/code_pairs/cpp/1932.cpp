#include <iostream>
#include <vector>
#include <complex>

void ZLASCL2(int M, int N, const std::vector<double>& D, std::vector<std::vector<std::complex<double>>>& X) {
    for (int J = 0; J < N; ++J) {
        for (int I = 0; I < M; ++I) {
            X[I][J] *= D[I];
        }
    }
}

int main() {
    int M = 2, N = 2;
    std::vector<double> D = {2.0, 3.0};
    std::vector<std::vector<std::complex<double>>> X = {
        {std::complex<double>(1.0, 0.0), std::complex<double>(2.0, -1.0)},
        {std::complex<double>(-1.0, 1.0), std::complex<double>(0.0, 2.0)}
    };

    ZLASCL2(M, N, D, X);

    for (int J = 0; J < N; ++J) {
        for (int I = 0; I < M; ++I) {
            std::cout << "X[" << I << "][" << J << "] = " << X[I][J] << std::endl;
        }
    }

    return 0;
}