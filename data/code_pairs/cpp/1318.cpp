#include <iostream>
#include <vector>
#include <string>

enum {
    ppm_param_alloc_fit = 1,
    ppm_param_alloc_fit_preserve,
    ppm_param_alloc_grow,
    ppm_param_alloc_grow_preserve,
    ppm_param_dealloc
};

const int ppm_error_error = -1;

void ppm_alloc_argcheck(const std::string& caller, const std::vector<int>& ldl, int iopt, int dimension, int& info) {
    info = 0;
    if (iopt != ppm_param_alloc_fit && iopt != ppm_param_alloc_fit_preserve &&
        iopt != ppm_param_alloc_grow && iopt != ppm_param_alloc_grow_preserve &&
        iopt != ppm_param_dealloc) {
        std::cerr << "Error in " << caller << ": unknown iopt" << std::endl;
        info = ppm_error_error;
        return;
    }

    for (int i = 0; i < dimension; ++i) {
        if (ldl[i] < 0) {
            std::cerr << "Error in " << caller << ": ldl() must be >= 0" << std::endl;
            info = ppm_error_error;
            return;
        }
    }
}

int main() {
    std::vector<int> ldl = {1, 2};
    int iopt = ppm_param_alloc_fit;
    int dimension = 2;
    int info;

    ppm_alloc_argcheck("TestCaller", ldl, iopt, dimension, info);
    if (info == 0) {
        std::cout << "Test 1 Passed" << std::endl;
    } else {
        std::cout << "Test 1 Failed" << std::endl;
    }

    ppm_alloc_argcheck("TestCaller", ldl, -1, dimension, info);
    if (info != 0) {
        std::cout << "Test 2 Passed" << std::endl;
    } else {
        std::cout << "Test 2 Failed" << std::endl;
    }

    // More tests can be added as needed

    return 0;
}