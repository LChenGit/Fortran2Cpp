#include <iostream>
#include <cmath> // for std::abs

float chgtemp(float stationelev, float cellelev) {
    return 0.0065 * (stationelev - cellelev);
}