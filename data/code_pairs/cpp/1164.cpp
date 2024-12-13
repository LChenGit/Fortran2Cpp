#include <cmath> // For sqrt(), atan2()

void sla_DC62S(const double V[6], double& A, double& B, double& R, double& AD, double& BD, double& RD) {
    double X, Y, Z, XD, YD, ZD, RXY2, RXY, R2, XYP;

    X = V[0];
    Y = V[1];
    Z = V[2];
    XD = V[3];
    YD = V[4];
    ZD = V[5];

    RXY2 = X * X + Y * Y;
    R2 = RXY2 + Z * Z;

    if (R2 == 0.0) {
        X = XD;
        Y = YD;
        Z = ZD;
        RXY2 = X * X + Y * Y;
        R2 = RXY2 + Z * Z;
    }

    RXY = sqrt(RXY2);
    XYP = X * XD + Y * YD;
    if (RXY2 != 0.0) {
        A = atan2(Y, X);
        B = atan2(Z, RXY);
        AD = (X * YD - Y * XD) / RXY2;
        BD = (ZD * RXY2 - Z * XYP) / (R2 * RXY);
    } else {
        A = 0.0;
        if (Z != 0.0) {
            B = atan2(Z, RXY);
        } else {
            B = 0.0;
        }
        AD = 0.0;
        BD = 0.0;
    }

    R = sqrt(R2);
    if (R != 0.0) {
        RD = (XYP + Z * ZD) / R;
    } else {
        RD = 0.0;
    }
}