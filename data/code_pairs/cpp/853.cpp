#include <iostream>
#include <string>

void test(std::string& s) {
    s = "Hello World";
}

int main() {
    std::string s(80, ' '); // Create a string of length 80 filled with spaces
    test(s);
    if (s == "Hello World") {
        std::cout << "Test passed." << std::endl;
    } else {
        std::cout << "Test failed. Got: " << s << std::endl;
    }
    return 0;
}