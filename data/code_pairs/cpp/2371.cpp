#include <array>
#include <iostream>

// Global variables as common blocks
std::array<int, 100> IU;
std::array<double, 50> QX, QY;
std::array<int, 25> IF;
int NQ, NF;
int JX, JY;

void UTILBD() {
    // This function is intentionally left empty to match the Fortran subroutine
}

void UTILBDX() {
    // Initialize IU array
    IU = {1, 1, 10, 10, 50, 2, 1, 1, 1, 8000, 0, 1, 1000, 1000};
    for (size_t i = 14; i < IU.size(); i++) {
        IU[i] = 0; // Fill the rest with zeros
    }

    // Initialize VCTSEQ common block
    NQ = 1;
    QX[0] = 0.0;
    QY[0] = 0.0;
    NF = 1;
    IF[0] = 1;
    for (size_t i = 1; i < QX.size(); i++) {
        QX[i] = 0.0; // Fill the rest with zeros
        QY[i] = 0.0; // Fill the rest with zeros
    }
    for (size_t i = 1; i < IF.size(); i++) {
        IF[i] = 0; // Fill the rest with zeros
    }

    // Initialize PLTCM common block
    JX = 0;
    JY = 0;
}

int main() {
    UTILBD();
    UTILBDX();
    // Main function logic if needed
    return 0;
}