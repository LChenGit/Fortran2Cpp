#include <iostream>
#include <cmath>
#include <iomanip> // for std::setprecision

void cdiv(double ar, double ai, double br, double bi, double& cr, double& ci);

int main() {
    double ar = 3.0, ai = 4.0, br = 1.0, bi = -2.0, cr = 0.0, ci = 0.0;

    cdiv(ar, ai, br, bi, cr, ci);

    std::cout << std::fixed << std::setprecision(6); // Set precision for output
    std::cout << "Result: (cr, ci) = " << cr << ", " << ci << std::endl;

    return 0;
}

void cdiv(double ar, double ai, double br, double bi, double& cr, double& ci) {
    double s_inv, ars, ais, brs, bis;
    s_inv = 1.0 / ( std::abs(br) + std::abs(bi) );
    ars = ar * s_inv;
    ais = ai * s_inv;
    brs = br * s_inv;
    bis = bi * s_inv;
    s_inv = 1.0 / ( brs*brs + bis*bis );
    cr = (ars*brs + ais*bis) * s_inv;
    ci = (ais*brs - ars*bis) * s_inv;
}