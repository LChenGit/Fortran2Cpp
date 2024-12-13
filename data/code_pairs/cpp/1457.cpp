#include <iostream>
#include <cmath>

// Global variables
double fcr1, fcr2, dfcr1, dfcr2;
double tcr1, tcr2, dtcr1, dtcr2, ampcr;

// Function declaration
double dh_board(double fi, double tet) {
    double f1, f2, t1, t2;
    int nfi, ntet, ifi, itet;
    bool flag = false;

    if ((fi - fcr1) * (fi - fcr2) > 0) return 0;
    if ((tet - tcr1) * (tet - tcr2) > 0) return 0;

    nfi = static_cast<int>((fcr2 - fcr1) / (dfcr1 + dfcr2));
    ntet = static_cast<int>((tcr2 - tcr1) / (dtcr1 + dtcr2));

    for (ifi = 0; ifi < nfi; ++ifi) {
        f1 = fcr1 + ifi * (dfcr1 + dfcr2);
        f2 = fcr1 + (ifi + 1) * (dfcr1 + dfcr2);
        if ((fi - f1) * (fi - f2) <= 0) break;
    }

    if (fi >= f1 + dfcr1) return 0;

    for (itet = 0; itet < ntet; ++itet) {
        t1 = tcr1 + itet * (dtcr1 + dtcr2);
        t2 = tcr1 + (itet + 1) * (dtcr1 + dtcr2);
        if ((tet - t1) * (tet - t2) <= 0) break;
    }

    if (tet >= t1 + dtcr1) return 0;

    return std::pow(-1, ifi + itet) * ampcr;
}

int main() {
    // Initialize variables
    fcr1 = 1.0; fcr2 = 5.0; dfcr1 = 0.5; dfcr2 = 0.5;
    tcr1 = 1.0; tcr2 = 5.0; dtcr1 = 0.5; dtcr2 = 0.5; ampcr = 10.0;

    // Test cases
    std::cout << "dh_board(2.0, 2.0) = " << dh_board(2.0, 2.0) << std::endl;
    std::cout << "dh_board(6.0, 2.0) = " << dh_board(6.0, 2.0) << std::endl;
    std::cout << "dh_board(2.0, 6.0) = " << dh_board(2.0, 6.0) << std::endl;
    std::cout << "dh_board(3.5, 3.5) = " << dh_board(3.5, 3.5) << std::endl;

    return 0;
}