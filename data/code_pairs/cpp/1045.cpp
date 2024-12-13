#include <vector>
#include <iostream>

void loop17_F77(int N, std::vector<double>& x, const std::vector<double>& a, const std::vector<double>& b, const std::vector<double>& c, const std::vector<double>& d) {
    for (int i = 0; i < N; ++i) {
        x[i] = (a[i] + b[i]) * (c[i] + d[i]);
    }
}

void loop17_F77Overhead(int N, std::vector<double>& x, const std::vector<double>& a, const std::vector<double>& b, const std::vector<double>& c, const std::vector<double>& d) {
    // Intentionally left blank.
}