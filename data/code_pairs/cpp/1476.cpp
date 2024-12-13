#include <iostream>
#include <cmath> // For fabs function

double stheta_sq(double x) {
    if (x <= -0.5) {
        return 0.0;
    } else if (x < 0.5) {
        return x + 0.5;
    } else {
        return 1.0;
    }
}