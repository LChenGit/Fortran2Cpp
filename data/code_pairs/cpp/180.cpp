#include <cmath>
#include <algorithm>

double DLAPY3(double X, double Y, double Z) {
    const double ZERO = 0.0;
    double W, XABS, YABS, ZABS;

    XABS = std::abs(X);
    YABS = std::abs(Y);
    ZABS = std::abs(Z);
    W = std::max({XABS, YABS, ZABS});

    if (W == ZERO) {
        return XABS + YABS + ZABS;
    } else {
        return W * std::sqrt((XABS / W) * (XABS / W) + (YABS / W) * (YABS / W) + (ZABS / W) * (ZABS / W));
    }
}