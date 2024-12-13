#include <iostream>
#include <array>

// Function to initialize array
std::array<int, 6> initializeArray() {
    std::array<int, 6> i;
    for(int j = 0; j < 6; j++) {
        i[j] = j + 1;
    }
    return i;
}

int main() {
    std::array<int, 6> i = initializeArray();
    
    // Print the initialized array (for demonstration)
    for(int j = 0; j < 6; j++) {
        std::cout << "i[" << j << "] = " << i[j] << std::endl;
    }
    
    return 0;
}