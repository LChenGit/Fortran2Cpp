#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>
#include <cmath>

float sla_gerpvgrw(int n, int ncols, const std::vector<std::vector<float>>& a, int lda, const std::vector<std::vector<float>>& af, int ldaf) {
    float amax, umax, rpvgrw = 1.0f;

    for (int j = 0; j < ncols; ++j) {
        amax = 0.0f;
        umax = 0.0f;
        for (int i = 0; i < n; ++i) {
            amax = std::max(std::abs(a[i][j]), amax);
        }
        for (int i = 0; i <= j; ++i) {
            umax = std::max(std::abs(af[i][j]), umax);
        }
        if (umax != 0.0f) {
            rpvgrw = std::min(amax / umax, rpvgrw);
        }
    }
    return rpvgrw;
}

int main() {
    // Example matrix A and its LU factorization AF
    std::vector<std::vector<float>> A = {{1.0f, 3.0f}, {2.0f, 4.0f}};
    std::vector<std::vector<float>> AF = {{4.0f, 0.5f}, {3.0f, 2.0f}};
    int n = 2;
    int ncols = 2;

    float result = sla_gerpvgrw(n, ncols, A, 2, AF, 2);

    std::cout << "Reciprocal Pivot Growth Factor: " << result << std::endl;

    // Verify the result matches the expected value
    assert(std::abs(result - 0.5f) < 1e-6);

    return 0;
}