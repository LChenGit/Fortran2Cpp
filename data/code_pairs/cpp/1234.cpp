#include <iostream>

// Define the equivalent structure in C++
struct CKSTRT {
    int NMM, NKK, NII, MXSP, MXTB, MXTP, NCP, NCP1;
    // Continue with other variables as in the Fortran COMMON block
};

// Function to test initialization and modification of a variable within the struct
bool testCKSTRTInitialization() {
    CKSTRT ckstrt;
    // Initialize the variable
    ckstrt.NMM = 1;

    // Modify and test the variable
    ckstrt.NMM += 1;
    if(ckstrt.NMM == 2) {
        std::cout << "All Tests Passed" << std::endl;
        return true;
    } else {
        std::cerr << "Test Failed for NMM" << std::endl;
        return false;
    }
}

int main() {
    if(!testCKSTRTInitialization()) {
        return 1; // Indicate failure
    }
    return 0; // Indicate success
}