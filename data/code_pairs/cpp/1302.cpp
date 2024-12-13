#ifndef TRILOC_HPP
#define TRILOC_HPP

#include <vector>

int triloc(double xp, double yp, const std::vector<double>& x, const std::vector<double>& y, const std::vector<std::vector<int>>& v, const std::vector<std::vector<int>>& e, int numtri);

#endif // TRILOC_HPP