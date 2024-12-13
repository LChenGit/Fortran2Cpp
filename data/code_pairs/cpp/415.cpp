#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <string>
#include <sstream>

bool testFunction() {
    int64_t i = 1;
    for (int j = 1; j <= 63; ++j) {
        i = i * 2;
    }
    std::stringstream ss;
    ss << i;
    std::string l = ss.str();
    return (l == "-9223372036854775808");
}

int main() {
    if (testFunction()) {
        std::cout << "Test Passed" << std::endl;
    } else {
        std::cout << "Test Failed" << std::endl;
    }
    return 0;
}