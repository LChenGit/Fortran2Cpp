#include <iostream>

// A function that we can call from our main or tests
void printHelloWorld() {
    std::cout << "Hello, World!" << std::endl;
}

int main() {
    printHelloWorld();
    return 0;
}