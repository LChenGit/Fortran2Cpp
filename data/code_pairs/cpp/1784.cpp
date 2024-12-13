#include <iostream>
#include <string>

// Function to be tested
int checkString(const std::string& c) {
    if (c != "Hello, world!") {
        return 1;
    }
    return 0;
}

// Test function
void testHelloWorld() {
    std::string c = "Hello, world!";
    // Expect 0 (success) if the string is correct
    if (checkString(c) == 0) {
        std::cout << "Test passed!" << std::endl;
    } else {
        std::cout << "Test failed!" << std::endl;
    }
}

int main() {
    testHelloWorld();
    return 0; // Successful execution
}