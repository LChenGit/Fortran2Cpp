#include <iostream>
#include <vector>
#include <omp.h>
#include <cstdlib> // For std::exit()

int main(int argc, char** argv) {
    int len = 1000;
    int argCount = argc - 1; // Adjust for 0-based indexing in C++

    if (argCount == 0) {
        std::cout << "No command line arguments provided." << std::endl;
        return 0;
    }

    // Dynamically allocate memory for args
    std::vector<std::string> args(argCount);
    for (int ix = 0; ix < argCount; ++ix) {
        args[ix] = argv[ix + 1]; // Adjust for 0-based indexing in C++
    }

    if (argCount >= 1) {
        // Attempt to parse the first argument as an integer
        char* endptr = nullptr;
        len = std::strtol(args[0].c_str(), &endptr, 10);
        if (*endptr != ' ') { // Check if the entire string was not converted
            std::cout << "Error, invalid integer value." << std::endl;
            return 0;
        }
    }

    // Dynamically allocate memory for the 2D array 'a'
    std::vector<std::vector<float>> a(len, std::vector<float>(len, 0.5f));

    // Parallel region to update the array
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < len - 1; ++i) {
        for (int j = 0; j < len; ++j) {
            a[i][j] += a[i + 1][j];
        }
    }

    // Print the value of a(10,10)
    std::cout << "a(10,10) = " << a[9][9] << std::endl; // Adjusted indices for 0-based indexing

    // No need to explicitly deallocate 'a' and 'args' as they will be automatically handled by the destructors
    return 0;
}
