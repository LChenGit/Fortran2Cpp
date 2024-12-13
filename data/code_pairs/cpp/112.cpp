#include <iostream>
#include <vector>
#include <cmath>

void qinit(int meqn, int mbc, int mx, int my, double xlower, double ylower, double dx, double dy, std::vector<std::vector<std::vector<double>>>& q, int maux) {
    for (int i = 0; i < mx; ++i) {
        for (int j = 0; j < my; ++j) {
            // Adjusting indices for 0-based indexing
            q[0][i + mbc][j + mbc] = 0.0;
            q[1][i + mbc][j + mbc] = 0.0;
            q[2][i + mbc][j + mbc] = 0.0;
            q[3][i + mbc][j + mbc] = 0.0;
            q[4][i + mbc][j + mbc] = 0.0;
        }
    }
}

int main() {
    int meqn = 5, mbc = 2, mx = 3, my = 3, maux = 0;
    double xlower = 0.0, ylower = 0.0, dx = 1.0, dy = 1.0;

    // Initialize q with the correct dimensions
    std::vector<std::vector<std::vector<double>>> q(meqn, std::vector<std::vector<double>>(mx + 2*mbc, std::vector<double>(my + 2*mbc, 0)));

    // Call the function
    qinit(meqn, mbc, mx, my, xlower, ylower, dx, dy, q, maux);

    // Print results for comparison
    std::cout << "q values:" << std::endl;
    for (int i = 0; i < mx; ++i) {
        for (int j = 0; j < my; ++j) {
            std::cout << "(" << i + 1 << "," << j + 1 << "):"; // +1 to match Fortran's 1-based indexing in the output
            for (int k = 0; k < meqn; ++k) {
                std::cout << " " << q[k][i + mbc][j + mbc];
            }
            std::cout << std::endl;
        }
    }

    return 0;
}