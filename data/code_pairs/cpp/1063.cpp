#include <iostream>

void testFunction() {
    if (false) {
        std::cout << "These lines" << std::endl;
        std::cout << "are not printed" << std::endl;
        std::cout << "if the the CLAW compiler has processed" << std::endl;
        std::cout << "the file." << std::endl;
    }
}

void test_no_output() {
    std::cout << "Running test_no_output: Expect no other output..." << std::endl;
    testFunction();
}

int main() {
    test_no_output();
    return 0;
}