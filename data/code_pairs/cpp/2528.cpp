#ifndef PRSIZES_H
#define PRSIZES_H

namespace PRSIZES {
    const int ISIZE = 4; // Adjusted based on the actual Fortran output and typical C++ int size
    const int DPSIZE = 8; // Typically, double in C++ is 8 bytes
    const int PE = 30;
    const int MAXRECID = 200;
    const int PC = 30;
    const int PCT = 30;
    const int PIR = 700;
    const int PD = 50;
    const int PAL = 50;
    const int MAXFCN = 1000000;
    const int MAXIC = 90;
    const int PG = 80;
    const int PES = 30;
}

#endif // PRSIZES_H

#include <iostream>
#include "PRSIZES.h"

int main() {
    using namespace PRSIZES;
    std::cout << "ISIZE: " << ISIZE << std::endl;
    std::cout << "DPSIZE: " << DPSIZE << std::endl;
    std::cout << "PE: " << PE << std::endl;
    std::cout << "MAXRECID: " << MAXRECID << std::endl;
    std::cout << "PC: " << PC << std::endl;
    std::cout << "PCT: " << PCT << std::endl;
    std::cout << "PIR: " << PIR << std::endl;
    std::cout << "PD: " << PD << std::endl;
    std::cout << "PAL: " << PAL << std::endl;
    std::cout << "MAXFCN: " << MAXFCN << std::endl;
    std::cout << "MAXIC: " << MAXIC << std::endl;
    std::cout << "PG: " << PG << std::endl;
    std::cout << "PES: " << PES << std::endl;

    return 0;
}