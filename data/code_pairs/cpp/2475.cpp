#include <iostream>
#include <vector>
#include <cmath>

void DDAWTS(int NEQ, int IWT, const std::vector<double>& RTOL, const std::vector<double>& ATOL, const std::vector<double>& Y, std::vector<double>& WT, const std::vector<double>& RPAR, const std::vector<int>& IPAR) {
    double RTOLI = RTOL[0];
    double ATOLI = ATOL[0];

    for (int I = 0; I < NEQ; ++I) {
        if (IWT != 0) {
            RTOLI = RTOL[I];
            ATOLI = ATOL[I];
        }
        WT[I] = RTOLI * std::abs(Y[I]) + ATOLI;
    }
}

int main() {
    const int NEQ = 5;
    int IWT = 1;
    std::vector<double> RTOL(NEQ), ATOL(NEQ), Y(NEQ), WT(NEQ, 0.0);
    std::vector<double> RPAR(1, 0.0);
    std::vector<int> IPAR(1, 0);

    // Initialize input arrays
    for (int I = 0; I < NEQ; ++I) {
        RTOL[I] = 0.01 * (I + 1);
        ATOL[I] = 0.001 * (I + 1);
        Y[I] = 1.0 * (I + 1);
    }

    // Call the function
    DDAWTS(NEQ, IWT, RTOL, ATOL, Y, WT, RPAR, IPAR);

    // Print the results
    std::cout << "WT:" << std::endl;
    for (int I = 0; I < NEQ; ++I) {
        std::cout << WT[I] << std::endl;
    }

    return 0;
}