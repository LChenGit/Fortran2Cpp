#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <omp.h>

int main(int argc, char* argv[]) {
    int len = 100;
    float getSum = 0.0f;
    std::vector<std::string> args;
    std::vector<std::vector<float>> u;

    // Check if command line arguments are provided
    if (argc == 0) {
        std::cout << "No command line arguments provided." << std::endl;
        return 1;
    }

    // Allocate memory for command line arguments
    try {
        args.resize(argc);
    } catch (const std::bad_alloc& e) {
        std::cerr << "Allocation error, program terminated." << std::endl;
        return 1;
    }

    // Copy command line arguments
    for (int ix = 0; ix < argc; ++ix) {
        args[ix] = argv[ix];
    }

    // Check if at least one command line argument is provided
    if (argc >= 1) {
        // Attempt to convert the first argument to an integer
        char* endptr = nullptr;
        len = std::strtol(args[0].c_str(), &endptr, 10);
        if (*endptr != ' ') {
            std::cerr << "Error, invalid integer value." << std::endl;
            return 1;
        }
    }

    // Allocate memory for the 2D array
    try {
        u.resize(len, std::vector<float>(len, 0.5f));
    } catch (const std::bad_alloc& e) {
        std::cerr << "Allocation error, program terminated." << std::endl;
        return 1;
    }

    // Parallelize the computation
    #pragma omp parallel for collapse(2) private(getSum)
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            float temp = u[i][j];
            getSum += temp * temp;
        }
    }

    std::cout << "sum = " << getSum << std::endl;

    // No need to explicitly deallocate args and u as they will be automatically done by the destructors
    return 0;
}
