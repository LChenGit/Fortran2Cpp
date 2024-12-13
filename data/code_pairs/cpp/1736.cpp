// ppm_module_fmm_init.hpp
#include <iostream>

class PpmModuleFmmInit {
public:
    static void ppm_fmm_init_s_sf() {
        std::cout << "Initializing single precision scalar field." << std::endl;
    }
    static void ppm_fmm_init_d_sf() {
        std::cout << "Initializing double precision scalar field." << std::endl;
    }
    static void ppm_fmm_init_s_vf() {
        std::cout << "Initializing single precision vector field." << std::endl;
    }
    static void ppm_fmm_init_d_vf() {
        std::cout << "Initializing double precision vector field." << std::endl;
    }
};

// test_ppm_module_fmm_init.cpp
#include "ppm_module_fmm_init.hpp"

int main() {
    PpmModuleFmmInit::ppm_fmm_init_s_sf();
    PpmModuleFmmInit::ppm_fmm_init_d_sf();
    PpmModuleFmmInit::ppm_fmm_init_s_vf();
    PpmModuleFmmInit::ppm_fmm_init_d_vf();

    std::cout << "All initialization routines called successfully." << std::endl;

    return 0;
}