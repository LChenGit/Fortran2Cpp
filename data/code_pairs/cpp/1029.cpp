// dnrm2.cpp
#include <cmath>

double dnrm2(int n, const double* x, int incx) {
    const double zero = 0.0;
    const double one = 1.0;
    double norm = zero, scale = zero, ssq = one, absxi;
    
    if (n < 1 || incx < 1) {
        norm = zero;
    } else if (n == 1) {
        norm = std::abs(x[0]);
    } else {
        for (int ix = 0; ix < n * incx; ix += incx) {
            if (x[ix] != zero) {
                absxi = std::abs(x[ix]);
                if (scale < absxi) {
                    ssq = one + ssq * (scale / absxi) * (scale / absxi);
                    scale = absxi;
                } else {
                    ssq += (absxi / scale) * (absxi / scale);
                }
            }
        }
        norm = scale * std::sqrt(ssq);
    }
    return norm;
}