#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip> // For std::setprecision

void ksd(double& df, const std::vector<double>& g, const std::vector<double>& dgdx, int ng, double rho);

int main() {
    std::vector<double> g = {1.0, 2.0, 3.0};
    std::vector<double> dgdx = {0.1, 0.2, 0.3};
    int ng = 3;
    double rho = 0.5;
    double df;

    ksd(df, g, dgdx, ng, rho);

    std::cout << "Computed df: " << std::setprecision(18) << df << std::endl;
    std::cout << "Correct expected df: 0.23201567401385645" << std::endl;

    return 0;
}

void ksd(double& df, const std::vector<double>& g, const std::vector<double>& dgdx, int ng, double rho) {
    double toler = -40.0;
    double sum1 = 0.0;
    double sum2 = 0.0;
    double gmax = g[0];  // Adjusted for 0-based indexing

    if (ng < 2) {
        df = dgdx[0];
        return;
    }

    for (int i = 1; i < ng; ++i) { // Adjusted loop for 0-based indexing
        if (g[i] > gmax) gmax = g[i];
    }

    for (int i = 0; i < ng; ++i) { // Adjusted loop for 0-based indexing
        double val = rho * (g[i] - gmax);
        if (val >= toler) {
            sum1 += exp(val) * dgdx[i];
            sum2 += exp(val);
        }
    }

    df = (ng > 1) ? sum1 / sum2 : dgdx[0];
}