#include <iostream>
#include <cstdlib> // For std::exit

// This C++ function mimics the behavior of the Fortran subroutine
// by displaying a warning message and then exiting the program.
void bmf_splitwrite() {
    std::cout << "*****************************************************" << std::endl;
    std::cout << "WARNING: bmf_splitwrite has been replaced by         " << std::endl;
    std::cout << " bmf_splitwrite2 with an additional first argument   " << std::endl;
    std::cout << " first argument should be RPN_COMM_split             " << std::endl;
    std::cout << "*****************************************************" << std::endl;
    std::exit(EXIT_FAILURE); // Exit the program
}

// Main function to test the bmf_splitwrite function.
int main() {
    bmf_splitwrite();
    // Note: The line below will never be executed because
    // bmf_splitwrite exits the program.
    return 0;
}