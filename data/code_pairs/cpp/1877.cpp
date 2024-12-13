#include <iostream>
#include <array>
#include <string>
#include <iomanip>
#include <sstream>

int arrayManipulationAndCheck() {
    std::array<std::array<std::string, 2>, 4> r = {{
        {"0123456789ab", "0123456789ab"},
        {"0123456789ab", "0123456789ab"},
        {"0123456789ab", "0123456789ab"},
        {"0123456789ab", "0123456789ab"}
    }};

    std::stringstream ss;
    ss << "hello\nworld";
    r[0][0] = ss.str().substr(0, 12);
    r[1][0] = ss.str().substr(6, 12);

    ss.str("");
    ss.clear();
    ss << "hello " << std::setw(1) << "HELLO !" << "\n" << std::left << std::setw(12) << "world" << "WORLD";
    r[0][1] = ss.str().substr(0, 12);
    r[1][1] = ss.str().substr(13, 12);

    if (r[0][0] != "hello      " || r[1][0] != "world      " ||
        r[2][0] != "0123456789a" || r[3][0] != "0123456789a" ||
        r[0][1] != "hello HELLO" || r[1][1] != "world      " ||
        r[2][1] != "0123456789a" || r[3][1] != "0123456789a") {
        return 1; // Indicate error
    }

    return 0; // Indicate success
}

// Main function for standalone execution
int main() {
    if(arrayManipulationAndCheck() == 0) {
        std::cout << "All tests passed successfully." << std::endl;
    } else {
        std::cerr << "Some tests failed." << std::endl;
    }
    return 0;
}