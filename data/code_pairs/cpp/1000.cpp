#include <iostream>
#include <string>
#include <cassert>

// Function that mimics the behavior of the Fortran program
std::string helloWorld() {
    return "Hello, World!";
}

// Main function that also serves as a simple test driver
int main() {
    // Expected output from the helloWorld function
    std::string expected = "Hello, World!";
    
    // Call the function and store its result
    std::string result = helloWorld();
    
    // Check if the result matches the expected output
    assert(result == expected);
    
    // If the program reaches this point, the test passed
    std::cout << result << std::endl;
    
    return 0;
}