#include <iostream>
#include <string>
#include <cstdlib> // For std::abort

struct t {
    std::string x = std::string(2, ' '); // Initialize with 2 spaces
};

int main() {
    t a;
    std::string b(3, ' '); // Initialize with 3 spaces
    std::string line(10, ' '); // Initialize with 10 spaces
    
    a.x[0] = 'a'; // Assign 'a' to the first position
    line = a.x.substr(0, 1) + "X" + std::string(8, ' '); // Mimic Fortran's write statement
    if (line != "aX        ") std::abort();
    
    b[0] = 'a'; b[1] = 'b'; // Assign 'ab' to b
    line = b.substr(0, 2) + "Y" + std::string(7, ' '); // Again mimic Fortran's write statement
    if (line != "abY       ") std::abort();
    
    std::cout << "All operations succeeded." << std::endl;
    return 0;
}