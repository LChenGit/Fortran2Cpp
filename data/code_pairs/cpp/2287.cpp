#include <iostream>
#include <vector>
#include <algorithm>

void jac(int Neq, double t, std::vector<double>& Y, int mlow, int mup, std::vector<std::vector<double>>& pd, int nrowpd) {
    int ntmax = Neq / 2;
    int N0 = ntmax - 1;

    // Assuming gr is defined somewhere in the global scope or passed as a parameter
    extern double gr;

    // Initialize the pd matrix to zero
    for (int i = 0; i < nrowpd; ++i) {
        std::fill(pd[i].begin(), pd[i].end(), 0.0);
    }

    for (int nt = 1; nt <= ntmax; ++nt) {
        double xtmm = (nt - 1) * (nt - 1);
        pd[4][2 * (nt - 1) + 1] += 0.5 * gr * xtmm; // Adjusting indices for 0-based arrays
        pd[6][2 * (nt - 1)] -= 0.5 * gr * xtmm;
    }

    for (int nt = 1; nt <= ntmax; ++nt) {
        double xtmm = (N0 - nt + 1) * (N0 - nt + 1);
        pd[4][2 * (nt - 1) + 1] += 0.5 * gr * xtmm;
        pd[6][2 * (nt - 1)] -= 0.5 * gr * xtmm;
    }

    for (int nt = 1; nt <= ntmax; ++nt) {
        double xtmm = -(nt - 1) * (N0 - nt + 1) * 2;
        pd[4][2 * (nt - 1) + 1] += 0.5 * gr * xtmm;
        pd[6][2 * (nt - 1)] -= 0.5 * gr * xtmm;
    }
}

double gr = 9.81;

int main() {
    int Neq = 10;
    double t = 0.0;
    std::vector<double> Y(Neq, 0.0);
    int mlow = 0;
    int mup = 0;
    int nrowpd = 10;

    std::vector<std::vector<double>> pd(nrowpd, std::vector<double>(Neq, 0.0));

    jac(Neq, t, Y, mlow, mup, pd, nrowpd);

    for (const auto& row : pd) {
        for (double val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}