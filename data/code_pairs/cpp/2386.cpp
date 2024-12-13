#include <iostream>
#include <string>
#include <cstdlib>

// Declaration of the ncheck function
void ncheck(int istat, const std::string& fname);

int main() {
    std::string fname = "non_existent_file.nc";
    int istat = -1; // Simulating a file operation error

    // This should exit the program with an error message
    ncheck(istat, fname);

    return 0;
}

// Definition of the ncheck function
void ncheck(int istat, const std::string& fname) {
    if (istat != 0) {
        std::cerr << "Error in file operation: " << fname << std::endl;
        exit(EXIT_FAILURE);
    }
}