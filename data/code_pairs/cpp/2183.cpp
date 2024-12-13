#include <iostream>
#include <cmath>

const double D2PI = 6.283185307179586476925287;

double iau_FASA03(double T) {
    return std::fmod(0.874016757 + 21.3299104960 * T, D2PI);
}

int main() {
    double T = 0.5; // Example input

    // Call the function and print the result
    std::cout << "iau_FASA03(" << T << ") = " << iau_FASA03(T) << std::endl;

    return 0;
}