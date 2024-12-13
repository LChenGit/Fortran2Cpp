#include <cmath> // For std::copysign

bool DLCTES(double ZR, double ZI, double D) {
    const double ZERO = 0.0;
    const double ONE = 1.0;

    if (D == ZERO) {
        return ZR < ZERO;
    } else {
        // std::copysign returns a value with the magnitude of the first argument and the sign of the second argument.
        // To replicate the Fortran SIGN behavior, we compare the signs of ONE with ZR and ONE with D.
        // If the signs are different, the expression evaluates to true; otherwise, false.
        return std::copysign(ONE, ZR) != std::copysign(ONE, D);
    }
}