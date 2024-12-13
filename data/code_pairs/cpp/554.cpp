#include <vector>
#include <iostream>

void loop15_F90(int N, std::vector<double>& x, const std::vector<double>& a, const std::vector<double>& b, const std::vector<double>& c) {
    for (int i = 0; i < N; ++i) {
        x[i] = c[i] + a[i] * b[i];
    }
}