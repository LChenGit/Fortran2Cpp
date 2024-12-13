#include <iostream>

namespace mod_behavior {
    int get_number() {
        return 42;
    }
}

void test_get_number() {
    int result = mod_behavior::get_number();
    std::cout << "Testing get_number function...\n";
    if (result == 42) {
        std::cout << "Test passed: get_number() returned " << result << std::endl;
    } else {
        std::cout << "Test failed: get_number() returned " << result << " instead of 42" << std::endl;
    }
}

int main() {
    test_get_number();
    return 0;
}