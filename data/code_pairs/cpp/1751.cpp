// spcore_I.h
#include <array>

class spcore_I {
public:
    static void spcore(int NI, int NJ, double R, std::array<std::array<double, 2>, 10>& CORE);
};

// spcore_I.cpp
#include "spcore_I.h"

void spcore_I::spcore(int NI, int NJ, double R, std::array<std::array<double, 2>, 10>& CORE) {
    for (int i = 0; i < 10; ++i) {
        CORE[i][0] = NI * R + (i + 1); // Adjusted to match Fortran's 1-based indexing
        CORE[i][1] = NJ * R - (i + 1);
    }
}