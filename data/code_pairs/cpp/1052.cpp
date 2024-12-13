#include <iostream>
#include <string>
#include <cstdlib> // For exit()
#include <cassert> // For assert()

int main() {
    std::string c(72, '!');

    // Test: Check if all characters initialized correctly to '!'
    for (std::size_t i = 0; i < c.length(); i += 2) {
        // We are asserting that every character pair is "!!"
        assert(c.substr(i, 2) == "!!");
    }

    std::cout << "Test Passed: All characters are !!" << std::endl;

    return 0;
}