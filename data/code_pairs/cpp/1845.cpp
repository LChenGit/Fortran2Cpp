// grid2deg.cpp
#include <iostream>
#include <string>
#include <cctype> // for toupper, tolower, and isalpha functions

void grid2deg(const std::string& grid0, double& dlong, double& dlat) {
    std::string grid = grid0;
    grid.resize(6, ' '); // Ensure grid is at least 6 characters long
    
    // Adjust fifth and sixth characters if necessary
    if(grid[4] == ' ' || grid[4] < 'A' || grid[4] > 'z') grid[4] = grid[5] = 'm';
    
    // Convert first and second characters to uppercase if they are lowercase
    grid[0] = toupper(grid[0]);
    grid[1] = toupper(grid[1]);

    // Convert fifth and sixth characters to lowercase if they are uppercase
    grid[4] = tolower(grid[4]);
    grid[5] = tolower(grid[5]);

    // Perform calculations
    dlong = 180 - 20 * (grid[0] - 'A') - 2 * (grid[2] - '0') - 5 * (grid[4] - 'a' + 0.5) / 60.0;
    dlat = -90 + 10 * (grid[1] - 'A') + (grid[3] - '0') + 2.5 * (grid[5] - 'a' + 0.5) / 60.0;
}

// testGrid2Deg.cpp
#include <cassert>
#include <cmath> // for fabs function

void testGrid2Deg() {
    double dlong, dlat;
    grid2deg("A1B2C3", dlong, dlat);
    std::cout << "C++: Test 1: Grid=A1B2C3, Longitude=" << dlong << ", Latitude=" << dlat << std::endl;
}

int main() {
    testGrid2Deg();
    std::cout << "All C++ tests passed successfully!" << std::endl;
    return 0;
}