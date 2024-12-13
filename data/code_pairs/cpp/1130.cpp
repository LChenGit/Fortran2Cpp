// slassq.cpp
#include <iostream>
#include <cmath>
#include <vector>

void SLASSQ(const size_t N, const float* X, const int INCX, float& SCALE, float& SUMSQ) {
    for (size_t IX = 0; IX < N * INCX; IX += INCX) {
        if (X[IX] != 0.0f) {
            float ABSXI = std::abs(X[IX]);
            if (SCALE < ABSXI) {
                SUMSQ = 1 + SUMSQ * std::pow(SCALE / ABSXI, 2);
                SCALE = ABSXI;
            } else {
                SUMSQ += std::pow(ABSXI / SCALE, 2);
            }
        }
    }
}

int main() {
    std::vector<float> x = {1.0f, 2.0f, -3.0f, 4.0f};  // Test array
    int incx = 1;
    float scale = 0.0f;
    float sumsq = 0.0f;

    SLASSQ(x.size(), x.data(), incx, scale, sumsq);

    std::cout << "Scale: " << scale << std::endl;
    std::cout << "SumSq: " << sumsq << std::endl;

    return 0;
}