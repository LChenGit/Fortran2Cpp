#include <vector>
#include <numeric>
#include <iostream>

class MEANFLUXES__genmod {
public:
    static double MEANFLUXES(const std::vector<double>& fluxes) {
        if(fluxes.empty()) return 0.0; // Handle empty vector case
        double sum = std::accumulate(fluxes.begin(), fluxes.end(), 0.0);
        return sum / fluxes.size();
    }
};