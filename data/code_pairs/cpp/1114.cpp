#include <iostream>
#include <vector>
#include <cmath>

void updateVectors(std::vector<double>& yv1, std::vector<double>& yv2,
                   const std::vector<double>& tiltc, const std::vector<double>& tilts,
                   const std::vector<std::vector<double>>& aaiv,
                   const std::vector<std::vector<double>>& bbiv,
                   const std::vector<double>& moidpsv) {
    size_t n = yv1.size();
    for (size_t j = 0; j < n; ++j) {
        for (size_t i = 0; i < n; ++i) {
            yv1[j] = yv1[j] + (tiltc[i] * bbiv[0][i] - tilts[i] * aaiv[0][i]) * moidpsv[j];
            yv2[j] = yv2[j] + (tiltc[i] * aaiv[0][i] + tilts[i] * bbiv[0][i]) * moidpsv[j];
        }
    }
}

int main() {
    std::vector<double> yv1(5, 0.0), yv2(5, 0.0);
    std::vector<double> tiltc = {0.1, 0.2, 0.3, 0.4, 0.5};
    std::vector<double> tilts = {0.05, 0.1, 0.15, 0.2, 0.25};
    std::vector<std::vector<double>> aaiv = {{0.2, 0.4, 0.6, 0.8, 1.0}};
    std::vector<std::vector<double>> bbiv = {{0.3, 0.6, 0.9, 1.2, 1.5}};
    std::vector<double> moidpsv = {1.0, 2.0, 3.0, 4.0, 5.0};

    updateVectors(yv1, yv2, tiltc, tilts, aaiv, bbiv, moidpsv);

    std::cout << "yv1: ";
    for (const auto& val : yv1) {
        std::cout << val << " ";
    }
    std::cout << "\nyv2: ";
    for (const auto& val : yv2) {
        std::cout << val << " ";
    }

    return 0;
}