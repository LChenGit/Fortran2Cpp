// main.cpp
#include <iostream>
#include <cmath>

const double rad = 3.14159265358979323846 / 180.0;

void updatePbias(double input, double& pbias) {
    pbias = std::pow(std::cos(input * rad), 0.576);
}

int main() {
    double pbias = 0.0;
    double input_angle = 45.0;

    updatePbias(input_angle, pbias);

    std::cout << "Updated pbias: " << pbias << std::endl;
    return 0;
}