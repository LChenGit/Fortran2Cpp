#include <cmath>

void iau_PAS(double AL, double AP, double BL, double BP, double &THETA) {
    double DL, X, Y;

    DL = BL - AL;
    Y = std::sin(DL) * std::cos(BP);
    X = std::sin(BP) * std::cos(AP) - std::cos(BP) * std::sin(AP) * std::cos(DL);

    if (X != 0.0 || Y != 0.0) {
        THETA = std::atan2(Y, X);
    } else {
        THETA = 0.0;
    }
}