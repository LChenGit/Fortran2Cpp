#include <iostream>

// Mock-up function - assumed to be implemented or declared in "gsw_mod_toolbox.hpp"
double gsw_gibbs_ice(int n0, int n1, double t, double p) {
    return t * p * 0.0001;
}

double gsw_specvol_ice(double t, double p) {
    return gsw_gibbs_ice(0, 1, t, p);
}