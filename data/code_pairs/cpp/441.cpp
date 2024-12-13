// file: update_y.cpp
#include <iostream>

void updateY(double y[], double ekk, const double* tiltc, const double* tilts, int i) {
    y[0] = y[0] + ekk * tiltc[i-1];
    y[1] = y[1] + ekk * tilts[i-1];
}