#include <iostream>

void compute_values(int& i, int& j) {
    i = 0; // Initialize i here for consistency
    i = i + 2 + 3;
    j = 1 + 2 * 3;
    i = (i + 1) * 2;
}

int main() {
    int i; // i is going to be initialized inside compute_values
    int j;
    compute_values(i, j);
    
    if (i == 12 && j == 7) {
        std::cout << "Test Passed." << std::endl;
    } else {
        std::cout << "Test Failed. i: " << i << " j: " << j << std::endl;
    }
    
    return 0;
}