#include <cmath>
#include <iostream>

double QSFNDP(double ECCENT, double SINPHI, double COSPHI) {
    const double HALF = 0.5;
    const double ONE = 1.0;
    const double TWO = 2.0;
    const double EPSLN = 1.0e-7;

    if (ECCENT < EPSLN) {
        return TWO * SINPHI;
    }

    double CON = ECCENT * SINPHI;
    return (ONE - ECCENT * ECCENT) * (SINPHI / (ONE - CON * CON) - 
                  (HALF / ECCENT) * log((ONE - CON) / (ONE + CON)));
}

int main() {
    double ECCENT = 0.1;
    double SINPHI = 0.5;
    double COSPHI = sqrt(1.0 - SINPHI * SINPHI); // Calculated for completeness, not used in function

    double result = QSFNDP(ECCENT, SINPHI, COSPHI);
    std::cout << "C++ Result: " << result << std::endl;

    return 0;
}