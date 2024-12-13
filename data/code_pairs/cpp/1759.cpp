#include <cmath>
#include <vector>
#include <iostream>
#include <iomanip>

void compute_v_n(double phi, double psi, double theta, double W, double V, double U, std::vector<double>& v_n) {
    v_n[0] = (std::cos(phi) * std::cos(psi) * std::sin(theta) + std::sin(phi) * std::sin(psi)) * W +
             (std::sin(phi) * std::cos(psi) * std::sin(theta) - std::cos(phi) * std::sin(psi)) * V +
             std::cos(psi) * std::cos(theta) * U;

    v_n[1] = (std::cos(phi) * std::sin(psi) * std::sin(theta) - std::sin(phi) * std::cos(psi)) * W +
             (std::sin(phi) * std::sin(psi) * std::sin(theta) + std::cos(phi) * std::cos(psi)) * V +
             std::sin(psi) * std::cos(theta) * U;

    v_n[2] = std::cos(phi) * std::cos(theta) * W + std::sin(phi) * std::cos(theta) * V - std::sin(theta) * U;
}

int main() {
    // Define test variables
    double phi = 0.5, psi = 0.25, theta = 0.75, W = 1.0, V = 2.0, U = 3.0;
    std::vector<double> v_n(3);

    // Compute v_n
    compute_v_n(phi, psi, theta, W, V, U, v_n);

    // Output results
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "v_n[0] = " << v_n[0] << std::endl;
    std::cout << "v_n[1] = " << v_n[1] << std::endl;
    std::cout << "v_n[2] = " << v_n[2] << std::endl;

    return 0;
}