#include <cmath>
#include <iostream>
#include <vector>

double ddwnrm(int neq, const double* v, const double* rwt, const double*, const int*) {
    double vmax = 0.0;
    for (int i = 0; i < neq; ++i) {
        double absVal = std::abs(v[i] * rwt[i]);
        if (absVal > vmax) vmax = absVal;
    }

    if (vmax <= 0.0) return 0.0;

    double sum = 0.0;
    for (int i = 0; i < neq; ++i) {
        sum += std::pow((v[i] * rwt[i]) / vmax, 2);
    }

    return vmax * std::sqrt(sum / neq);
}