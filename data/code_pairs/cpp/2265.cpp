#include <iostream>
#include <array>
#include <string>

int main() {
    std::array<std::string, 2> arr = {"a", "bb"};  // Original array, as it matches the Fortran output
    for (const auto& str : arr) {
        std::cout << str << " ";  // Space added after each string for consistency with Fortran output
    }
    std::cout << std::endl;  // Ensure newline at the end, matching Fortran's behavior
    return 0;
}