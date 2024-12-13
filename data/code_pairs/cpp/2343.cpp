#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <algorithm>

void cirfil(float xcen, float ycen, float rad, float rval, int ixext, int iyext, std::vector<std::vector<float>>& array) {
    int ixcen = static_cast<int>(std::round(xcen));
    int iycen = static_cast<int>(std::round(ycen));
    int irad = static_cast<int>(std::round(rad));
    int jmin = std::max(1, iycen - irad);
    int jmax = std::min(iyext, iycen + irad);
    int imin = std::max(1, ixcen - irad);
    int imax = std::min(ixext, ixcen + irad);

    for (int j = jmin; j <= jmax; ++j) {
        for (int i = imin; i <= imax; ++i) {
            float kr = std::sqrt(static_cast<float>((i - ixcen) * (i - ixcen) + (j - iycen) * (j - iycen)));
            if (kr <= rad) {
                array[i - 1][j - 1] = rval; // Adjust indices for 0-based indexing in C++
            }
        }
    }
}

void printArray(const std::vector<std::vector<float>>& array) {
    for (const auto& row : array) {
        for (const auto& elem : row) {
            std::cout << std::fixed << std::setprecision(1) << elem << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    const int IXEXT = 10;
    const int IYEXT = 10;

    std::vector<std::vector<float>> array(IXEXT, std::vector<float>(IYEXT, 0.0f));

    cirfil(5.0f, 5.0f, 3.0f, 1.0f, IXEXT, IYEXT, array);

    printArray(array);

    return 0;
}