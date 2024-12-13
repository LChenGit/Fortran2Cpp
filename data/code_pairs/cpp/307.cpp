// Main operation - assumed to be part of a larger program or class
#include <vector>

void updateY(std::vector<double>& Y, const std::vector<double>& TILTS, const std::vector<double>& TILTC, double EKK, int I) {
    Y[0] = Y[0] - EKK * TILTS[I - 1];
    Y[1] = Y[1] + EKK * TILTC[I - 1];
}