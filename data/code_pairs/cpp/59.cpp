#ifndef TOMOGRAPHY_PAR_HPP
#define TOMOGRAPHY_PAR_HPP

#include <vector>

class TomographyPar {
public:
    int NSPEC = 0, NGLOB = 0;
    std::vector<double> x, y, z; // Assuming CUSTOM_REAL maps to double

    void initialize(int ns, int ng) {
        NSPEC = ns;
        NGLOB = ng;
        x.assign(NGLOB, 1.0);
        y.assign(NGLOB, 2.0);
        z.assign(NGLOB, 3.0);
    }
};

#endif // TOMOGRAPHY_PAR_HPP