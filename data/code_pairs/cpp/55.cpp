#include <cmath>
#include <iostream>

void DLAE2(double A, double B, double C, double& RT1, double& RT2) {
    const double ONE = 1.0;
    const double TWO = 2.0;
    const double HALF = 0.5;
    double SM, DF, ADF, TB, AB, ACMN, ACMX, RT;

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
        RT = ADF * std::sqrt(ONE + std::pow((AB / ADF), 2));
    } else if (ADF < AB) {
        RT = AB * std::sqrt(ONE + std::pow((ADF / AB), 2));
    } else {
        RT = AB * std::sqrt(TWO);
    }

    if (SM < 0) {
        RT1 = HALF * (SM - RT);
        RT2 = (ACMX / RT1) * ACMN - (B / RT1) * B;
    } else if (SM > 0) {
        RT1 = HALF * (SM + RT);
        RT2 = (ACMX / RT1) * ACMN - (B / RT1) * B;
    } else {
        RT1 = HALF * RT;
        RT2 = -HALF * RT;
    }
}

int main() {
    double A = 4.0, B = 1.0, C = 3.0, RT1, RT2;

    DLAE2(A, B, C, RT1, RT2);
    std::cout << "Test case 1: Eigenvalues should be 5 and 2." << std::endl;
    std::cout << "Computed eigenvalues: " << RT1 << " " << RT2 << std::endl;

    return 0;
}