#include <iostream>
#include <string>
#include <memory>

void testStringLength(const std::string& s, int expected_length) {
    int l2 = s.length();
    if (l2 == expected_length) {
        std::cout << "Test Passed. String length is: " << l2 << std::endl;
    } else {
        std::cout << "Test Failed. Expected: " << expected_length << " Got: " << l2 << std::endl;
    }
}

int main() {
    std::unique_ptr<std::string> s = std::make_unique<std::string>("123  ");
    testStringLength(*s, 5); // Testing the string length

    return 0;
}