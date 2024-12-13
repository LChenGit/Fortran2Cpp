#include <iostream>
#include <cmath>
#include <functional>

class SimpleQuadpack {
public:
    double integrate(std::function<double(double)> f, double a, double b, int n) {
        double h = (b - a) / n;
        double s = f(a) + f(b);
        for (int i = 1; i < n; i += 2) {
            s += 4 * f(a + i * h);
        }
        for (int i = 2; i < n - 1; i += 2) {
            s += 2 * f(a + i * h);
        }
        return s * h / 3;
    }
};

// Function to integrate: f(x) = x^2
double f(double x) {
    return x * x;
}

int main() {
    SimpleQuadpack qp;
    double a = 0.0; // Lower limit of integration
    double b = 1.0; // Upper limit of integration
    int n = 1000; // Number of subdivisions for the integration
    
    double result = qp.integrate(f, a, b, n);
    std::cout << "Integration result: " << result << std::endl;
    std::cout << "Expected result: " << 1.0 / 3.0 << std::endl;
    
    return 0;
}