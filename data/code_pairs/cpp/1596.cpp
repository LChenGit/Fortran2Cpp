#ifndef MNORMAL_H
#define MNORMAL_H

#include <array>
#include <cmath>

class MNormal {
public:
    static std::array<double, 2> normal(const std::array<double, 2>& v) {
        std::array<double, 2> n;
        n[0] = v[1];
        n[1] = -v[0];
        double norm = std::sqrt(n[0] * n[0] + n[1] * n[1]);
        n[0] /= norm;
        n[1] /= norm;
        return n;
    }
};

#endif // MNORMAL_H