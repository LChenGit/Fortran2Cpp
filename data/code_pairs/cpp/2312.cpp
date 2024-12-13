#include <iostream>
#include <iomanip> // For std::setw

int main() {
    int i = 1;
    int j = 2;
    // Attempt to mimic Fortran's default spacing; exact replication may require manual spacing
    std::cout << std::setw(12) << i << std::setw(12) << j << std::endl;
    return 0;
}