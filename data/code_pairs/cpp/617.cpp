#include <iostream>
#include <cmath>

void cdiv(float ar, float ai, float br, float bi, float &cr, float &ci) {
    float s, ars, ais, brs, bis;
    s = fabs(br) + fabs(bi);
    ars = ar / s;
    ais = ai / s;
    brs = br / s;
    bis = bi / s;
    s = brs*brs + bis*bis;
    cr = (ars*brs + ais*bis) / s;
    ci = (ais*brs - ars*bis) / s;
}

int main() {
    float ar = 5.0f, ai = 3.0f, br = 2.0f, bi = 4.0f, cr, ci;

    // Test case 1
    cdiv(ar, ai, br, bi, cr, ci);
    std::cout << "Test Case 1: CR=" << cr << " CI=" << ci << std::endl;

    return 0;
}