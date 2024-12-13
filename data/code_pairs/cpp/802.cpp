#include <iostream>
#include <vector>
#include <cmath>

void cor(int n, const double* x, const double* y, double& output) {
    double sxx = 0.0, sxy = 0.0, syy = 0.0;
    double xsum = 0.0, ysum = 0.0, xysum = 0.0;
    double x2sum = 0.0, y2sum = 0.0;
    double rn = static_cast<double>(n);

    for (int i = 0; i < n; ++i) {
        xsum += x[i];
        ysum += y[i];
        xysum += x[i] * y[i];
    }

    for (int i = 0; i < n; ++i) {
        x2sum += x[i] * x[i];
        y2sum += y[i] * y[i];
    }

    double xsum2 = xsum * xsum;
    double ysum2 = ysum * ysum;

    double cornum = xysum - ((xsum * ysum) / rn);
    double corden = sqrt((x2sum - (xsum2 / rn)) * (y2sum - (ysum2 / rn)));
    output = cornum / corden;
}

int main() {
    int n = 5;
    std::vector<double> x = {1.0, 2.0, 3.0, 4.0, 5.0};
    std::vector<double> y = {2.0, 4.0, 5.0, 6.0, 7.0};
    double output;

    cor(n, x.data(), y.data(), output);

    std::cout << "Correlation: " << output << std::endl;

    return 0;
}