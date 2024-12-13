#ifndef RRSW_KG20_H
#define RRSW_KG20_H

#include <array>

// Assuming kind_im and kind_rb correspond to specific types in C++
using kind_im = int; // Placeholder, adjust as needed
using kind_rb = double; // Placeholder, assuming double for floating-point precision

namespace rrsw_kg20 {
    constexpr int no20 = 16;
    constexpr int ng20 = 20; // Example value, adjust as necessary

    // Declaration of arrays
    extern std::array<std::array<std::array<kind_rb, no20>, 13>, 5> kao;
    extern std::array<std::array<std::array<kind_rb, no20>, 47>, 5> kbo;
    extern std::array<std::array<kind_rb, no20>, 10> selfrefo;
    extern std::array<std::array<kind_rb, no20>, 4> forrefo;
    extern std::array<kind_rb, no20> sfluxrefo;
    extern std::array<kind_rb, no20> absch4o;

    extern kind_rb rayl;

    extern std::array<std::array<std::array<kind_rb, ng20>, 13>, 5> ka;
    extern std::array<std::array<kind_rb, ng20>, 65> absa;
    extern std::array<std::array<std::array<kind_rb, ng20>, 47>, 5> kb;
    extern std::array<std::array<kind_rb, ng20>, 235> absb;
    extern std::array<std::array<kind_rb, ng20>, 10> selfref;
    extern std::array<std::array<kind_rb, ng20>, 4> forref;
    extern std::array<kind_rb, ng20> sfluxref;
    extern std::array<kind_rb, ng20> absch4;
}

#endif // RRSW_KG20_H