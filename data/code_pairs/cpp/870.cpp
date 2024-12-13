#ifndef MOD_LBMODEL_H
#define MOD_LBMODEL_H

#include <vector>

struct VelType {
    std::vector<double> coo;

    VelType() : coo(3, 0.0) {}
};

struct LbModelType {
    std::vector<VelType> vel;

    LbModelType(int size) : vel(size) {}
};

#endif // MOD_LBMODEL_H