#ifndef COMPUTE_JACOBIAN_2D_HPP
#define COMPUTE_JACOBIAN_2D_HPP

#include <vector>

void compute_jacobian_2d(
    int myrank,
    int ispecb,
    const std::vector<double>& xelm,
    const std::vector<double>& yelm,
    const std::vector<double>& zelm,
    const std::vector<std::vector<std::vector<std::vector<double>>>>& dershape2d,
    std::vector<std::vector<std::vector<float>>>& jacobian2d,
    std::vector<std::vector<std::vector<std::vector<float>>>>& normal,
    int nglla,
    int nglb,
    int nspec2dmax_ab
);

#endif // COMPUTE_JACOBIAN_2D_HPP