#include <iostream>
#include <vector>

// Function declaration
void uboun(double& boun, const std::vector<double>& coords);

int main() {
    double boun;
    std::vector<double> coords;

    // Test case 1
    coords = {0.0, 0.0, 0.0}; // Should result in boun=150.0
    uboun(boun, coords);
    std::cout << "Coords: (" << coords[0] << ", " << coords[1] << ", " << coords[2] << ") Boun: " << boun << std::endl;

    // Test case 2
    coords = {0.0, 1.0, 0.0}; // Should result in boun=112.5
    uboun(boun, coords);
    std::cout << "Coords: (" << coords[0] << ", " << coords[1] << ", " << coords[2] << ") Boun: " << boun << std::endl;

    // Test case 3
    coords = {0.0, 2.0, 0.0}; // Should result in boun=0.0
    uboun(boun, coords);
    std::cout << "Coords: (" << coords[0] << ", " << coords[1] << ", " << coords[2] << ") Boun: " << boun << std::endl;

    return 0;
}

// Function definition
void uboun(double& boun, const std::vector<double>& coords) {
    boun = 300.0 / 8.0 * (4.0 - coords[1] * coords[1]);
}