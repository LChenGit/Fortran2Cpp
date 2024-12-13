#include <iostream>

// Assuming this function is defined in a separate file or earlier in the same file
void S(int& P) {
    P = P + 1;
}

// Main function to demonstrate usage, this part can be separated into a test file if needed.
int main() {
    int x = 5;
    S(x); // Call the function
    std::cout << "After calling S, x = " << x << std::endl;
    return 0;
}