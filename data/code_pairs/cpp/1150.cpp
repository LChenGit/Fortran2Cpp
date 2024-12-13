#ifndef M_PHYS_CONSTANTS_H
#define M_PHYS_CONSTANTS_H

#include <array>

namespace m_phys_constants {

    constexpr int n_scalar = 1;
    constexpr int n_vector = 3;
    constexpr int n_sym_tensor = 6;
    constexpr int n_asym_tensor = 3;
    constexpr int n_solenoid = 2;

    constexpr std::array<std::array<int, 3>, 3> l_sim_t{{
        {{0, 1, 2}},
        {{1, 3, 4}},
        {{2, 4, 5}}
    }};

    constexpr std::array<std::array<std::array<int, 2>, 3>, 3> l_asim_t{{
        {{{0, 0}, {0, 0}, {2, 1}}},
        {{{0, 1}, {-1, 0}, {1, -1}}},
        {{{2, 1}, {1, -1}, {0, 0}}}
    }};

    constexpr std::array<int, 3> lst_sim_t{{0, 3, 5}};

} // namespace m_phys_constants

#endif // M_PHYS_CONSTANTS_H