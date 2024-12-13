#include <iostream>
#include <string>
#include <cassert>

std::string Upper(const std::string& str) {
    if (str.size() < 2) { // Check if string has at least two characters
        std::cerr << "STOP 2" << std::endl;
        std::exit(2);
    }
    // Extract first two characters and assume upper case conversion
    std::string upper = str.substr(0, 2); 
    return upper;
}

void test_upper() {
    std::string result = Upper("abcdefgh");
    assert(result == "ab" && "Test failed: Expected 'ab'");
    std::cout << "Test passed." << std::endl;
}

int main() {
    test_upper();
    return 0;
}