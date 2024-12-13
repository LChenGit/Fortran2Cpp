#include <iostream>
#include <cmath>

double dasumf(size_t n, const double* dx, int incx) {
    double dtemp = 0.0;

    if (n <= 0 || incx <= 0) {
        return 0.0;
    }

    if (incx == 1) {
        size_t m = n % 6;
        for (size_t i = 0; i < m; ++i) {
            dtemp += std::abs(dx[i]);
        }
        if (n >= 6) {
            for (size_t i = m; i < n; i += 6) {
                dtemp += std::abs(dx[i]) + std::abs(dx[i + 1]) + std::abs(dx[i + 2])
                         + std::abs(dx[i + 3]) + std::abs(dx[i + 4]) + std::abs(dx[i + 5]);
            }
        }
    } else {
        size_t nincx = n * incx;
        for (size_t i = 0; i < nincx; i += incx) {
            dtemp += std::abs(dx[i]);
        }
    }

    return dtemp;
}

int main() {
    double dx[] = {1.0, -2.0, 3.0, -4.0, 5.0, -6.0};
    double result;

    result = dasumf(6, dx, 1);
    std::cout << "Test case 1: " << result << std::endl;  // Expected: 21.0

    result = dasumf(3, dx, 2);
    std::cout << "Test case 2: " << result << std::endl;  // Expected: 9.0 (1.0 + 3.0 + 5.0)

    result = dasumf(0, dx, 1);
    std::cout << "Test case 3: " << result << std::endl;  // Expected: 0.0

    return 0;
}