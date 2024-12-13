#include <iostream>
#include <cmath> // For std::abs

class QuadraticParameters {
public:
    double a, b, c;

    QuadraticParameters() : a(0.0), b(0.0), c(0.0) {}

    void set(double new_a, double new_b, double new_c) {
        a = new_a;
        b = new_b;
        c = new_c;
    }

    double quadratic(double x) {
        return a * x * x + b * x + c;
    }
};

int main() {
    QuadraticParameters qp;
    
    qp.set(1.0, -3.0, 2.0); // Parameters a, b, c
    
    double x = 1.0;
    double result = qp.quadratic(x);
    
    const double epsilon = 1e-7;
    if (std::abs(result) < epsilon) {
        std::cout << "Test passed: quadratic(1) = 0" << std::endl;
    } else {
        std::cout << "Test failed: quadratic(1) != 0, result = " << result << std::endl;
    }

    return 0;
}