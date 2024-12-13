#include <iostream>
#include <cmath>

const double D2R = 0.017453292519943;

void hlugProj(double phi0, double lambda0, double phi, double lambda, double& x, double& y) {
    double sin0 = std::sin(D2R * phi0);
    double cos0 = std::cos(D2R * phi0);
    double sinp = std::sin(D2R * phi);
    double cosp = std::cos(D2R * phi);
    double sind = std::sin(D2R * (lambda - lambda0));
    double cosd = std::cos(D2R * (lambda - lambda0));
    
    double denom = sin0 * sinp + cos0 * cosp * cosd;
    
    x = (cosp * sind) / denom;
    y = (cos0 * sinp - sin0 * cosp * cosd) / denom;
}

int main() {
    double phi0 = 45.0, lambda0 = 10.0, phi = 50.0, lambda = 20.0;
    double x, y;

    hlugProj(phi0, lambda0, phi, lambda, x, y);

    std::cout << "X: " << x << " Y: " << y << std::endl;

    return 0;
}