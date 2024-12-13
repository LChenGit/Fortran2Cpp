#include <iostream>
#include <vector>
#include <cassert>

void verify_subvector(const std::vector<float>& subvector) {
    // Expected values in the subvector
    std::vector<float> expected = {1.0, 3.0, 5.0, 7.0, 9.0};

    // Check each element
    for (size_t i = 0; i < subvector.size(); ++i) {
        assert(subvector[i] == expected[i] && "Test failed: subvector element mismatch");
    }

    std::cout << "Test passed: subvector is correct" << std::endl;
}

int main() {
    std::vector<float> vector(10);
    std::vector<float> subvector(5);

    // Initialize the vector with some values
    for (int i = 0; i < 10; ++i) {
        vector[i] = static_cast<float>(i + 1);  // Example initialization
    }

    // Assign every other element from vector to subvector
    for (int i = 0; i < 5; ++i) {
        subvector[i] = vector[i * 2];
    }

    // Print subvector to verify
    std::cout << "Subvector: ";
    for (const auto& val : subvector) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Verify the correctness
    verify_subvector(subvector);

    return 0;
}