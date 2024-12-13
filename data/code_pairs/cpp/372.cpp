#include <iostream>
#include <cassert>
#include <cmath> // For std::abs

double damaxf(int n, const double* dx, int incx) {
    if (n < 1 || incx <= 0) return 0.0;

    double result = 0.0;
    int ix;

    if (incx != 1) {
        ix = 0; // Adjusted for 0-based indexing in C++
        result = std::abs(dx[ix]);
        ix += incx;
        for (int i = 1; i < n; i++) {
            if (std::abs(dx[ix]) > result) {
                result = std::abs(dx[ix]);
            }
            ix += incx;
        }
    } else { // Handling unit stride
        result = std::abs(dx[0]);
        for (int i = 1; i < n; i++) {
            if (std::abs(dx[i]) > result) {
                result = std::abs(dx[i]);
            }
        }
    }
    return result;
}