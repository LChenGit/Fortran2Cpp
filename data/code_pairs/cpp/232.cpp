#include <array>
#include <iostream>
#include <string>

int main() {
    std::array<std::string, 2> arr = { "abc", "foobar" };
    
    std::cout << "Array contents:" << std::endl;
    for (const auto& str : arr) {
        std::cout << str << std::endl;
    }

    return 0;
}