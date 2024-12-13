#include <iostream>
#include <vector>

int main() {
    std::vector<float> s;

    // Allocate space for 5 elements
    s.resize(5);

    // Assign values to the array
    for (size_t i = 0; i < s.size(); ++i) {
        s[i] = static_cast<float>(i + 1);
    }

    // Print the values to verify correctness
    std::cout << "Array values:" << std::endl;
    for (size_t i = 0; i < s.size(); ++i) {
        std::cout << s[i] << std::endl;
    }

    return 0;
}