#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

int main() {
    std::ofstream out("cpp_output.txt");

    // For each line in the Fortran output, we reproduce the formatting in C++.
    // The C++ code here is adjusted to closely mimic the Fortran formatting behavior.

    // Equivalent to write(*,'(I4,T8,I1)') 1234,8 in Fortran
    out << std::setw(4) << 1234 << std::setw(4) << " " << 8 << std::endl;

    // Equivalent to write(*,'(I4,TR3,I1)') 1234,8 in Fortran
    // C++ does not have a direct equivalent of Fortran's TR, but we can approximate the position.
    out << std::setw(4) << 1234 << std::setw(3) << " " << 8 << std::endl;

    // Equivalent to write(*,'(I4,5X,TL2,I1)') 1234,8 in Fortran
    // C++ does not have a TL equivalent, so we adjust by calculating the necessary spaces.
    out << std::setw(4) << 1234 << std::string(3, ' ') << 8 << std::endl; // Adjusted to match Fortran's output

    out.close();
    return 0;
}