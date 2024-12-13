#include <vector>
#include <iostream>
#include <cassert>

void grid2triple(const std::vector<double>& X, const std::vector<double>& Y,
                 const std::vector<std::vector<double>>& Z, int MX, int NY,
                 std::vector<std::vector<double>>& D, int& LD, int LDMAX,
                 double ZMSG, int& IER) {
    IER = 0;
    LD = 0;

    D.resize(LDMAX, std::vector<double>(3, 0.0));

    for (int n = 0; n < NY; ++n) {
        for (int m = 0; m < MX; ++m) {
            if (Z[m][n] != ZMSG) {
                if (LD < LDMAX) {
                    D[LD][0] = X[m];
                    D[LD][1] = Y[n];
                    D[LD][2] = Z[m][n];
                    ++LD;
                } else {
                    IER = -11; // Error code for exceeding LDMAX
                    return;
                }
            }
        }
    }

    if (LD == 0) {
        IER = -10;
    }
}