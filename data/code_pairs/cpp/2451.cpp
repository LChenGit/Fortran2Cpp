#include <iostream>
#include <cstring>

// Equivalent to Fortran's COMMON blocks
struct LXCOM1 {
    char ILINE[505]; // 504 characters + 1 for null-terminator to safely contain the characters
};

struct LXCOM2 {
    int JLINE;
    int LXINIT;
};

LXCOM1 lxcom1;
LXCOM2 lxcom2;

void LXRST() {
    lxcom2.LXINIT = 12345;
    lxcom2.JLINE = 504;
    
    // Initialize the last character to '\0' (equivalent to CHAR(0) in Fortran)
    // Note: Array indexing in C++ starts at 0, so JLINE is decremented by 1.
    lxcom1.ILINE[lxcom2.JLINE - 1] = '\0';
}

int main() {
    LXRST();
    
    // Output the results to verify
    std::cout << "LXINIT: " << lxcom2.LXINIT << std::endl;
    std::cout << "JLINE: " << lxcom2.JLINE << std::endl;
    std::cout << "ILINE[504]: " << (int)lxcom1.ILINE[504 - 1] << std::endl; // cast to int to display the null character

    return 0;
}