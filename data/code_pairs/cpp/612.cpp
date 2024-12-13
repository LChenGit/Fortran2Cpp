#include <iostream>
#include <cmath>

const int npde = 2;
const int mtri = 3;
const int nepn = npde + 2;

void scheck(double y[][nepn], int kvec, int& errc, double dxymin, double dxy0[], double dxy1[], double dxy[]) {
    for (int j = 0; j < mtri; ++j) {
        if (kvec == 1) {
            dxy1[j] = dxy[j];
        }

        double x0 = y[j][0];
        double y0 = y[j][1];
        double x1 = y[j][0];
        double y1 = y[j][1];
        double x2 = y[j][0];
        double y2 = y[j][1];
        dxy[j] = std::abs((x0 - x2) * (y1 - y0) - (x1 - x0) * (y0 - y2));
        if (dxy[j] < dxymin) {
            errc = 1;
            return;
        }

        if (kvec == 0) {
            dxy0[j] = dxy[j];
        }
    }
    errc = 0;
}