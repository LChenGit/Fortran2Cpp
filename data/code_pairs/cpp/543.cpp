#ifndef CORRECTFLUX_H
#define CORRECTFLUX_H

#include <vector>
#include <cstddef>

void correctflux(size_t nef, const std::vector<int>& ipnei, const std::vector<int>& neifa,
                 const std::vector<int>& neiel, std::vector<double>& flux,
                 const std::vector<std::vector<double>>& vfa, const std::vector<double>& advfa,
                 const std::vector<double>& area, const std::vector<std::vector<double>>& vel,
                 const std::vector<double>& alet, const std::vector<std::vector<int>>& ielfa,
                 const std::vector<double>& ale, const std::vector<int>& ifabou,
                 int nefa, int nefb, const std::vector<std::vector<double>>& xxnj,
                 const std::vector<std::vector<double>>& gradpcfa);

#endif // CORRECTFLUX_H