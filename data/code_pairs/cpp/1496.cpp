#include <iostream>

struct SharedMemory {
    union {
        int nums[2];
        int numse[4];
    };
    int& numx = nums[1]; // Reference to the second element of nums to mimic FORTRAN COMMON/EQUIVALENCE
};

SharedMemory scr;

int main() {
    // Mimicking the do-loop from Fortran code
    for (int i = 0; i < 4; ++i) {
        scr.numse[i] = 10 + i + 1; // +1 to adjust for 0-based indexing in C++
    }

    // Mimicking the WRITE statements from Fortran code
    std::cout << scr.nums[1] << " " << scr.nums[0] << " " << scr.numse[3] << " " << scr.numx << std::endl;
    for (int i = 0; i < 4; ++i) {
        std::cout << scr.numse[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}