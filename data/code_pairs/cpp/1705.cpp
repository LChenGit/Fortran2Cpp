#include <iostream>
#include <string>
#include <algorithm>
#include <array>

int main() {
    const std::string b = "a";
    const std::string e = "c";
    std::array<std::string, 3> s = {{"a", "b", "c"}};

    auto minElement = *std::min_element(s.begin(), s.end());
    auto maxElement = *std::max_element(s.begin(), s.end());

    if (minElement != b) {
        std::cerr << "Unexpected minimum value" << std::endl;
        exit(1); // Corresponds to STOP 1 in Fortran
    }

    if (maxElement != e) {
        std::cerr << "Unexpected maximum value" << std::endl;
        exit(2); // Corresponds to STOP 2 in Fortran
    }

    return 0;
}