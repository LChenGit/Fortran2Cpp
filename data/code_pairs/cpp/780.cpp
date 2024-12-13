#include <iostream>
#include <iomanip> // For std::fixed and std::setprecision

int main() {
    double tmp = 1.0;
    std::cout << std::fixed << std::setprecision(6) << tmp << std::endl; // Ensure similar formatting to Fortran
    return 0;
}