#include <iostream>
#include <vector>
#include <omp.h>
#include <cstdlib> // For std::exit

int main(int argc, char* argv[]) {
    int len = 1000;
    int argCount = argc;
    std::vector<std::string> args(argCount);
    std::vector<int> a(len);

    // Check if command line arguments are provided
    if (argCount == 0) {
        std::cout << "No command line arguments provided." << std::endl;
    }

    // Allocate memory for args and a
    try {
        for (int ix = 0; ix < argCount; ++ix) {
            args[ix] = argv[ix];
        }
    } catch (const std::bad_alloc& e) {
        std::cerr << "Allocation error, program terminated." << std::endl;
        std::exit(EXIT_FAILURE);
    }

    // If at least one argument is provided, try to parse it as an integer
    if (argCount >= 1) {
        char* endptr = nullptr;
        len = std::strtol(args[0].c_str(), &endptr, 10);
        if (*endptr != ' ') {
            std::cerr << "Error, invalid integer value." << std::endl;
        }
    }

    // Initialize a(1)
    a[0] = 2;

    // Parallel loop to compute a(i) = a(i) + a(1)
    #pragma omp parallel for
    for (int i = 1; i < len; ++i) {
        a[i] = a[i] + a[0];
    }

    // Print a(0)
    std::cout << "a(0) = " << a[0] << std::endl;

    // No need to explicitly deallocate args and a as they will be automatically done by the destructors
    return 0;
}
