#include <cmath>

void LBTORD(double& LRAD, double& BRAD, double& RA, double& DEC) {
    const double PI = 3.1415926535898;
    const double TWOPI = 2.0 * PI;
    const double CON27 = 27.40 * PI / 180.0;
    const double CON33 = 33.00 * PI / 180.0;
    const double CON192 = 192.25 * PI / 180.0;

    double X, Y, SINA;

    SINA = std::sin(BRAD) * std::sin(CON27) + std::cos(BRAD) * std::cos(CON27) * std::sin(LRAD - CON33);
    X = std::cos(BRAD) * std::cos(LRAD - CON33);
    Y = std::sin(BRAD) * std::cos(CON27) - std::cos(BRAD) * std::sin(CON27) * std::sin(LRAD - CON33);

    RA = std::atan2(X, Y) + CON192;
    DEC = std::asin(SINA);
    
    RA = std::fmod(RA + TWOPI, TWOPI);
}