#include <iostream>
#include <cmath> // For fabs (not used in this simple example, but included for completeness)

// Function to calculate the square of a number
float square(float x) {
    return x * x;
}

// Function to perform and print the results of the energy calculations
void test_energy_calculations() {
    const float mass = 3.00;
    const float gravity = 9.81;
    const float height = 4.20;
    const float velocity = 4.00;

    float potential_energy = mass * gravity * height;
    float kinetic_energy = 0.5 * mass * square(velocity);
    float total_energy = potential_energy + kinetic_energy;

    std::cout << "Testing Energy Calculations:" << std::endl;
    std::cout << "Potential Energy: " << potential_energy << std::endl;
    std::cout << "Kinetic Energy: " << kinetic_energy << std::endl;
    std::cout << "Total Energy: " << total_energy << std::endl;
    std::cout << "Tests Completed." << std::endl;
}

int main() {
    test_energy_calculations();
    return 0;
}