// File: CRASH_ModCaltz.cpp and CRASH_ModCaltz.hpp (if you split declaration and implementation)
#include <iostream>

namespace CRASH_ModCaltz {
    int getValue() {
        return 42;
    }
}

void testGetValue() {
    int expected = 42;
    int result = CRASH_ModCaltz::getValue();
    if (result == expected) {
        std::cout << "Test passed: Value is " << result << std::endl;
    } else {
        std::cout << "Test failed: Expected " << expected << ", got " << result << std::endl;
    }
}

int main() {
    testGetValue();
    return 0;
}