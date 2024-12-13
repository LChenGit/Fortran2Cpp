#include <iostream>

// Function prototype
void GRFLUN(int& LUN);

int main() {
    int LUN = 5; // Initialize LUN with a non-zero value
    GRFLUN(LUN); // Call the function

    // Check if LUN has been set to 0
    if (LUN == 0) {
        std::cout << "Test passed: LUN is 0" << std::endl;
    } else {
        std::cout << "Test failed: LUN is not 0" << std::endl;
    }

    return 0;
}

// Function definition
void GRFLUN(int& LUN) {
    LUN = 0;
}