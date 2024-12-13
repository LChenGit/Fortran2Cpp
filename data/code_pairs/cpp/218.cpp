#include <iostream>
#include <cmath>
#include <iomanip>

double calculateYd(double x) {
    return x - std::sin(x);
}

double calculateFirstS(double x) {
    return std::pow(x, 3) / 6.0;
}

double calculateError(double s, double yd) {
    return std::abs((s - yd) / yd);
}

int main() {
    double x = 1.9;
    double y, yd, p, t, s, error;
    int M = 7;

    y = x - std::sin(x);
    yd = calculateYd(x);
    p = (std::pow(x, 3) / 6.0) * (1.0 - (std::pow(x, 2) / 20.0) * (1.0 - (std::pow(x, 2) / 42.0) * (1.0 - (std::pow(x, 2) / 72.0))));
    
    std::cout << "Testing with x = " << x << std::endl;
    std::cout << "yd: " << yd << std::endl;

    t = calculateFirstS(x);
    s = t;
    error = calculateError(s, yd);

    std::cout << "First s: " << s << std::endl;
    std::cout << "First error: " << error << std::endl;

    for (int n = 1; n <= M; ++n) {
        t = -t*x*x/(static_cast<double>((2*n+2)*(2*n+3)));
        s += t;
        error = calculateError(s, yd);
        std::cout << "n: " << n << " s: " << s << " error: " << error << std::endl;
    }

    return 0;
}