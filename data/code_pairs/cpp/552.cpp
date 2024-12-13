#include <iostream>
#include <omp.h>
#include <cmath>    // For std::abs
#include <cassert>  // For assert

int main() {
    const int num_steps = 100000;
    double step;
    double pi, x;
    double summ = 0.0;
    const double known_pi = 3.14159265358979323846;
    const double error_margin = 0.001;
    double error;

    step = 1.0 / num_steps;

    #pragma omp parallel for reduction(+:summ) private(x)
    for (int i = 0; i < num_steps; i++) {
        x = (i + 0.5) * step;
        summ += 4.0 / (1.0 + x * x);
    }

    pi = summ * step;

    error = std::abs(known_pi - pi);

    assert(error <= error_margin);
    std::cout << "Test Passed: pi is " << pi << std::endl;

    return 0;
}