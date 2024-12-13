#include <iostream>
#include <string>

std::string version() {
    return "2.2.1";
}

int main() {
    std::cout << "Testing version function..." << std::endl;
    if (version() == "2.2.1") {
        std::cout << "Test passed." << std::endl;
    } else {
        std::cout << "Test failed." << std::endl;
    }
    return 0;
}