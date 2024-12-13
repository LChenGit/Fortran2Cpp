#ifndef SEGMENT_HPP
#define SEGMENT_HPP

#include <cmath>

namespace segment {
    int whichSegment(double x, double xLower, double xUpper, int iLower, int iUpper) {
        if (x <= xLower) return iLower;
        else if (x >= xUpper) return iUpper;
        else return iLower + static_cast<int>(std::floor(0.5 + (x - xLower) / (xUpper - xLower) * (iUpper - iLower)));
    }
}

#endif // SEGMENT_HPP