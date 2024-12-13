#include <cmath>
#include <iostream>

float SNRM2(int N, float* SX, int INCX) {
    int I, J, NEXT, NN;
    float CUTLO = 4.441e-16, CUTHI = 1.304e19, HITEST, SUM, XMAX, ZERO = 0.0e0, ONE = 1.0e0;

    if (N <= 0) {
        return ZERO;
    }

    NEXT = 15;
    SUM = ZERO;
    NN = N * INCX;
    I = 0; // Adjusted for 0-based indexing

    do {
        switch (NEXT) {
            case 15:
                if (fabs(SX[I]) > CUTLO) {
                    NEXT = 55;
                    continue;
                }
                NEXT = 20;
                XMAX = ZERO;
                [[fallthrough]];
            case 20:
                if (SX[I] == ZERO) {
                    NEXT = 65;
                    continue;
                }
                if (fabs(SX[I]) > CUTLO) {
                    NEXT = 55;
                    continue;
                }
                NEXT = 35;
                [[fallthrough]];
            case 25:
                I = J;
                NEXT = 40;
                SUM = (SUM / SX[I]) / SX[I];
                [[fallthrough]];
            case 30:
                XMAX = fabs(SX[I]);
                [[fallthrough]];
            case 35:
                if (fabs(SX[I]) > CUTLO) {
                    NEXT = 50;
                    continue;
                }
                [[fallthrough]];
            case 40:
                if (fabs(SX[I]) <= XMAX) {
                    NEXT = 45;
                    continue;
                }
                SUM = ONE + SUM * (XMAX / SX[I]) * (XMAX / SX[I]);
                XMAX = fabs(SX[I]);
                NEXT = 65;
                continue;
            case 45:
                SUM = SUM + (SX[I] / XMAX) * (SX[I] / XMAX);
                NEXT = 65;
                continue;
            case 50:
                SUM = (SUM * XMAX) * XMAX;
                [[fallthrough]];
            case 55:
                HITEST = CUTHI / static_cast<float>(N);
                for (J = I; J < NN; J += INCX) {
                    if (fabs(SX[J]) >= HITEST) {
                        NEXT = 25;
                        break;
                    }
                    SUM = SUM + SX[J] * SX[J];
                }
                if (J < NN) continue;
                return sqrt(SUM);
            case 65:
                I = I + INCX;
                if (I < NN) {
                    NEXT = 10;
                    continue;
                }
                return XMAX * sqrt(SUM);
        }
    } while (false);

    return 0; // Should never reach here
}