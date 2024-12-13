#include <iostream>
#include <vector>
#include <complex>
#include <cmath>

double dzsum1(int n, const std::vector<std::complex<double>>& cx, int incx) {
    if (n <= 0) {
        return 0.0;
    }

    double stemp = 0.0;

    if (incx == 1) {
        for (int i = 0; i < n; ++i) {
            stemp += std::abs(cx[i]);
        }
    } else {
        for (int i = 0; i < n * incx; i += incx) {
            stemp += std::abs(cx[i]);
        }
    }

    return stemp;
}

int main() {
    std::vector<std::complex<double>> cx = {
        {1.0, 2.0},
        {2.0, 3.0},
        {3.0, 4.0},
        {4.0, 5.0},
        {5.0, 6.0}
    };

    int n = 5;
    int incx = 1;

    double result = dzsum1(n, cx, incx);

    std::cout << "Result: " << result << std::endl;

    return 0;
}