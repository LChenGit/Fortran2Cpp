#include <iostream>
#include <random>
#include <cassert>

int main() {
    const int size = 123;
    float array[size];

    // Set up random number generation
    std::random_device rd;  // Obtain a random number from hardware
    std::mt19937 gen(rd()); // Seed the generator
    std::uniform_real_distribution<> distr(0.0, 1.0); // Define the range

    // Initialize the array with random numbers and perform a basic test
    for (int i = 0; i < size; ++i) {
        array[i] = distr(gen);
        // Use assert to check each value is within the expected range
        assert(array[i] >= 0.0 && array[i] <= 1.0);
    }

    std::cout << "Test passed: All values are within the range [0.0, 1.0]." << std::endl;

    return 0;
}