#include <vector>
#include <iostream>

void loop18_F77(int N, std::vector<double>& x, const std::vector<double>& a, const std::vector<double>& b, double u, double v) {
    for (int i = 0; i < N; ++i) {
        x[i] = (u + a[i]) * (v + b[i]);
    }
}

// Example usage
int main() {
    int N = 5;
    std::vector<double> x(N), a(N, 1.0), b(N, 2.0); // Example initialization
    double u = 3.0, v = 4.0;

    loop18_F77(N, x, a, b, u, v);

    for (int i = 0; i < N; ++i) {
        std::cout << "x[" << i << "] = " << x[i] << std::endl;
    }

    return 0;
}