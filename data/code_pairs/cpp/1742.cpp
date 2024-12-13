#include <iostream>
#include <cassert>

void extUray(double** U, double* Uray, int nd, int np, int iray) {
    iray -= 1; // Adjusting to 0-based indexing

    for (int L = 0; L < nd; ++L) {
        Uray[L] = U[L][iray];
    }
}