#ifndef NETWORKS_H
#define NETWORKS_H

#include <vector>
#include <cmath>
#include <iostream>

class Networks {
public:
    void normal(std::vector<std::vector<std::vector<double>>>& arr);
    double calc_distance(const std::vector<std::vector<double>>& laplacian, int node1, int node2);
};

#endif