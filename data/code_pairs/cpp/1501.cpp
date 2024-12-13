#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

extern "C" {
    int NGLQSH(int lmax);
    void PreGLQ(double lower, double upper, int nlat, double* zero, double* w);
}

void GLQGridCoord(std::vector<double>& latglq, std::vector<double>& longlq, int lmax, int& nlat, int& nlong) {
    const double pi = std::acos(-1.0);
    nlat = NGLQSH(lmax);
    nlong = 2 * lmax + 1;

    std::vector<double> zero(nlat), w(nlat);
    PreGLQ(-1.0, 1.0, nlat, zero.data(), w.data());

    latglq.resize(nlat);
    for (int i = 0; i < nlat; ++i) {
        latglq[i] = std::asin(zero[i]) * 180.0 / pi;
    }

    longlq.resize(nlong);
    for (int i = 0; i < nlong; ++i) {
        longlq[i] = 360.0 * i / nlong;
    }
}

int main() {
    int lmax = 3;
    int nlat, nlong;
    std::vector<double> latglq, longlq;

    GLQGridCoord(latglq, longlq, lmax, nlat, nlong);

    std::cout << "Latitude: ";
    for (const auto& lat : latglq) {
        std::cout << lat << " ";
    }
    std::cout << "\nLongitude: ";
    for (const auto& lon : longlq) {
        std::cout << lon << " ";
    }
    std::cout << std::endl;

    return 0;
}