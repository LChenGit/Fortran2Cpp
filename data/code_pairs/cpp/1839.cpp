#include <iostream>
#include <cstdint>

int main() {
    const int i1 = sizeof(int); // Mimicking the kind functionality as size, for demonstration.
    const int i2[1] = {i1};
    int i3;

    // Assigning and printing i3 with the kind from i1.
    i3 = static_cast<int>(0);
    std::cout << i3 << std::endl;

    // Assigning and printing i3 with the kind from i2(1).
    i3 = static_cast<int>(0);
    std::cout << i3 << std::endl;

    return 0;
}