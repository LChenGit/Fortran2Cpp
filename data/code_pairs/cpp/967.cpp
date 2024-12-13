#ifndef FLOOD_H
#define FLOOD_H

#include <vector>
#include <cmath>
#include <algorithm>

void flood(const std::vector<std::vector<double>>& zslice,
           const std::vector<std::vector<int>>& wet,
           const std::vector<std::vector<int>>& dry,
           const std::vector<std::vector<double>>& x,
           const std::vector<std::vector<double>>& y,
           double dmax,
           std::vector<std::vector<double>>& flooded_zslice,
           int im, int jm, int nbwet, int nbdry) {
    
    flooded_zslice = zslice;
    std::vector<double> d(nbwet);
    
    for (int n = 0; n < nbdry; ++n) {
        int idry = dry[n][0] - 1;
        int jdry = dry[n][1] - 1;
        
        for (int m = 0; m < nbwet; ++m) {
            int iwet = wet[m][0] - 1;
            int jwet = wet[m][1] - 1;
            
            d[m] = std::sqrt((x[idry][jdry] - x[iwet][jwet]) * (x[idry][jdry] - x[iwet][jwet]) +
                             (y[idry][jdry] - y[iwet][jwet]) * (y[idry][jdry] - y[iwet][jwet]));
        }
        
        auto it = std::min_element(d.begin(), d.end());
        int dmin_idx = std::distance(d.begin(), it);
        
        if (dmax == 0 || *it <= dmax) {
            int iclose = wet[dmin_idx][0] - 1;
            int jclose = wet[dmin_idx][1] - 1;
            flooded_zslice[idry][jdry] = zslice[iclose][jclose];
        }
    }
}

#endif