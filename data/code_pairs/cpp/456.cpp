// main.cpp
#include <iostream>
#include <vector>

struct Container {
    int entry = -1;
};

std::vector<Container> pack(const std::vector<Container>& a, const std::vector<bool>& mask) {
    std::vector<Container> result;
    for (size_t i = 0; i < a.size(); ++i) {
        if (mask[i]) {
            result.push_back(a[i]);
        }
    }
    return result;
}

int main() {
    std::vector<Container> a1(1), a2(1); // Initialize with size 1
    std::vector<bool> mask = {true}; // Mask is always true

    a2[0].entry = 1; // Set up test data
    a1 = pack(a2, mask); // Perform the operation under test

    // Check that the operation produced the expected result
    if (a1[0].entry == 1) {
        std::cout << "Test Passed" << std::endl;
    } else {
        std::cout << "Test Failed" << std::endl;
        return 1;
    }

    return 0;
}