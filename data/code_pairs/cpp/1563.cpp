#include <iostream>
#include <vector>
#include <cmath>

void FPOLY(double x, std::vector<double>& p);

void runTest(double x, const std::vector<double>& expected) {
    std::vector<double> p(expected.size());
    FPOLY(x, p);
    std::cout << "Test Case: X = " << x << ", NP = " << expected.size() << std::endl;
    for (size_t i = 0; i < p.size(); ++i) {
        std::cout << "P[" << i + 1 << "] = " << p[i];
        if (std::fabs(p[i] - expected[i]) < 1e-6) {
            std::cout << " (PASS)" << std::endl;
        } else {
            std::cout << " (FAIL)" << std::endl;
        }
    }
}

int main() {
    // Test case 1
    runTest(2.0, {1, 2, 4, 8, 16});

    // Test case 2
    runTest(3.0, {1, 3, 9});

    return 0;
}

void FPOLY(double x, std::vector<double>& p) {
    p[0] = 1.0;
    for (int j = 1; j < p.size(); ++j) {
        p[j] = p[j - 1] * x;
    }
}