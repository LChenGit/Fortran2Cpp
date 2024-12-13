#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

double calculate_pi(int64_t npts) {
    int64_t inside_circle = 0;
    double x, y;
    
    srand(static_cast<unsigned>(time(0)));
    for (int64_t i = 0; i < npts; ++i) {
        x = static_cast<double>(rand()) / RAND_MAX * 2.0 - 1.0; // Scale x to [-1,1]
        y = static_cast<double>(rand()) / RAND_MAX * 2.0 - 1.0; // Scale y to [-1,1]
        if (x*x + y*y <= 1.0) {
            inside_circle++;
        }
    }
    return 4.0 * inside_circle / static_cast<double>(npts);
}

int main() {
    int64_t npts = 1000000; // Use the same number of points as in Fortran code
    double pi_estimate = calculate_pi(npts);
    std::cout << "Estimated PI = " << pi_estimate << std::endl;
    return 0;
}