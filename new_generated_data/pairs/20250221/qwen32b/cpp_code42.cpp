#include <cmath>  // For log function
#include <iostream>
#include <cassert>

void entropy(double* f, double temp, int nx, double& ent) {
    const double eps = 1.0e-10;
    ent = 0.0;
    for (int i = 0; i < nx; ++i) {
        double fm = 0.5 * f[i];
        ent += fm * log(eps + fm) + (1.0 - fm) * log(eps + 1.0 - fm);
    }
    ent = -2.0 * temp * ent;
}

int main() {
    // Test Case 1: Single element array
    double f1[] = {1.0};
    int nx1 = 1;
    double temp1 = 1.0;
    double ent1;
    entropy(f1, temp1, nx1, ent1);
    assert(std::abs(ent1 - (-2.0 * temp1 * (0.5 * log(0.5 + 1.0e-10) + 0.5 * log(0.5 + 1.0e-10)))) < 1e-6);
    std::cout << "Test Case 1 Passed!" << std::endl;

    // Test Case 2: Multiple elements
    double f2[] = {0.5, 1.0, 0.0};
    int nx2 = 3;
    double temp2 = 2.0;
    double ent2;
    entropy(f2, temp2, nx2, ent2);
    // Expected value calculation
    double expected2 = -2.0 * temp2 * (0.25 * log(0.25 + 1.0e-10) + 0.25 * log(0.75 + 1.0e-10) +
                                        0.5 * log(0.5 + 1.0e-10) + 0.5 * log(0.5 + 1.0e-10) +
                                        0.0 * log(0.0 + 1.0e-10) + 1.0 * log(1.0 + 1.0e-10));
    assert(std::abs(ent2 - expected2) < 1e-6);
    std::cout << "Test Case 2 Passed!" << std::endl;

    // Test Case 3: Edge case with zero
    double f3[] = {0.0};
    int nx3 = 1;
    double temp3 = 1.0;
    double ent3;
    entropy(f3, temp3, nx3, ent3);
    assert(std::abs(ent3 - (-2.0 * temp3 * (0.0 * log(0.0 + 1.0e-10) + 1.0 * log(1.0 + 1.0e-10)))) < 1e-6);
    std::cout << "Test Case 3 Passed!" << std::endl;

    std::cout << "All Tests Passed!" << std::endl;
    return 0;
}