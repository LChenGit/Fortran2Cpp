#ifndef COE_I_H
#define COE_I_H

#include <array>

namespace coe_I {

void coe(double X2, double Y2, double Z2, int NORBI, int NORBJ, std::array<double, 75>& C, double& R) {
    R = X2 + Y2 + Z2;
    for(size_t i = 0; i < C.size(); i += 2) {
        C[i] = NORBI;
        if (i + 1 < C.size()) {
            C[i+1] = NORBJ;
        }
    }
}

} // namespace coe_I

#endif // COE_I_H