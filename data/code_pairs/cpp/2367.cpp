#include <iostream>
#include <array>
#include <string>

int main() {
    std::array<std::string, 3> a = { "Takata ", "Tanaka ", "Hayashi" };
    std::array<std::string, 3> b = { "abc", "abc", "abc" };
    std::string c = "abcd";

    // Print the values to verify
    std::cout << "Array a:" << std::endl;
    for (const auto& str : a) {
        std::cout << str << std::endl;
    }

    std::cout << "Array b:" << std::endl;
    for (const auto& str : b) {
        std::cout << str << std::endl;
    }

    std::cout << "String c:" << std::endl;
    std::cout << c << std::endl;

    return 0;
}