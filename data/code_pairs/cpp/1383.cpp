#include <iostream>
#include <vector>
#include <cmath>

void LAGZO(int N, std::vector<double>& X, std::vector<double>& W) {
    double HN = 1.0 / N;
    for (int NR = 1; NR <= N; ++NR) {
        double Z = (NR == 1) ? HN : X[NR - 2] + HN * std::pow(NR, 1.27);
        int IT = 0;
        double PD;
        do {
            ++IT;
            double Z0 = Z;
            double P = 1.0;
            for (int I = 1; I < NR; ++I) {
                P *= (Z - X[I - 1]);
            }
            double F0 = 1.0;
            double F1 = 1.0 - Z;
            for (int K = 2; K <= N; ++K) {
                double PF = ((2.0 * K - 1.0 - Z) * F1 - (K - 1.0) * F0) / K;
                PD = K / Z * (PF - F1);
                F0 = F1;
                F1 = PF;
            }
            double FD = F1 / P;
            double Q = 0.0;
            for (int I = 1; I < NR; ++I) {
                double WP = 1.0;
                for (int J = 1; J < NR; ++J) {
                    if (J != I) WP *= (Z - X[J - 1]);
                }
                Q += WP;
            }
            double GD = (PD - Q * FD) / P;
            Z = Z - FD / GD;
        } while (IT <= 40 && std::abs((Z - Z0) / Z) > 1.0e-15);
        
        X[NR - 1] = Z;
        W[NR - 1] = 1.0 / (Z * PD * PD);
    }
}

int main() {
    int N = 5;
    std::vector<double> X(N), W(N);

    LAGZO(N, X, W);

    std::cout << "X: ";
    for (const auto& x : X) {
        std::cout << x << " ";
    }
    std::cout << "\nW: ";
    for (const auto& w : W) {
        std::cout << w << " ";
    }
    std::cout << std::endl;

    return 0;
}