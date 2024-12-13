#include <iostream>
#include <string>
#include <cstdlib> // For std::exit

void error(const std::string& function_name, const std::string& message, double value, int level) {
    if (level < 1 || level > 3) {
        std::cerr << "*** Error in Subroutine error:" << std::endl;
        std::cerr << "*** Message: Wrong Errorlevel" << std::endl;
        std::cerr << "*** Related Value: " << level << std::endl;
    }

    if (level == 1) {
        std::cerr << "*** Warning in Subroutine " << function_name << ":" << std::endl;
    } else if (level == 2) {
        std::cerr << "*** Error in Subroutine " << function_name << ":" << std::endl;
    } else if (level == 3) {
        std::cerr << "*** Fatal Error in Subroutine " << function_name << ":" << std::endl;
    }
    std::cerr << "*** Message: " << message << std::endl;
    std::cerr << "*** Related Value: " << value << std::endl;

    if (level >= 3) {
        std::cerr << "*** Program stopped." << std::endl;
        std::exit(137);
    }
}

int main() {
    // Demonstrate the usage of the 'error' function
    error("testFunc1", "This is a warning message.", 1.0, 1);
    error("testFunc2", "This is an error message.", 2.0, 2);
    // Note: Uncommenting the line below will terminate the program due to std::exit(137)
    // error("testFunc3", "This is a fatal error message.", 3.0, 3);

    return 0;
}