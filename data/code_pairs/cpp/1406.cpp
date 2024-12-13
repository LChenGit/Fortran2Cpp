#include <iostream>
#include <vector>

// Function Prototype
void movint(int nmov, const std::vector<int>& ifrom, std::vector<int>& ito);

int main() {
    int nmov = 5;
    std::vector<int> ifrom(nmov), ito(nmov);

    // Initialize the source vector
    for (int i = 0; i < nmov; ++i) {
        ifrom[i] = i + 1; // Adjusting for 0-based indexing in C++
    }
    
    // Perform the operation
    movint(nmov, ifrom, ito);
    
    // Check the results
    for (int i = 0; i < nmov; ++i) {
        if (ito[i] != ifrom[i]) {
            std::cout << "Test failed!" << std::endl;
            return 1;
        }
    }
    
    std::cout << "Test passed!" << std::endl;
    return 0;
}

// Function Definition
void movint(int nmov, const std::vector<int>& ifrom, std::vector<int>& ito) {
    for (int i = 0; i < nmov; ++i) {
        ito[i] = ifrom[i];
    }
}