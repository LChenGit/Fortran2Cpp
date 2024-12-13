#ifndef ADIOSHELPERS_H
#define ADIOSHELPERS_H

#include <vector>
#include <iostream>

class AdiosHelpers {
public:
    static void define_adios_scalar(double scalar) {
        std::cout << "Defining ADIOS scalar with value: " << scalar << std::endl;
    }

    static void define_adios_global_real_1d_array(const std::vector<double>& array) {
        std::cout << "Defining ADIOS global real 1D array of size " << array.size() << std::endl;
        for (double val : array) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    static void check_adios_err() {
        std::cout << "Checking for ADIOS errors..." << std::endl;
    }
};

#endif // ADIOSHELPERS_H