#include <iostream>

void zmlt(double ar, double ai, double br, double bi, double& cr, double& ci) {
    double ca = ar * br - ai * bi;
    double cb = ar * bi + ai * br;
    cr = ca;
    ci = cb;
}