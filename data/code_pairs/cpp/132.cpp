#include <iostream>
#include <vector>

namespace mo_column {

void compute(int nz, int b, std::vector<std::vector<float>>& q, std::vector<std::vector<float>>& t, int nproma) {
    float c = 5.345f;
    for (int k = 1; k < nz; ++k) {
        for (int proma = 0; proma < nproma; ++proma) {
            t[k][proma] = c * (k + 1); // Adjusted for Fortran 1-based indexing
            q[k][proma] = q[k - 1][proma] + t[k][proma] * c;
        }
    }
    for (int proma = 0; proma < nproma; ++proma) {
        q[nz - 1][proma] *= c; // Adjusted for 0-based indexing
    }
}

} // namespace mo_column

int main() {
    const int nproma = 2, nz = 3, b = 3;
    std::vector<std::vector<float>> t(b, std::vector<float>(nproma, 0.0f));
    std::vector<std::vector<float>> q(b, std::vector<float>(nproma, 0.0f));

    mo_column::compute(nz, b, q, t, nproma);

    std::cout << "Results for T:" << std::endl;
    for (const auto& row : t) {
        for (float val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Results for Q:" << std::endl;
    for (const auto& row : q) {
        for (float val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}