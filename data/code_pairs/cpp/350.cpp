#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    long double x = 1.0L + std::pow(2.0L, -105);

    // Output the value of x for verification
    std::cout << "Value of x: " << std::setprecision(20) << x << std::endl;

    return 0;
}