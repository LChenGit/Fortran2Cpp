#include <iostream>
#include <vector>
#include <omp.h>
#include <cstdlib>
#include <cstring>

int main(int argc, char* argv[]) {
    int inLen = 1000;
    int outLen = 1;
    int argCount = argc;
    std::vector<std::string> args(argCount);
    std::vector<int> input(inLen);
    std::vector<int> output(inLen);

    if (argCount == 0) {
        std::cout << "No command line arguments provided." << std::endl;
    }

    for (int ix = 0; ix < argCount; ++ix) {
        args[ix] = argv[ix];
    }

    if (argCount >= 1) {
        char* endptr = nullptr;
        inLen = std::strtol(args[0].c_str(), &endptr, 10);
        if (*endptr != ' ') {
            std::cout << "Error, invalid integer value." << std::endl;
        }
    }

    for (int i = 0; i < inLen; ++i) {
        input[i] = i + 1; // Adjust for zero-based indexing
    }

    #pragma omp parallel for
    for (int i = 0; i < inLen; ++i) {
        output[outLen - 1] = input[i]; // Adjust for zero-based indexing
        outLen++;
    }

    std::cout << "output(0)=" << output[0] << std::endl;

    return 0;
}
