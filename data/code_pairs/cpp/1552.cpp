#include <string>
#include <array>
#include <iostream>

std::string foo(const std::array<int, 4>& ibufr) {
    std::string value;
    for (int i = 0; i < 4; ++i) {
        if (ibufr[i] >= 0 && ibufr[i] <= 255) {
            value += static_cast<char>(ibufr[i]);
        } else {
            std::cerr << "Value out of ASCII range: " << ibufr[i] << std::endl;
        }
    }
    return value;
}

int main() {
    std::array<int, 4> testArray = {65, 66, 67, 68}; // ASCII for ABCD
    std::string result = foo(testArray);
    std::cout << "Test 1: ABCD - " << result << std::endl;
    return 0;
}