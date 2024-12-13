#include <iostream>
#include <vector>
#include <cmath> // For std::abs

void loop12_F77(int N, std::vector<double>& y, const std::vector<double>& a, std::vector<double>& x, 
                const std::vector<double>& b, const std::vector<double>& c, const std::vector<double>& d, double u) {
    for (int i = 0; i < N; i++) {
        y[i] = u + a[i];
        x[i] = a[i] + b[i] + c[i] + d[i];
    }
}