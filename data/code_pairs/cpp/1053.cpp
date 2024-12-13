#ifndef MO_SALSA_SIZEDIST_HPP
#define MO_SALSA_SIZEDIST_HPP

#include <vector>
#include <cmath>

namespace mo_salsa_sizedist {
    void size_distribution(int kproma, int kbdim, int klev,
                           const std::vector<double>& n,
                           const std::vector<double>& dpg,
                           const std::vector<double>& sigmag,
                           std::vector<std::vector<std::vector<double>>>& naero);
}

#endif // MO_SALSA_SIZEDIST_HPP