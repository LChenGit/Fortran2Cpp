#include <iostream>
#include <sstream>

// Function to encapsulate the output generation
std::string generateOutput() {
    std::ostringstream oss;
    oss << "next is a form feed" << char(12) << std::endl;
    oss << "that was a form feed" << std::endl;
    oss << "this is BEL" << char(7) << std::endl;
    return oss.str();
}

int main() {
    std::cout << generateOutput();
    return 0;
}