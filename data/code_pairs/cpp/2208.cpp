#include <iostream>

int main() {
    int i = 5;

    // Check if i is equal to 5
    if (i == 5) {
        std::cout << "Test passed: i is equal to 5" << std::endl;
    } else {
        std::cout << "Test failed: i is not equal to 5" << std::endl;
    }
    return 0; // Indicate success or failure is not explicitly shown here, but could be inferred from the message.
}