#include <iostream>
#include <string>
#include <cstdlib> // for std::abs

std::string CHR_NTH(int IVALUE) {
    int TENS, UNITS;
    std::string TABLE[4] = {"th", "st", "nd", "rd"};
    
    TENS = std::abs(IVALUE) % 100;
    UNITS = TENS % 10;
    TENS /= 10;
    
    if (TENS == 1 || UNITS > 3) {
        return "th";
    } else {
        return TABLE[UNITS];
    }
}

void TestCHR_NTH(int num, const std::string& expected) {
    std::string result = CHR_NTH(num);
    if (result == expected) {
        std::cout << "Test passed for number " << num << std::endl;
    } else {
        std::cout << "Test failed for number " << num << ". Expected: " << expected << ", Got: " << result << std::endl;
    }
}

int main() {
    TestCHR_NTH(1, "st");
    TestCHR_NTH(2, "nd");
    TestCHR_NTH(3, "rd");
    TestCHR_NTH(4, "th");
    TestCHR_NTH(11, "th");
    TestCHR_NTH(21, "st");
    TestCHR_NTH(22, "nd");
    TestCHR_NTH(23, "rd");
    TestCHR_NTH(24, "th");
    TestCHR_NTH(100, "th");
    TestCHR_NTH(101, "st");
    TestCHR_NTH(102, "nd");
    TestCHR_NTH(103, "rd");
    TestCHR_NTH(104, "th");
    // Add more tests as needed
    return 0;
}