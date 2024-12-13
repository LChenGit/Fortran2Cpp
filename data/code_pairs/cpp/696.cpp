#include <vector>
#include <cmath>
#include <iostream>

void SLARRA(int n, const std::vector<float>& d, std::vector<float>& e, std::vector<float>& e2,
            float spltol, float tnrm, int& nsplit, std::vector<int>& isplit, int& info) {
    const float ZERO = 0.0f;
    float eabs, tmp1;
    info = 0;

    if (n <= 0) {
        return;
    }

    nsplit = 1;
    if (spltol < ZERO) {
        tmp1 = std::abs(spltol) * tnrm;
        for (int i = 0; i < n - 1; ++i) {
            eabs = std::abs(e[i]);
            if (eabs <= tmp1) {
                e[i] = ZERO;
                e2[i] = ZERO;
                isplit[nsplit - 1] = i + 1;
                nsplit++;
            }
        }
    } else {
        for (int i = 0; i < n - 1; ++i) {
            eabs = std::abs(e[i]);
            if (eabs <= spltol * std::sqrt(std::abs(d[i])) * std::sqrt(std::abs(d[i + 1]))) {
                e[i] = ZERO;
                e2[i] = ZERO;
                isplit[nsplit - 1] = i + 1;
                nsplit++;
            }
        }
    }
    isplit[nsplit - 1] = n;
}