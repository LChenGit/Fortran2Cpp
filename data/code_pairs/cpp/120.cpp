#include <iostream>
#include <cmath>
#include <vector>

void per_labsim2(int n, std::vector<std::vector<double>>& a, std::vector<double>& b, std::vector<double>& x, double eps, int itmax) {
    // Initial setup - scale rows
    for (int i = 0; i < n; ++i) {
        double ast = a[i][i];
        b[i] = b[i] / ast;
        for (int j = 0; j < n; ++j) {
            a[i][j] = a[i][j] / ast;
        }
    }

    // Iterative refinement
    for (int it = 1; it <= itmax; ++it) {
        int ifl = 1;

        for (int i = 0; i < n; ++i) {
            double xst = x[i];
            double sum = 0.0;
            for (int j = 0; j < n; ++j) {
                if (i != j) sum += a[i][j] * x[j];
            }
            x[i] = b[i] - sum;

            if (std::abs(xst - x[i]) > eps) ifl = 0;
        }

        if (ifl == 1) break;
    }

    if (ifl != 1) {
        std::cout << "No convergence after " << itmax << " iterations." << std::endl;
    }
}

int main() {
    int n = 2;
    int itmax = 100;
    double eps = 1e-6;
    std::vector<std::vector<double>> a = {{1, 1}, {2, 1}};
    std::vector<double> b = {3, 4};
    std::vector<double> x(n, 0);

    per_labsim2(n, a, b, x, eps, itmax);

    std::cout << "Solution x: [";
    for (int i = 0; i < n; ++i) {
        std::cout << x[i] << (i < n-1 ? ", " : "");
    }
    std::cout << "]" << std::endl;

    return 0;
}