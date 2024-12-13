#include <iostream>
#include <cassert>

namespace DLABAD__genmod {
    void DLABAD(double& SMALL, double& LARGE) {
        if (SMALL < 0.1) SMALL = 0.1;
        if (LARGE > 100.0) LARGE = 100.0;
    }
}