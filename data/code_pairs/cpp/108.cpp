#include <iostream>

const int nLons = 2, nLats = 2, nAlts = 2;
double eTemperature[nLons][nLats][nAlts];
double Temperature[nLons][nLats][nAlts];
double TempUnit[nLons][nLats][nAlts];
double Altitude_GB[nLons][nLats][nAlts] = {{{1000.0, 1500.0}, {2000.0, 2500.0}},
                                           {{3000.0, 3500.0}, {4000.0, 8000.0}}};

void calc_electron_temperature(double eTemp[nLons][nLats][nAlts], double Temp[nLons][nLats][nAlts], double TUnit[nLons][nLats][nAlts], double Alt_GB[nLons][nLats][nAlts], int Lons, int Lats, int Alts, int Block) {
    for (int iLon = 0; iLon < Lons; ++iLon) {
        for (int iLat = 0; iLat < Lats; ++iLat) {
            for (int iAlt = 0; iAlt < Alts; ++iAlt) {
                double Alt = Alt_GB[iLon][iLat][iAlt] / 1000.0;
                if (Alt < 130.0) {
                    eTemp[iLon][iLat][iAlt] = Temp[iLon][iLat][iAlt] * TUnit[iLon][iLat][iAlt];
                } else {
                    eTemp[iLon][iLat][iAlt] = 0.0;
                }
            }
        }
    }
}

int main() {
    // Initialize Temperature and TempUnit with some values for demonstration
    for (int i = 0; i < nLons; ++i) {
        for (int j = 0; j < nLats; ++j) {
            for (int k = 0; k < nAlts; ++k) {
                Temperature[i][j][k] = 20.0;
                TempUnit[i][j][k] = 1.0;
            }
        }
    }

    int iBlock = 1; // Arbitrary block number for demonstration
    calc_electron_temperature(eTemperature, Temperature, TempUnit, Altitude_GB, nLons, nLats, nAlts, iBlock);

    // Print the eTemperature array for demonstration
    std::cout << "C++ eTemperature:" << std::endl;
    for (int i = 0; i < nLons; ++i) {
        for (int j = 0; j < nLats; ++j) {
            for (int k = 0; k < nAlts; ++k) {
                std::cout << "eTemperature(" << i << ", " << j << ", " << k << ") = " << eTemperature[i][j][k] << std::endl;
            }
        }
    }

    return 0;
}