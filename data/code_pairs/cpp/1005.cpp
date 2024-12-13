// great.cpp
#include <iostream>

// Declaration for integer parameters
void great(int a, int b) {
    std::cout << "Great function called with: " << a << ", " << b << std::endl;
}

// Assuming only the integer version is required based on the Fortran example provided
int main() {
    great(5, 10);
    return 0;
}