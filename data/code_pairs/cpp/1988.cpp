#ifndef DATA_GLLMESH_H
#define DATA_GLLMESH_H

#include <vector>

class DataGllMesh {
public:
    std::vector<std::vector<std::vector<double>>> sgll, zgll;
    std::vector<std::vector<std::vector<double>>> sgll_fluid, zgll_fluid;
    std::vector<std::vector<std::vector<double>>> sgll_solid, zgll_solid;

    double hmin_glob, hmax_glob;
    double min_distance_dim;
    double min_distance_nondim;

    double char_time_max;
    int char_time_max_globel;
    double char_time_max_rad, char_time_max_theta;
    double char_time_min;
    int char_time_min_globel;
    double char_time_min_rad, char_time_min_theta;

    DataGllMesh() = default;
    ~DataGllMesh() = default;

    void allocateSgll(int x, int y, int z) {
        sgll.resize(x, std::vector<std::vector<double>>(y, std::vector<double>(z)));
    }

    // Similar allocation functions can be defined for zgll, sgll_fluid, etc.
};

#endif // DATA_GLLMESH_H