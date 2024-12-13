// prog.cpp
#include <iostream>
#include <cmath>
#include <iomanip>

void compute_vals(double vals[]) {
    vals[0] = 1.2;
    vals[1] = std::pow(vals[0], 2);
    vals[2] = std::pow(2, vals[1]);
    vals[3] = std::pow(vals[1], vals[2]);
}

int main() {
    const int size = 4;
    double vals[size];

    compute_vals(vals);

    for (int i = 0; i < size; ++i) {
        std::cout << std::fixed << std::setprecision(2) << std::setw(5) << vals[i];
    }
    std::cout << std::endl;

    return 0;
}