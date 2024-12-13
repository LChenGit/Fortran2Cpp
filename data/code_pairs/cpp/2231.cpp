#include <iostream>
#include <string>
#include <stdexcept>

void test_program() {
    std::string textt(7, ' '); // Create a string of length 7 filled with spaces.
    std::string& textp = textt; // Reference to textt, similar to Fortran pointer.
    std::string textp2 = textt.substr(0, 5); // Substring of first 5 characters, not a live reference.

    // Check the length conditions
    if (textp.length() != 7) throw std::runtime_error("STOP 1");
    if (textp2.length() != 5) throw std::runtime_error("STOP 2");

    // Modify the strings
    textp = "aaaaaaa"; // This modification affects textt directly.
    textp2 = "bbbbb"; // This modification does not affect textt, so we need to manually update textt.

    // Manually reflect the changes of textp2 back to textt
    textt.replace(0, 5, textp2);

    // Check the final conditions
    if (textp != "bbbbbaa") throw std::runtime_error("STOP 3");
    if (textp2 != "bbbbb") throw std::runtime_error("STOP 4");
}

int main() {
    try {
        test_program();
        std::cout << "All tests passed successfully!" << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}