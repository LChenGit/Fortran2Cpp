// cntab2.cpp
#include <iostream>
#include <vector>
#include <cmath>

void cntab2(const std::vector<std::vector<int>>& NN, int NI, int NJ,
            double& H, double& HX, double& HY, double& HYGX, double& HXGY,
            double& UYGX, double& UXGY, double& UXY) {
    const double TINY = 1.E-30;
    std::vector<double> SUMI(NI, 0.0), SUMJ(NJ, 0.0);
    double SUM = 0.0;
    
    for (int I = 0; I < NI; ++I) {
        for (int J = 0; J < NJ; ++J) {
            SUMI[I] += NN[I][J];
            SUM += NN[I][J];
        }
    }
    
    for (int J = 0; J < NJ; ++J) {
        for (int I = 0; I < NI; ++I) {
            SUMJ[J] += NN[I][J];
        }
    }
    
    HX = 0.0;
    for (int I = 0; I < NI; ++I) {
        if (SUMI[I] != 0) {
            double P = SUMI[I] / SUM;
            HX -= P * log(P);
        }
    }
    
    HY = 0.0;
    for (int J = 0; J < NJ; ++J) {
        if (SUMJ[J] != 0) {
            double P = SUMJ[J] / SUM;
            HY -= P * log(P);
        }
    }
    
    H = 0.0;
    for (int I = 0; I < NI; ++I) {
        for (int J = 0; J < NJ; ++J) {
            if (NN[I][J] != 0) {
                double P = NN[I][J] / SUM;
                H -= P * log(P);
            }
        }
    }
    
    HYGX = H - HX;
    HXGY = H - HY;
    UYGX = (HY - HYGX) / (HY + TINY);
    UXGY = (HX - HXGY) / (HX + TINY);
    UXY = 2.0 * (HX + HY - H) / (HX + HY + TINY);
}

int main() {
    std::vector<std::vector<int>> NN = {{10, 20}, {30, 40}};
    int NI = 2, NJ = 2;
    double H, HX, HY, HYGX, HXGY, UYGX, UXGY, UXY;
    
    cntab2(NN, NI, NJ, H, HX, HY, HYGX, HXGY, UYGX, UXGY, UXY);
    
    std::cout << "H: " << H << std::endl;
    std::cout << "HX: " << HX << std::endl;
    std::cout << "HY: " << HY << std::endl;
    std::cout << "HYGX: " << HYGX << std::endl;
    std::cout << "HXGY: " << HXGY << std::endl;
    std::cout << "UYGX: " << UYGX << std::endl;
    std::cout << "UXGY: " << UXGY << std::endl;
    std::cout << "UXY: " << UXY << std::endl;

    return 0;
}