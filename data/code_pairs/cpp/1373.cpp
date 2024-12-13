#include <cfloat>
#include <cmath>
#include <limits>
#include <cctype>
#include <iostream>
#include <iomanip>

double DLAMC3(double A, double B) {
    return A + B;
}

double DLAMCH(char CMACH) {
    double ONE = 1.0, ZERO = 0.0;
    double EPS = std::numeric_limits<double>::epsilon() / 2.0;
    double SFMIN, SMALL, RMACH;

    CMACH = std::toupper(CMACH); // Making case-insensitive

    if (CMACH == 'E') {
        RMACH = EPS;
    } else if (CMACH == 'S') {
        SFMIN = std::numeric_limits<double>::min();
        SMALL = ONE / std::numeric_limits<double>::max();
        if (SMALL >= SFMIN) {
            SFMIN = SMALL * (ONE + EPS);
        }
        RMACH = SFMIN;
    } else if (CMACH == 'B') {
        RMACH = FLT_RADIX;
    } else if (CMACH == 'P') {
        RMACH = EPS * FLT_RADIX;
    } else if (CMACH == 'N') {
        RMACH = std::numeric_limits<double>::digits;
    } else if (CMACH == 'R') {
        RMACH = ONE; // Assuming rounding to nearest
    } else if (CMACH == 'M') {
        RMACH = std::numeric_limits<double>::min_exponent;
    } else if (CMACH == 'U') {
        RMACH = std::numeric_limits<double>::min();
    } else if (CMACH == 'L') {
        RMACH = std::numeric_limits<double>::max_exponent;
    } else if (CMACH == 'O') {
        RMACH = std::numeric_limits<double>::max();
    } else {
        RMACH = ZERO;
    }

    return RMACH;
}

int main() {
    std::cout << "Testing DLAMC3(1.0, 2.0)... Result: " << DLAMC3(1.0, 2.0) << std::endl;

    const char test_chars[] = {'E', 'S', 'B', 'P', 'N', 'R', 'M', 'U', 'L', 'O', 'X', '\0'};
    for (const char* ch = test_chars; *ch != '\0'; ++ch) {
        std::cout << "Testing DLAMCH(" << *ch << ")... Result: " << std::setprecision(10) << DLAMCH(*ch) << std::endl;
    }

    return 0;
}