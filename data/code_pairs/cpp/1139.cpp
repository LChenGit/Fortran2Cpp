#ifndef RRSW_KG22_H
#define RRSW_KG22_H

#include <array>
#include <iostream>

constexpr int no22 = 16;
constexpr int ng22 = 16;
using rb = double;

struct rrsw_kg22 {
    std::array<std::array<std::array<std::array<rb, no22>, 13>, 5>, 9> kao{};
    std::array<std::array<std::array<rb, no22>, 47>, 5> kbo{}; // Adjusted for 0-based indexing
    std::array<std::array<rb, no22>, 10> selfrefo{};
    std::array<std::array<rb, no22>, 3> forrefo{};
    std::array<std::array<rb, 9>, no22> sfluxrefo{};

    rb rayl{};

    union {
        std::array<std::array<std::array<std::array<rb, ng22>, 13>, 5>, 9> ka{};
        std::array<rb, 585 * ng22> absa{};
    };

    union {
        std::array<std::array<std::array<rb, ng22>, 47>, 5> kb{};
        std::array<rb, 235 * ng22> absb{};
    };

    std::array<std::array<rb, ng22>, 10> selfref{};
    std::array<std::array<rb, ng22>, 3> forref{};
    std::array<std::array<rb, 9>, ng22> sfluxref{};

    void test_equivalence() {
        ka[0][0][0][0] = 123.456;
        if (absa[0] == 123.456) {
            std::cout << "Equivalence mapping successful for ka -> absa" << std::endl;
        } else {
            std::cerr << "Equivalence mapping failed for ka -> absa" << std::endl;
        }
    }
};

#endif // RRSW_KG22_H