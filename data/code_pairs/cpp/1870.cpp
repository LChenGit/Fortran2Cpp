// ps_local_gth_module.hpp
#include <vector>
#include <cmath>

void init_ps_local_gth(double Va, int NMGL, int ielm, const std::vector<double>& GG, std::vector<double>& vqlg) {
    const double pi = std::acos(-1.0);
    const double constValue = 1.0 / std::abs(Va);
    std::vector<double> parloc = {1.0, 2.0, 3.0, 4.0}; // Assuming these are the values
    double Zps = 1.0; // Assuming
    double Rcloc = 1.0; // Assuming

    double rloc, C1, C2, C3, C4, G, v;
    
    vqlg.assign(NMGL, 0.0); // Initialize vqlg with 0s

    rloc = Rcloc; // Adjusted for example
    C1 = parloc[0]; // Adjusted for example
    C2 = parloc[1]; // Adjusted for example
    C3 = parloc[2]; // Adjusted for example
    C4 = parloc[3]; // Adjusted for example

    vqlg[0] = constValue * ( 2.0 * pi * Zps * std::pow(rloc, 2) +
                             std::sqrt(std::pow(2.0 * pi, 3)) * std::pow(rloc, 3) *
                             ( C1 + C2 * 3.0 + C3 * 15.0 + C4 * 105.0 ) );

    for (int ig = 1; ig < NMGL; ++ig) {
        G = std::sqrt( GG[ig] );

        v = -4.0 * pi * Zps * std::exp(-0.5 * std::pow(G * rloc, 2)) / std::pow(G, 2);

        v += std::sqrt(std::pow(2.0 * pi, 3)) * std::pow(rloc, 3) * std::exp(-0.5 * std::pow(rloc * G, 2))
             * ( C1 
               + C2 * (3.0 - std::pow(rloc * G, 2)) 
               + C3 * (15.0 - 10.0 * std::pow(rloc * G, 2) + std::pow(rloc * G, 4)) 
               + C4 * (105.0 - 105.0 * std::pow(rloc * G, 2) + 21.0 * std::pow(rloc * G, 4) - std::pow(rloc * G, 6)) );

        vqlg[ig] = constValue * v;
    }
}

// test_ps_local_gth.cpp
#include <iostream>
#include <vector>
#include "ps_local_gth_module.hpp"

int main() {
    double Va = 1.0;
    int NMGL = 5;
    int ielm = 1;
    std::vector<double> GG = {1.0, 2.0, 3.0, 4.0, 5.0};
    std::vector<double> vqlg(NMGL);

    init_ps_local_gth(Va, NMGL, ielm, GG, vqlg);

    for (int i = 0; i < NMGL; ++i) {
        std::cout << "vqlg[" << i << "] = " << vqlg[i] << std::endl;
    }

    return 0;
}