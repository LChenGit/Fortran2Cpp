#include <iostream>
#include <vector>
#include <cmath>

void DLAR2V(int N, std::vector<double>& X, std::vector<double>& Y, std::vector<double>& Z, int INCX, const std::vector<double>& C, const std::vector<double>& S, int INCC) {
    int IX = 0;
    int IC = 0;

    for (int I = 0; I < N; ++I) {
        double XI = X[IX];
        double YI = Y[IX];
        double ZI = Z[IX];
        double CI = C[IC];
        double SI = S[IC];
        
        double T1 = SI * ZI;
        double T2 = CI * ZI;
        double T3 = T2 - SI * XI;
        double T4 = T2 + SI * YI;
        double T5 = CI * XI + T1;
        double T6 = CI * YI - T1;
        
        X[IX] = CI * T5 + SI * T4;
        Y[IX] = CI * T6 - SI * T3;
        Z[IX] = CI * T4 - SI * T5;

        IX += INCX;
        IC += INCC;
    }
}

int main() {
    int N = 3;
    int INCX = 1;
    int INCC = 1;

    std::vector<double> X = {1.0, 2.0, 3.0};
    std::vector<double> Y = {4.0, 5.0, 6.0};
    std::vector<double> Z = {7.0, 8.0, 9.0};
    std::vector<double> C = {0.5, 0.5, 0.5};
    std::vector<double> S = {0.5, 0.5, 0.5};

    DLAR2V(N, X, Y, Z, INCX, C, S, INCC);

    std::cout << "X: ";
    for (double x : X) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    std::cout << "Y: ";
    for (double y : Y) {
        std::cout << y << " ";
    }
    std::cout << std::endl;

    std::cout << "Z: ";
    for (double z : Z) {
        std::cout << z << " ";
    }
    std::cout << std::endl;

    return 0;
}