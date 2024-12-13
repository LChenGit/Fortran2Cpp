#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    double val;
    for (int ie = -30; ie <= 30; ++ie) {
        if ((ie >= -4 && ie <= 17) || ie % 10 == 0) {
            val = 1.2345678901234567 * std::pow(10.0, ie);
            std::cout << std::scientific << std::setprecision(17) << val << std::endl;
        }
    }
    return 0;
}