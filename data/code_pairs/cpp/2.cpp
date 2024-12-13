#include <iostream>
#include <complex>

void CLAPMT(bool forwrd, int m, int n, std::complex<float>* X, int ldx, int* K) {
    if (n <= 1) {
        return;
    }

    for (int i = 0; i < n; ++i) {
        K[i] = -K[i];
    }

    if (forwrd) {
        for (int i = 0; i < n; ++i) {
            if (K[i] > 0) continue;

            int j = i;
            K[j] = -K[j];
            int in = K[j] - 1;

            while (true) {
                if (K[in] > 0) break;

                for (int ii = 0; ii < m; ++ii) {
                    std::complex<float> temp = X[ii + j * ldx];
                    X[ii + j * ldx] = X[ii + in * ldx];
                    X[ii + in * ldx] = temp;
                }

                K[in] = -K[in];
                j = in;
                in = K[in] - 1;
            }
        }
    } else {
        for (int i = 0; i < n; ++i) {
            if (K[i] > 0) continue;

            K[i] = -K[i];
            int j = K[i] - 1;

            while (true) {
                if (j == i) break;

                for (int ii = 0; ii < m; ++ii) {
                    std::complex<float> temp = X[ii + i * ldx];
                    X[ii + i * ldx] = X[ii + j * ldx];
                    X[ii + j * ldx] = temp;
                }

                K[j] = -K[j];
                j = K[j] - 1;
            }
        }
    }
}