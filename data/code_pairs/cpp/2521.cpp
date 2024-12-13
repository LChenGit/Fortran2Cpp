#include <iostream>
#include <string>
#include <cassert>

std::string ch() {
    return "hello";
}

void test_ch() {
    assert(ch() == "hello");
    std::cout << "Test passed!" << std::endl;
}

int main() {
    test_ch();
    return 0;
}