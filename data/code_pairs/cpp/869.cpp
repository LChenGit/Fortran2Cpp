#include <cmath>
#include <utility>
#include <random>

std::pair<double, double> boxMuller() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_real_distribution<> dis(0.0, 1.0);

    double u1 = dis(gen);
    double u2 = dis(gen);
    double r = sqrt(-2.0 * log(u1));
    double theta = 2.0 * M_PI * u2;
    double x = r * cos(theta);
    double y = r * sin(theta);

    return std::make_pair(x, y);
}