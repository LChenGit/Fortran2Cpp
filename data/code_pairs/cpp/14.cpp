#include <iostream>
#include <cmath>

// Function to calculate the peak frequency of the JONSWAP spectrum
double jonswapPeakFrequency(double wspd, double fetch, double grav) {
    return wspd * std::sqrt(fetch / grav);
}

int main() {
    double grav = 9.81;
    double wspd = 10.0;  // Example wind speed (m/s)
    double fetch = 1e4;  // Example fetch (m)

    double calculated_peak_frequency = jonswapPeakFrequency(wspd, fetch, grav);
    std::cout << "Calculated Peak Frequency: " << calculated_peak_frequency << std::endl;

    return 0;
}