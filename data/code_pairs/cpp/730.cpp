#ifndef CGCA_M3CLVG_HPP
#define CGCA_M3CLVG_HPP

#include <array>
#include <vector>

class CGCA_M3CLVG {
public:
    virtual void cgca_clvgs_abstract(
        const std::array<std::array<std::array<int, 3>, 3>, 3>& farr,
        const std::array<std::array<std::array<int, 3>, 3>, 3>& marr,
        const std::array<float, 3>& n,
        int cstate,
        bool debug,
        int& newstate) = 0;
};

#endif // CGCA_M3CLVG_HPP