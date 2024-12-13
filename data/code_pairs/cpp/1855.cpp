#include <iostream>
#include <cmath>
#include <cassert>

// Declaration of global variables
double GAMMA = 1.0;
double XT = 0.75;

// The SOLUTN function translated from Fortran to C++
void SOLUTN(double X, double Z[], double DMVAL[]) {
    double CONS = GAMMA * X * (1.0 - 0.5 * X * X);
    double DCONS = GAMMA * (1.0 - 1.5 * X * X);
    double D2CONS = -3.0 * GAMMA * X;

    if (X > XT) {
        Z[0] = 0.0;
        Z[1] = 0.0;
        Z[2] = -CONS;
        Z[3] = -DCONS;
        DMVAL[1] = -D2CONS;
    } else {
        Z[0] = 2.0 * X;
        Z[1] = 2.0;
        Z[2] = -2.0 * X + CONS;
        Z[3] = -2.0 + DCONS;
        DMVAL[1] = D2CONS;
    }
    DMVAL[0] = 0.0;
}

// Test function for SOLUTN
void testSolutn() {
    double Z[4], DMVAL[2];
    double X = 0.5; // Test value for X

    SOLUTN(X, Z, DMVAL);

    std::cout << "Z: ";
    for (int i = 0; i < 4; ++i) {
        std::cout << Z[i] << " ";
    }
    std::cout << "\nDMVAL: ";
    for (int i = 0; i < 2; ++i) {
        std::cout << DMVAL[i] << " ";
    }
    std::cout << std::endl;

    // Example of verification (assertions could be used for more rigorous testing)
}

int main() {
    testSolutn();
    return 0;
}