#include <iostream>
#include <type_traits>

template<typename T>
void ppm_fmm_pretraverse();

template<>
void ppm_fmm_pretraverse<float>() {
    std::cout << "Single precision calculation." << std::endl;
}

template<>
void ppm_fmm_pretraverse<double>() {
    std::cout << "Double precision calculation." << std::endl;
}