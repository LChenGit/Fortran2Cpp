#include <iostream>
#include <cmath>
#include <vector>

void exptaylor(double x, int nmax, double& y, int& nterms) {
    double term = 1.0;
    double partial_sum = term;
    int j;

    for (j = 1; j <= nmax; ++j) {
        term *= x / j;
        partial_sum += term;
        if (std::abs(term) < 1e-16 * partial_sum) break;
    }

    nterms = j;
    y = partial_sum;
}

void test_exptaylor() {
    std::vector<double> test_values = {0.0, 1.0, -1.0};
    std::vector<double> expected_results = {std::exp(0.0), std::exp(1.0), std::exp(-1.0)};
    double y, tolerance = 1e-8;
    int nmax = 100, nterms;

    for (size_t i = 0; i < test_values.size(); ++i) {
        exptaylor(test_values[i], nmax, y, nterms);
        if (std::abs(y - expected_results[i]) > tolerance) {
            std::cerr << "Test failed for x = " << test_values[i];
            std::cerr << " Expected: " << expected_results[i] << " Got: " << y << std::endl;
        } else {
            std::cout << "Test passed for x = " << test_values[i] << std::endl;
        }
    }
}

int main() {
    std::cout << "     x         true              approximate          error         nterms" << std::endl;

    double x, exp_true, y, relative_error;
    int nmax = 100, nterms;

    for (int j = -20; j <= 20; j += 4) {
        x = static_cast<double>(j);
        exptaylor(x, nmax, y, nterms);
        exp_true = std::exp(x);
        relative_error = std::abs(y - exp_true) / exp_true;

        std::cout << x << " " << exp_true << " " << y << " " << relative_error << " " << nterms << std::endl;
    }

    test_exptaylor();

    return 0;
}