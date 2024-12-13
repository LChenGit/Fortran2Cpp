#include <iostream>
#include <cmath>

void machpi(double& MACH, double PI, double kappa, double rgas) {
    double kappax, KAPPAM, PIKRIT, MA2;

    kappax = (kappa - 1) / kappa;
    KAPPAM = 2.0 / (kappa - 1.0);
    PIKRIT = std::pow((2.0 / (kappa + 1.0)), (kappa / (kappa - 1.0)));

    if (PI >= 1.0) {
        MACH = 0.0;
    } else if (PI > PIKRIT) {
        MA2 = KAPPAM * (std::pow(PI, -kappax) - 1.0);
        if (MA2 > 0.0) {
            MACH = std::sqrt(MA2);
        } else {
            MACH = 0.0;
        }
    } else if (PI > 0.0) {
        MACH = 1.0;
    } else {
        MACH = std::pow(10.0, 20.0); // Equivalent to 1.d20 in Fortran
    }
}

int main() {
    double MACH, PI, kappa, rgas;

    // Test case 1
    kappa = 1.4;
    rgas = 287.0;
    PI = 0.8;
    machpi(MACH, PI, kappa, rgas);
    std::cout << "Test 1: MACH = " << MACH << std::endl;

    // Test case 2
    PI = 1.0;
    machpi(MACH, PI, kappa, rgas);
    std::cout << "Test 2: MACH = " << MACH << std::endl;

    // Test case 3
    PI = 0.0;
    machpi(MACH, PI, kappa, rgas);
    std::cout << "Test 3: MACH = " << MACH << std::endl;

    return 0;
}