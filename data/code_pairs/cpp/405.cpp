#include <cmath>

class Functions {
public:
    static double epsilon; // Equivalent to 'real(kind=8) :: epsilon' and 'save'

    static double f_sqrt(double x) {
        return std::pow(x, 2) - 4.0;
    }

    static double fprime_sqrt(double x) {
        return 2.0 * x;
    }

    static double f_quartic(double x) {
        return std::pow(x - 1.0, 4) - epsilon;
    }

    static double fprime_quartic(double x) {
        return 4.0 * std::pow(x - 1.0, 3);
    }
};

// Initialize static member variable 'epsilon'
double Functions::epsilon = 1e-6; // Assuming an initial value, adjust as needed