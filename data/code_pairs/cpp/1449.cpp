#ifndef SIZES_H
#define SIZES_H

#include <array>

namespace sizes {
    constexpr int Ndim = 3;
    constexpr std::array<int, Ndim> mesh = {100, 100, 100};
    constexpr int meshx = mesh[0];
    constexpr int meshy = mesh[1];
    constexpr int meshz = mesh[2];
}

#endif // SIZES_H