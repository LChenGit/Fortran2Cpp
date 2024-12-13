// ThermoVars.h
#ifndef THERMOVARS_H
#define THERMOVARS_H

#include <string>
#include <array>

const int MAX_NSP = 20;
const int MAX_PROF = 100;
const int MAX_NCP = 7;
const int MAX_SAT = 10;

class ThermoVars {
public:
    int imixture;
    std::array<double, MAX_PROF> thermo_param;

    double gama0, GRATIO;
    double MRATIO;

    int NSP, NCP_CHEMKIN;
    std::array<std::string, MAX_NSP> THERMO_SPNAME;
    std::array<double, MAX_NSP> WGHT, WGHT_INV;
    double WREF, TREF, RGAS;
    std::array<std::array<std::array<double, 2>, MAX_NCP>, MAX_NSP> THERMO_AI;
    std::array<std::array<double, 3>, MAX_NSP> THERMO_TLIM;

    int iuse_chemkin;
    std::string chemkin_file;

    double WMEAN, dsmooth;
    std::array<double, MAX_NSP> YMASS;

    int NPSAT;
    std::array<double, MAX_SAT> THERMO_PSAT;
    double NEWTONRAPHSON_ERROR;
};

#endif // THERMOVARS_H

// main.cpp
#include "ThermoVars.h"
#include <iostream>

int main() {
    ThermoVars thermo;

    // Initialize some variables
    thermo.imixture = 1;
    thermo.thermo_param[0] = 5.0;
    thermo.NSP = 10;
    thermo.THERMO_SPNAME[0] = "H2O";
    thermo.WGHT[0] = 18.015;

    // Print to check values
    std::cout << "imixture = " << thermo.imixture << std::endl;
    std::cout << "thermo_param[0] = " << thermo.thermo_param[0] << std::endl;
    std::cout << "NSP = " << thermo.NSP << std::endl;
    std::cout << "THERMO_SPNAME[0] = " << thermo.THERMO_SPNAME[0] << std::endl;
    std::cout << "WGHT[0] = " << thermo.WGHT[0] << std::endl;

    return 0;
}