#include <iostream>
#include <complex>
#include <cassert>

void ZSWAP(int N, std::complex<double>* ZX, int INCX, std::complex<double>* ZY, int INCY) {
    if (N <= 0) return;

    std::complex<double> ZTEMP;
    int IX, IY;

    if (INCX == 1 && INCY == 1) {
        for (int I = 0; I < N; ++I) {
            ZTEMP = ZX[I];
            ZX[I] = ZY[I];
            ZY[I] = ZTEMP;
        }
    } else {
        IX = 0;
        IY = 0;
        if (INCX < 0) IX = (-N + 1) * INCX;
        if (INCY < 0) IY = (-N + 1) * INCY;
        for (int I = 0; I < N; ++I) {
            ZTEMP = ZX[IX];
            ZX[IX] = ZY[IY];
            ZY[IY] = ZTEMP;
            IX += INCX;
            IY += INCY;
        }
    }
}

int main() {
    // Test 1: Positive N, INCX = INCY = 1
    std::complex<double> ZX1[3] = {{1, 1}, {2, 2}, {3, 3}};
    std::complex<double> ZY1[3] = {{-1, -1}, {-2, -2}, {-3, -3}};
    ZSWAP(3, ZX1, 1, ZY1, 1);
    for(int i = 0; i < 3; i++) {
        assert(ZX1[i] == std::complex<double>(-i-1, -i-1));
        assert(ZY1[i] == std::complex<double>(i+1, i+1));
    }

    // Test 2: Zero N
    std::complex<double> ZX2[3] = {{1, 1}, {2, 2}, {3, 3}};
    std::complex<double> ZY2[3] = {{-1, -1}, {-2, -2}, {-3, -3}};
    ZSWAP(0, ZX2, 1, ZY2, 1);
    // No change expected, no assert needed

    // Test 3: Negative INCX and INCY
    std::complex<double> ZX3[3] = {{3, 3}, {2, 2}, {1, 1}};
    std::complex<double> ZY3[3] = {{-3, -3}, {-2, -2}, {-1, -1}};
    ZSWAP(3, ZX3, -1, ZY3, -1);
    for(int i = 0; i < 3; i++) {
        assert(ZX3[i] == std::complex<double>(-3+i, -3+i));
        assert(ZY3[i] == std::complex<double>(3-i, 3-i));
    }

    std::cout << "All tests passed." << std::endl;

    return 0;
}