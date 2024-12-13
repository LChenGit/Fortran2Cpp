#include <cmath>

double dpowint(double xlow, double xhigh, double ylow, double yhigh, double xval, double pow) {
    const double EPSLON = 1.0e-20;

    if (std::abs(xhigh - xlow) < EPSLON) {
        return (yhigh + ylow) / 2.0;
    } else {
        return ylow + (yhigh - ylow) * std::pow((xval - xlow) / (xhigh - xlow), pow);
    }
}