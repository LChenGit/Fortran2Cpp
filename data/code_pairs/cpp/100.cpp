#include <cmath>
#include <iostream>
#include <cassert>

void ODE2(double A, double B, double C, double& RT1, double& RT2) {
    const double ONE = 1.0;
    const double TWO = 2.0;
    const double ZERO = 0.0;
    const double HALF = 0.5;
    double AB, ACMN, ACMX, ADF, DF, RT, SM, TB;

    SM = A + C;
    DF = A - C;
    ADF = std::abs(DF);
    TB = B + B;
    AB = std::abs(TB);
    if (std::abs(A) > std::abs(C)) {
        ACMX = A;
        ACMN = C;
    } else {
        ACMX = C;
        ACMN = A;
    }
    if (ADF > AB) {
        RT = ADF * std::sqrt(ONE + (AB / ADF) * (AB / ADF));
    } else if (ADF < AB) {
        RT = AB * std::sqrt(ONE + (ADF / AB) * (ADF / AB));
    } else {
        RT = AB * std::sqrt(TWO);
    }
    if (SM < ZERO) {
        RT1 = HALF * (SM - RT);
        RT2 = (ACMX / RT1) * ACMN - (B / RT1) * B;
    } else if (SM > ZERO) {
        RT1 = HALF * (SM + RT);
        RT2 = (ACMX / RT1) * ACMN - (B / RT1) * B;
    } else {
        RT1 = HALF * RT;
        RT2 = -HALF * RT;
    }
}

int main() {
    double A = 1.0, B = 2.0, C = 3.0, RT1, RT2;
    ODE2(A, B, C, RT1, RT2);

    std::cout << "RT1: " << RT1 << ", RT2: "RT2" << std::endl;

    return 0;
}