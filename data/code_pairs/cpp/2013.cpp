#include <cstdint>
#include <iostream>
#include <string>

std::string repeat(const std::string& str, int n) {
    std::string result;
    for(int i = 0; i < n; ++i) {
        result += str;
    }
    return result;
}

int main() {
    int8_t i1 = 1; // equivalent to integer(kind=1)
    int16_t i2 = 1; // equivalent to integer(kind=2)
    int32_t i4 = 1; // equivalent to integer(kind=4)
    int64_t i8 = 1; // equivalent to integer(kind=8), corrected to match 64-bit integer
    double r = 1.0; // equivalent to real(kind=8)

    std::string s1 = "42"; // character(len=2)
    std::string s2;

    s2 = repeat(s1, i1);
    if (s2 != s1) return 1;
    s2 = repeat(s1, i2);
    if (s2 != s1) return 2;
    s2 = repeat(s1, i4);
    if (s2 != s1) return 3;
    s2 = repeat(s1, i8);
    if (s2 != s1) return 4;

    std::cout << "All tests passed successfully." << std::endl;
    return 0; // Successful execution
}