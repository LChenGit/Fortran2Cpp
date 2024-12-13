// NORM_ROT__genmod.hpp
#ifndef NORM_ROT__GENMOD_HPP
#define NORM_ROT__GENMOD_HPP

class NORM_ROT__genmod {
public:
    void NORM_ROT(double THN, double PHN, double TH, double PH, double& TH_NEW, double& PH_NEW) {
        // For demonstration, simply copy inputs to outputs.
        TH_NEW = TH;
        PH_NEW = PH;
    }
};

#endif // NORM_ROT__GENMOD_HPP

// test_norm_rot.cpp
#include <iostream>
#include "NORM_ROT__genmod.hpp"

int main() {
    NORM_ROT__genmod normRotGenmod;
    double THN = 1.0, PHN = 2.0;
    double TH = 3.0, PH = 4.0;
    double TH_NEW, PH_NEW;

    normRotGenmod.NORM_ROT(THN, PHN, TH, PH, TH_NEW, PH_NEW);

    if (TH_NEW == TH && PH_NEW == PH) {
        std::cout << "Test Passed." << std::endl;
    } else {
        std::cout << "Test Failed." << std::endl;
    }

    return 0;
}