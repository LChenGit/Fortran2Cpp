#ifndef BLOCKDATA_H
#define BLOCKDATA_H

#include <array>

// Equivalent structure to COMMON/RAND2/
struct RAND2 {
    int IY = 0;
    int IFF = 0; // Initialized as per DATA statement
    std::array<int, 97> IR = {}; // Default initialized to 0
};

// Equivalent structure to COMMON/ICPU0/
struct ICPU0 {
    int ICPU = 0; // Initialized as per DATA statement
};

// Global instances
extern RAND2 rand2;
extern ICPU0 icpu0;

// Initialization function, equivalent to BLOCK DATA BLOCK
void initializeBlock();

#endif // BLOCKDATA_H