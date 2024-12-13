#ifndef CONSTANTS_M_H
#define CONSTANTS_M_H

#include <cmath>

namespace constants_m {

constexpr int wp = 8;
constexpr double zero = 0.0;
constexpr double one = 1.0;
constexpr double ten = 10.0;
constexpr double small = std::pow(ten, -5);
constexpr double large = one / small;

constexpr double pi = 4.0 * std::atan(one);
constexpr double rad = pi / 180.0;

constexpr int nmax = 9;
constexpr int nlen = 5000;
constexpr int endpatch = 18;
constexpr int nindex = 10;
constexpr int res_u = 50;
constexpr int res_v = 50;
constexpr int res_box = 11;
constexpr int big_int = 100000;
constexpr int max_iter = 1000000;
constexpr double eps_1 = 1e-1;
constexpr double eps_2 = 1e-6;
constexpr int nullkey = -1;

} // namespace constants_m

#endif // CONSTANTS_M_H