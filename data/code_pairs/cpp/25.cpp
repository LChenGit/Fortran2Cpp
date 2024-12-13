// Filename: DLA_WWADDW.cpp
#include <vector>

void DLA_WWADDW(int N, std::vector<double>& X, std::vector<double>& Y, const std::vector<double>& W) {
    for (int i = 0; i < N; ++i) {
        X[i] += W[i];
        // Y[i] remains unchanged based on the operations given in the original question
    }
}