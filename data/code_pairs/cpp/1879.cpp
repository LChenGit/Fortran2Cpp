#include <cmath>
#include <iostream>
#include <cfenv>
#include <algorithm>

double hypot_cpp(double x, double y) {
    std::feclearexcept(FE_ALL_EXCEPT);
    double result = std::hypot(x, y); // Use built-in hypot to avoid manual overflow/underflow checks

    if (std::fetestexcept(FE_OVERFLOW) || std::fetestexcept(FE_UNDERFLOW)) {
        std::feclearexcept(FE_OVERFLOW | FE_UNDERFLOW);
        if (x == 0.0 || y == 0.0) {
            result = std::abs(x) + std::abs(y);
        } else {
            int expX = std::ilogb(x);
            int expY = std::ilogb(y);
            if (2 * std::abs(expX - expY) > std::numeric_limits<double>::digits + 1) {
                result = std::max(std::abs(x), std::abs(y));
            } else {
                double scaledX = std::scalbn(x, -expX);
                double scaledY = std::scalbn(y, -expY);
                double scaledResult = std::sqrt(scaledX * scaledX + scaledY * scaledY);
                result = std::scalbn(scaledResult, expX);
            }
        }
    }

    return result;
}

int main() {
    // Normal case
    std::cout << "HYPOT(3, 4) = " << hypot_cpp(3.0, 4.0) << std::endl;

    // Test near overflow
    std::cout << "HYPOT(1.0E+150, 1.0E+150) = " << hypot_cpp(1.0E+150, 1.0E+150) << std::endl;

    // Test for underflow
    std::cout << "HYPOT(1.0E-200, 1.0E-200) = " << hypot_cpp(1.0E-200, 1.0E-200) << std::endl;

    // Test with large and small values
    std::cout << "HYPOT(1.0E+150, 1.0E-150) = " << hypot_cpp(1.0E+150, 1.0E-150) << std::endl;

    return 0;
}