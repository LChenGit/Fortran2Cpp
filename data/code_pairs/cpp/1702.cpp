// vla_primitives.cpp
#include <vector>
#include <complex>
#include <iostream>

int main() {
    // Define three-dimensional vector (VLA equivalents) for different data types
    std::vector<std::vector<std::vector<int>>> intVla(11, std::vector<std::vector<int>>(22, std::vector<int>(33)));
    std::vector<std::vector<std::vector<float>>> realVla(11, std::vector<std::vector<float>>(22, std::vector<float>(33)));
    std::vector<std::vector<std::vector<std::complex<float>>>> complexVla(11, std::vector<std::vector<std::complex<float>>>(22, std::vector<std::complex<float>>(33)));
    std::vector<std::vector<std::vector<bool>>> logicalVla(11, std::vector<std::vector<bool>>(22, std::vector<bool>(33)));
    std::vector<std::vector<std::vector<char>>> charactervla(11, std::vector<std::vector<char>>(22, std::vector<char>(33)));

    // Assignment
    for (int i = 0; i < 11; ++i) {
        for (int j = 0; j < 22; ++j) {
            for (int k = 0; k < 33; ++k) {
                intVla[i][j][k] = 1;
                realVla[i][j][k] = 3.14f;
                complexVla[i][j][k] = std::complex<float>(2.0, -3.0);
                logicalVla[i][j][k] = true;
                charactervla[i][j][k] = 'K'; // ASCII value of 75 is 'K'
            }
        }
    }

    // Specific Assignment
    intVla[4][4][4] = 42;
    realVla[4][4][4] = 4.13f;
    complexVla[4][4][4] = std::complex<float>(-3.0, 2.0);
    logicalVla[4][4][4] = false;
    charactervla[4][4][4] = 'X';

    return 0;
}