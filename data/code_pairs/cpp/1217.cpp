#include <vector>
#include <iostream>

void loop23_F77(int N, std::vector<double>& x, const std::vector<double>& a, 
                const std::vector<double>& b, const std::vector<double>& c, 
                const std::vector<double>& d, std::vector<double>& y) {
    for (int i = 0; i < N; ++i) {
        x[i] = a[i] * b[i] + c[i] * d[i];
        y[i] = b[i] + d[i];
    }
}

void loop23_F77Overhead(int N, std::vector<double>& x, const std::vector<double>& a, 
                        const std::vector<double>& b, const std::vector<double>& c, 
                        const std::vector<double>& d, std::vector<double>& y) {
    // This function intentionally left blank
}