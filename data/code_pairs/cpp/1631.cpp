#include <iostream>
#include <string>
#include <cassert>

void foo(int i) {
    std::string s = "Hello"; // Assuming the input i is at least 5
    std::cout << "Function foo called with i = " << i << ". String length: " << s.length() << std::endl;
    std::cout << "Contents of s: " << s << std::endl;
}

int main() {
    foo(10); // Example call with i=10
    return 0;
}