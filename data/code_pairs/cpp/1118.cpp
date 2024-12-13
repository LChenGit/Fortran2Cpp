#include <cmath>

double DDANRM(int NEQ, const double* V, const double* WT, const double* RPAR, const int* IPAR) {
    double SUM = 0.0, VMAX = 0.0;
    for (int I = 0; I < NEQ; ++I) {
        double temp = std::abs(V[I] / WT[I]);
        if (temp > VMAX) VMAX = temp;
    }
    if (VMAX > 0.0) {
        for (int I = 0; I < NEQ; ++I) {
            SUM += std::pow((V[I] / WT[I]) / VMAX, 2);
        }
        return VMAX * std::sqrt(SUM / NEQ);
    }
    return 0.0;
}