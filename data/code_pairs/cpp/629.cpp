#include <array>
#include <cmath>

void sla_DM2AV(const std::array<std::array<double, 3>, 3>& RMAT, std::array<double, 3>& AXVEC) {
    double X, Y, Z, S2, C2, PHI, F;

    X = RMAT[1][2] - RMAT[2][1];
    Y = RMAT[2][0] - RMAT[0][2];
    Z = RMAT[0][1] - RMAT[1][0];
    S2 = std::sqrt(X*X + Y*Y + Z*Z);
    
    if (S2 != 0.0) {
        C2 = RMAT[0][0] + RMAT[1][1] + RMAT[2][2] - 1.0;
        PHI = std::atan2(S2, C2);
        F = PHI / S2;
        
        AXVEC[0] = X * F;
        AXVEC[1] = Y * F;
        AXVEC[2] = Z * F;
    } else {
        AXVEC[0] = 0.0;
        AXVEC[1] = 0.0;
        AXVEC[2] = 0.0;
    }
}