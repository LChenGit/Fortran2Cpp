#ifndef LIB_HPP
#define LIB_HPP

#include <array>

namespace lib {
    struct Kozo {
        std::array<double, 42> U;
        std::array<double, 42> V;
    };

    Kozo Iriguchi;
    Kozo Deguchi;
}

#endif // LIB_HPP