#include <cmath>
#include <iostream>
#include <iomanip>

void hcrit(double xflow, double rho, double b, double theta, double dg, double sqrts0, double& hk) {
    const double smallThetaThreshold = 1e-10;
    const double dhkThreshold = 1e-3;

    hk = std::pow((std::pow(xflow / (rho * b), 2) / (dg * sqrts0)), 1.0 / 3.0);

    if (std::abs(theta) < smallThetaThreshold) return;

    double tth = std::tan(theta);
    double c1 = rho * rho * dg * sqrts0;
    double xflow2 = xflow * xflow;
    double A, dBBdh, dAdh, BB, dhk;

    do {
        A = hk * (b + hk * tth);
        dBBdh = 2.0 * tth;
        dAdh = b + hk * dBBdh;
        BB = dAdh;
        dhk = (xflow2 * BB - c1 * std::pow(A, 3)) / (xflow2 * dBBdh - 3.0 * c1 * A * A * dAdh);

        if (std::abs(dhk) / hk < dhkThreshold) break;

        hk -= dhk;
    } while (true);
}

int main() {
    double xflow = 1.0;
    double rho = 1.0;
    double b = 1.0;
    double theta = 0.1;
    double dg = 1.0;
    double sqrts0 = 1.0;
    double hk;

    hcrit(xflow, rho, b, theta, dg, sqrts0, hk);

    std::cout << "hk = " << std::setprecision(8) << hk << std::endl;

    return 0;
}