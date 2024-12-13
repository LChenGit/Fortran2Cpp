// program.cpp
#include <iostream>
#include <string>

void test(const std::string& str) {
    std::cout << "Testing with string: " << str << std::endl;
}

int main() {
    test("abc");
    return 0;
}