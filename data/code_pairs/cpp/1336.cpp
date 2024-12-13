#include <iostream>
#include <sstream>
#include <string>
#include <cassert>

// Function that generates the "Hello, world!" string
std::string helloWorld() {
    std::ostringstream oss;
    oss << "Hello, world!";
    return oss.str();
}

// Unit test for the helloWorld function
void testHelloWorld() {
    assert(helloWorld() == "Hello, world!"); // Test that the function's output matches the expected string
    std::cout << "C++ Stdout: Test passed" << std::endl;
}

int main() {
    // Call the unit test
    testHelloWorld();
    // Optionally, you can also directly print the "Hello, world!" message to demonstrate functionality
    std::cout << "Fortran Stdout: " << helloWorld() << std::endl;
    return 0;
}