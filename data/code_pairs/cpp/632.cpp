#include <iostream>
#include <vector>
#include <complex>

void zflmconj(int lmax, const std::vector<std::complex<double>>& zflm1, std::vector<std::complex<double>>& zflm2) {
    int lm1, lm2;
    std::complex<double> z1;

    zflm2.resize(zflm1.size());

    for (int l = 0; l <= lmax; ++l) {
        lm1 = l*l;
        lm2 = (l + 1)*(l + 1);
        for (int m = -l; m < 0; ++m) {
            lm1 += 1;
            lm2 -= 1;
            z1 = zflm1[lm1 - 1]; // Adjust for 0-based indexing
            zflm2[lm1 - 1] = std::conj(zflm1[lm2 - 1]);
            zflm2[lm2 - 1] = std::conj(z1);
            if (m % 2 != 0) {
                zflm2[lm1 - 1] = -zflm2[lm1 - 1];
                zflm2[lm2 - 1] = -zflm2[lm2 - 1];
            }
        }
        if (l != 0) {
            lm1 += 1;
            zflm2[lm1 - 1] = std::conj(zflm1[lm1 - 1]); // Adjust for 0-based indexing
        }
    }
}