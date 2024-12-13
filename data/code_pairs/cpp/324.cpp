#include <iostream>
#include <array>

void r3mtm(const std::array<std::array<double, 3>, 3>& a,
           const std::array<std::array<double, 3>, 3>& b,
           std::array<std::array<double, 3>, 3>& c) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            c[i][j] = 0.0;
            for (int k = 0; k < 3; ++k) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}