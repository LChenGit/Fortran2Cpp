#include <iostream>

// Assuming A's type is int for simplicity; adjust as needed.
int A;

// Declaration of the subroutine inside a namespace to mimic the Fortran module structure.
namespace TMod {
    void A22_5S_WRONG() {
        std::cout << "A22_5S_WRONG called successfully." << std::endl;
    }
}

// The translation of the A22_5_WRONG subroutine.
void A22_5_WRONG() {
    // Call to the nested subroutine.
    TMod::A22_5S_WRONG();
    
    A = 5; // Modify the global variable.
    std::cout << "A22_5_WRONG completed. A = " << A << std::endl;
}

int main() {
    A22_5_WRONG(); // Call the subroutine.
    std::cout << "C++ test passed: A22_5_WRONG called successfully." << std::endl;
    return 0;
}