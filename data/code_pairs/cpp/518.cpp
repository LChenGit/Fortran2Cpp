// FJAC.cpp
#include <vector>
#include <iostream>

void FJAC(std::vector<double>& X, const std::vector<double>& V, int K) {
    for (int i = 0; i < K; ++i) {
        X[i] = X[i] + 1;
    }
}

int main() {
    std::vector<double> X = {1.0, 2.0, 3.0, 4.0, 5.0};
    std::vector<double> V(5); // The vector V is included to match the Fortran subroutine signature, but it's not used.
    int K = 5;

    FJAC(X, V, K);

    for (int i = 0; i < K; ++i) {
        std::cout << "X(" << i << ") = " << X[i] << std::endl;
    }

    return 0;
}