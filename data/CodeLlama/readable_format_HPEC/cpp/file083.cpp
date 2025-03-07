#include <iostream>
#include <vector>
#include <omp.h>
#include <cstdlib>
#include <cstring>

int main(int argc, char* argv[]) {
    int len = 100;
    std::vector<std::string> args;
    std::vector<int> a, b;

    // Check if command line arguments are provided
    if (argc == 0) {
        std::cout << "No command line arguments provided." << std::endl;
        return 1;
    }

    // Allocate memory for args and a, b
    try {
        args.resize(argc);
        a.resize(len);
        b.resize(len);
    } catch (const std::bad_alloc& e) {
        std::cerr << "Allocation error, program terminated." << std::endl;
        return 1;
    }

    // Get command line arguments
    for (int ix = 0; ix < argc; ++ix) {
        args[ix] = argv[ix];
    }

    // Check if at least one argument is provided
    if (argc >= 1) {
        // Attempt to convert the first argument to an integer
        char* endptr = nullptr;
        len = std::strtol(args[0].c_str(), &endptr, 10);
        if (*endptr != ' ') {
            std::cerr << "Error, invalid integer value." << std::endl;
            return 1;
        }
    }

    // Initialize arrays a and b
    for (int i = 0; i < len; ++i) {
        a[i] = i + 1; // Fortran arrays are 1-based, C++ arrays are 0-based
        b[i] = i + 2;
    }

    // SIMD operation
    #pragma omp simd
    for (int i = 0; i < len - 1; ++i) {
        a[i + 1] = a[i] + b[i];
    }

    // Print values of a
    for (int i = 0; i < len; ++i) {
        std::cout << "Values for i and a[i] are: " << i + 1 << " " << a[i] << std::endl; // +1 to match Fortran output
    }

    return 0;
}
