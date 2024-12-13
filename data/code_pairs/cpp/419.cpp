// writecvg.cpp
#include <iostream>
#include <iomanip>
#include <cmath>

void writecvg(int istep, int iinc, int icutb, int iit, int ne, int ne0, double* ram, double* qam, double* cam, double* uam, int ithermal) {
    double residforce, corrdisp, residflux, corrtemp;

    if (ithermal == 2) {
        residforce = 0.0;
        corrdisp = 0.0;
    } else {
        if (std::abs(qam[0]) < 1e-30) {
            if (std::abs(ram[0]) < 1e-30) {
                residforce = 1e-30;
            } else {
                residforce = 1e30;
            }
        } else {
            residforce = ram[0] / qam[0] * 100.0;
        }

        if (std::abs(uam[0]) < 1e-30) {
            if (std::abs(cam[0]) < 1e-30) {
                corrdisp = 1e-30;
            } else {
                corrdisp = 1e30;
            }
        } else {
            corrdisp = cam[0] / uam[0] * 100.0;
        }
    }

    if (ithermal <= 1) {
        residflux = 0.0;
        corrtemp = 0.0;
    } else {
        if (std::abs(qam[1]) < 1e-30) {
            if (std::abs(ram[1]) < 1e-30) {
                residflux = 1e-30;
            } else {
                residflux = 1e30;
            }
        } else {
            residflux = ram[1] / qam[1] * 100.0;
        }
        if (std::abs(uam[1]) < 1e-30) {
            if (std::abs(cam[1]) < 1e-30) {
                corrtemp = 1e-30;
            } else {
                corrtemp = 1e30;
            }
        } else {
            corrtemp = cam[1] / uam[1] * 100.0;
        }
    }

    std::cout << istep << ' ' << iinc << ' ' << icutb+1 << ' ' << iit << ' ' << ne-ne0 << ' '
              << std::scientific << std::setprecision(4) << residforce << ' ' << corrdisp << ' ' 
              << residflux << ' ' << corrtemp << std::endl;
}

int main() {
    int ne = 2;
    double ram[2] = {0.1, 0.2};
    double qam[2] = {0.1, 0.2};
    double cam[2] = {0.1, 0.2};
    double uam[2] = {0.1, 0.2};

    writecvg(1, 1, 0, 0, ne, 1, ram, qam, cam, uam, 0);
    writecvg(1, 1, 0, 0, ne, 1, ram, qam, cam, uam, 1);
    writecvg(1, 1, 0, 0, ne, 1, ram, qam, cam, uam, 2);

    return 0;
}