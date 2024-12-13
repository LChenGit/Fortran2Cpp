#include <iostream>
#include <cmath>
#include <cstdlib>

// Function to check if the norm is approximately 1
bool checkNorm(double theta) {
    double cosTheta = cos(theta);
    double sinTheta = sin(theta);
    double norm = sqrt(cosTheta * cosTheta + sinTheta * sinTheta);
    return std::abs(norm - 1.0) <= 1.0e-4;
}

int main() {
    double theta = 1.0; // Example angle in radians

    if (!checkNorm(theta)) {
        std::cerr << "Error: The norm of the vector is not approximately 1." << std::endl;
        std::exit(1); // Exiting with an error
    } else {
        std::cout << "Test passed for theta = " << theta << std::endl;
    }

    // The program can include more functionality or tests here

    return 0;
}