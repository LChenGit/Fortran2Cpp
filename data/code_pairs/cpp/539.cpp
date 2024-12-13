#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace constants {
    constexpr double pi = 3.141592653589793238462643383279502884197;
    constexpr double eps0 = 8.8541878176e-12;
    constexpr double mu0 = 4.0 * pi * 1e-7;
    constexpr double c0 = 2.997924580003e8;
    constexpr double eta0 = 3.767303134622e2;

    constexpr double radtodeg = 180.0 / pi;
    constexpr double degtorad = pi / 180.0;

    constexpr int prd_none = 1;
    constexpr int prd_2d = 2;
}

#endif // CONSTANTS_H