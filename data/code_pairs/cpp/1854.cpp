// Sss.hpp
#ifndef SSS_HPP
#define SSS_HPP

class Sss {
public:
    void exampleMethod() {
        std::cout << "This is an example method within the class Sss." << std::endl;
    }
};

#endif // SSS_HPP

// main.cpp
#include <iostream>
#include "Sss.hpp"

int main() {
    Sss instance; // Create an instance of the class.
    instance.exampleMethod(); // Call the method to print the message.
    return 0;
}