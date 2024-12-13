#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

void eval(double foo1, double foo2, double* foo3, double* foo4, const double* x, int n, int nnd) {
    foo3[0] = foo2 * foo4[0]; // Adjusted for 0-based indexing
    for (int i = 1; i < n; ++i) { // Adjusted loop to start from 1 for 0-based indexing
        foo3[i] = foo2 * foo4[i];
        for (int j = 0; j < i; ++j) {
            double temp = 0.0;
            int jmini = j - i;
            for (int k = i; k < nnd; k += n) {
                temp += std::pow(x[k] - x[k + jmini], 2.0);
            }
            temp = std::sqrt(temp + foo1);
            foo3[i] = foo3[i] + temp * foo4[j];
            foo3[j] = foo3[j] + temp * foo4[i];
        }
    }
}

void runTest() {
    double foo1 = 1.0;
    double foo2 = 2.0;
    int n = 3;
    int nnd = 5;
    std::vector<double> foo3(n), foo4 = {1.0, 2.0, 3.0}, x = {0.0, 1.0, 2.0, 3.0, 4.0};

    eval(foo1, foo2, foo3.data(), foo4.data(), x.data(), n, nnd);

    std::cout << "foo3:" << std::endl;
    for (auto val : foo3) {
        std::cout << val << std::endl;
    }
}

int main() {
    runTest();
    return 0;
}