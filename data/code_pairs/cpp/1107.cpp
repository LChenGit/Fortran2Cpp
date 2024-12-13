#ifndef DROTAT_I_H
#define DROTAT_I_H

#include <array>

void drotat(int NI, const std::array<double, 3>& XI, const std::array<double, 3>& XJ,
            std::array<double, 10>& E1B, double& ENUC, double RIJ);

#endif