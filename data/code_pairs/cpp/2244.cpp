#include <cmath>
#include <vector>
#include <iostream>
#include <cassert>

float snrm2(int n, const std::vector<float>& x, int incx) {
    const float ONE = 1.0f;
    const float ZERO = 0.0f;

    float absxi, norm = ZERO, scale = ZERO, ssq = ONE;

    if (n < 1 || incx < 1) {
        return norm;
    } else if (n == 1) {
        return std::abs(x[0]);
    } else {
        for (int ix = 0; ix < n * incx; ix += incx) {
            if (x[ix] != ZERO) {
                absxi = std::abs(x[ix]);
                if (scale < absxi) {
                    ssq = ONE + ssq * (scale / absxi) * (scale / absxi);
                    scale = absxi;
                } else if (scale != ZERO) { // Ensure division by zero is handled
                    ssq += (absxi / scale) * (absxi / scale);
                }
            }
        }
        norm = scale * std::sqrt(ssq);
    }

    return norm;
}