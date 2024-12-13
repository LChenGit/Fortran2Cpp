#include <iostream>
#include <cmath>
#include <iomanip>

void recCell(float cell[6], float rCell[6]) {
    float casq, cbsq, ccsq, cba, albtgm, volume, xnum, den, temp;

    casq = std::pow(std::cos(cell[3]), 2);
    cbsq = std::pow(std::cos(cell[4]), 2);
    ccsq = std::pow(std::cos(cell[5]), 2);
    cba = cell[0] * cell[1] * cell[2];
    albtgm = std::cos(cell[3]) * std::cos(cell[4]) * std::cos(cell[5]);
    volume = cba * (std::sqrt(1.0f - casq - cbsq - ccsq + 2.0f * albtgm));

    rCell[0] = cell[1] * cell[2] * std::sin(cell[3]) / volume;
    rCell[1] = cell[0] * cell[2] * std::sin(cell[4]) / volume;
    rCell[2] = cell[0] * cell[1] * std::sin(cell[5]) / volume;

    xnum = std::cos(cell[4]) * std::cos(cell[5]) - std::cos(cell[3]);
    den = std::sin(cell[4]) * std::sin(cell[5]);
    temp = xnum / den;
    rCell[3] = std::acos(temp);

    xnum = std::cos(cell[3]) * std::cos(cell[5]) - std::cos(cell[4]);
    den = std::sin(cell[3]) * std::sin(cell[5]);
    temp = xnum / den;
    rCell[4] = std::acos(temp);

    xnum = std::cos(cell[3]) * std::cos(cell[4]) - std::cos(cell[5]);
    den = std::sin(cell[3]) * std::sin(cell[4]);
    temp = xnum / den;
    rCell[5] = std::acos(temp);
}

int main() {
    float cell[6] = {90.0f, 90.0f, 90.0f, 1.57079632679f, 1.57079632679f, 1.57079632679f}; // Example values
    float rCell[6];

    recCell(cell, rCell);

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "rCell values: ";
    for (int i = 0; i < 6; i++) {
        std::cout << rCell[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}