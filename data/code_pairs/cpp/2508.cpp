#include <iostream>
#include <cmath>
#include <vector>
#include <cassert>

int IDAMAX(int N, const std::vector<double>& DX, int INCX) {
    if (N <= 0) return 0;
    int IDAMAX = 1;
    if (N == 1) return IDAMAX;
    double DMAX = std::abs(DX[0]);
    int IX = 0;
    
    if (INCX != 1) {
        if (INCX < 0) IX = (-N + 1) * INCX;
        DMAX = std::abs(DX[IX]);
        IX += INCX;
        for (int I = 2; I <= N; ++I) {
            double XMAG = std::abs(DX[IX]);
            if (XMAG > DMAX) {
                IDAMAX = I;
                DMAX = XMAG;
            }
            IX += INCX;
        }
    } else {
        for (int I = 1; I < N; ++I) {
            double XMAG = std::abs(DX[I]);
            if (XMAG > DMAX) {
                IDAMAX = I + 1;
                DMAX = XMAG;
            }
        }
    }
    return IDAMAX;
}

int main() {
    std::vector<double> dx = {1.0, 3.0, -5.0, 2.0, 4.0};
    int n = dx.size();
    int incx = 1;
    
    // Expected result: 3 (since | -5.0 | is the largest)
    int expected_result = 3;

    // Call the IDAMAX function
    int result = IDAMAX(n, dx, incx);

    // Print the result
    std::cout << "IDAMAX result: " << result << std::endl;

    // Verify the result
    assert(result == expected_result);
    
    std::cout << "Unit test passed!" << std::endl;

    return 0;
}