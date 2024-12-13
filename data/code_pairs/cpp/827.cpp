#include <iostream>
#include <string>

// Function that replicates the Fortran `repeat` behavior
std::string repeat_char(char c, int n) {
    return std::string(n, c);
}

int main() {
    char z = 'z';
    int repetitions = 3; // Adjusted to match the unit test scenario
    std::string output = repeat_char(z, repetitions);
    
    std::cout << output << std::endl;
    
    return 0;
}