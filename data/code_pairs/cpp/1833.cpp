#ifndef LOOP10_H
#define LOOP10_H

#include <vector>

void loop10_F90(int N, std::vector<double>& x, const std::vector<double>& a, const std::vector<double>& b, const std::vector<double>& c, double u);
void loop10_F90Overhead(int N, std::vector<double>& x, const std::vector<double>& a, const std::vector<double>& b, const std::vector<double>& c, double u);

#endif // LOOP10_H