// main.cpp
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

int main() {
    std::ostringstream buffer;
    float real_4 = 4.18f;
    double real_8 = 4.18;

    buffer << std::fixed << std::setprecision(6) << ":" << real_4 << ":";
    std::cout << buffer.str() << std::endl;
    buffer.str(""); // Clear the buffer

    buffer << std::fixed << std::setprecision(6) << ":" << real_8 << ":";
    std::cout << buffer.str() << std::endl;

    return 0;
}