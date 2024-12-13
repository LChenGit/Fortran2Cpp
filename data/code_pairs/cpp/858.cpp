#ifndef PPM_MODULE_HAMJAC_EXT_H
#define PPM_MODULE_HAMJAC_EXT_H

#include <iostream>

class PpmModuleHamjacExt {
public:
    void ppm_hamjac_ext_step_3ds() {
        std::cout << "This is the single precision routine in C++." << std::endl;
    }
    void ppm_hamjac_ext_step_3dd() {
        std::cout << "This is the double precision routine in C++." << std::endl;
    }
};

#endif // PPM_MODULE_HAMJAC_EXT_H