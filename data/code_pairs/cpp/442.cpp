#include <iostream>
#include <string>

// Function to return the greeting message
std::string getHelloWorld() {
    return " Hello, world!";
}

int main() {
    std::cout << getHelloWorld() << std::endl; // Ensure to add a leading space to match Fortran's default behavior
    return 0;
}