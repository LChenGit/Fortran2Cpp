#include <iostream>
#include <random>
#include <vector>
#include <cassert>

// Function to generate random numbers
std::vector<float> generateRandomNumbers(size_t count) {
    std::vector<float> r(count);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    for (size_t i = 0; i < count; ++i) {
        r[i] = dis(gen);
    }

    return r;
}

int main() {
    // Generate 5 random numbers
    auto randomNumbers = generateRandomNumbers(5);

    // Print the generated random numbers
    std::cout << "Generated random numbers (within the range [0, 1]):" << std::endl;
    for (auto num : randomNumbers) {
        std::cout << num << std::endl;
    }

    return 0;
}