#pragma once
#include <vector>
#include <array>

namespace modstore {
    const int maxspecies = 10;  
    const int maxatoms = 100;   

    struct ModStore {
        std::array<std::array<double, 3>, 3> avec0;
        std::array<std::array<double, 3>, 3> bvec0, binv0;
        double omega0;
        bool tshift0;
        bool primcell0;
        std::array<int, maxspecies> natoms0;
        int natmtot0;
        std::vector<std::vector<std::array<double, 3>>> atposl0; 
        std::vector<std::vector<std::array<double, 3>>> atposc0; 
        double rmtdelta0;
        std::array<int, 3> ngridg0;
        int ngtot0;
        std::vector<std::vector<int>> ivg0; 
        std::vector<int> igfft0;
        bool spinpol0, spinorb0, cmagz0;
        std::array<double, 3> bfieldc00;
        std::vector<std::vector<std::array<double, 3>>> bfcmt00;
        double reducebf0;
        int fsmtype0;
        std::array<double, 3> momfix0;
        std::vector<std::vector<std::array<double, 3>>> mommtfix0;
        bool tforce0;
        bool autokpt0;
        std::array<int, 3> ngridk0;
        std::array<double, 3> vkloff0;
        int lmaxinr0;
        bool trimvg0;

        ModStore() : atposl0(maxspecies, std::vector<std::array<double, 3>>(maxatoms)),
                     atposc0(maxspecies, std::vector<std::array<double, 3>>(maxatoms)),
                     bfcmt00(maxspecies, std::vector<std::array<double, 3>>(maxatoms)),
                     mommtfix0(maxspecies, std::vector<std::array<double, 3>>(maxatoms)) {}
    };
}