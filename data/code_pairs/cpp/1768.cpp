#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

void zbessela(int lmax, double x, std::vector<double>& a) {
    if (lmax < 0 || lmax > 50) {
        std::cerr << "Error(zbessela): lmax out of range: " << lmax << std::endl;
        exit(1);
    }
    if (x < 0.0 || x > 1e8) {
        std::cerr << "Error(zbessela): x out of range: " << x << std::endl;
        exit(1);
    }

    // Special handling for very small x values
    if (x < 1e-7) {
        a[0] = 1.0;
        double t1 = 1.0, t2 = 1.0;
        for (int l = 1; l <= lmax; ++l) {
            t1 = t1 / (2*l + 1);
            t2 = -t2 * x;
            a[l] = t2 * t1;
        }
        return;
    }

    // General case
    a[0] = 1.0;
    for (int l = 1; l <= lmax; ++l) {
        a[l] = a[l-1] * l / (2.0 * l + 1.0) * (-x);
    }
}

int main() {
    const int lmax = 5;
    double x = 0.5;
    std::vector<double> a(lmax + 1);

    zbessela(lmax, x, a);

    for (int i = 0; i <= lmax; ++i) {
        std::cout << "a[" << i << "] = " << std::setprecision(17) << a[i] << std::endl;
    }

    return 0;
}