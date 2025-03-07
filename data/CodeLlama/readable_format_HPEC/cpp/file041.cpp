#include <iostream>
#include <vector>
#include <omp.h>
#include <cstdlib>
#include <cstring>

int main(int argc, char** argv) {
    int len = 100;
    int numNodes = 0;
    int numNodes2 = 0;
    std::vector<std::string> args;
    std::vector<int> x;

    // Check if command line arguments are provided
    if (argc == 0) {
        std::cout << "No command line arguments provided." << std::endl;
        return 1;
    }

    // Allocate memory for args and x
    try {
        args.resize(argc);
        x.resize(len);
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

    // Initialize x
    for (int i = 0; i < len; ++i) {
        if (i % 2 == 0) {
            x[i] = 5;
        } else {
            x[i] = -5;
        }
    }

    // Parallel loop to count negative values in x
    #pragma omp parallel for reduction(+:numNodes2)
    for (int i = len - 1; i >= 0; --i) {
        if (x[i] <= 0) {
            numNodes2--;
        }
    }

    std::cout << "numNodes2 = " << numNodes2 << std::endl;

    return 0;
}
