#include <iostream>

// Mimicking the Fortran common block using a global structure
struct BlockA {
    double a = 0.0; // Default-initialized to 0.0
    double b = 0.0; // Default-initialized to 0.0
    double d[10][30] = {}; // Default-initialized to 0.0
} blocka;

int main() {
    std::cout << "ok" << std::endl;
    return 0;
}