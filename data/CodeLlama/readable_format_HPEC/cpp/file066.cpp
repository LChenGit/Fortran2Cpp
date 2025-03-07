#include <iostream>
#include <vector>
#include <omp.h>
#include <cstdlib>
#include <cstring>

int main(int argc, char* argv[]) {
    int len = 10000;
    int argCount = argc;
    int allocStatus, rdErr, x, ix;
    std::vector<std::string> args(argCount);

    if (argCount == 0) {
        std::cout << "No command line arguments provided." << std::endl;
        return 0;
    }

    try {
        for (ix = 0; ix < argCount; ++ix) {
            args[ix] = argv[ix];
        }
    } catch (const std::bad_alloc& e) {
        std::cerr << "Allocation error, program terminated." << std::endl;
        return 1;
    }

    if (argCount >= 1) {
        char* endptr = nullptr;
        len = std::strtol(args[0].c_str(), &endptr, 10);
        if (*endptr != ' ') {
            std::cerr << "Error, invalid integer value." << std::endl;
            return 1;
        }
    }

    #pragma omp parallel for private(i)
    for (int i = 0; i <= len; ++i) {
        x = i;
    }

    std::cout << "x = " << x << std::endl;

    return 0;
}
