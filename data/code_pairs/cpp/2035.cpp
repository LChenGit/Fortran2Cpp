#include <iostream>
#include <string>
#include <sstream>

int main() {
    int intVar = 10;
    float floatVar = 20.5;
    std::string strVar = "Hello";

    // Arithmetic operations
    intVar = intVar + 5;
    floatVar = floatVar * 2.0;

    // Character to integer conversion
    std::string str = "123";
    int num;
    std::stringstream(str) >> num; // String to integer

    // Integer to character conversion
    str = std::to_string(num); // Integer to string

    return 0;
}