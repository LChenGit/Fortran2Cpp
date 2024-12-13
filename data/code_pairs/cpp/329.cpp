// delmol.h
#ifndef DELMOL_H
#define DELMOL_H

#include <array>

using DOUBLE = double;

void delmol(
    std::array<std::array<DOUBLE, 25>, 3>& COORD,
    int& I,
    int& J,
    const int& NI,
    const int& NJ,
    const int& IA,
    const int& ID,
    const int& JA,
    const int& JD,
    int& IX,
    DOUBLE& RIJ,
    DOUBLE& TOMB,
    int& ISP);

#endif // DELMOL_H