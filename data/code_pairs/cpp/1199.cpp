#include <iostream>

namespace SET_THETAPHI_RANGE__genmod {
    void SET_THETAPHI_RANGE(double& THETA, double& PHI, bool USE_POSITIVE_LON) {
        if (USE_POSITIVE_LON && PHI < 0) {
            PHI += 360;
        } else if (!USE_POSITIVE_LON && PHI > 0) {
            PHI -= 360;
        }
    }
}